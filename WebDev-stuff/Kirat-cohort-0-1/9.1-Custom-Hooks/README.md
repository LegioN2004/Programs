# Custom Hooks

What are custom hooks in react?  Why do we need them and how to create hooks of our own?  
And a lot of the hooks that we'll be creating today have already been created by very smart people and they're very popular libraries out on the market right now to use for free. How they have been created under the hood and how can we make such libraries of our own

Do we really need? No but yes it can probably help us in a few place where we can encapsulate code well to create hooks rather than having everything in a single component.

The goal is to know how to create custom hooks of our own, we'll probably not need it but it can be seen in a good open source projects or codebases. Similar to the argument that we don't need React, we can do everything with HTML and JS.

## Hooks

- What are hooks: "Hooks" are a feature introduced in 'React' 16.8 that allow you to use state and other React features without writing a class. They are functions that let you "hook into" React state and lifecycle features from function components.
  - In the early days of react, functional components weren't a thing and everything were written in class based components, but after functional components were introduced and then after the 16.8 version hooks where introduced that could provide us 'state' with the `useState` hook and a bunch of other hooks that gave access to the "lifecycle events".
  - If we are using class based components, we don't need hooks.
  - Hooks were introduced when we are worried about state and lifecycle events i.e when we are using functional components
  - functional components example:

  ```jsx
    import React, { useState } from 'react';
    function MyComponent() {
        const [count, setCount] = useState(0);
        const incrementCount = () => {
            setCount(count + 1);
        };

        return (
                <div>
                <p>{count}</p>
                <button onClick={incrementCount}>Increment</button>
                </div>
        );
    }
    ```

  - Class based components example:

    ```jsx
    class MyComponent extends React.Component {
    constructor(props) {
        super(props);
        this.state = { count: 0 };
    }

    incrementCount = () => {
        this.setState({ count: this.state.count + 1 });
    }

    render() {
            return (
            <div>
                <p>{this.state.count}</p>
                <button onClick={this.incrementCount}>Increment</button>
            </div>
            );
        }
    }
    ```

  - After writing functional components, we can see that the class is not a thing anymore there like class so we can't set/change the state like we did using `this` keyword and as such the hooks were introduced which did the same thing and the concepts still remain the same.
  - We can write components in both ways since react is backwards compatible but nowadays class based components are not used nowadays

### Lifecycle events

- The events that can get triggered or some code that we can run whenever the lifecycle of a component changes like when first mounts i.e when it is put on the DOM or when it unmounts i.e when it is put off the DOM. And a lot of times we need this feature because there will be moments when we'll need to run some code when the component mounts and when the components unmounts.
- We have done this many times using `useEffect` hook in functional components.

```jsx
function MyComponent() {
 useEffect(() => {
  console.log('component mounted');
  // Perform setup or data fetching here

  return () => {
   // Cleanup code (similar to componentWillUnmount)
   console.log('component unmounted');
  };
 }, []);
```

- Notable thing in the above: the component mounted log gets in the console when we use `useEffect` since it only run for the first time on component render when there is no dependency array and the next main thing is that we can return something from the `useEffect` hook but that must only be a function and nothing else which runs whenever the dependency changes.
- How does this return of the `useEffect` work: The function from the last render would run first and then the logic in the useEffect will run. So if we have a useEffect which has some dependency then the first time the dependency changes the code of useEffect outside of the return function runs and then if there is a change for the second in the dependency array then first the code inside return function runs for cleanup purposes and then the main useEffect code runs
- So when component mounts the code of useEffect outside of the return function runs and when the component unmounts the code inside return function runs. This is the signifance of using the return inside the useEffect. So anytime the dependencies change or the component unmounts, the code inside tne return function will run.
- Since the useEffect is supposed to re-render when the dependency changes so it'll run the unmount logic in the return from the previous useEffect and then it'll

- This is how to apply the probem statement: Show that the component logs mounted and then unmounts eventually making the DOM blank

```jsx
function App() {
 const [showComponent, setShowComponent] = useState(true);
 useEffect(() => {
  setTimeout(() => {
   // Perform setup or data fetching here
   setShowComponent(false);
  }, 2000);
 }, [showComponent]);
 return (
  <>
   {showComponent? <MyComponent></MyComponent> : <div></div>}
  </>
 );
}

function MyComponent() {
 useEffect(() => {
  console.log('component mounted');
  // Perform setup or data fetching here
  return () => {
   // Cleanup code (similar to componentWillUnmount)
   console.log('component unmounted');
  };
 }, []);

 // Render UI
 return <h1>Hello World</h1>;
}
```

- This same mount and unmount was easier a few years ago with the use of class based components.

```jsx
class MyComponent extends React.Component {
  componentDidMount() {
    // Perform setup or data fetching here
  console.log('component mounted');
  }

  componentWillUnmount() {
    // Clean up (e.g., remove event listeners or cancel subscriptions)
  console.log('component unmounted');
  }

  render() {
    // Render UI
 return <div>Hello World</div>;
  }
}
```

## Custom Hooks

