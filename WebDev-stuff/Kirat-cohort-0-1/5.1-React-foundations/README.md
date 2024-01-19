# Reach shallow dive

1. Understand why react was introduced
2. Basic syntax
3. JSX file
4. many jargons like jsx, class vs className, static vs dynamic websites, State, components, re-rendering
5. This is the last intro class to React

## Why do we need React, Vue.js, svelte, etc

- For static website you don't need that.
- For dynamic websites, you can use frameworks since it makes our lives as a dev easier because it makes it easy to do DOM manipulation, but it can also be written in pure HTML, CSS and JS

- So React came into the picture which is an easier way to write normal HTML CSS and JS. It's a new syntax that under the hood gets converted to normal HTML, CSS and JS. But the browser doesn't understand it, it just is one syntax to convert what we write in react to html, css and js.
- But is it good enough to replace the conventional way of writing DOM stuff to create dynamic websites and the answer is yes it is due to the following reasons

  - People realized that it's harder to do DOM manipulation the conventional way
  - There were libraries that came into the picture such as "JQuery" that made it slightly easier to do DOM manipulation, but still for a very big app it's very hard.
  - Eventually VueJS and React created a new syntax to do frontends, which is jsx
  - Under the hood, there is a React compiler that converts the react code to normal HTML, CSS and JS

- How React fixes stuff: To create a react app we need to know three things properly

1. **Components**
2. **State**
3. **Re-rendering**

- Whenever we are writing react code we need to write Components, State and rest of the things are taken care of by React itself
- Creaters of frontend frameworks realized that all websites can be effectively divided into two parts: State and Component

### State

It is a javascript object that represents the current 'state' of the app. It represents the dynamic things in your app(things that change with time). For example the value of the counter which changes on click. The counter button needs to be on the state. Anything that changes on the website is called a state and rest of the things are not to be worried about

- in our counter html the state looks something like this: This count is the state of our dynamic counter application, there can be a bunch of other things.

```json
{
  "count": 1
}
```

- a real world application like linked.in has something like this: lets say if the navbar is being converted to a state because it changes dynamically then it'll contain this
  - It would be nice if we update the state and the frontend updates auto. Lets say we have 99+ notifications in one of the navbar part 'myNetwork' and lets say the backend converted the state to 10 and the frontend auto converted that 'myNetwork' to 10 too.

```json
{
  "navbar": {
    "home": 0,
    "myNetwork": "99+",
    "jobs": 0,
    "messaging": 0,
    "notifications": 13
  }
}
```

### Components/Re-rendering

- How a DOM element should render, given a state. It is reusable, dynamic, HTML snippet(not a html snippet) that changes given the state
- Lets say in the linked.in example, the myNetwork is a state of a component named 'network' which shows up at the navbar at the very top. When the state is 99+, it knows that it has to render like this red thing written 99 at the top like 'to the power' to show the numbers, and when the input state is 0 , it should not do any colorization and should show the icon normally
- So any big application has thousands of components.
- the button that we made in DOM is also a component, it takes a state `currentCount` as input and it is supposed to render accordingly
- more example: lets say the run button of the repl.it website that is used to run the code written by us. Let's say it uses a 'buttonComponent' function that takes many params of which the word 'run', the icon 'play' and the color of the button 'green'; so a function that takes props or state as an input and returns an actual html button like that above or something on the website is called a component

- How does react expects devs to write code
  - Give me a state of the code that you're writing, a very big object that represents all the dynamic part of the application
  - Give me all the individual components and how they're structured together
  - Give me how this state is connected to these components. we need to tell that this notification number is what needs to appear here, this button needs to stay here and so on
  - React takes care of all the other stuff, just update the stuff in the state and it'll take care of the updating of all the components, buttons, etc

### Re-rendering

