# 6.1 React deeper dive

all about react returns, re-rendering, key, wrapper components; useEffect, useMemo, useCallback, useRef

## About returns

You cannot return multiple siblings, A component can only return a single top level xml

- Why is that?(popular interview question)

  - Makes it easy to do reconciliation. What is that: the process of figuring out when and what dom update needs to happen as our application grows
    - using parent div: We can't store two child in xml inside the parent, we must have one top level parent that can consists of the child, can also get sub-parents, but top level parent is necessary
    - Empty element: Or If we don't want any element to be the parent, then we can just keep empty element tags as the top level parent, that also works. Empty parent and as such the child/ other elements come as sibling(more nesting if given)
    - React.Fragment:Or we can use React.Fragment, which does the same as the above empty element
    - The above empty and fragment ones are better because they don't introduce a new DOM element.

- solving this question, explanation above

  - Create a react app that has a
    1. Header component that takes a title as a prop and renders it inside a div
    2. The top level App component renders 2 Headers
  - And the following is the answer
    - note that we are using the objects destructuring syntax, that can be directly given like that and can be used by the elements, instead of using another variable to store and then using the dot operator to put the value

  ```js
  function App() {
    return (
      // the error comes here when we don't have that parent div
      <div>
        <Header title={"helooooo"}></Header>
        <Header title={"helooooo"}></Header>
      </div>
      // or do something like this where the parent must not be anything, empty parent
      <>
        <Header title={"helooooo"}></Header>
        <Header title={"helooooo"}></Header>
      </>
      // or you can use `React.Fragment` which does the same by not rendering any element and just making the nested ones siblings
      <React.Fragment>
        <Header title={"helooooo"}></Header>
        <Header title={"helooooo"}></Header>
      </React.Fragment>
    );
  }

  function Header({ title }) {
    return <div>{title}</div>;
  }

  export default App;
  ```

## About Re-Rendering

Anytime, a final dom manipulation happens, anytime react actually updates the DOM, then "re-rendering" happens. React gives us a easy way to create dynamic websites, the logic that is updating something on the screen when we update/remove/add something to the DOM whenever that DOM updates happen, is what's called a "re-render".

Any framework like React,etc, the rule of thumb will be to reduce the no of re-renders when creating a lets say website, etc. There will be no issues for most websites but if we are writing a mobile app, or a game then we'll need to optimize the re-renders so that the performance doesn't degrade.

- The code that we wrote to re-render and change the name to some random number should re-render only the line where that name is written and the parent component since the line is a child of that parent but the next element to the main line shouldn't re-render. Ideally only the line and the parent should re-render
  - But after using the react-dev tools extension, we can see that all the components in the div (but not the button element, since it is not a component) are also getting re-renderd everytime we update the state using the logic of the button we wrote for that line.

A re-render means that:

1. React did some work to calculate what all should update in this component
2. The component actually got called (you can put a log to confirm this)
3. The inspector shows you a bounding box around the component

It happens when:

1. A state variable that is being used inside a component changes
2. A parent component re-render triggers all children re-rendering(imp), irrespective of if the child has used the state variable or not

We should make the re-renders as low as possible so as to make a highly optimal react app since the more no of re-renders, the worse.

- So if we can move the state variable to the place where the state var is actually used, then we'll be able to save a bunch of re-renders from the ones which don't need them.
  - So using the following syntax, we have shifted the onclick stuff and the button and title that must be updated to a custom component and that component acts like a parent that re-renders when the state gets changed
  - **NOTE**: The main rule is that whenever you have a nested component structure where we have a bunch of parent, sub-parent and children, we should always keep the state variable at the lowest common ancestor so as to avoid unnecessary re-renders, never keep it at the root we can but it worsens our performance of the app/website/etc. We should try to push down the state as much as we can in the chain and then use the states in the coming children using props
  - by default the state is in the very top of the main component since in that way we can share the state with everyone(very obvious)

```js
function App() {
  return (
    <div>
      <HeaderWithButton></HeaderWithButton>
      <Header title={"heloooo"}></Header>
      <Header title={"heloooo1"}></Header>
      <Header title={"heloooo2"}></Header>
      <Header title={"heloooo3"}></Header>
      <Header title={"heloooo4"}></Header>
    </div>
  );
}

function HeaderWithButton() {
  const [title, setTitle] = useState("My name is harkirat");
  function onClick() {
    setTitle("My name is " + Math.random());
  }
  return (
    <>
      <button onClick={onClick}>change name</button>;<Header title={title}></Header>
    </>
  );
}

function Header({ title }) {
  return (
    <div>
      {/* <button onClick={onClick}>click me</button> <br></br> */}
      {title}
    </div>
  );
}

export default App;
```

- chatgpt exp

In your React code, you're using the `useState` hook to manage the state in functional components. Let's break down what's happening:

