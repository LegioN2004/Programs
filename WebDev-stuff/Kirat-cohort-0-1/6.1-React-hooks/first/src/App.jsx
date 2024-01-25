// better todo
import { useEffect, useState } from "react";
import "./App.css";

function App() {
  const [todos, setTodos] = useState([]);
  useEffect(() => {
    setInterval(() => {
      fetch("https://sum-server.100xdevs.com/todos").then(async (res) => {
        const json = await res.json();
        setTodos(json.todos);
      });
    }, 10000);
  }, []);

  return (
    <>
      {todos.map((todo) => (
        <Component
          key={todo.id}
          title={todo.title}
          description={todo.description}
        ></Component>
      ))}
    </>
  );
}
function Component({ title, description }) {
  return (
    <>
      <h3>{title}</h3>
      <br />
      <p>{description}</p>
    </>
  );
}

export default App;