- Hooks that you create yourself, so other people can use them are called custom hooks.
- A custom hook is effectively a function, but with the following properties
  - It Uses another hook internally (`useState`, `useEffect`, another custom hook), but effectively it is a function only
  - Starts with `use`(it should) just like the others like `useEffect`
  - If it doesn't use another hook internally, then it is just another normal function that we can call and use

- A few good examples of this can be
  - Data fetching hooks
  - Browser functionality related hooks - *`useOnlineStatus`* , *`useWindowSize`*, *`useMousePosition`*
  - Performance/Timer based - *`useInterval`*, *`useDebounce`*

### Data Fetching hooks

Data fetching hooks can be used to encapsulate all the logic to fetch the data from your backend
For example, look at the following code-

```jsx
import { useEffect, useState } from 'react'
import axios from 'axios'

function App() {
  const [todos, setTodos] = useState([])

  useEffect(() => {
    axios.get("https://sum-server.100xdevs.com/todos")
      .then(res => {
        setTodos(res.data.todos);
      })
  }, [])

  return (
    <>
      {todos.map(todo => <Track todo={todo} />)}
    </>
  )
}

function Track({ todo }) {
  return <div>
    {todo.title}
    <br />
    {todo.description}
  </div>
}

export default App
```

Here the code is ugly, it first sets the todos as an empty string in the state, then fetches the todos gets the response and sets todos in the state and then renders it. It is all shoved inside a single component. This is what "custom hooks" take away.

What if we could do something like the following

```jsx
function App() {
  const todos = useTodos()

  return (
    <>
      {todos.map(todo => <Track todo={todo} />)}
    </>
  )
}

function Track({ todo }) {
  return <div>
    {todo.title}
    <br />
    {todo.description}
  </div>
}
```

The above useTodos is what's called the data fetching hook that does the heavy lifting of fetching data from the server and stores it in a single variable for us and makes the code clean. If there is any change in the logic we'll need to change it in only one place and that will take effect in all the places where the logic will be required

- So to create one custom hook for the todo example for the above we can do the following
  - What have we done here is that we have created a new `useTodos` hook that contains the same data fetching logic which was previously inside the main app component and it returns the data(put inside state variable) that we get from the server and then that return value is then being put inside another variable inside the main component and then used
  - This simply encapsulates the logic and cleans the code and now we can separate that logic in another file import it and then use it and in that way it becomes clean Af
  - We only return todos here since the component only needs to use and not update the state.

```jsx
function useTodos() {
 const [todos, setTodos] = useState([]);

 useEffect(() => {
  axios.get('https://sum-server.100xdevs.com/todos').then((res) => {
   setTodos(res.data.todos);
  });
 }, []);

 return todos;
}

export function Todo() {
 const todos = useTodos();
 return (
  <>
   {todos.map((todo) => (
    <Track todo={todo} />
   ))}
  </>
 );
}
```

- Also we can add here something like a loader or something that makes up for the time it takes to fetch the data from the backend and we can do that by sending objects directly in the custom hooks' return and then when using that in the main component we can take in that value by not using variable but again an array ( destructuring ).
  - We are using another state to manage that loading part, which firstly stays true since the data starts fetching and shows up and then when the control reaches the todos set function i.e it finishes the data fetching the loading becomes false goes away and the new data render

```jsx
function useTodos() {
 const [todos, setTodos] = useState([]);
 const [loading, setLoading] = useState(true);

 useEffect(() => {
  axios.get('https://sum-server.100xdevs.com/todos').then((res) => {
   setTodos(res.data.todos);
   setLoading(false);
  });
 }, []);

 return { todos, loading };
}

export function Todo() {
 const { todos, loading } = useTodos();
 if (loading) return <div>Loading...</div>;
 return (
  <>
   {todos.map((todo) => (
    <Track todo={todo} />
   ))}
  </>
 );
}
```

- Step 3 - Auto refreshing hook
What if you want to keep polling the backend every n seconds? n needs to be passed in as an input to the hook

The following is not a great solution but works anyway, where we don't need to hard reload to get the new set of data and the server auto sends the data, refreshes the backend and is populated on the screen

```jsx
function useTodos(n) {
 const [todos, setTodos] = useState([]);
 const [loading, setLoading] = useState(true);

 useEffect(() => {

  const value = setInterval(() => {
   axios.get('https://sum-server.100xdevs.com/todos').then((res) => {
    setTodos(res.data.todos);
    setLoading(false);
   });
  }, n * 1000);

  axios.get('https://sum-server.100xdevs.com/todos').then((res) => {
   setTodos(res.data.todos);
   setLoading(false);
  });
    // cleanup logic
  return () => {
   // the way to clear the interval
   clearInterval(value);
  };
 }, [n]);

 return { todos, loading };
}
```

- The problems in the above code is that we have a dependency variable that is changing but we are not using it in the dependency  array which is wrong since if the value of n changes then the render part will run for the old value of n which we don't want
- If we set the dep array and also change the n then there will be two setInterval of both the new and the old one which is wrong and the old one must be cleared, so as said earlier we'll use the return function inside the useEffect hook which acts as the cleanup function
- So in the return function we'll use the `clearInterval()` function which clears the interval set by `setInterval()`. Here setInteval returns a value(which is a way to find that clock running) which can be stored and then be used to do the cleaning of the interval(JS stuff).

