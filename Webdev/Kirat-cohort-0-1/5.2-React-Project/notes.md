# Creating a todo application with authentication, and CRUD support

- Whenever a client comes with a request with lets say creating a todo application firstly we should start with the backend

## Backend using node, express, mongoose, mongoDB, jwt

- First after creating a backend folder, we should start with initializing a node project, which means put a package.json file(very important file) because it contains a lot of details about the application you are building like dependencies, scripts, etc
- Then run the command in the backend folder to initialize a backend project in node.js which is `npm init`, which upon entering asks a lot of questions like:

  - package name: what shall be the folder name of the backend
  - version: not important for now but will be in the future when we'll be deploying our stuff
  - description: write something about the app
  - then it will ask somethings which are not that important for this time, but may be in the future:
    - entry point:
    - test command:
    - git repository:
    - keywords:
    - author: write your name
    - license:
  - Then this creates a package.json template for your backend and shows it for preview
  - Then just write yes to create your package.json
  - This package.json is the same as the javascript object that has a key value pairs and it contains all the details in it.
  - Among all of them, the dependencies part is the most important for now, it has the entries of all the external dependencies added to the application where the package.json lies
  - `npm install package_name` is the command used to find the things/dependencies that is not bundled with node.js and when we feel like we need them we pull from the internet to our machine using this command. Also installing like that will fill our package.json with all the details of the dependencies and as such when we need to install the dependencies again on another machine we can just do `npm install` without any other params and npm will go to our package.json and install everything listed under the dependencies key.
    - For our project we'll need express, jsonwebtoken so we will pull them using npm. Also when we install we see a new folder being created called the 'node_modules' which contains all the dependencies but we'll also see that there are a lot of extra stuff added alongwith what we installed because express also has its package.json which contains its own dependencies since express people didn't want to write everything from scratch
    - package.json contains and exhaustive list of all the dependencies and when you want to share we don't share the dependencies folder, the person on the other side can just `npm install` and all the dependencies will come with the help of our package.json which is the only thing needed to share
      - Also a thing inside the dependencies part has something like this after the dependencies name `^` and then the version number. It means that put this package with the same number or anything above if present, as more and more express versions come give me more and more versions
      - The 'package-lock.json' locks the dependencies version, it says that whatever 'package.json' has set is fine, this is the final running on my machine and if this is pushed to github and someone downloads dependencies using this 'package.json' then he will get the same version of dependencies. This is done so that the version remains same throughout the devices whenever this project is setup or wherever it is deployed.

- **Express**
  - Now we have create a file index.js which will contain all the express server stuff and
- **Zod**

  - we'll also create a new file called types.js which contains all the types for taking in data of the todos and updating of data using zod library

    - but we'll need to import that to the main file so that it can access it for taking in correct data and for that out of the many styles we'll use the following syntax

    ```js
    module.exports = {
      createTodo: createTodo,
      updateTodo: updateTodo,
    };
    ```

    - now we'll use the syntax to pull in the exported variables in the main file for parsing correct input: i.e `const { createTodo } = require("./types.js");`

