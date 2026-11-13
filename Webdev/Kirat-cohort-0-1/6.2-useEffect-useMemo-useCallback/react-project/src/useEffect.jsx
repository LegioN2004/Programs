// pagination
import { useState, useEffect } from "react";
import "./App.css";
import axios from "axios";

function App() {
  const [count, setCount] = useState(1);
  return (
    <>
      <button type="button" onClick={() => setCount(1)}>
        1
      </button>
      <button type="button" onClick={() => setCount(2)}>
        2
      </button>
      <button type="button" onClick={() => setCount(3)}>
        3
      </button>
      <button type="button" onClick={() => setCount(4)}>
        4
      </button>
      <Todo id={count}></Todo>
    </>
  );
}
function Todo({ id }) {
  const [todo, setTodo] = useState({});
  useEffect(() => {
    axios
      .get(`https://sum-server.100xdevs.com/todo?id=${id}`)
      .then((result) => {
        setTodo(result.data.todo);
      });
  }, [id]);

  return (
    <>
      <h1>{todo.title}</h1>
      <p>{todo.description}</p>
      <h4>{id}</h4>
    </>
  );
}

export default App;
