`# Recoil Deep Dive

All the basics: Atoms, selectors, Async data queries, `useRecoilState`, `useRecoilValue`, `useSetRecoilState`.
And advanced: `atomFamily`, `selectorFamily`, `useRecoilStateLoadable`, `useRecoilValueLoadable`

## Basics

Trying to build the linkedin navbar where there is home, network, jobs, messaging, notifications, me.
In the normal react way we'll have four state variables in the main App component, but in the recoil way we'll also have four atoms which are similar but much more optimal than normal state vars and is the main Recoil way to do state management.

We can define the atoms in the same file but it'll be better to use a new file

Then did some normal logic to set the state from outside into the main component

Also since we defined the state inside the App component previously so we need to wrap the whole component in the `<RecoilRoot>` but since it is the main component so we need to define another component and then define the state iniside it and then wrap the `<RecoilRoot>` over that custom component in the main App component

- NOTE: If you want to just update the state and not get the actual value, much like using the `setFunction` of the useState only and not doing anything by the variable, then use the `useRecoilSetState` hook which lets you only update the data singlehandedly and not get anything back. `const setMessageCount = useSetRecoilState(messageAtom)`

### Selectors

A **selector** represents a piece of derived state. You can think of derived state as the output of passing state to a pure function that derives a new value from the said state. Derived state is a powerful concept because it lets us build dynamic data that depends on other data.

- Now if we want to add all the notifications and show them on top of the me button, then you will need to add all the count that we've got until now. So we add but that will cause a re-render everytime the main App loads, so we should at the very least use `useMemo` so that if neither of the value changes then it should not re-render the number of notifications.
  - Or the more optimal way to do this using the state as well is by using `selectors` of Recoil. This is the much better approach since now Recoil handles all the re-render and also sees who depends on whom and if that changes then it'll re-render. Also the main reason to use this approach is that if we have a new selector that needs to show another icon to render the total notifications + the messages not replied to or something that will depend on the other selector, we can just use that selector in the new selector, i.e they can depend on each other. If atoms depend no each other for another usecase we can just create a selector and that'll work as well as per needed. Also if we want to create a new one we can do that too and recoil will handle everything of teleporting that stuff to one another. But in case of React's `useState` we can't do that.

### Asynchronous Data Queries

If we actually hit the backend and get the data from the server we will be using that using a normal useState but now using Recoil we can do that via the atoms and inside that we can set the atom types.

Also here we are combining all the different types of atoms into one so that it is easy to look at, instead of having four different for four types of data and then adding them differently.

So atom now here doesn't return a single value, it returns a value that has four keys of which all of them can be individually used

```jsx
export const notifications = atom({
  key: "networkAtom",
  default: {
    network: 4,
    jobs: 6,
    messaging: 3,
    notifications: 3,
  },
});
// giving these default values will make them appear on the first render and then the actual values from the backend will replace it causing a flash and then a replacement

