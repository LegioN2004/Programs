# All about Routing, Context-API and Prop Drilling

## Routing

Firstly jargons:

1. Single page applications: Dynamically change data in a site without refetching data from the backend

- The websites made with "React" are an example of single page application. Before React days, whenever we opened any website the request went to the backend server and it returned an index.html, a js file and so on to the client browser(we still get that with React but it is different). Whenever we had to go to lets say a messages section of linkedin like page of the same website, then the the browser had to send another request to the backend and it got another html,js and other files of that page and the client first saw a blank screen after a 'hard reload' and then the new contents got populated. This hard reload to got to another page happenend until React came into the picture.
- React helps us create a single page which gets all the html,css and js and to open another page or tab or section, it doesn't need to send another request to get a new set of html,css and js for that specific page itself, and so it doesn't do a hard reload as well. We are doing the change somehow rather than hard reloading. This is called "client side routing", we are routing on the client that these stuff will render, and the html, css and js are still the same that is able to change the view there.
- So for example, if we go to the linkedin website and go to the messages tab, don't we get any html,css, js, almost. We can optimize the app so that if we click on messages the part of messages or the "bundle" of messages after we click on it, but we don't have to. This is an opitimization, we can choose to not do so that full app's code come together such that the html,css and js file contains the contents of all our pages and even as we change our pages no code comes, only client side routing happens.

2. Client side bundle and routing:

- Client side bundle basically means the bundle that we get from the backend, which basically means the html, css and js. More specifically the js file is what's called the bundle the final big js file which contains all the logic/code for linkedin.com, linkedin.com/messages, etc, all the pages.
- We can optimize it to be of multiple js files linked to each other from one parent but if we want we can make one big js file and shove it all there.
- We get the single js file from the server and do client side routing based on what the user is going to.
- The code that we write as a dev that manages that if the user is on this page then show this, if they're on the landing page show them that then show them that and so on.

## What are Routes

Like backend we had routes, these routes here in React are of the frontend.

Now if we are on different routes we see different things shown on the page and this doesn't happen on reload. This happpens Dynamically on the client side and using routing in react. How does it happen? : It can be done using a library using "react-router-dom". The name itself says that it does react routing inside the DOM means inside the browser. There are many others but the most popular one is the stated one.

- The syntax goes some thing like the following:

```js
function App(){
  return(
    <BrowserRoutes>
    <Routes>
    <Route path="/dashboard" element={<Dashboard />}/>
    <Route path="/" element={<Landing />}/>
    </Routes>
    </BrowserRoutes>
  )
}
```

- In react we are allowed to put components as props to other components and render it inside. Here comes the children. If there is a component 1 and there is a component 2 that takes children as an input, so this component 2 can return a div which renders the children. So we can do as much stuff as we can with the children and it'll be rendered accordingly

- So according to the syntax, "react-router-dom" library provides all the jsx to implement client side routing as per our needs so we get:
  - `<BrowserRouter>` which needs to wrap all the `<Routes>`
  - `<Routes>` needs to wrap all the routes(that are the actual routes that takes us to different pages) like `<Route path="/dashboard" element={<Dashboard />}/>`.
  - and the `<Route path="/route_name" element={<the_element_name_of_the_route_specified/>}>`  which containt every details of the route and what to show
- In the example we have a small 2 page app, that has two routes dashboard and the main page known as landing page, so when we reach to dashboard we route to the dashboard page and landing page routes to the main landing page. This much code is enough to create a dynamic website having client side routing which only gets the bundle once and renders the right page according to the route
- So of all the code that we have added, if we want to make a navbar that remains consistent across all the pages then we can add it as a div with the content above the `<BrowserRouter>` element, and it gives us the desired client side routing with no reload
- But if we do client side routing correctly, then it should not return an index.html file, when going to the dashboard from the landing provided open the page gives us the landing page which itself has its own html

