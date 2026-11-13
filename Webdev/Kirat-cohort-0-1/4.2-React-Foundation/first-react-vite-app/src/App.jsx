import { useState } from "react";
// import "./App.css";

// this is what creates the app function which then gets called to the main.jsx file
function App() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <button
        onClick={() => {
          setCount(Math.random());
        }}
      >
        count is {count}
      </button>
    </div>
  );
}

export default App;
