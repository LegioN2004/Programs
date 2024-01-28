# React Recap: Reconcilliation, state, useState, useEffect, useMemo, useCallback, useRef

## React vs ReactDOM vs React-Native

ReactDOM is the thing that deals with re-rendering things and putting them on the screen. It is actually that 'ReactDOM' library imported from the `react-dom/client` that has all the document.getElementById element calls and React doesn't. React is for building ui interfaces for mobile apps, websites, etc; ReactDOM when used with React makes React write things on a website and by using the 'react-native' library we can use very similar code to write cross platform mobile apps

## Reconcilliation

Can you do DOM manipulation yourself - Yes
Should you do it yourself - No
Is it good for you to delegate the heavy task of calculating the DOM changes to React - Yes
What do you give to React - The state
How often does react re-render - Any time state changes
Does React have tricks to make calculations faster - Yes

## state

State is something like a variable that stores the state of the app, what is has, what it should show, etc that react will render eventually. And whenever that state changes React will trigger a re-render of the DOM according to the logic that is being use besides the state.

The 'state' in React is a special JavaScript object that holds the current data or condition of a component. It is used to manage dynamic content and respond to user interactions. When the state of a component changes, React efficiently re-renders the component, updating the DOM to reflect the latest state. This mechanism allows React to maintain a responsive and interactive user interface

## useMemo & useEffect

Both useEffect and useMemo lets us skip executing some logic between re-renders based on the dependencie array(of some state variables) and that happens. But useEffect doesn't return us anything but the useMemo does.

useMemo and memo are significantly different from each other: The former lets the function re-render only when the props coming to that component changes and the latter does re-render only when the dependencies in the dependency's array changes

## useCallback

When there is the case of useCallback then the memo even doesn't work because the functions are passed as a callback and it doesn't have reference equality so it always return false even if the value inside it is same, so React sees it as change in state and then re-renders it everytime.

```js
import { useEffect, useState, useMemo } from "react";
import "./App.css";

function App() {
  const [exchange1Data, setExchange1Data] = useState({});
  const [exchange2Data, setExchange2Data] = useState({});
  const [bankData, setBankData] = useState({});

  useEffect(() => {
    // Some operation to get the data
    setExchange1Data({
      returns: 100,
    });
  }, []);

  useEffect(() => {
    // Some operation to get the data
    setExchange2Data({
      returns: 100,
    });
  }, []);

  useEffect(() => {
    // Some operation to get the data
    setTimeout(() => {
      setBankData({
        income: 100,
      });
    }, 5000);
  }, [exchange1Data, exchange2Data]);

  // const calculateCryptoReturns = memo(() => {
  // return exchange1Data.returns + exchange2Data.returns;
  // });
  // if we do the above then it will always re-render this function because react is good enough to only know the reference and values of variables and not functions so it sees them as their value changing everytime

  //but if we use useCallback here with the dependencies that are to be checked to re-render then it'll work as expected

  const calculateCryptoReturns = useCallback(() => {
    return exchange1Data.returns + exchange2Data.returns;
  }, [exchange1Data, exchange2Data]);
  const incomeTax = (cryptoReturns + bankData.income) * 0.3;

  return <div>hi there, your income tax returns are {incomeTax}</div>;
}
export default App;
```

- here after changing it to the useCallback and then using the exchange1Data and exchange2Data we can take them as the dependencies and then change only when they change and not when bankData changes just as it did when not use useCallback here
- In case of useMemo, the initialized variable got a value but in the case of useCallback it got a function which gets called anyway but has the same reference only until the dependencies doesn't change else its reference also changes causing a re-render
- We need to make sure that whatever is inside the function or is getting used by the funcion inside the useCallback has the same as the dependencies or else it'll not work as expected and cause errors

## useRef

