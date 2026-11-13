import "./App.css";

function App() {
  return (
    <>
      <Todo
        title="hello"
        description="byeeeeeeeeeeeeeeeeeeeee"
        done={true}
      ></Todo>
      <Todo
        title="go to gym"
        description="go to gym nowwwwwwwww"
        done={false}
      ></Todo>
    </>
  );
}

interface Todos {
  title: string;
  description: string;
  done: boolean;
}
function Todo(todos: Todos) {
  return (
    <div>
      <div>{todos.title}</div>
      <div>{todos.description}</div>
      <div>{todos.done}</div>
    </div>
  );
}

export default App;