export const totalNotificationSelector = selector({
  key: "totalNotificationSelector",
  get: ({ get }) => {
    const allNotifications = get(notifications);
    return (
      allNotifications.network +
      allNotifications.jobs +
      allNotifications.notifications +
      allNotifications.messaging
    );
  },
});
```

So now we can just import it and use it like any other object in the main app function. And the total notification selector just gets the value and whenever it changes it re-changes the old value causing a re-render

Also the backend call is happening using useEffect, so we are using the set function from the atom to update it on component mount.

```jsx
useEffect(() => {
  axios.get("https://sum-server.100xdevs.com/notifications").then((res) => {
    setNetworkCount(res.data);
  });
}, []);
```

This is not the correct way of doing "async queries" but surely it is a dumb way of doing it. The reasons are as follows:

1. The flash that occurs due to the default values being already set and then the actual values coming from the backend to replace it. We can directly just hit the backend in the place of synchronously storing the data in the atom in the get

So we can just put the axios data fetching directly in the atoms default value and as such it will populated with that data only from the starting. But there comes an error saying that the default value cannot be a function since the default value of an atom should be synchronous or it can be a selector which can be async, so here comes the concept of async data queries

Now if we know that the data fetching happens asynchronously and this is how we would write the atom

```jsx
export const notifications = atom({
  key: "networkAtom",
  default: selector({
    key: "notificationsSelector",
    get: async () => {
      const data = await Axios.get(
        "https://sum-server.100xdevs.com/notifications",
      );
      return res.data;
    },
  }),
});
```

- We would have to use `selector` inside the default value since atom can't contain async code in the default value and the put all the async data fetching logic there and so the whole thing now becomes optimized to get async data with a somewhat white flash but with no zeroes(default values) first being populated.

- Why there is no flash? : Because there is first a re-render that happens which makes the whole screen white and it means that nothing renders on the screen until the main data comes and then when the backend serves the data it then quickly repopulates the data with a re-render and its too fast for the eye to see so it just feels like it happened immediately. But to see the actual white screen before a re-render we can use a promisified delay

- About the logic of the `await new Promise(r => setTimeout(r, 5000))`

Yes, you are correct. The `setTimeout` logic is creating a delay using a Promise. Here's a breakdown of how it works:

```javascript
await new Promise((r) => setTimeout(r, 5000));
```

1. `setTimeout`: It's a JavaScript function that schedules a function or evaluates an expression after a specified delay (in milliseconds).

2. `new Promise`: It creates a new Promise object. A Promise represents the eventual completion or failure of an asynchronous operation and its resulting value.

3. `(r => setTimeout(r, 5000))`: It's an arrow function that takes a single argument `r` (which represents the `resolve` function of the Promise). Inside the function, it calls `setTimeout` with a delay of 5000 milliseconds and passes the `resolve` function as the callback. This means the Promise will be resolved after the specified delay.

4. `await`: It pauses the execution of the surrounding async function until the Promise is resolved or rejected.

So, in summary, this line is creating a delay of 5000 milliseconds (5 seconds) before fetching data from the backend. It's a common practice to introduce delays in certain scenarios, for example, to simulate a loading state or to prevent too frequent requests to a server. In this case, it looks like it's introducing a delay before making the actual request to the notifications endpoint.

## atomFamily

Sometimes we need more than one atoms for our use case like in case of the todo application

- Question - Create a component that takes a todo id as input, and renders the TODO
  You need to store the Todo in an atom (can’t use useState)
  All the TODOs can be hardcoded as a variable

- The problems that we'll face here are:
  Would you have a single atom ?
  Would you have one atom per todo?
  How would you create (and delete) todos dynamically?

Out of all the things that we have learnt until now about Recoil and Atoms, we haven't learnt how to dynamically create atoms since atoms work when we know that we have stuff that will render once on screen(much like that notifications of which only the values change), but if we have a bunch of todos then each will need it's own atoms so we'll have to dynamically create more and more atoms. We can make the default value an array such that we can update dynamically but there are downsides in doing so, so we will need to do stuff in another way

So we'll have 5 todos and each needs to have its own atom and if two of them have the same id then they need to hit the same atom and if they have different ids then it should create one dynamically. This is where the `atomFamily` comes to solve.

So rather than hitting an atom we would hit the `atomFamily` which contains all the atoms. So whenever the component calls the `atomFamily` for a new atom from it or an atom specific to an input, it needs to tell it what todo id does it need values for, it'll give a new atom for that todos id.

Now whenever we create one `atomFamily` we need to pass in input in it inside its parenthesis and these inputs will uniquely give us an atom. Also we'll need to use `useRecoilValue` here so the syntax goes like `useRecoilValue(todoAtomsFamily(id))`

and the way to do set the atomFamily happens in this way; And the default value here is that we are not setting new atoms for every todo, instead we are storing the todos in another file and then we are just iterating over it to get the default value to every atom in the atomFamily

```jsx
import { atomFamily } from "recoil";
import { TODOS } from "./todos";

