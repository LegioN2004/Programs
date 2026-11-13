# Context, State Management, Recoil

context recap, more state management and context API and state improving library "Recoil" intro

## Context

Recapped some stuff from last class of the Context API. It teleported state without prop drilling the intermediate components using the `useContext` hook of React and very elegantly passed in the state from the parent to the very nested children

```
                                     teleport count
                            App.jsx ----------------> CountContext
                               |                      / |
                               |                     /  |
                               |                   /    |
                               |                 /      |
                             Count             /        |
                            /     \          /          |
                           /       \        /           |
                          /         \      /            |
                         /           \    /             |
                 CountRenderer      Buttons             |
                                         |              |
                                         ----------------
```

### The downsides of Context API

There are certain downsides of using Context API. What are the things that it couldn't fix that the state management tools like "Recoil" fixes.

- Up until now we have used the context api to teleport the state variables from the main `App` component to the `Button` and `CountRenderer` child nested components without prop drilling in the intermediate `Count` component but does it really solve the problem of minimal re-rendering in react, since the state variables are used and changed in the `App`, `CountRenderer` and `Buttons` component does it really not re-render the intermediate `Count` componenet i.e whoever is using the `CountContext` should re-render when the count state changes and whoever is not using doesn't need to re-render since nothing in the componenet changed. And after using a log we can see that the `Count` does re-render and there is no performance improvements from the Context API side in React.
- It would have been better if there were strict state management tools that would take away this problem of re-rendering even when it is not using a state variable in the midst of the Context API, only the ones that use should re-render.
- This is a interview thing to know: Is the Context API somethinng that we would use to make the app performant? Why do we use the Context API: To make rendering more performant, NO. To make syntax cleaner/ get rid of prop drilling, YES
  - The solution libraries written by very smart people that give both the functionalities, clear syntax, no prop drilling as well as performance.

## State Management

How it helps to get rid of the shortcomings of the Context API

What is state management:
It is a a cleaner way to store the state of your app
Until now, the cleanest thing we can do is use the Context API.
It lets you teleport state
But there are better solutions that get rid of the problems that Context Api has
(unnecessary re-renders)

There was a time when people had two types of engineers in a frontend team - a UI eng and a one maintaining state

- Any React codebase can be divided into two codebase:
  - one containing the State logic and
  - the other containing Component
- Up until now we have shoved the state logic directly in the component logic, there was no real distinction. So it becomes very hard for people to deal with them who doesn't have perfection in both the sections
- By the intro of state management library, we can see very good separation of concerns after which two people can focus on two different parts: State logic and Component logic.
- By using Recoil or any other state management library, we will define all the components in one folder and the state in another folder called store, so that engineers can work in independent folders and one ui engineers doesen't have to worry for the state logic and so on.

## Recoil

Recoil is a state management library for managing the state of React applications. It was developed by Facebook and is designed to make it easy to manage the state of an application and share that state between different components. Recoil is built on three main principles: atoms, selectors, and the React model. The other popular ones are Zustand and Redux, everyone has their own set of nuances we have to go through the docs, we can't learn all of these libaries by just learning one of them. The only thing in Recoil is that it does the same stuff but it has its own set of APIs that revolves around to lets it do stuff.

### Concepts

1. **Atoms:**
   - 90% of the understanding Recoil goes to creating Atoms. Atoms are units of state in Recoil. They represent a piece of state that can be read from or written to by different parts of the application. It is similar to the `useState` of 'React' which lets us define a state variable and here in the 'Recoil' world `atom` lets us create state. Each atom has a unique key that identifies it. In our component tree, the Atom state is always created outside of that component logic inside a folder as said above called `store`. We can give it an initial value and it'll let only the ones using it to re-render, rest of them will not re-render on change

   ```jsx
   import { atom } from 'recoil';

   export const countState = atom({
     key: 'countState', // unique ID (with respect to other atoms/selectors)
     default: 0, // default value (aka initial value)
   });
   ```

2. **Selectors:**
   - Selectors are functions that compute derived state from atoms and other selectors. They allow you to create pieces of state that are derived from the current state of the application.

   ```jsx
   import { selector } from 'recoil';
   import { countState } from './atoms';

   export const doubledCountState = selector({
     key: 'doubledCountState',
     get: ({ get }) => {
       const count = get(countState);
       return count * 2;
     },
   });
   ```

