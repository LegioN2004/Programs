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
  - The other thing that it lets us do is maintain a variable across re-renders

  ```js
  import { useCallback, useEffect, useRef, useState } from 'react';

  function App() {
    const [incomeTax, setIncomeTax] = useState(20000);

    useEffect(() => {
      setTimeout(() => {
        document.getElementById('incomeTaxContainer').innerHTML = 10;
      }, 5000);
    }, []);

    return (
      <div>
        {/* hi there, your income tax returns are <div id="incomeTaxContainer" ref={divRef}>{incomeTax}</div> */}
        hi there, your income tax returns are{' '}
        <div id="incomeTaxContainer">{incomeTax}</div>
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
  import { useCallback, useEffect, useRef, useState } from 'react';

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
         hi there, your income tax returns are <div ref={divRef}>{incomeTax}</div>
      </div>
    );
  }

  export default App;
  ```