1. **Global Nature of State:**

   - The `useState` hook is used to declare state variables within functional components. Each time you call the `useState` hook, it returns an array with two elements: the current state value and a function that allows you to update the state.

   ```javascript
   const [title, setTitle] = useState("My name is harkirat");
   ```

   - The `title` variable holds the current state value, and `setTitle` is the function to update the state.

2. **HeaderWithButton Component:**

   - `HeaderWithButton` is a functional component that contains a button to change the name. It uses the `useState` hook to manage the `title` state.

   ```javascript
   const [title, setTitle] = useState("My name is harkirat");
   ```

   - When the button is clicked, it triggers the `onClick` function, which updates the `title` state with a new random name.

   ```javascript
   function onClick() {
     setTitle("My name is " + Math.random());
   }
   ```

   - The `HeaderWithButton` component then renders a `Header` component with the updated `title` as a prop.

3. **Reducing Re-renders:**

   - By putting the state in the parent component (`HeaderWithButton`), you can indeed control the state updates and potentially avoid unnecessary re-renders in child components. This is a good practice when you want to optimize performance.

4. **State Scope:**
   - The state variable (`title`) is local to the `HeaderWithButton` component. It's not global across components; each component manages its own state.

Overall, your code looks fine. The `useState` hook helps manage component state, and by organizing your code in this way, you can control state changes and optimize re-renders. The `HeaderWithButton` component acts as a parent that manages the state and passes it down to the `Header` component.

### Also we have another method to avoid unnecessary re-renders using React's `memo`

- **memo** lets us skip re-rendering when the props of the component are unchanged.
- Whenever we want to define a component that we want to memoize. i.e we want to not re-render when its props haven't changed then we can do somethinng like:
  - syntax is something like `const some_name = React.memo(function)` this where it is a function that comes after the dot notation from the React keyword and then just pass the another function anonymously that shouldn't change its state inside the parenthese of memo.
  - So when we don't use `memo` and lets say we have a parent and the child then if the parent re-renders then the child will also re-render even if the state variables that are inputs to this child hasn't changed. Even if it doesn't taken inputs if the parent re-renders then the child will also re-render unless we wrap the child inside `memo`. Then the child will only re-render if the inputs to child have changed
  - We can destructure the react library and just use `memo` also by doing something like `import React, { memo } from 'react` and then directly use memo by `const some_name = memo(function)`
  - When we use memo for a empty element/ fragment then we must know that it doesn't exist in the DOM and as such the memo doesn't have any effect and react just re-renders the whole component

#### some dos and don'ts

- never change the state from the child to the parent. Always state should be pushed from the parent to a child
- never change a component from the child to the parent

## Keys in React

- task

  - Lets create a simple todo app that renders 3 todos
    1. Create a Todo component that accepts title, description as input
    2. Initialise a state array that has 3 todos
    3. Iterate over the array to render all the TODOs
    4. A button in the top level App component to add a new TODO

- we are not updating the id, it is just hardcoded so we can use a global counter variable that just increments from the last hardcoded part.
- Then after writing the code we can see in the console of the dev tools that there is an error saying, "Each child in a list should have a unique "key" prop." This error is also said by eslint everytime annoyingly -**Why** is it necessary: Because keys in react is a way to identify stuff. Whenever we are rendering an array in react, to make sure that react knows the order of the array, since it can easily get confused when we add/remove/update stuff or sort and it just increases the re-renders in the app by removing everything and entering them again in the new way. Instead of doing that if we add a 'key' which is a way to uniquely identify a todo here, then the warning goes away, and react is able to know when we change stuff in the array and then it fixes/re-renders them automatically, rather then removing and adding them. It has the keys in the virtual DOM and then in the actual DOM it'll check the differences between them and then fix stuff rendering stuff more optimally just the way react works
  - We need to just write it the right way, whenever we are rendering a list we need to make sure that there is a unique identifier for every element in the list and make sure that key is equal to that unique identifier
  - in short Keys let react figure out if a
    - TODO has been update,
    - which has been delete,
    - which has been added

This is what the react website says:
You need to give each array item a key — a string or a number that uniquely identifies it among other items in that array:

```js
<li key={person.id}>...</li>
```

- Note: JSX elements directly inside a map() call always need keys!

Keys tell React which array item each component corresponds to, so that it can match them up later. This becomes important if your array items can move (e.g. due to sorting), get inserted, or get deleted. A well-chosen key helps React infer what exactly has happened, and make the correct updates to the DOM tree.
Rather than generating keys on the fly, you should include them in your data

## Wrapper components

Lets say we want to build a website that has a lot of cards that look the same, what we can do when we want to build stuff like that is we can make a "wrapper card components" which takes the inner React components as an input or more specifically a prop. That means that a component takes another component as an input

- one way of doing that is the following