3. **React Model:**
   - Recoil integrates seamlessly with React. Components can read from and write to atoms and selectors. When the state of an atom changes, Recoil automatically triggers a re-render of components that depend on that state.

   ```jsx
   import { useRecoilState, useRecoilValue } from 'recoil';
   import { countState, doubledCountState } from './atoms';

   function CounterComponent() {
     const [count, setCount] = useRecoilState(countState);
     const doubledCount = useRecoilValue(doubledCountState);

     return (
       <div>
         <p>Count: {count}</p>
         <p>Doubled Count: {doubledCount}</p>
         <button onClick={() => setCount(count + 1)}>Increment</button>
       </div>
     );
   }
   ```

### Benefits of Recoil

1. **Flexibility:**
   - Recoil provides a flexible and scalable way to manage state in React applications. It's not tied to a specific framework architecture and allows for easy adoption in existing projects.

2. **Cross-Component Communication:**
   - Atoms and selectors facilitate easy communication and sharing of state between different components without the need for prop drilling or complex state management setups.

3. **Efficiency:**
   - Recoil optimizes the reactivity model, ensuring that only components that depend on a specific piece of state are re-rendered when that state changes.

4. **DevTools Support:**
   - Recoil comes with a set of developer tools that make it easier to inspect and debug the state of your application.

### Installation

To use Recoil in your React project, you need to install the Recoil package:

```bash
npm install recoil
```

or

```bash
yarn add recoil
```

### Usage

Firstly we'll need to learn the following: RecoilRoot, atom, useRecoilState, useRecoilValue, useSetRecoilState and selector

1. **Define Atoms and Selectors:**
   - Define atoms and selectors to represent different pieces of state in your application.
   - make a new folder with the structure store/atoms inside which we will have the state of the application in the file called count.jsx
   - so in inside the file we'll the countState which is the state more appropriately atom name  of the application defined with equals to `atom` keyword which comes from Recoil library, and it expects a single argument which is an object having a key itself which is a unique ID and its name is usually the name of the atom. This key should not have same occurences anywhere. And then export that const as well. This concludes the separate state definition in a separate file and folder so we can remove the `useState`, `useContext` and its APIs, and other stuff from the main component.

   ```jsx
   import { atom } from 'recoil';

   export const countAtom = atom({
     key: 'countAtom', // unique ID (with respect to other atoms/selectors)
     default: 0, // default value (aka initial value)
   });
   ```

2. **Initialize RecoilRoot:**
   - Wrap your application with the `RecoilRoot` component at the top level to enable Recoil state management. This is just like that context api provider where to use the context API we need to wrap it inside the `<ContextCount.Provider></ContextCount.Provider>`, similarly for recoil we need to do that too here in Recoil
   - It doesn't matter if we not use the parent div here in the main App component, but the final component using the context/atom must be wrapped inside the `<RecoilRoot>` component

   ```jsx
   import { RecoilRoot } from 'recoil';

   function App() {
     return (
       <RecoilRoot>
         {/* Your application components */}
       </RecoilRoot>
     );
   }
   ```

