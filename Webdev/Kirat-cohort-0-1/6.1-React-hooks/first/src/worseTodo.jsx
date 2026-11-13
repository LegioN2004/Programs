import { useEffect, useState } from "react";
import "./App.css";

function App() {
  const [todos, setTodos] = useState([]);
  useEffect(() => {
    button();
  }, []);
  function button() {
    fetch("https://sum-server.100xdevs.com/todos").then(async (res) => {
      const json = await res.json();
      setTodos(json.todos);
    });
  }

  return (
    <>
      <div>
        <Component value={todos}></Component>
        <button onClick={button}>click me to updat</button>
      </div>
    </>
  );
}

function Component({ value }) {
  return (
    <>
      {value.map((todo) => {
        return (
          <div>
            {todo.title}
            <br />
            {todo.description}
            <br />
            {todo.completed}
            <br />
          </div>
        );
      })}
    </>
  );
}

export default App;