export const todosAtomFamily = atomFamily({
  key: "todosAtomFamily",
  default: (id) => {
    // this return statement just finds the id that matches the constraints of the things in the brackets and returns the todo if that matches or else returns null if not
    return TODOS.find((x) => x.id === id);
  },
});
```

the inside documentation of atomFamily also says the same thing; it is just another function that returns a memoized atom for each unique parameter value, since if we get lets say a lot of todo we can't just go on creating a lot of atoms by hand, instead we need to give that task to someone else who will create an atom for us dynamically

```ts
/**
 * Returns a function which returns a memoized atom for each unique parameter value.
 */
export function atomFamily<T, P extends SerializableParam>(
  options: AtomFamilyOptions<T, P>,
): (param: P) => RecoilState<T>;
jsx;
```

This does the job of making an atom dynamically whenever we create more todos using an id and when we copy and create more using the same id it generates a single atom once for all of them and if we update the value in one of them then it'll be reflected in all of the others. And if one of the todo changes, then it'll only re-render the one that changes and the other ones remain intact

## Selector Family

Just like we need async calls in an atom we need a selector, similarly in a todo application if we are supposed to get todos from a backend is when we need a selector family. Given an id as an input, how to hit a specific server get back the data from the server and then render it rather then getting it from in memory

Also we cannot write an async call in the default value and hit the backend in the atom as well as the atomFamily. So we need the `selectorFamily` inside the default value of the `atomFamily` to do the async task but this is different from the `selector` inside `atom` code. It looks something like the following:

```jsx
export const todosAtomFamily = atomFamily({
  key: "todosAtomFamily",
  default: selectorFamily({
    key: "todoSelectorFamily",
    get:
      (id) =>
      async ({ get }) => {
        const res = await axios.get(
          `https://sum-server.100xdevs.com/todo?id=${id}`,
        );
        return res.data.todo;
      },
  }),
});
```

The above code will be a little hard to understand, but in the default value of the `atomFamily` it returns a `selectorFamily` that has another set of `key` and `get` and so the `get` gets a function which has a argument `id` which is thing passed by the `atomFamily` call in the `const [todo, setTodo] = useRecoilState(todosAtomFamily(id));` main App.jsx file which returns the final function that does the async task and as such does the data fetching. This is the way to write it in production but it can be written in an easy way using traditional functions style. (this arrow just means return the thing that comes to the next of the arrow).

There is more stuff in the official [docs](https://recoiljs.org/docs/introduction/getting-started). One more important thing is that we should always use a `selectorFamily` when we need the features of selectors inside the `atomFamily` because an `atomFamily` creates multiple atoms but using only `selectors` will create only one selector for different atoms which we don't want and it will surely cause errors since the key will be the same for every atom. But by using `selectorFamily` inside `atomFamily` we'll be creating different selectors for different atoms and as such it will not cause any errors

Also selector family is also optimized so if the request is repeated it doesn't send more requests and instead shows the once fetchd and cached data stored in the browser

In the last question we didn't do a selector family because the todos were of the in-memory variable type so there is no need of the selector family but in case of a real backend we'll need one.

## useRecoilStateLoadable and useRecoilValueLoadable

What happens when the values aren’t loaded immedietely? There is a blank white space as long as the values don't come back.
For example, the TODOs that are coming back from the server. As long as the todo data don't come from the server there will be a white space in place of the todos
How can we show loader on screen when that happens rather than an empty state, rather than showing an empty state.

So to implement this loader/loading animation or something like that so that we don't see a blank space, we did the `Suspense` thing in the previous classes but in the case of 'Recoil' we use the `useRecoilStateLoadable` instead of `useRecoilState`.

So this `useRecoilStateLoadable` returns the same two things as the `useRecoilState` namely the variable to store the current state and a set function to change that state, but in the loadable's case the todo(is no longer a set of todos) is an object that returns a few things some of those being 'state' and 'contents'.

- The state represents whether or not this atomFamily's selectorFamily( most appropriately the async stuff ) has resolved / returned something or not
- On logging out the state we can see that until the state resolves it gives out "loading" to the console which basically tells to the component itself that it is loading, and then eventually we get the `hasValue` which means that the async stuff has been resolved.
- Why do we need this: Because the user has to know that the stuff is loading when their internet connection is a bit slow and as such they shouldn't get a white space instead a "loading..." or a loading animation or a skeleton of what may appear instead of the data so that the user knows that the thing is taking time to come i.e loading and they're supposed to wait till then.
-

```jsx
// what does the todo contain
// {
//   contents:   ,
//   state:   ,
// }