- What we have done to route to pages onClick of a button is the following, where `window.location.href` is the DOM thing, window means current window, location is an object that has a bunch of details that come with it in which href is one of them and if we want to change/go to a route then we can pass in some with quotes and then it'll move our window to that route. But in this process there is a whole reload happening(i.e getting a new html page for another route and so on) which is not what client side routing does. This is as such not the right way to do.

```js
 const landing = () => {
  window.location.href = '/';
 };
 const dashboard = () => {
  window.location.href = '/dashboard';
 };
```

#### `useNavigate()` to the rescue

- In React's way of client side routing we don't refetch data from the server, so inplace of location.href we use React's own `useNavigate()` hook.
- As the name suggests, it lets you to navigate from one route to another and it can be imported from react-router-dom
- This route takes care of the client side routing, making sure that there is no hard reload of the page, it simply changing the route, keeping the same client bundle and changing the page because the route has changed. This is the correct way to do routing so that the router doesn't fetch the index.html, css and js bundle again and again
- rules
  - It expects us to invoke the `useNavigate()` i.e the variable that is initialized to it, inside the `<BrowserRouter>` only, and anywhere outside will give us an error. It'll not also allow a component that is using `useNavigate()` outside the `<BrowserRouter>`. So to fix that we can directly initialize the useNavigate inside that custom component that will need it then pass that component directly in the BrowserRouter with the necessary logic
  - In this way we can make a client side routing which doesn't reload on change in routes, which is also the right way to do routing

    ```js

  function App() {
  return (
    <div>
    <div>this is the navbar</div>
    <BrowserRouter>
      <AppRouter></AppRouter>
      <Routes>
      <Route path="/dashboard" element={<Dashboard />} />
      <Route path="/" element={<Landing />} />
      </Routes>
    </BrowserRouter>
    </div>
  );
  }

  function AppRouter() {
  const navigate = useNavigate();
  return (
    <div>
    <button onClick={() => { navigate('/'); }} >
      landing
    </button>
    <button onClick={() => { navigate('/dashboard'); }} >
      dashboard
    </button>
    </div>
  );
  }
    ```

#### lazy-loading

- There is another thing with useNavigate which is known as lazy-loading seen in a bunch of websites
- The way we have written the code is that it returns a complete bundle all at once that is all the html, css and js files, then the logic does all the routing and other stuff on the client side.
- The problem here is that the person will not always access all the routes/links/pages/tabs etc on the site, they may only come to see the landing page only, so why get all the whole bundle from the server that includes so many unnecessary stuff including the landing page logic.
- So it would be nice if there is a website which has 20 different pages and if there is a way that the person receives page 1 logic only when he visits page1 and nothing else, similarly when he visits page 2 then he'll receive page 2 logic only, so on and so forth. This would be an optimal solution by not giving the whole bundle, and only giving a smaller bundle to them when needed and only that part which has been accessed, i.e incrementally giving them the website in parts rather than the whole. This was a common usecase so 'react-router-dom' introduced "**Lazy Loading**" which basically states we can change our code a little bit and it'll make sure that if the person is on page 1 then they'll get the main react code and the code for the page 1 and if they go to page 2 they'll go the extra code of page 3, so on and so forth. They'll lazily load the code of the page that the person is not currently on.
- the way to write is that by wrapping inside the `React.lazy()` function which takes in the extra component/route that needs to be lazily loaded i.e only access when needed: `const Dashboard = React.lazy(() => import('./components/Dashboard'));`(this dashboard now is a component), after doing this we need to write this lazy applied route variable(actually component) name "Dashboard" in the route element so that it applies properly and but keep the main route path same.
  - Here we get an error because the route data is in the backend and it depends on the internet of the user how fast they'll get the data when it is lazy loaded. So for that we have the `<Suspense fallback={"some message/ something else / animations ,etc"}>` which basically says that if that component (lazy loaded) data has been suspended, not yet there, going to come eventually, then render the callback which is kind of a message for the client. So we need to use suspense here. This makes it a mildly more optimized client side routing application