- Given this state we have a component like this notifications which currently shows 10, lets say we update the state from 10 to 12, then the component needs to change to 12 from 10 as well. This updating of the state to change from 10 to 12 whenever the backend talks to the state or whatever the reason may be, react then re-renders meaning takes the current updated input from the state, and puts it in the component i.e it changes the DOM.
- A state change triggers a re-render
- A re-render represents the actual DOM being manipulated when the state changes

So we usually need to define all our components once and then all we have to do is update the state of your app. React takes care of re-rendering the app. Using the reactStructureinHTML file the things we need in react are:

1. State(global): First we have the state count which is a very necessary part in react

```js
// this part the state count that is in react
let state = {
  count: 0,
};
```

2. main Logic: Then we have the main counter logic which is much smaller and cleaner than the one written with all the dom manipulation logic, the two examples being below

```js
// cleaner logic
function onButtonPress() {
  state.count++;
  // buttonComponentReRender(); // this is also taken care of by react
}
```

```html
// don't include this in the separated state component onclick button counter
<script>
  // trashy logic
  function onButtonPress() {
    const currentValue = document.getElementById("btn").innerHTML;
    console.log(currentValue.split(" "));
    const currentCounter = currentValue.split(" ")[1];
    const newCounter = parseInt(currentCounter) + 1;
    document.getElementById("btn").innerHTML = "Counter " + newCounter;
  }
</script>
```

- This following code is in the react library which we'll not have to write, and we can see that although our dom manipulation involved logic was shorter than the one with separated logic but when we reach react we'll see how easy that becomes

```js
function buttonComponentReRender() {
  document.getElementById("buttonParent").innerHTML = "";
  const component = buttonComponent(state.count);
  document.getElementById("buttonParent").appendChild(component);
}
```

3. Component: We also have to write the following logic which is not that hard to write in react

```js
function buttonComponent(count) {
  const button = document.createElement("button");
  button.innerHTML = `Counter ${count}`;
  button.setAttribute("onclick", `onButtonPress()`);
  return button;
}

// and the above  just returns
<button onclick="onButtonPress">counter 2</button>;
```

- And this calling the function that the react library writes will be done by react itself

```js
buttonComponentReRender();
```

- So in react we'll have to care about the above state, component and the main logic

Now how we'll write that in React comes in the following parts; Also App.jsx is the main file that we'll need inorder to write react, we can think of it as the main meat

```js
// first parts importing and defining function
import React from "react";

function App() {
  // the logic part from below
```

1. State: The state part is written in the following way, we can't write in a simple js like syntax because it is written that way and otherwise React won't monitor the state.

   - Why this syntax only: because it is something called 'array destructuring' which is found in js and that is being used here in react. How array destructuring works, lets say you have `const [a, b] = [1, 2]`, then `a[0]` gives you the value at the 0th index i.e 1 and the `a[1]` gives the value at the 1th index i.e 2.
   - You can also do something like `const arr = [ 1, 2 ]` and `const [a , b] = arr` then `arr[0]` as well as `a` gives the value 1 and `arr[1]` and `[b]` gives the value 2, 0th and 1th index values. This is same saying `const [a, b] = [1, 2]` which directly stores the 0th index and 1th index values to the variable that is at that same index.
   - The same also applies to objects so they're, in that case called 'object destructuring'.
   - But in react we follow the below mentioned structure of writing the destructuring. React also gives two values in the state which gets added to the state; 0 is the initial state value and count and setCount is the two thins that the useState function returns basically returns an array, first value of an array is send to the first count, then the next value of the array is sent to the next setCount variable

```js
// this is just the way to define the state in react
const [count, setCount] = React.useState(0);
```

3. The component part comes after that which says retuns a div which also returns a button or renders a button component which it has

```js
return (
<div>
    <button count={count} setCount={setCount}></button>
  </div
)
```

2. Main logic: Like the buttonComponent function that we wrote in html, this part is also the same as that. This button function takes the count and setCount as an input and returns a button dom element to us. The above return calls the button component and it takes count and setCount in a very wierd way and returns those to the component button.