3. **Removing the dependency of the main and intermediate Components on the state variable**
    - In React we had two things, one for getting state and the other for updating the state. Similarly Recoil provides us with three APIs/hooks `useRecoilState`(exactly similar to `useState`, so it gives two things one the current value and second to update the current value), `useRecoilValue`(which gives us just the value of the state, so no array, for cases when we just want the value and we don't need to update it), `useSetRecoilState`(when we only want to update the value and not actually get it).
    - We have to use according to our use case but in the worst case scenario we can just use the hook  `useRecoilState` which is the same as what `useContext` gives us.
    - We could have also used RecoilState and could have ignored the second value but there are some performance benefits in only calling the value since it is required and  RecoilState only be used when both the things are required.

    ```jsx
    function CountRenderer() {
    const count = useRecoilValue(countAtom)
    // const [count, setCount ] = useRecoilState(countAtom) could have done this, but should not be used for performant site
    
    return <div>
        <b>
        {count}
        </b>
        <EvenCountRenderer />
    </div>
    }
    ```

4. **Does that mean we will never use `useState` and put everything in atoms in the vicinity?**
    - No its not like that, there are and will be usecases where `useState` makes sense if we want to define a state in a component and use it there, that block only.
    - For example the assignent from last week that needed to filter words, that input state will start and end in that `Input` component scope only so no use of adding it to the atom. The following example doesn't make sense to store in the recoil state i.e atom. Atoms are always global state.

     ```jsx
     function Input(){
      const [input, setInput] = useState(0)
      return (
        <>
        <input onChange={(e) => {
          setInput(e.target.value)
        }}></input>
      </>
      )
     }
     ```

5. **More opitimizations**
    - Now its working as expected, in the example code `Count` has stopped re-rendering and the `Buttons` only re-renders, but it should not too because only the text above neeeds to change/re-render
    - Since Recoil is good enough to not re-render `Count` since it is not using state but not in case of buttons, we got to fix that by setting the `setCount` function(which changes the count value) to `const setCount = useSetRecoilState(countAtom)`. As such we'll not see the buttons re-rendering as well only the text that needs to re-render will only happen
    - And now only the component that is actually using the value of count is re-rendering

    ```jsx
    function Buttons() {
      // const [count, setCount] = useRecoilState(countAtom); // don't need this now
      console.log('Buttons re-renedered');
      const setCount = useSetRecoilState(countAtom);

      return (
        <div>
          <button
            onClick={() => {
              setCount((count) => count + 1);
            }}
          >
            Increase
          </button>

          <button
            onClick={() => {
              setCount((count) => count - 1);
            }}
          >
            Decrease
          </button>
        </div>
      );
    }
    ```

    - This is the most performant the application/website can get, we have achieved the state of most minimal re-renders and all those who don't depend on anything else doesn't re-render
  
6. **Using the selectors**
   - Selector: A selector represents a piece of derived state. You can think of derived state as the output of passing state to a pure function that derives a new value from the said state.
   - Derived state is a powerful concept because it lets us build dynamic data that depends on other data. In the context of our todo list application, the following are considered derived state:
   - So in our app to calculate the count if it is even or not and then render the result below the button, we can use the slightly optimal way by using useMemo and inside it conditinals and not directly use conditionals. Because whenever we have a derived state, we should always use `useMemo` so that its opitimized and only re-renders when when the dependent value(Count) changes.

   ```jsx
    function EvenCountRenderer() {
      const count = useRecoilValue(countAtom);
      const isEven = useMemo(
        () =>  (count % 2 == 0 ? `${count} is even` : `${count} is not even`),
        [count]
      );
      return <>{isEven}</>;
    }
   ```

   - In Recoil we also have this same concept of useMemo known as `selectors`, if we know that something is directly derived from a bunch of dependencies use a `selector`
     - The `selector` syntax is the same as the `atom` one, initialise it with a name then equals to `selector` which is an object so expects key-value pair like `key` which gets a unique ID/name and then the `get` one expects a function and that function gets an argument `get` inside which we pass the atom that the count variable derives from(we can also not object destructure then we can pass any object in place of the argument we can pass an object that gets the `get` and then we can use the dot notation to use that get where we want to).
     - This selector basically says that `evenSelector` depends on `countAtom`, if there is any other dependency we need to pass that instead. This is the same as the `useMemo` where we pass in the dependency in the array, but instead we are using `get(countAtom)` and telling the selector or recoil that it depends on that `countAtom` so whenever the countAtom changes make sure that you re-run this selector logic and return the thing. But the main difference between `useMemo` and `selector` is that other atoms and selectors can depend on the selector but a `useMemo` can't be defined like that so it becomes hard when there is more and more derived states.
     - It is by defintion dependent on the other atoms so it doesn't have the default key, instead it uses `get` to write the derivation logic on how it depends on the other atoms
     - It can depend on other atoms and selectors as well.

   ``` jsx
    export const evenSelector = selector({
      key: 'evenSelector',
      get: ({get}) => {
        const count = get(countAtom);
        return count % 2
      }
      // or
      // get: (props) => {
      //  const count = props.get(countAtom);
      //  return count % 2
      // }
    })
   ```

### Example

Here's a simple example of a Recoil-powered counter:

```jsx
// atoms.js
import { atom } from 'recoil';

export const countState = atom({
  key: 'countState',
  default: 0,
});
```

```jsx
// CounterComponent.js
import { useRecoilState } from 'recoil';
import { countState } from './atoms';

function CounterComponent() {
  const [count, setCount] = useRecoilState(countState);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={() => setCount(count + 1)}>Increment</button>
    </div>
  );
}

export default CounterComponent;
```

### Additional Resources

- [Recoil GitHub Repository](https://github.com/facebookexperimental/Recoil)
- [Recoil Documentation](https://recoiljs.org/)
- [Recoil for the Redux Developer](https://medium.com/hackernoon/recoil-for-the-redux-developer-17152134015d)

Recoil provides a powerful and flexible solution for state management in React applications, and its ease of use and integration with React make it a popular choice among developers.