- By doing this we will have a more optimized site with lazy loading
- Also we need to add `default` which is available to apply to only once. We need to apply `default` to the dashboard `export default function Dashboard(){}` so that we can import it like the above in the lazy syntax. But if we do the standard array destructuring syntax type import then it just returns a no const exports( including the function which is also a const export when not used default on it) which can be many but `default` is only one. We can send const exports with default lke `import Dashboard, {x ,y, } from "./some/file"` but the usage in the main file only differs that(like special lazy usage, etc)
- fetching different data for different routes logic will be included in that routes/component's file/definition itself only, so that lazy works for all. We'll still need to fetch data even if we use client side routing but this will be fixed with next where it becomes untrue
- We can confirm the lazy loading by clearing the network tab and then pressing one only fetches one component
- NOTE: that lazy loading only happens for the frontend code so as to make the website performant, it has nothing to do with the backend data in json, which is already very small so doesn't matter if we get the whole chunk or a small part of it only for the frontend which needs it.

## Prop drilling

Before we begin, how do you think one should one manage state?

1. Keep everything in the top level component (C1)
2. Keep everything as low as possible
 (at the LCA of children that need a state)

eg: As our app grows, like an app like linkedin we'll have a very big object containing all sorts of object like notifications, requests, connection requests, current connnection, etc. Where should be store this very big object lets say individual state variables, should be store in App.jsx or some child components, where should be stored.
The ans should be that keep everything as low as possible or push down as much as possible, eg: if we have something like linkedin and it has the feed component that has a feed state that updates the feed dynamically on scrolling and it is stored in app.jsx then updating the feed will cause the whole app to re-render, eventually re-rendering the children as well, instead we can push the state to the feed component itself so that the whenever the feed component re-renders only when the feed variable changes. Since the ones not dependent on feed should not re-render so pushing state is necessary. We'll store it in the "Least Common Ancestor"

- In the code shown in the video: we are creating a counter like the hw with two buttons to increment and decrement that count to showcase prop drilling
  - wrote all the code necessary
  - now when we try to move the button to the count component, then we'll also need the state to pass down to the Count component so we'll need to pass the count(because it is being used) and setCount which is not being used also as a prop so that button can use it inside the Count comp. This is where things get ugly, lets say we have a big nested chain of components and they're using the state from the parent component, then we'll have to pass them again and again throughout the chain and that becomes visually disturbing.
  - This is called 'prop drilling' which just drills the state into the components props. This is an antipattern because of how unmanageable and unreadable it makes the code. It has nothing to do with re-rendering, just because of its syntax it should be highly avoided

  - official documentation: Passing props is a great way to explicitly pipe data through your UI tree to the components that use it. But passing props can become verbose and inconvenient when you need to pass some prop deeply through the tree, or if many components need the same prop. The nearest common ancestor could be far removed from the components that need data, and lifting state up that high can lead to a situation called “prop drilling”.

## Context API

The Context API lets us fix prop drilling. We use it because it makes it very easy to pass state variables between components without drilling them down, it lets us 'teleport' state components . With React's context feature, we can do that

If we use the context API, we’re pushing our state management outside the code react components which is what recoil lets us do and It also lets us teleport state components directly from the parent to the children be it nested very far down the chain without even reaching the middle child components that come in the way. But its main use is to make the code more readable but recoil/redux or any state management library helps us make the code more performant because it has 10 different optimizations done on top of it

- In the file that we have written the nested child components we will now need to find a way to pass in the state without using the middleman children. So we will define it in another file that will make this context API working like context.jsx using the export const syntax like the following

```js
import { createContext } from "react";

// this is the teleport thing that we have created
// we can give the initial value as 0 here
export const CountContext = createContext(0)
export const CountContext2 = createContext(0)
// to pass in more stuff
export const CountContext = createContext({
 count:0 , setCount:0,
});
```

