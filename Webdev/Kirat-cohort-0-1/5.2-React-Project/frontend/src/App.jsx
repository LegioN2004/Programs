import { useState } from 'react'
import './App.css'
import { CreateTodo } from './Components/CreateTodo'
import { Todos } from './Components/Todos'

function App() {
  const [todos, setTodos] = useState([])

  // buggy way to do this
  // fetch("http://localhost:3000/todos").then(async function(res) {
  //  const json = await res.json()
  //  setTodos(json.todos)
  // });

  return (
    <div>
      <h1>A fullstack todo app</h1>
      {/* creating a todo */}
      <CreateTodo></CreateTodo>
      {/* redering those todo */}
      <Todos todos={todos}></Todos>
    </ div>
  )
}

export default App