```js
function Button(props) {
  function onButtonClick() {
    props.setCount(props.count + 1);
  }
  return <button onclick={onButtonClick}>Counter {props.count}></button>;
}
```

Now we're creating a boilerplate ready codebase of React using **Vite** (`npm create vite@latest`) so we can easily bootstrap as our application. It is a bundler

The new things we find there is the file structure and the jsx file extension files

- In the index.html file we get some things and a div with id root and script tag sourcing the main.jsx file in the body. So anything outside root id's div can't be controlled by React
- `<script type="module" src="/src/main.jsx"></script>` the file this line sources is a JavaScript XML file which helps use to write both JavaScript and XML. Before it was told that we were writing JS and HTML but it is actually JS and XML(which is almost html but extended hence the name Extended Markup Language)
- Then the main.jsx file, it calls a function `ReactDOM.createRoot(document.getElementById('root')).render(<App />)` which says that take this root id wala div and inside this render this 'App' application. This `<App />` application is the first component.
- The index.html files has the same empty div that we had in our dom html file and then we also had a render function i.e is present in the main.jsx file, in the same way telling us to render the component 'App'

- Now how this react code gets rendered to html, and js is dependent on the compiler, when we run `npm run build` it builds the code and renders some html and js in a dist folder which contains everything that we need to display what we wrote in the react application. this dist folder is now ready to be deployed. That is how react works and after building out we can remove everthing in the folder except dist and it'll still run the stuff we made in react as it was.
  - So in the real world we will use this 'dist' to distribute to people, `npm run dev` is only for developers for hot reloading and developing stuff.

#### Creating a dynamic website using react using state and components

- Created the same count variable like in the html file for the global state count
- Then created a button that renders state.count and that can be done as `<button>Counter {state.count}</button>`
- Then calling the function with an onClick handler to a function that increments the state.count
- **NOTE**: But after doing so it doesn't re-render the component even if the state and componenet is present, because react doesn't look at every variable as a state variable, we cannot define anything at the top of the file and say it is a state variable there is a certain way to define the state variable
  - So it asks the developer to use a certain syntax so that react can identify it as the state variable
  - what we need is this hook: `import { useState } from "react";` which defines the useState to set a state for our application, and then we define the state which is the only thing monitored by react using the syntax `const [count, setCount] = useState(0);`. This `useState` returns two values in an array
    - Whatever this function `useState` returns, its first value goes to `count` and the second value goes to the `setCount` variable. By using the console in the dev tools, we can see that the count gets a value of 0 and the `setCount` gets some function returned called `dispatch...` which means that whenever we call this dispatches something which re-renders our dom
- We are then trying to increment the count state by 1 everytime the button is clicked by doing `count++ or count = count + 1` but this is a wrong way to set state or increment it when using react components. Instead we should do something like `setCount(count+1)`, it gave us a function so we call it with a function with the increment logic

things to note:

- Whenever you try to access/render dynamic js variables inside React components then you need to put it inside curly braces. This is a syntax rule
- Also the attributes of html(more appropriately xml) are not written like all of them in small letters, instead it follows this style called **"Camel Case"** which means writing the attributes' second word in capital, something like this: `onclick="function()"` in html; `onClick={function(){ some_logic }}`/ `onClick={function}` then call the function outside before this return statement; in jsx
  - Because it is not html but XML and the elements are not standard elements

So in 10 lines we wrote this counter application, it is less than 10 lines of code

```js
import { useState } from "react"; // this is the hook to define the so that we can use it

function App() {
  const [count, setCount] = useState(0);

  function onClickHandler() {
    // count++; // this is not the right way to set
    setCount(count + 1);
  }
  return <button onClick={onClickHandler}>Counter {count}</button>;
}

export default App;
```

This much code is doing many things:

1. defining the initial state
2. returning dynamic html(the return part), given the count variable this is how the button should render
3. and anytime the button is clicked, the function runs which sets the state and under the hood react re-renders