- **Mongoose & MongoDB**

  - created a new db file that contains the connection to the db and a schema for defining the types of the data
  - **note**: this is not how you define a schema and also you don't push this to github, it happens from a dotenv file in a production level app. We are doing this to quickly start our app
  - The thing to note there is the way to export the schema and for that took ref from this [website](https://stackoverflow.com/questions/74780320/how-do-i-get-my-mongo-schema-to-export-into-a-file-then-use-it-to-insert-data) which says to do this

    - module.exports is not a function.

      ```js
      module.exports = User;
      //  or
      // if key and the value are the same we can write this
      module.exports = { User };
      ```

      - if you do the first one, then required should be like this,

      ```js
      const User = require("./assets/js/data");
      ```

      otherwise

      ```js
      const { User } = require("./assets/js/data");
      ```

  - Now we'll also need to make the todo creation async or else if the db fails then the server will still show that the todos has been created
  - Also hitting from the db to get all the todos using `find` will also take some time and as such it returns a promise which will eventually resolve upon getting the data. So we must naturally async await in that finding of data
  - The completed endpoint updates the todo with the "id" which is autogenerated by mongoDB using the variable(kinda) called `_id` for every entry in the table and as such we can use that to uniquely identify the things in the table of the db, and now we can update it to be `completed: true`.

    - Also you can set the default value in the db entry directly using the syntax below

    ```js
    const todoSchemaModel = new mongoose.Schema({
      description: String,
      completed: {
        type: Boolean,
        default: false,
      },
    });
    ```

    - some misc stuff regarding

### now the frontend using React, vite

- The frontend part also has the package.json file which contains all the dependencies setup by vite, the bundler. So it contains all the react stuff in the dependencies which is the main and devDependencies which is for the developers which contain react as well as other stuff needed by devs when developing or testing out the application, one of them is vite itself which is the app bundler

  - In production we don't need vite or any of the devDependencies

- Creating a new folder for Components, so as to keep all the custom components in that

  - The filename in different folders should start with capital letters and the file extension should be .jsx
  - Also we have written some xml in the new file but to use it we need to export the file so that other files can use it, so we can use the previous `module.exports` syntax or in the more modern syntax being directly exporting the function when initializing it like:
    - function should have a name starting with caps as the filename
  - also using the default styling from vite with some mixed styling from my head

  ```js
  export function CreateTodo() {
    return (
      <div>
        <input type="text" placeholder="title" /> <br />
        <input type="text" placeholder="description" /> <br />
        <button>Add a todo</button>
      </div>
    );
  }
  ```

- another main component, that will render all our todos, i.e put them in the dom. So making a separate file called 'Todos.jsx'
- we'll not have static todos by dynamic todos so we'll need to add them dynamically so we'll need to do something like `const todos = props.todos` after taking props in the component as the state variable param or the modern way to do this is we can just directly take todos and destructure its array of objects directly in the function params(whoever is rendering Todos just pass it the todos as an input where todos will be an array)`export function Todos({todos})`
- we'll need to get rid of that todos, since we want to update the todos and add them one after the other dynamically from the state and so we'll need new syntax
- So we are again using the map function to iterate over all the todos ( todos' indexes which the map function does) using the map function that takes in a param of the todos, then we can use the `todo` variable from the function that contains the props to send the next set of keys like 'title' and 'description' to the desired elements and then render them accordingly and dynamically; and then it maps the child to the parent div
  - or we can write the divs and their children repeatedly with the index of the array but that will violate DRY, so we can instead use the map function to iterate over the whole array
  - note: when returning elements in jsx always encolse it in parentheses, it can only return one parent element so it should have one parent element for the other children, or lets say some sub parents that have the children inside but you need to have one parent element above all, since using two parent divs for children is not allowed in jsx

```js
return (
  <div>
    {todos.map(function (todo) {
      return (
        <div>
          <h1>{todo.title}</h1>
          <p>{todo.description}</p>
          <button>
            {todo.completed == true ? "Completed" : "Mark as Complete"} // the
            above is an if else like statement and is a conditional statement
          </button>
        </div>
      );
    })}
  </div>
);
```

- We are almost done with the todo dynamic addition logic, the last thing we need to do is using the state variable hit the backend and so first we'll do it the wrong way using fetch api. So we set up the state variable as `const [todos, setTodos] = useState([])`(**note**: we need to set useState as per our needs, here we need the array to just add the arrays inside it so we setup the state variable like that, if we need )

  - The hard thing is to hit the backend, get the current set of `todos` and call `setTodos` with the current set of todos. hitting the backend, getting the current set of todos and updating the state
  - Wrong way: using fetch hit the backend. this is the wrong way to send a request in an express application because once we fetch it updates the state inside the fetch request itself after the promise resolves and so it re-renders the whole application and then again control reaches the fetch again does the above and this continues in a infinite cycle which is a major bug in our implementation.
    - This is solved by a hook called `useEffect` which is another hook like `useState`, for getting rid of this error
  - It also gives a **CORS** error which means in high level that you cannot hit the frontend url with another backend url unless the backend allows the frontend to do so

  ```js
  // buggy way to do this
  fetch("https://localhost:3000/todos").then(async function (res) {
    const json = await res.json();
    setTodos(json.todos);
  });
  ```

  - so we'll need to install cors package using npm,(will be covered in more detail later on) and then use the cors package by importing and adding global catch in our backend at the very top. By doing that it'll be vulnerable, because any frontend can hit our backend, not necessarily the 'localhost:3000'(where it is hosted), we can also hit this from our mobile-app/postman. But when we try to "silently send request/ silently hit" it from another localhost that is not 3000 (5173 in our case for react-vite project), then we'll see cors error, then your backend will have to allow everyone, or we can allow only one by saying `app.use(cors({ origin: "http://localhost:5173"}))`

- good practice: never pass props from child to the parent, it goes from parent to the child.
- Now to get the title and description field added when button is clicked can be done by doing the following by adding setting up id of the title and description inputs and then putting everthing inside the fetch in the body:

  ```js
  <button
    onClick={() => {
      fetch("http://localhost:3000/todos", {
        method: "POST",
        body: JSON.stringify({
          // not the cleanest way to write since react was made to get away from this
          title: document.getElementById("title").innerHTML,
          description: document.getElementById("description").innerHTML,
        }),
        headers: {
          "Content-type": "application/json",
        },
      }).then(async function (res) {
        const json = await res.json();
        alert("Todo added");
      });
    }}
  >
    Add a todo
  </button>
  ```

  - But since react was made to not use this syntax so we get two different methods to do this the right way:
    - slightly unoptimal but widely used way is we create local state variables here
    - and optimal way called 'React Query'

- slightly unoptimal way:

  - we can make the different things that are required in the body as a in memory state variable
  - this is slightly unoptimal because it causes a lot of re-renders since everytime the title variable updates it will re-render the whole component since it is a state variable, but the DOM way didn't do any re-renders and the "React" thumb of rule is 'minimizing the no of re-renders'

  ```js
  const [title, setTitle] = useState("");
  const [description, setDescription] = useState("");
  ```

  - So we will use something called `onChange(function(variable){})` which gets triggered when there is a change in the element in which it is placed, in our case when our field input gets changed it'll trigger it then by using the variable sent as the param inside the function of the `onChange` event it will get the value and then we can use `const value = variable.target.value` to get the value in the field. Event.target is that specific dom element. Then we can do is `setTitle(e.target.value)`

- After setting up the in-memory state variables we can get the inputs in the following manner
- what we are doing here is that anytime there is a change in input, we set the value in the in-memory state variables like setDescription/setTitle so that the global state variable changes, and when sending the request it sets the global state title and description
  - we have to setup the fetch request url there in between the double quotes, then we need to set up the method as post request
  - The proper way to send body is to also stringify it, but why stringify it; because body stringify is how fetch works and it doesn't auto tell the backend that this is json data, the app.use(express.json()) checks the data if the header is json or not, if no it ignores it
  - And then the headers will be required as well (that specific), otherwise the backend will not be able to identify the type of data as json
  - and then async await to push them after fetch promise resolves

```js
<button
  onClick={() => {
    fetch("http://localhost:3000/todos", {
      method: "POST",
      body: JSON.stringify({
        title: title,
        description: description,
      }),
      headers: {
        "Content-type": "application/json",
      },
    }).then(async function (res) {
      const json = await res.json();
      alert("Todo added");
    });
  }}
>
  Add a todo
</button>
```

- **note**
  - The new in-memory state variable that we have created only re-renders the its parent component i.e sub-parent as a whole `CreateTodo` only, not the main `App` component since it doesn't update the global state variable of the `App` component, and it is re-rendering the CreateTodo inifinitely. If it had any child components then they'll also re-render
    - As we get to state management we will know more about how to optimize this further.
  - If we use "Axios" then we'll get much easier syntax to work with
  - render network for free backend
  - vercel or netlify for free frontend

#### Things to fix

- The biggest thing missing is we are sending infinite requests
- not yet implemented updateTodos
