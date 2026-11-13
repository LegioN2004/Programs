import { useState } from "react";
import "./App.css";

let counter = 4;

function App() {
  const [todos, setTodos] = useState([
    {
      id: 1,
      title: "go to gym",
      description: "go to gym today",
    },
    {
      id: 2,
      title: "go to gym",
      description: "go to gym today",
    },
    {
      id: 3,
      title: "go to gym",
      description: "go to gym today",
    },
  ]);

  function addTodo() {
    return setTodos([
      ...todos,
      {
        id: counter++,
        title: Math.random(),
        description: Math.random(),
      },
    ]);
  }

  return (
    <>
      <div>
        <button onClick={addTodo}>Add a todo</button>
        {todos.map((todo) => (
          <Todo
            key={todo.id}
            title={todo.title}
            description={todo.description}
          ></Todo>
        ))}
      </div>
    </>
  );
}

function Todo({ title, description }) {
  return (
    <>
      <h1>{title}</h1>
      <p>{description}</p>
    </>
  );
}

export default App;