Most of the apps have the same things: a very big state variable on top and a bunch of components defined at the bottom that use these states and as we update our state variables our app gets re-rendered

- Better writing style
  - creating a function i.e a component outside of the main app component(which we didn't do earlier, shoving everything inside the main `App()`)and then they can take state variables as inputs which can then be rendered here inside the elements.
  - So you can create multiple child components which then can be rendered by the main parent component
  - we can put the onclick main logic here too
  - As such we have created our own element by doing so and we can then render that element inside our main App component, and we can remove the button creation element
  - This is a slightly cleaner code
  - Now we can easily make four dynamic divs by copying the first one and doing slight changes instead of writing rendering logic for the four of them again and again
  - More about props below

```js
function CustomButton(props) {
  function onClickHandler() {
    // count++; // this is not the right way to set
    props.setCount(count + 1);
  }

  return <button>Counter {props.count}</button>;
}
```

and we can set the custom button in the main app component

```js
function App() {
  const [count, setCount] = useState(0);
  // return <button onClick={onClickHandler}>Counter {count}</button>; // we  can now not use this and just render our own custom button which has turned into an elements
  return (
    <div>
      <CustomButton count={count} setCount={setCount}></CustomButton>
    </div>
  );
}
```

- More about state by chatGPT
  In React, the `useState` hook is a function that allows functional components to manage state. It returns an array with two elements. The first element is the current state value, and the second element is a function that allows you to update the state.

  Let's break down the line of code in your `App` component:

  ```javascript
  const [count, setCount] = useState(0);
  ```

  1. **`count`**: This is the **state variable** that holds the current value of the state. In your example, it's named `count` and initialized with a default value of `0`. This is the value that you can read and display in your component.

  2. **`setCount`**: This is the **function** that allows you to update the state. In React, you don't directly modify the state variable (`count` in this case) like you would in a traditional JavaScript variable. Instead, you use the `setCount` function provided by `useState` to update the state. When you call `setCount(newValue)`, it not only updates the `count` value but also triggers a re-render of your component with the updated state.

  Here's a brief overview of how it works:

  - **Initialization**: The `useState(0)` call initializes the state with an initial value of `0`.
  - **Current Value**: `count` is the current value of the state. Initially, it's `0`.
  - **Updating State**: When you want to update the state, you use `setCount(newCount)`. React will then re-render the component with the new state value, and any part of your UI that depends on this state will be updated.

  So, in the context of your `App` component, the `count` state is used to keep track of the current count, and `setCount` is the function you use to update that count. This pattern ensures that React can efficiently manage the component's state and trigger re-renders when necessary.

  - The names `count` and `setCount` are just variable names, and you can choose any valid JavaScript identifier according to your preference. The key thing is that the first item in the array returned by `useState` is the current state value, and the second item is the function used to update that state. The convention of naming them `stateVariable` and `setStateFunction` is commonly followed in the React community for clarity, but it's not a strict requirement.

  For example, you could name them `value` and `updateValue`:

  ```javascript
  const [value, updateValue] = useState(0);
  ```

  Or any other names that make sense in the context of your component. It's all about making your code readable and understandable. The important part is the relationship between the current state value and the function used to update it.

- About props:

  - In React, props (short for properties) are a way to pass data from a parent component to a child component. In your example, the `CustomButton` component is a child component of the `App` component, and you are passing data to it through props. It is just kind of a standard to put in there

  Here's a breakdown of how it works:

  1. In the `App` component, you define a state variable called `count` using the `useState` hook. This state variable is initially set to 0.

  ```javascript
  const [count, setCount] = useState(0);
  ```

  2. You render the `CustomButton` component and pass the `count` state variable and the `setCount` function as props to it.

  ```javascript
  <CustomButton count={count} setCount={setCount}></CustomButton>
  ```

  3. In the `CustomButton` component, you receive these props as function parameters:

  ```javascript
  function CustomButton(props) {
    // props.count refers to the value of the 'count' prop passed from the parent
    // props.setCount refers to the 'setCount' function passed from the parent
    // These are just names you can choose; 'count' and 'setCount' are used in this case.

    function onClickHandler() {
      // When the button is clicked, you use the setCount function to update the 'count' state.
      props.setCount(props.count + 1);
    }

    // Render a button with an onClick event that calls the onClickHandler function.
    return <button onClick={onClickHandler}>Counter {props.count}</button>;
  }
  ```

- The following is the original/another way to write React code which it used to be a few years back. This is much more relatable to the html code that we wrote earlier.
  - What we write is jsx which is much easier to write for devs but after we write it the code gets transpiled to the following code

```js
import React from "react";

function App() {
  return (
    <div>
      <Button></Button>
    </div>
  );
}

function Button(props) {
  const [count, setCount] = React.useState(0);

  function onButtonClick() {
    setCount(count + 1);
  }

  return React.createElement(
    "button",
    { onClick: onButtonClick },
    `Counter ${count}`
  );
}

export default App;
```

# Creating a todo application in the React way

It has three elements in the array in the state:

```json
todo {
  todos: [{title: "todo1", description: "first todo", completed: false}]
}
```

Also I have made the main.jsx file point to the todo.jsx file in the src directory so make sure to change that to App.jsx if you want to run the counter file

## Start

Now the problem is that how to print the array objects one after another since the state is now a complicated state

- dumbest way is to dump it in a div, but you will need to stringify it since it is an array of objects using `Json.stringify`

- Usually whenever we are rendering arrays we shoud create a new component given a single todo

- or we can do something like printing the array with their index and the key of the object so as to show the value, but we'll need to repeat ourselves for every array object

```js
  return (
    <div>
      <Todo title={todos[0].title} description={todos[0].description}></Todo>
      <Todo title={todos[1].title} description={todos[1].description}></Todo>
  ); // most noob way
```

- So instead the better way of doing that is using map function which iterates over every array and just follows the conditon that is given to it, which in our case is just putting the array objects in the custom component
- The map function takes a function as an argument. This function is executed for each element in the array ('todo' in this case). It returns a new array of Todo components with the specified props based on the properties of each todo object.

```js
return (
  <div>
    <button onClick={addTodo}> Add a random todo</button>
    {todos.map(function (todo) {
      return <Todo title={todo.title} description={todo.description}></Todo>;
    })}
  </div>
);
```

- Also to add a todo dynamically one after the other on the click of a button, we can do smoething like this:

  - defining a function outside of the main App component return statement, we can then do `setTodos([...todos])`, what this `...todos` does is that it spreads all the original values here and then you can add more things there, so if there was `[1, 2]` in the array then `[...todos]` will give the same array but `[...todos, 3]` will add the 3 to the next index of the same array i.e `[1,2,3]`. This `...` is called the spreads operator
  - **note** that this is the only way to update the todos as per 'React', by using the state variable's function and then sending new values to be added to the state variable by putting them inside the function, in the following way.

  ```js
  function addTodo() {
    setTodos([
      ...todos,
      {
        title: "new todo",
        description: "noarsetnaeir",
      },
    ]);
  }
  ```

- misc
- Again we have to worry about the state, React takes care of the re-rendering, iterating, moving of the elements.
- If the parent re-renders then it's child will also re-render, so anything inside the main function's return will get rendered whether it uses the state variable or not.
- The props comes from the state variable inside the parent and as such when the props/state variable changes the components will re-render. It is monitoring state only, but we are doing props and changing them and as such state is also getting changed and as such the components concerned also get re-rendered
- If you want to put any JS variable inside the xml attributes, then you will first need one curly brace for the variable and then if there is an object then you will need another set of curly braces to put the objects inside lets say for CSS
- var, let are some variable declaration primitives that can be defined more than once but let can be defined only once in its lifetime. **note**: you will be using let and const, let for something that changes more than once and const for the variable that'll not be initialized again, it can be modified, only you can reassign the values of that const variable.