function Todo({ id }) {
  const [todo, setTodo] = useRecoilStateLoadable(todosAtomFamily(id));
  console.log(todo.state);
  if (todo.state === "loading") {
    return <div>loading......</div>;
  } else if (todo.state === "hasValue") {
    return (
      <>
        {todo.contents.title}
        {todo.contents.description}
        <br />
      </>
    );
  } else if (todo.state === "hasError") {
    return <div>Error while loading the data from the backend</div>;
  }
}
```

And if we want to apply that loadable to just the value then we can use the `useRecoilValueLoadble` which does the same but only for the value

This loadable hook is also useful for the error catching because there will be times when the backend will be down or website url is wrong or endpoint is wrong or there may be errors(no loading or value) in the 400/500 status codes, in fetching data. Axios also throws error if it finds any but we can also manually throw error. There is a need to handle them more gracefully since if we use normal use `useRecoilState` or `useRecoilValue` then our app will crash and so it just blows up the DOM(nothing will render). So we should handle them properly using axios' loadables or the suspense, ErrorBoundary API so as to show something else while the hook fetches the data

#### About the 'hasValue' 'hasError' and 'loading'

In Recoil, `hasValue`, `hasError`, and `loading` are states provided by the `Loadable` type, which is used for handling asynchronous data.

Here's a brief explanation of each state:

1. **`hasValue`:** This state indicates that the asynchronous operation has completed successfully, and the `contents` property of the `Loadable` object contains the actual value or data that was loaded.

2. **`hasError`:** This state indicates that an error occurred during the asynchronous operation. The `contents` property might be `undefined` in this case, and additional information about the error might be available in other properties like `error`.

3. **`loading`:** This state indicates that the asynchronous operation is still in progress, and the data has not been fully loaded yet. The `contents` property might be `undefined` at this stage.

These states are specific to Recoil's `Loadable` type and are not inherent to JavaScript itself. Recoil uses these states to provide a clean way to handle asynchronous data in a React application. When working with Recoil and asynchronous data, you use these states to determine the current status of the asynchronous operation and act accordingly in your components.

In your `Todo` component:

- If `todo.state` is `'loading'`, you display a loading message.
- If `todo.state` is `'hasValue'`, you display the content of the loaded data.
- If `todo.state` is `'hasError'`, you display an error message.

This pattern allows you to handle different scenarios during the lifecycle of an asynchronous operation and provide a good user experience.

In your `Todo` component:

```javascript
function Todo({ id }) {
  const [todoLoadable, setTodoLoadable] = useRecoilStateLoadable(
    todosAtomFamily(id),
  );

  if (todoLoadable.state === "loading") {
    return <div>Loading...</div>;
  } else if (todoLoadable.state === "hasValue") {
    const todo = todoLoadable.contents; // Access the loaded data
    return (
      <>
        {todo.title}
        {todo.description}
        <br />
      </>
    );
  } else if (todoLoadable.state === "hasError") {
    return <div>Error while loading the data from the backend</div>;
  }
}
```

By checking the `state` property of `Loadable`, you can handle different scenarios based on whether the data is still loading, has been successfully loaded (`hasValue`), or if there's an error (`hasError`). This helps you create more robust and responsive components when dealing with asynchronous data.

### Some assignment misc stuff

- You can add if else ternary operator to show something else when the data has not been loaded yet by doing

```jsx
<div>
  {userData ? (
    <div>
      <img src={userData.avatar_url} alt="GitHub Avatar" />
      <h2>{userData.name}</h2>
      <p>{userData.bio}</p>
      <p>Followers: {userData.followers}</p>
      <p>Following: {userData.following}</p>
      <p>Public Repositories: {userData.public_repos}</p>
    </div>
  ) : (
    <p>Loading...</p>
  )}
</div>
```
