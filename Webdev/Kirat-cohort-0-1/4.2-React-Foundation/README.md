# Frontend and Reconcilers

- Why frontend frameworks like React and Vue were introduced and is currently the way to write frontends and what problems do they solve
- What are Reconcilers
- Basic React-app creation today

## DOM again

- before frontend frameworks were introduced, people were able to create dynamic websites only by using DOM manipulation. Dynamic sites are those which dynamically updates the html that we get from the server initially after some time or as per design.
- React made it easier to do DOM manipulation. for eg: When we open the linked.in website we see that when we scroll new things get added to the page, the things getting newly added and updated(appended to) to the things that were initially something else, this is what DOM manipulation more specifically adding these things to the end is called DOM manipulation. Even notifications updating itself without not being refreshed is DOM manipulation.
- DOM manipulation is very to write as a developer. Making dynamic websites, with the primitives that DOM provides you is very hard

## DOM manipulation project todo application

- we'll be using
  - document.createElement
  - document.appendChild
  - element.setAttribute
  - element.children
- we are going to create a simple todo application using dom manipulation

  - make two fields which gets some todo input like title and description
  - then run a todo function that prints the todo after every click one after the other
  - the fields also have a div where the new inputs gets added

- thing used here are backticks which can be used to write multiline strings and also there the values of variables can be incorporated using '$' followed by curly braces and inside the braces we'll have to write the name of the variable whose value we want
- but if we use innerHTML the previous text gets overwritten instead of printing it below
- so we can use appendChild
- Also we can create a new element using `document.createElement("element_name")` but it doesn't get directly entered into the document

  - So the goal of createElement is to create element in-memory and eventually put them in DOM

  ```js
  const outerDiv = document.createElement("div");
  outerDiv.innerHTML = title;
  document.getElementById("container").appendChild(outerDiv);
  ```

  - first outerDiv creates a div element then the next one gets title and puts it in memory first then after that the next line tells to take the container id wala div and puts the new created divs(taking input from title) from outerDiv and appends them as the child of the div and that is appenChild does
  - setAttribute lets you add attributes dynamically to the element

#### Why this todo html is a problem?

Very hard to add and remove elements and there is no central **State**

- What if there is a server where these todos are put
- What if you update a todo from the mobile app
- If you get back an array of todo items on the frontend how will you then update the DOM
- You only have an add todo function, there is no function to update or remove

The backend only returns the data that has changed in another place, the job of updating it dyanmically on the frontend is the frontend's job and as such by using only DOM, it is not possible to do so.

- So there comes **State**, which is the data that the backend gives, stores, updates, etc when talking to the backend.
- If there is a way to write a function that takes this **State** as an input and creates the output on the frontend, that is much more powerful than our original approach.
- So the framework _React_ has this thing called **Global State** which contains a list of strings, strings, etc in the form of data, given this we need to update/delete/rewrite the frontend part

- Now we'll be using state to do take the backend data and update it in the frontend

- Constraints of state:

  - state is always an array
  - every element of state in our example will have a title, description and an id

- We are adding the data directly in the html code, but in the real world we'll not have accesss to the data like that and also the data will be chaning very dynamically and as such we will be facing with a lot of devices updating the data every second. So the browser needs to keep refreshing what is new the thing.
- After writing every thing we get to know how react is useful, react does all the heavy lifting of writing all the dom, it just asks you for the state and some other data to add and rest of all the stuff is done by React
- This approach is bad because it clears the DOM, there are many reasons as to why that's bad
- Rather is should be updated based on what's changed, how to do that, by checking the differences between what's changed. Let's say that the first set of objects contained 5 objects in the state but the next set of objects is 3 that got updated, so you need to check them one after another serially to the previous set of objects. So anytime the state changes, calculate the diff and based on the diff update the dom, don't clear it but readd things, but do some other stuff such as update, delete, etc.

  - You need to remember the old todos in a variable, i.e storing the existing state in a **Virtual DOM**. React also does the same thing. So what esssentially happens is that we have the old set of stuff always in memory and the new stuff gets added and then calculate the differences between the both and based on that do something, changes and all.
  - Do the hw