how can we do that: By passing the same way we did with the props, like title.name but instead we pass the wrapper component to the target component call using a variable that'll store that(that'll render the wrapper component inside the target component call or as per the needs) and then also pass that variable, and then use the variable in the target component definition that holds the target structure of that component

- here target component is the `<CardWrapper></CardWrapper>` and variable is `innerComponent`(can be any name) and the wrapper component is `<TextComponent />`, according to the below example.

```js
function App() {
  return (
    <>
      <CardWrapper innerComponent={<TextComponent />}></CardWrapper>
    </>
  );
}

function TextComponent() {
  return <div>hi there</div>;
}

function CardWrapper({ innerComponent }) {
  return <div style={{ border: "2px solid black", padding: 20; }}>{innerComponent}</div>;
}
```

This is one way to solve the many cards problem. You can create as many card wrapper as you want then pass them into the main card, in that way we can maintain the same style everywhere

- The main way of doing that is by using a 'real wrapper'.

  - What that means is that we will be writing the main logic of the code directly inside main component call and then pass in a variable called `children` instead of that innerComponent to the the wrapper that we want to wrap with. This `children` gives access to everything that is inside the main component call `CardWrapper` and not the component definition(do note that), and as such we can pass in apply that the logic of the function to everything that comes within that component call.
  - We always get access to this children variable, just we'll need to use them like the props.
  - This is the actual cleaner syntax that will be used in the real world, and we need to understand this.

  ```js
  function App() {
    return (
      <>
        <CardWrapper>
          <div>hi there</div>
        </CardWrapper>
        <CardWrapper>
          <div>bye there</div>
        </CardWrapper>
      </>
    );
  }

  function CardWrapper({ children }) {
    return (
      <div style={{ border: "2px solid black", padding: 17 }}>{children}</div>
    );
  }
  ```

  - As per the code using the `children`, we get some complex objects passed when we log out which all in all contains everything inside the component call. NOTE: using children we get only access to everything that is inside the same component call as of the function where this children has been used. In our example we have the hi there enclosed with div, so whereever we have used children that whole div gets copied in its place.
  - Then we can copy the main component call to make a card wrapper like thing and pass in the different inputs to the children in every occurence so as to apply the same stuff to different stuff/elements/anything as per requirement.
  - for more complexity, we can define other components outside and then run them in the CardWrapper so as to apply that signature style that main component applies by writing the other components calls inside that CardWrapper

## Popular Hooks

Functions that React gives us and start with a 'use' are called "Hooks". Hooks in react are functions that allow us to "hook into" React state and lifecycle features from functional components. Eg; useState, useRef, useMemo, useCallback, useReducer, useContext.

- What are lifecycle features: In old React we had something called lifecycle functions something like `onComponentMount()` which is a function which can then take a alert in the logic which can be then be attached to a component and a trigger to that component alerts whenever a it mounts. More examples include `onComponentUnMount()`, `onRender()` this was the way to do stuff in class based components in old React (pre 2019ish days).
- But now we follow the functional component based approach, where we have no easy way to hook into lifecycle events to say yes this got rendered for which these hooks were introduced. These hooks lets us do something similar to the old lifecycle functions/events and we need access to these very often
- mount means the first time the component renders in the DOM

### useEffect

- The first hook is the 'useEffect' hook which lets us to write some function inside it which runs only when the component mounts `useEffect(function(){some_logic}, [])`. It is similar to the class based components to alert when component mounts in old react
- useEffect is defined in two parts where the first is a function inside hook which contains the logic that'll run and after that it contains a dependency array after the function that says when should the function run. If we keep the array empty then it'll run on component mount. But if we put todos there, then it'll run anytime the todos state variable changes
- The useEffect runs two times if we have the strict mode on in the react main.jsx file. It auto goes away in production react but is present when that line is present and we are running the dev server
- We cannot use async directly to the useEffect main function logic
- Regarding the assignment of useEffect hook

  - used setInterval to run the inside the useEffect hook to fetch after every 10 second.
  - remember res.json is like that get request we get from the server that returns some json object which can then be using the keys using the dot notation
  - useEffect's first part which has a function can't itself be an async but the functions inside it can be async
  - the syntax we've used in the `map` function is a concise arrow function syntax. When the arrow function body is a single expression, we can omit the `return` keyword, and the expression will be automatically returned.
    In our example:

  ```jsx
  {
    todos.map((todo) => (
      <Component
        key={todo.id}
        title={todo.title}
        description={todo.description}
      ></Component>
    ));
  }
  ```

  The JSX expression inside the parentheses is the single expression in the arrow function body. Therefore, you can omit the `return` keyword. This shorthand syntax is often used for brevity when the function body is concise.

  This syntax is specific to arrow functions and can be used in certain situations, like mapping over an array, where a single expression is expected. In other cases or with regular function declarations, you typically need to use the `return` keyword explicitly.

  - Also can return main two keys using two variables in the component call for better usage in the component definition with the elements