- How to do this:
- defining part
  - Now we'll also need to access this teleported value in the nested children chain, so we'll need to wrap the teleported value inside a "provider". What is a "provider": something that "provides" the context value later on.
  - Basically we need to define the context in a another file and then import it to the main file where we want to use it and then like react-router-dom we need to wrap that component with the ones where we want to pass in the context using the syntax `<CountContext.Provider value={count} >keep the components here</CountContext.Provider>`(here 'CountContext' with which we just passed in the context can be any name as per your needs).
  - So the components that want to use that teleported value must be between those provider components and the provider syntax should also pass a prop that will contain the states that needs to be teleported since react can't magically provide them. Then we can use that `value`(which is also a react thing) to use that state from the parent in the children. If you want to pass in more stuff as the context then you can set more context consts or just add them in one with the correct name using array destructuring. Then in the same way increase the no of stuff passed in the `value` using the same array destructuring and then adding stuff separated by commas.
    - There is an error regarding the array destructuring in the context file, look at the end of this README file
  - Also that `Provider` is an object which is a React thing on context definition in a separate file returns which we can then use in the main App component in xml like syntax.

  ```js
  function App() {
    const [count, setCount] = useState(0);
    return (
      <>
        <div>
          hi there
          <CountContext.Provider value={count}>
            <Count setCount={setCount}></Count>
          </CountContext.Provider>
        </div>
      </>
    );
  }
  ```

- Then in the context usage part we have
  - The place where we want to use that value(nested children in the chain), we need to call in the `useContext()` hook from "React" and initiaize it to the variable that wanted that state value and then we need to pass in the context for which value we want, which in our case is `CountContext` to the parentheses. So now we don't neeed to pass in the prop for the first child component `Count` to get the state to the one nested to that children, i.e `CountRenderer` and `Button`.
  - To use more context state vars we can pass in their names using the array destructuring syntax and use them accordingly

  ```js
  function Count({ setCount }) {
    return (
      <div>
        <CountRenderer />
        <Buttons setCount={setCount}></Buttons>
      </div>
    );
  }

  // this part is of prop drilling and context api
  function CountRenderer() {
    const count = useContext(CountContext);
    // const { count, setCount } = useContext(CountContext);
    return <div>{count}</div>;
  }

  function Buttons({ setCount }) {
    const count = useContext(CountContext);
    return (
      <div>
        <button onClick={() => setCount(count + 1)}>Increment</button>

        <button onClick={() => setCount(count - 1)}>Decrement</button>
      </div>
    );
  }
  ```

  - Most of the times we'll see that the context object is a very big complex object that has a bunch of state to teleport to places in the project
- This is all React had to offer to make our application more structured and clean. But people realized that this still wasn't enough so Recoil, Redux was introduced and they provides 10 more benefits on top of providing context API by getting rid of prop drilling. But if we want to go more advanced by not using these libraries for efficient state management, then we should go for "reducer" and "useReducer" hook in the React docs, we don't need these but its good to know since projects use them.

## misc and silly errors

### more chatGPT stuff

#### Context API Overview

1. **Purpose of Context API:**
   - The Context API in React is designed to address the problem of prop drilling, making it easier to pass state or values down the component tree without explicitly passing them through each intermediate component.

2. **Provider and Consumer:**
   - The Context API involves two main components: the **Provider** and the **Consumer**.
   - **Provider:** Wraps the components that need access to a particular context, providing the context's value to them.
   - **Consumer:** Components that want to access the context's value use the `useContext` hook or the `Consumer` component.

3. **Creating a Context:**
   - A context is created using the `createContext` function.
   - Example:

     ```jsx
     import { createContext } from "react";
     export const CountContext = createContext();
     ```

     - Here, `CountContext` is a context created with `createContext`.

4. **Provider Usage:**
   - Wrap the part of the component tree where you want to share the context using the `<CountContext.Provider>` component.
   - Example:

     ```jsx
     <CountContext.Provider value={count}>
       {/* Components that can now access CountContext value */}
     </CountContext.Provider>
     ```

     - `value={count}` provides the current value of the context to the components wrapped by the provider.

