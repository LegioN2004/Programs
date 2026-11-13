import { useState, useEffect } from "react";
import "./App.css";
import axios from "axios";

function App() {
  return (
    <>
      <Todo id={1}></Todo>
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
  }, []);

  return (
    <>
      <h1>{todo.title}</h1>
      <p>{todo.description}</p>
    </>
  );
}

export default App;