- This is the one hook that hasn't been done till now. It has two cases:

  - The most important use case is that it gives us access to DOM elements. We need DOM but the html way of doing it was a little complex but using this React makes it easy for us.
    - If we have something rendered on the screen, how can we override it what react has written and put something else there
  - The other thing that it lets us do is maintain a variable(its value) across re-renders. It can be any value string, int, etc

  ```js
  import { useCallback, useEffect, useRef, useState } from "react";

  function App() {
    const [incomeTax, setIncomeTax] = useState(20000);

    useEffect(() => {
      setTimeout(() => {
        document.getElementById("incomeTaxContainer").innerHTML = 10;
      }, 5000);
    }, []);

    return (
      <div>
        {/* hi there, your income tax returns are <div id="incomeTaxContainer" ref={divRef}>{incomeTax}</div> */}
        hi there, your income tax returns are <div id="incomeTaxContainer">{incomeTax}</div>
      </div>
    );
  }

  export default App;
  ```

  - In the above example we are overriding the state variable with DOM manip, and it is not a good practice. Because we are confusing React by putting 10 but it still feels that 20000 is present in that place. This is not the correct way to do it instead it should be done like this
    - We just need to give the hook a name and we don't need to use objects here or anything else simple variable only initialization.
    - Then we can give the reference to the div a `ref={the_initialized_variable}` which stands for the reference which contains the reference to that particular div(or any element) equals and then the curly braces with the variable name `divRef` in our case. And instead of the `document.getElementById` we can then use the variable to use the current value the syntax
      `divRef.current` (ref_variable.current is the syntax, then again use `.` to do the main thing) is how we can access the current refernce of that div and then `.innerHTML` to change the value

  ```js
  import { useCallback, useEffect, useRef, useState } from "react";

  function App() {
    const divRef = useRef();
    const [incomeTax, setIncomeTax] = useState(20000);

    useEffect(() => {
      setTimeout(() => {
        divRef.current.innerHTML = 10;
      }, 5000);
    }, []);

    return (
      <div>
        hi there, your income tax returns are{" "}
        <div ref={divRef}>{incomeTax}</div>
      </div>
    );
  }

  export default App;
  ```

## Some assignment stuff

### week-6 ; useMemo ; assignment 1

The usage of useMemo doesn't justify it because it is a child custom component which only has a single state variable and as such it re-renders on the change of the `input` variable only, so it is not as such necessary to do so but if the main parent has some state then'll it'll trigger the childs to re-render and then the usage of it becomes necessary.

### week-6 ; useMemo ; assignment 2

The sentences that has the words gets filtered here, that was the whole usecase of that input field. The final ans depends on two inputs, the filter arguments given in the field and the filtering logic also that needs to re-run which is used to convert a very big list to this subset logic to render. Then we need to re-run the render when the sentences or the filter changes so we add them to the dependency array because if either one of the two changes then the value returned inside the useMemo will also change. It is not necessary that we'll only have a single input in the dependency array, depending on what are being used in the function it should be filled with those.

### week-6 ; useCallback ; assignment 1

The component using useCallback when used there with the state variable itself such that it is changing, then the useCallback should have that state variable as a dependency otherwise it'll not re-render(it this not re-renders then the state variable will change the increment value and react will not show anything). Also we can call this set functions(or state changing functions) in two ways

```js
 const handleIncrement = useCallback(() => {
    // setCount(count+1)
  setCount((a) => {
   return a + 1;
  });
 // }, [count]);
 }, []);
```

- first directly uses the state variable to do the increment so it takes that var directly in the set function and sets that in the state. Here we pass in some value directly or the state variable itself
- secondly it uses another function inside the set function that gets the current value of the state variable in the function arguments without needing to access it from the state. This is better because it no longer depends on the count state variable and so we can remove count as a dependency

### week-6 ; useCallback ; assignment 1

The usage of `useCallback` in this scenario is to ensure that the functions `handleIncrement` and `handleDecrement` are not recreated on every render. When you pass functions as props to child components, and if those functions are recreated on every render, it may cause unnecessary re-renders of the child components. By using `useCallback`, you're memoizing these functions, preventing them from being recreated unless their dependencies change.

In your code:

```js
const handleIncrement = useCallback(() => {
  setCount(function (currentCount) {
    return currentCount + 1;
  });
}, []);

const handleDecrement = useCallback(() => {
  setCount((count) => {
    return count - 1;
  });
}, []);
```

The dependency array for both `useCallback` calls is an empty array (`[]`). This is appropriate in this case because the functions don't depend on any external variables or props. They only depend on the `setCount` function, which doesn't change between renders. Using an empty dependency array is a common pattern when the callback doesn't depend on any external variables.

Regarding the usage of `memo` for `CounterButtons`, it's used to optimize performance. `memo` is a higher-order component that memoizes the result of the component rendering. It prevents unnecessary re-renders of the `CounterButtons` component when its props (`onIncrement` and `onDecrement`) remain the same. In this case, if the `handleIncrement` and `handleDecrement` functions are not recreated due to `useCallback`, and their references remain constant, `memo` helps avoid unnecessary renders of `CounterButtons`.