- What is the easiest way to create a dynamic website; These are all of the stuff that we'll have to do in React as well

1. update a state variable(done by devs): Even in react it's needed;
2. delegate the task of figuring out the diff to a hefty function(crux of react): where to call update on/ add on / remove on, etc.
3. Tell the hefty function how to add, update or remove elements(done by devs)

- The part of the code where we have the add/remove/update functions is what is in the library React DOM(for websites) or React-Native(for mobile apps). It tells react that this is how you put things / remove things / add things to the DOM and in case of native applications it tells the way to remove or add things to native applications
- The part where there is a change the state is the main React part
- The last part of the code where we devs write the main logic is our own code and

## React frontend

Now we'll move on to react and see how as a react dev we'll have to write very minimum code instead of writing long dom code and how react makes our lives easier

- We are using _Vite_ which gives a very good starter pack to get started with react

### Directory structure

- in the src directory lies all of the source files/ main files
- main.jsx file:
  - It is a combination of javascript and html which is known as JavaScriptXml, and inside those files we can return html from a function as well as javascript
  - It consists of the react import statement and the react-dom import statement as react is not a website framework, it is a remove difference calculating framework. It is able to calculate that based on the current state something should get removed from the native app/ website or something should get added.
  - It also consists of the react-dom which further says that this framework is currently running for the website

```js
// this is what creates the app function which then gets called to the main.jsx file
function App() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <button onClick={() => setCount((count) => count + 1)}>
        count is {count}
      </button>
    </div>
  );
}

export default App;
```

- Since the above file contains some html code why not just put it in a separate html file why put it in there. Till what we have learnt we haven't wrote anything impressive but we will have to write a lot of JS code to create a dynamic website, most of the html is injected via JS.
- In the DOM stuff we have been creating so many dom stuff and injecting stuff into them, but in react we are doing the same but it is slightly easier in react.
- The dom stuff also returns you a dom object but the

#### About the state variable

- We have created the same counter button which increments on click event in the equivalentCounter html file where this count variable is what is called a "state" sort of, which represents the state of the app.

- The way we define state variables in react is: `const [count, setCount] = useState(0);`. It is a variable that react needs to consciously watch that if this updates then the whole dom changes too, so it needs to monitor it continuously. The actual meaning is the following:

React provides a special function called `useState` that you can call from your component to let it “remember” things.from the tic tac toe eample: Let’s store the current value of the Square in state, and change it when the Square is clicked.

Import useState at the top of the file. Remove the value prop from the Square component. Instead, add a new line at the start of the Square that calls useState. Have it return a state variable called value:

```js
import { useState } from 'react';

function Square() {
const [value, setValue] = useState(null);

function handleClick() {
//...
```

`value` stores the `value` and `setValue` is a function that can be used to change the value. The null passed to `useState` is used as the initial value for this state variable, so value here starts off equal to null.

- now after this syntax: when we press the count button it prints random numbers from 0 to 1

```javascript
import { useState } from "react";
// import "./App.css";

// this is what creates the app function which then gets called to the main.jsx file
function App() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <button
        onClick={() => {
          setCount(Math.random());
        }}
      >
        count is {count}
      </button>
    </div>
  );
}

export default App;
```

- What did the dev had to do instead of writing such big syntax of dom? He/She had to call setCount, update the state variable and then React took care of updating the thing inside the dom, i.e continuously changing the number and replacing it with the new number on click in the button
- The syntax is a bit weird because it follows camel case instead of snake case, then to call the setCount variable to update the state, that is setup in the state and the whole process of reading and writing is taken care of by React. Still the DOM is being updated under the hood, but we are not doing that as a dev, React is taking care of that for us