## SWR by vercel

All of the above custom hooks that we have written is already made into a library called "**SWR**" and it provides us with such hooks and a bunch of other things on top of those and by using them we'll make our life easier.

Also whoever is using the SWR library don't need to worry about the set function, like the `[todos, setTodos]` because it is like provide me the set of todos and we need to worry about only updating the todos, the rest of the work will be done by SWR and so it doesn't return it.

### More hooks random

4 - Browser funtionality related hooks

- The way to write these hooks is by creating a folder named hooks in the src and then we can put all the hooks there and then import those in the file where it'll be used.
- **`useIsOnline`** hook
  - Create a hook that returns true or false based on wether the user is currently online
  - We are given that -
    - `window.navigator.onLine` returns true or false based on weather the user is online
    - You can attach the following event listeners to listen to weather the user is online or not
  - *usecase*: for gaming websites where the person comes and if there internet connection cuts off then it'll show up as "you are offline". We can do this without hooks and also without react.

```js
window.addEventListener('online', () => console.log('Became online'));
window.addEventListener('offline', () => console.log('Became offline'));
```

- **`useMousePointer`** hook
  - Create a hook that returns you the current mouse pointer position.
  - You are given that `window.addEventListener('mousemove', handleMouseMove);` will trigger the handleMouseMove function anytime the mouse pointer is moved.

- Also we should clear this event listeners so that we don't have any lingering events when the component unmounts.

5 - Performance/Timer based

- **`useInterval`**
Create a hook that runs a certain callback function every n seconds.
We'll have to implement useInterval which is being used in the code below -

```jsx
import { useEffect, useState } from 'react';

function App() {
  const [count, setCount] = useState(0);

  useInterval(() => {
    setCount(c => c + 1);
  }, 1000)

  return (
    <>
      Timer is at {count}
    </>
  )
}

export default App
```

But in most cases, if `fn` and `timeout` are not expected to change, it's safe to omit them from the dependency array to avoid unnecessary re-renders.

- The main one: `useDebounce` The debouncing concept
  - What is **debouncing**: For example in the amazon page, when we search for something and there we type slowly letter by letter then multiple requests goes to the backend based on the input query that is being written and it sends, searches and sends back suggestions and those get populated in the search suggestion below accordingly. If we type all the words in a second then how should the request be sent, ideally it should send the whole word as a single request such that there is less stress on the server as much as possible. Or we can do something like no change as long as no key has been pressed for 200ms, so after 200ms after the last key pressed will the request be sent. This is called 'debouncing'

- Create a hook that debounces a value given
  - The value that needs to be debounced
  - The interval at which the value should be debounced.

```jsx
import React, { useState } from 'react';
import useDebounce from './useDebounce';

const SearchBar = () => {
  const [inputValue, setInputValue] = useState('');
  const debouncedValue = useDebounce(inputValue, 500); // 500 milliseconds debounce delay

  // Use the debouncedValue in your component logic, e.g., trigger a search API call via a useEffect

  return (
    <input
      type="text"
      value={inputValue}
      onChange={(e) => setInputValue(e.target.value)}
      placeholder="Search..."
    />
  );
};

export default SearchBar;
```

- inputValue state changes immmediately but
- Here the debounced value doesn't change instantly, but only when we are ready to fire off the requests. When we search for 'airpods' it shouldn't get 'a' then 'i' then 'air' instead it should get the letter first and then the word as a whole, i.e it should not get the intermediate values that we know that we shouldn't send, it needs to debounce storing these value in there until we are ready to fire off the request.
- After the implementation, the following is the code
  - The thing to note here is that we should clear the clock after the last keystroke happens because if we keep typing the clock will run for all the keystrokes continuously and debouncing just becomes of no use since it'll continuously type and instead we want it to happen after 500ms of the last keystroke. So we'll keep starting new clocks and stopping the old clocks until it reaches the point when it doesn't need to run the clearing function and then the request gets sent

```jsx
function useDebounce(value, timeout) {
 const [debouncedValue, setDebouncedValue] = useState(value);
 useEffect(() => {
  setTimeout(() => {
   setDebouncedValue(value);
   console.log(value);
  }, timeout);
  return () => {
   clearTimeout(hello);
  };
 }, [value]);
}

```

### doubt

In this case, you don't need to include `fn` or `timeout` in the dependency array of the `useEffect` hook. The reason is that `fn` and `timeout` are provided by the parent component when invoking the `useInterval` custom hook, and they don't change over time. Including them in the dependency array would cause the effect to re-run unnecessarily.

However, if `fn` or `timeout` were to change during the component's lifecycle and you needed to react to those changes, you would include them in the dependency array. For example:

```javascript
function useInterval(fn, timeout) {
 useEffect(() => {
  const intervalId = setInterval(() => {
   fn();
  }, timeout);

  // Return a cleanup function to clear the interval when the component unmounts
  return () => {
   clearInterval(intervalId);
  };
 }, [fn, timeout]); // Include fn and timeout in the dependency array
}
```