The issue you mentioned about requiring two clicks might be related to other aspects of your code. The provided code snippets for `handleIncrement` and `handleDecrement` in the current context should work as expected with a single click. If you're experiencing issues, it might be helpful to review the entire code, including the usage of these functions and any other related logic.

- My solution has the count variable in the dependency array, and the setCount was something like setCount(a++) for increment and a-- for decrement respecitively. What is the problem here

When you include the `count` variable in the dependency array of `useCallback`, it indicates that the callback depends on the current value of `count`. If you use the form `setCount(a++)` or `setCount(a--)`, where the update function depends on the current value of `count`, this can lead to issues.

The problem arises because the function inside `setCount` is not guaranteed to run immediately. React batches state updates for performance reasons. Therefore, when you use `setCount(a++)` or `setCount(a--)`, the value of `count` inside the callback might not be what you expect. It could be the old value, and you might miss updates.

Instead, you should use the functional form of `setCount`, which receives the current state as an argument. This ensures that you are working with the latest state:

```js
const handleIncrement = useCallback(() => {
  setCount((currentCount) => currentCount + 1);
}, []);

const handleDecrement = useCallback(() => {
  setCount((currentCount) => currentCount - 1);
}, []);
```

By using the functional form, you avoid dependencies on the external `count` variable directly, and React takes care of providing the correct and latest state when the callback is executed. This approach is more reliable and helps prevent issues related to stale state values.

In summary, when using `setCount` or any other state update function, it's recommended to use the functional form to ensure that you work with the latest state and avoid unexpected behaviors.

### week-6 ; useCallback ; assignment 2

If you are using a state variable inside the useCallback then make sure to add it to the dependency array as well

### week-6 ; useRef ; assignment 1

- vanilla DOM method: Using the input box focus can be done by adding an id to the input box(or where you want to shift the focus to) and then using the syntax from where you want to shift the focus to, here in our case a button so add there `document.getElementById("id_name").focus()`
- and when we don't have a dependency in the useEffect then it runs only once which means that it'll run on component mount, as simple as that
- use the ref as a dependency in the useEffect, it'll be better to use that

- About the useRef hook 'focus'

Certainly! Here are some notes and considerations regarding focusing an input element using `useRef` in a React component:

1. **Ref Creation:**

   - The `useRef` hook is used to create a mutable object, referred to as a ref, which has a `current` property.
   - Example: `const inputRef = useRef();`

2. **Assigning Ref to an Element:**

   - Attach the ref to an HTML element by assigning it to the `ref` attribute of the element.
   - Example: `<input type="text" ref={inputRef} />`

3. **Focusing on Mount:**

   - Use the `useEffect` hook with an empty dependency array to run code when the component mounts.
   - Inside this effect, call the `focus` method on the `current` property of the ref to focus on the input element.
   - Example:

     ```js
     useEffect(() => {
       inputRef.current.focus();
     }, []);
     ```

4. **Focusing on Button Click:**

   - Implement a function (e.g., `handleButtonClick`) that is called when the button is clicked.
   - Inside this function, use the `focus` method on the `current` property of the ref to focus on the input element.
   - Example:

     ```js
     const handleButtonClick = () => {
       inputRef.current.focus();
     };
     ```

5. **Notable Considerations:**
   - Make sure to handle cases where the ref might be `null` (e.g., if the component is unmounted).
   - Refs should be used cautiously to avoid direct manipulation of the DOM. In React, state and refs should be the primary means of managing component state.
   - When focusing elements programmatically, consider accessibility concerns, and ensure that the user experience is not compromised.

Putting these notes into practice will help you effectively use `useRef` to manage focus in your React component.

- The thing that I did wrong in my part of the solution

The issue in the first code snippet is that you are using the same ref (`Ref`) for both the input and the button. In React, a ref should be assigned to a single element. When you use the same ref for both the input and the button, it might lead to unexpected behavior.

In the corrected code (second snippet), a separate ref (`inputRef`) is created for the input element, and it is used exclusively for that element. This ensures that each ref is associated with a specific element and prevents potential conflicts or unexpected behavior.

Here's a breakdown of the corrected code:

```js
export function Assignment1() {
  // Separate ref for the input element
  const inputRef = useRef();

  useEffect(() => {
    inputRef.current.focus();
  }, []); // Effect runs only on mount

  const handleButtonClick = () => {
    inputRef.current.focus();
  };

  return (
    <div>
      {/* Assign the ref to the input element */}
      <input ref={inputRef} type="text" placeholder="Enter text here" />
      <button onClick={handleButtonClick}>Focus Input</button>
    </div>
  );
}
```

By using a dedicated `inputRef` for the input element and not sharing it with the button, you ensure that each element has its own ref, and the focus behavior is consistent and reliable.

- more doubts: I am not getting the usage of useEffect here, what does it mean by on mount. Why the input tag has the useEffect and a useRef usage and not the button. If the button doesn't use the reference to the useRef then how does it get applied to the button, isn't it necessary to do so. Why does the useEffect has a reference useRef as the dependency in the array, does it even fit in an array

Let me clarify the usage of `useEffect` and `useRef` in the context of your React component.

1. **`useEffect` and "on Mount":**
   - `useEffect` is a hook in React that allows you to perform side effects in function components. The function passed to `useEffect` is executed after the component renders.
   - When you pass an empty dependency array (`[]`) to `useEffect`, it means that the effect will run only once, after the initial render. This is often referred to as "on mount" because it runs when the component is first mounted to the DOM.
   - In your code, the `useEffect` with `inputRef` as a dependency ensures that the input element is focused when the component is first mounted.

```js
useEffect(() => {
  inputRef.current.focus();
}, []); // Runs once on mount
```

2. **`useRef` for Input and Button:**
   - The `useRef` hook is used to create mutable object references that can be attached to DOM elements or other values. In your case, `inputRef` is used to create a reference to the input element.

```js
const inputRef = useRef();
```

- You attach the `inputRef` to the input element using the `ref` attribute:

```js
<input ref={inputRef} type="text" placeholder="Enter text here" />
```

- The button doesn't necessarily need a `useRef` because it's not directly interacting with the DOM or requiring a reference to the button element in this scenario. The `onClick` handler can still access the `inputRef.current` directly without needing a separate ref for the button.

```js
const handleButtonClick = () => {
  inputRef.current.focus();
};
```

3. **Dependency Array in `useEffect`:**
   - The dependency array in `useEffect` is optional. It's used to specify dependencies that the effect relies on. If any of the dependencies change between renders, the effect will re-run.
   - In your case, `inputRef` is used inside the effect, but it doesn't actually change after the initial render. Including it in the dependency array is not strictly necessary, and you could safely omit it.

```js
useEffect(() => {
  inputRef.current.focus();
}, []); // inputRef is not required in the dependency array
```

- Omitting dependencies can be done when you're certain that the effect doesn't rely on any changing variables. This can help prevent unnecessary re-renders.

In summary, the `useEffect` with `inputRef` ensures that the input element is focused when the component is first mounted. The button doesn't need a separate ref because it can use the same `inputRef.current` to access the input element directly. The dependency array in `useEffect` is optional in this case, as the effect doesn't depend on changing variables.

### week-6 ; useRef ; assignment 2

- If we know we won't use the state variable we can just keep it empty and keep the set function only separated by comma

- First way of doing this is by using another state variable that stores the count and increments it on re-render. But this method is not feasible since we should avoid using state variables since using them will cause another re-render(because it'll need to update the state which causes one extra render) on top of the first which is the main one. To track something in this way using state variables is the worst way possible

- Second way of using is adding a global variable outside of the component which is not a state and then adding the increment logic inside of the component. The problem here is that we should never define a global variable let alone use them outside of the component lifecycle. But then again if we add that variable definition inside the component, then it is still not possible since on every re-render the variable(not a state one) gets initialized to its original value and so incrementing is not possible

- Then we can use the useRef to do this stuff of remembering the variable value across re-renders. We can use it to store anything we like. Now instead of using a global variable, we can use that variable to useRef to store the reference to 0 `const noOfTimesRendered = useRef(0)` and this reference doesn't change across re-renders. We can change the value but the reference won't change. This is good because it will now be a part of the react lifecycle and react will know its existence instead of being confused and react will not override its value. So then we can just take the current value of that var and increment it by 1 everytime needed using `noOfTimesRendered.current = noOfTimesRendered.current + 1` and we can also show it by using `{noOfTimesRendered.current}`. Also by doing this we don't need to call the reference in the button