5. **Consumer Usage:**
   - Use the `useContext` hook or the `Consumer` component to access the context value.
   - Example:

     ```jsx
     const count = useContext(CountContext);
     ```

     - `count` now contains the value provided by the `CountContext.Provider`.

#### File Definitions and Exports

1. **Export Default vs. Export Named:**
   - `export default` is used to export a single value or function as the default export of a module. It's commonly used when there's a main export.
   - `export const` is used to export named constants, variables, functions, or objects. It allows you to have multiple named exports in a module.

2. **File Definitions:**
   - A file can have one default export and multiple named exports.
   - Example:

     ```jsx
     // context.jsx
     import { createContext } from "react";
     const CountContext = createContext();
     export default CountContext; // Default export

     export const MAX_COUNT = 10; // Named export
     export const MIN_COUNT = 0; // Named export
     ```

#### Importing Context in Another File

1. **Using Default Export:**
   - When a file has a default export, you import it without curly braces.
   - Example:

     ```jsx
     // AnotherFile.jsx
     import CountContext from "./context"; // Default import
     ```

2. **Using Named Exports:**
   - Named exports are imported with curly braces and the exact export name.
   - Example:

     ```jsx
     // AnotherFile.jsx
     import { MAX_COUNT, MIN_COUNT } from "./context"; // Named imports
     ```

3. **Using Both Default and Named Exports:**
   - Example:

     ```jsx
     // AnotherFile.jsx
     import CountContext, { MAX_COUNT, MIN_COUNT } from "./context";
     ```

These practices make it clear whether you're dealing with a default or named export in your imports.

Your understanding of the Context API and its application in React components is accurate. The use of `useContext`, `Provider`, and `Consumer` components helps create a more flexible and cleaner code structure

##### first error

In React, when you define a functional component, the convention is to use curly braces `{}` when accessing and rendering the values of props. This is because props are typically passed as an object, and React expects you to destructure them or use the full object with braces when accessing their values.

In your case, if you're trying to render the `count` prop directly without using braces, you might encounter an error because React interprets it as an attempt to render an object directly, which is not allowed.

Here's the corrected version of your `Count` component:

```jsx
function Count({ count }) {
  return (
    <div>
      {count}
    </div>
  );
}
```

In this corrected version, `{ count }` uses destructuring to extract the `count` prop from the props object. This is the standard way to access props in a functional component.

When you use `{ count }`, it's equivalent to writing `{ props.count }`. However, the destructuring syntax is cleaner and more concise. If you don't destructure the prop and try to render it directly, you might encounter the error you mentioned.

So, always use curly braces when accessing and rendering the values of props in a functional component
-----------

##### error regarding context api array destructuring

The error you're encountering is because you are attempting to destructure properties (`count` and `setCount`) from an object that is provided as the default value for the `createContext` call. However, the properties `count` and `setCount` are not defined within that object.

When you define a default value for a context using `createContext`, it's important to ensure that the properties you intend to use are properly defined within that default object.

In your case, it seems like you want to provide a default object with `count` and `setCount` properties, but you are assigning `0` to `setCount`, which should be a function.

Here's a corrected version:

```jsx
import { createContext } from 'react';

// Default value with count and setCount properties
export const CountContext = createContext({
  count: 0,
  setCount: () => {}, // Placeholder function
});
```

Now, the `setCount` property is initialized as an empty function. It's important to note that this is just a placeholder, and the actual value of `setCount` should be set dynamically when you use the `Provider` component to wrap your components.

When you provide the actual value for the context using the `Provider`, you will replace the placeholder function with the actual function that modifies the `count` state.

Example usage in a component:

```jsx
import React, { useContext } from 'react';
import { CountContext } from './yourContextFile';

function YourComponent() {
  const { count, setCount } = useContext(CountContext);

  // Now you can use count and setCount in your component
  // ...
}
```

Ensure that you are using the correct values when you provide the context value using the `Provider`.
