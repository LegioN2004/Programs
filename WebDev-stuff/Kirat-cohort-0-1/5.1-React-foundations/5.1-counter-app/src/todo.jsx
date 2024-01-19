import { useState } from "react"; // this is the hook to define the so that we can use it

function App() {
  const [todos, setTodos] = useState([
    {
      title: "go to gym",
      description: "go to gym from 7 to 9",
      completed: false,
    },
    {
      title: "Study DSA",
      description: "study dsa from 9 to 11",
      completed: true,
    },
    {
      title: "Study DSA",
      description: "study dsa from 9 to 11",
      completed: true,
    },
  ]);
  function addTodo() {
    setTodos([
      ...todos,
      {
        title: "new todo",
        description: "noarsetnaeir",
      },
    ]);
  }
  return (
    <div>
      {/* <Todo title={todos[0].title} description={todos[0].description}></Todo>
      <Todo title={todos[1].title} description={todos[1].description}></Todo> */}
      <button onClick={addTodo}> Add a random todo</button>
      {todos.map(function (todo) {
        return <Todo title={todo.title} description={todo.description}></Todo>;
      })}
    </div>
  ); // most noob way
}

// todo component
function Todo(props) {
  return (
    <div>
      <h1>{props.title}</h1>
      <p>{props.description}</p>
    </div>
  );
}

export default App;
