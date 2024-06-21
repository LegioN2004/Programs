# hooks brushup

- you gotta know that the hooks can only be used with the functional components but not with class based components since they have their own way of state management.
- every time the component runs the hooks must execute in the exact same order. So the hooks cannot be nested in any way be it conditionals, functions or loops. They must stay at the top level and there must be nothing around them.

## useState hook

```ts
 function decrement() {
  setCount(count - 1);
  setCount(count - 1);
 }
```

When we have state variables like the above where we use the state variable to change the state in the setFunction of the state then we need to take care of one thing that may change how we'll do stuff. And they're as follows:

- Whenever we call the setFunction with the new count value, it will trigger a re-render our component, with a new value to the count. But this way is  an incorrect way to change the state value.
  - Why is it incorrect?: Because on using the state variable with the state function two times we essentially overwrite the value because the value of count is just the value when we render the function.
  - But if we do something like the function version(arrow) instead of using the state variable directly then we can prevent that error. Why can we do this: since JS can take callbacks (yes that thing is a callback), so after using that we can trigger the setFunction to pass the changed value instead of using the state variable which overwrites the main state variable and as such we'll have proper changes to the variable which doesn't get overwritten on re-render.

  ```js
    function increment() {
      // setCount(count + 1);
      setCount((prevCount) => prevCount + 1);
      setCount((prevCount) => prevCount + 1);
    }
  ```

  - So things to *note*: Anytime we're modifying state where we are using the previous value of the state to create the new value then we need to make sure that we use the function version of setting the state just like we.
- But if we have a specific usecase where the process keeps happening over and over again, then by re-rendering  everytime it could really slow down our application, so we have another style of useState() usage, which is by passing in another callback to the useState hook directly which will take care of running that callback function body once and then working with that only. This is the second way to pass in the state.
  - Or we can make a function for that state functionality outside the main app function and then call that using a callback style cal and not directly calling since that will trigger a two times re-render.
  - React uses the initial state function (passed to useState) only during the component's initial render. On subsequent renders, the initial state is no longer needed because React keeps track of the state internally. Hence, the function passed as a callback to useState is only called once. When you pass a function itself to useState, React will call this function only once during the initial render to get the initial state value.
    - So for a complex computation that is needed in the initial state we gotta use the function version of the state variable so that the process doesn't just keep on happening after every render.

# React + TypeScript + Vite

This template provides a minimal setup to get React working in Vite with HMR and some ESLint rules.

Currently, two official plugins are available:

- [@vitejs/plugin-react](https://github.com/vitejs/vite-plugin-react/blob/main/packages/plugin-react/README.md) uses [Babel](https://babeljs.io/) for Fast Refresh
- [@vitejs/plugin-react-swc](https://github.com/vitejs/vite-plugin-react-swc) uses [SWC](https://swc.rs/) for Fast Refresh

## Expanding the ESLint configuration

If you are developing a production application, we recommend updating the configuration to enable type aware lint rules:

- Configure the top-level `parserOptions` property like this:

```js
export default {
  // other rules...
  parserOptions: {
    ecmaVersion: 'latest',
    sourceType: 'module',
    project: ['./tsconfig.json', './tsconfig.node.json'],
    tsconfigRootDir: __dirname,
  },
};
```

- Replace `plugin:@typescript-eslint/recommended` to `plugin:@typescript-eslint/recommended-type-checked` or `plugin:@typescript-eslint/strict-type-checked`
- Optionally add `plugin:@typescript-eslint/stylistic-type-checked`
- Install [eslint-plugin-react](https://github.com/jsx-eslint/eslint-plugin-react) and add `plugin:react/recommended` & `plugin:react/jsx-runtime` to the `extends` list
