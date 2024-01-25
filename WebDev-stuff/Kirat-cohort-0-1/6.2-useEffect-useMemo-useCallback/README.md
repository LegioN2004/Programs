# 6.2 Common hooks in React

All about useEffect, useCallback, useMemo, custom hooks(biggest thing) for other people to use, Prop drilling

## some jargons to know

**Side effects**: In react the concept of a side effect encompasses any operations that reach outside the functional scope of a React component. These operations can affect other components, interact with the browser, or perform async data fetching. Means in React functional components(we create a function and pass some logic inside it) anything that is not related to rendering i.e updating/adding/removing anything from the DOM are called side effects. For eg: data fetching, setTimeout/setInterval, directly manipulating DOM from React(shouldn't be done btw)

Most dynamic websites are full stack having both frontend and backend. So the talking that is done with the backend are also called side-effects. Why should we know this, there are some specific things that are happening when there are some rendering, functions get called, and there are these other set of things that need to happen like that data fetching that happen in the side and as such they're called side-effects. They shouldn't necessarily collude with the rendering cycle

**Hooks**: Hooks are a feature that was introduced in React 16.8 that allow us to use state and other React features without writing a class. They enable functional components to have access to stateful logic and lifecyle features which were previously only possible in class components. This has led to a more concise and readabale way of writing components in React

## Hooks

### useState

lets us describe the state of our app. Whenever the state updates, it triggers a re-render which finally results in a DOM update. As everything that we have done until now

### useEffect

The 'useEffect' hook is a feature in React, a popular JavaScript library for building user interfaces. It allows you to perform side effects in function components. Side effects are operations that can affect other components or can't be done during rendering, such as data fetching, subscriptions, or manually changing the DOM in React components.

- Ignore subscriptions
- Data fetching is something that can't be done during rendering, or more specifically shouldn't be done during rendering. If we try to do so we'll face many issues since React renders very often, that's why we need 'useEffect' here.

The 'useEffect' hook serves the same purpose as componentDidMount componentDidUpdate', and 'component WillUnmount in React class components, but unified into a single API.

- With an example: lets take the example of a F1 race that does some no of laps and needs to do pit stop for certain problems or checks for the car/driver. Will he do that in every lap, no, but will he do that if there is any problems with his car/himself, yes. So data fetching is also like that. Whenever React renders for the first time, then only we need to fetch data from the backend for the first time. This is the certain condition that when met, it doesn't matter how many re-renders happen in the frontend, only when the condition is met then will the backend fetch data will happen. It is not supposed to do that in every every render and it is what's a pit stop called a side-effect.

  - There are then certain conditions under which we'll run the side-effect.
  - pit stop is the side effect but we making the pit stop is something called useEffect
  - useEffect has the two part and the second part is the 'dependency array' that lets us put the set of conditions under which we want to run the main logic inside the useEffect function, so that it only goes once(as per the todo app from the todos server)

- What is dependency array: It states when should the callback function run, the callback being the function written inside the 'useEffect' as the main logic function. Also it can only take a state variable so that anytime the state variable changes the 'useEffect' will run the function inside it again. That's the whole

#### using Axios library

It still uses fetch under the hood but has much cleaner syntax and usage. Can be used in a similar way as of fetch

```js
axios.get("https://sum-server.100xdevs.com/todos?id=1").then(async (result) => {
  setCount(result.data.todos);
});
```

Explanation:

1. **Import Axios:**

   - Import Axios at the beginning of your file. You need to install Axios first using `npm install axios` if you haven't done so.

   ```js
   import axios from "axios";
   ```

2. **Axios GET Request:**

   - Use `axios.get()` to make a GET request to the specified URL (`"https://sum-server.100xdevs.com/todos?id=1"` in this case).
   - we can use get/post/put/delete which shows the type of request then in the parentheses and inside the double quotes we need to send in the specific url

   ```js
   axios.get("https://sum-server.100xdevs.com/todos?id=1");
   ```

3. **Handling the Promise:**

   - Use `.then()` to handle the successful response from the API.
   - Inside the `.then()`, you can access the response using the `result` parameter.
   - then we can just take the json output by using the correct key directly in the setCount using `setCount(result.data.todos)` where data is the json

   ```js
   .then(async (result) => {
     setCount(result.data.todos);
   })
   ```

4. **Setting State:**

   - Use `setCount` to update the state with the data received from the API.

   ```js
   setCount(result.data.todos);
   ```

5. **Error Handling:**

   - Use `.catch()` to handle any errors that might occur during the API request.

   ```js
   .catch((error) => {
     console.error("Error fetching data:", error);
   });
   ```

6. **Rendering the Result:**

   - Render the `Todo` component for each item in the `count` state.

   ```js
   {
     count.map((todo) => (
       <Todo key={todo.id} title={todo.title} description={todo.description} />
     ));
   }
   ```

- Also we don't need to add async await explicitly since axios is smart enough to know that this is pulling in json and doing all the async stuff by itself
- Due to the strict mode in react, it does render the useEffect twice for which we see the elements rendering twice

- About the `request.data.todos`

In Axios, the `result` object returned in the `.then()` callback of a successful request contains various properties, including the `data` property. The `data` property contains the response data returned from the server.

In your specific example:

```jsx
axios.get("https://sum-server.100xdevs.com/todos?id=1").then(async (result) => {
  setCount(result.data.todos);
});
```

- `result`: The `result` object is the response object returned by the Axios request.
- `result.data`: The `data` property of the response object contains the response data, which is typically the body of the HTTP response.
- `result.data.todos`: Assuming that the API response is a JSON object with a property named `todos`, this line extracts the `todos` property from the response data.

For example, if the API response looks like this:

```json
{
  "todos": [
    {
      "id": 1,
      "title": "Task 1",
      "description": "Description for Task 1"
    },
    {
      "id": 2,
      "title": "Task 2",
      "description": "Description for Task 2"
    }
    // ... other todo items
  ]
}
```

Then, `result.data.todos` would be an array of todo items.

This is a common pattern when working with APIs that return JSON data. The structure of `result.data` depends on the specific API you are interacting with, and you need to refer to the API documentation or inspect the response to understand its structure.

#### pagination part of the react app, that opens the todo acc to the id in the button

- Don't set the setCount function directly inside the event, that sets it into undefined, instead write a function inside it that sets the function setCount as the 1/2/3/4,etc. Now whenever that setCount is set to 1/2/3/4/etc on button click the count variable of the state also gets set to that same respective count and then it is passed on to the todo component and as such does thing afterwards
- Now we also need to set dependency in the useEffect using id as the dependency and as such it'll re-render when id changes and as such it will not be set to first todo only since the useEffect with no dependency only runs for the first time and setting the id, when changed will render the whole todo for every id from the server to the frontend.

### useMemo hook

First of all what is memoization: It is a mildly DSA concept. It means remembering some output given an input and not computing it again. Its like caching, if we have computed an output for a given input once for someone and if again someone asks for that input then the same value is given to the individual and not recompute again.

for the example of F1 car: how would check the amount of petrol left. Would you do that after every lap or would you do that after every 10 laps or after every 20 mins? We would most likely do that after every 10 laps or after every 20 mins under some condition which is very expensive operation. We won't be running that after every lap

- The chatGPT model is the example of an expensive operation which gets prompts and then answers them, but it would be better if it could store them in the browser locally i.e memoize it. Given an already given input we store the output somewhere so that we don't need to recompute and give an output again

- assignment question: If I ask you to create an app that does two things -

1. Increases a counter by 1
2. Lets user put a value in an input box (n) and you need
   to show sum from 1-n
   One restriction - everything needs to be inside App

- The way we can solve this will be by using useMemo in the main App component itself but we can also use useEffect and then add a dependency when the input value changes then rerun the calculation(expensive operation). This is a good way to do it but the problem with this approach is that we are updating the state variable again which causes two re-render. But this approach requires another set of state variables
- The main way to do this is by using `useMemo` which has the same syntax as all the other hooks and so it runs the function inside it only when the `inputValue` changes provided the variable is written in the dependency array, doesn't matter how many re-renders happens. This is a much cleaner way to write instead of using `useEffect` which needs another state variable.
- Both of the usecases come very close to each other in terms of what finally happens but harkirat himself has always used `useEffect` most of the times and rarely `useMemo`. If there is some codebases where the persons tells us to use `useMemo` only then we'll take that into account and it is good to know both. The only downside to `useEffect` is that first the `input` state var changes which calls the useMemo to run and also causes a re-render and then inside that another independent state variable `finalValue` changes which again renders, so 2 re-renders happen here
- `useMemo` is used when there is an expensive operation taking place in or if there is a derivative operation where a variable that depends on something inside the function of useMemo, and compute them on the fly. And in case of useEffect it is used for lifecycle events, if something has changed go and do something

### useCallback

No alternate approach like the two above.

- Before `useCallback`, there are somethings that we need to know like reference equality. When we do something like `a = 1`, `b = 1`, then `a == b` gives out true but if we do that individually inside a function and then compare the equality it returns false. The reason is that it doesn't point to the same "reference" i.e the same place in the "memory/RAM", as the first case where it does. The first case is equal by value as well as reference but the second one is not. So in the case of React too when we remove all the state variables and then run a custom component with some standard variable passed to it, then it doesn't re-render. But in the case of functions it does re-render the whole component because across re-renders this function will get redefined(because it doesn't have reference equality), React thinks that the function has changed(because the function doesn't match with the other that is being compared with that has been passed before to the component) even though it hasn't and as such re-renders. So to prevent this re-render the `useCallback` is used. React is dependent on that `==` check for the re-renders. It is very rarely used here but we should no those

- especially in child components that rely on the reference equality: child components that rely on two functions that are defined separately even if their body is the same, they're not referencially equal.

`useCallback` is a React hook that is used for memoizing functions. It is particularly useful when working with child components that rely on reference equality of functions to prevent unnecessary renders.

Here are some key points about `useCallback`:

1. **Memoizing Functions:**

   - `useCallback` is used to memoize (remember) a function so that it is not recreated on every render unless its dependencies change. This can be helpful in optimizing performance.

2. **Syntax:**

   - The basic syntax of `useCallback` is: first argument is a function and the second one is the dependency array acc to which you will want to re-.. stuff

     ```jsx
     const memoizedCallback = useCallback(
       () => {
         // function body
       },
       [
         /* dependencies */
       ]
     );
     ```

3. **Dependencies Array:**

   - The second argument to `useCallback` is an array of dependencies. If any of the dependencies change, the memoized callback function is re-created. If the dependencies are empty, the function is created once and remains the same for the entire component life.

4. **Use Cases:**

   - `useCallback` is often used when passing callbacks to child components to ensure that the callback doesn't change unless its dependencies change. This can be beneficial in preventing unnecessary renders of child components.

5. **Example:**

   - Here's a simple example:

     ```jsx
     import React, { useCallback, useState } from "react";

     function ParentComponent() {
       const [count, setCount] = useState(0);

       // This callback will not change unless count changes
       const increment = useCallback(() => {
         setCount((prevCount) => prevCount + 1);
       }, [count]);

       return (
         <div>
           <ChildComponent callback={increment} />
           <p>Count: {count}</p>
         </div>
       );
     }

     function ChildComponent({ callback }) {
       // Use the memoized callback
       return <button onClick={callback}>Increment Count in Parent</button>;
     }
     ```

In this example, the `increment` callback in the `ParentComponent` is memoized using `useCallback`. This ensures that `ChildComponent` doesn't unnecessarily re-render when the parent renders. Because if don't use `useCallback` then react will not know that it is the same function as the first render and as such it does re-render everytime the main state changes, but it is good enough in case of strings and other numbers which it can determine equality and that also applies to React. So we can make the function a variable which is a function wrapped inside the `useCallback`

Remember that while `useCallback` can be helpful for optimization in certain scenarios, it's important not to prematurely optimize. It's generally recommended to profile and measure performance before applying optimizations like `useCallback`.

## Custom hooks

These are hooks like `useEffect`, `useState`, etc but they are defined by us hence the name custom hooks. The only condition to make them is that the name should start with 'use' which is the naming convention. It needs to be a function only


### some misc stuff

- you can write custom components like this: like initializing a variable and then we can call it in the main App component using the component function call

```js
const SomeComponent = (){
  console.log("re-rendered");
  return <div>hi there {a} </div>;
}
```

- you can pass a function as an input in the main component function call then use them inside the component function.
