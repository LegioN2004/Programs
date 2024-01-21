/* todos =  [ // structure
    {
        title: "go to gym"
        description: "go to gym"
    }
]
*/

export function Todos({ todos }) {
  return <div>
      {todos.map(function(todo) {
        return <div>
            <h1>{todo.title}</h1>
            <p>{todo.description}</p>
            <button>{todo.completed == true ? "Completed" : "Mark as Complete"}</button>
          </div>
      })}
    </div>
}
