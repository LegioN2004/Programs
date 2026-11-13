// pagination
import { useState, useEffect, useMemo } from "react";
import "./App.css";

function App() {
  const [counter, setCount] = useState(0);
  const [input, setInput] = useState(1);
  // const [finalValue, setFinalValue] = useState(1);

  // useEffect(() => {
  //   let finalCount = 0;
  //   for (let i = 0; i <= input; i++) {
  //     finalCount = finalCount + i;
  //   }
  //     setFinalValue(finalCount)
  // }, [input])

  let count = useMemo(() => {
    let finalCount = 0;
    for (let i = 0; i <= input; i++) {
      finalCount = finalCount + i;
    }
    return finalCount;
  }, [input]);
  return (
    <>
      <input
        type="text"
        onChange={(e) => {
          setInput(e.target.value);
        }}
        placeholder="Find sum from 1 to n"
      />
      <br />
      sum from 1 to {input} is {count}
      <br />
      <button
        onClick={() => {
          setCount(counter + 1);
        }}
      >
        Counter ({counter})
      </button>
    </>
  );
}

export default App;
