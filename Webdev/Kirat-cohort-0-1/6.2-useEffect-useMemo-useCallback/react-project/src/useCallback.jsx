// useCallback
import { useState, useCallback, memo } from "react";
import "./App.css";

function App() {
  const [counter, setCount] = useState(0);

  const a = useCallback(() => {
    console.log("hi there");
  }, []);
  // var a = 1;

  return (
    <>
      <button
        onClick={() => {
          setCount(counter + 1);
        }}
      >
        Counter ({counter})
      </button>

      <Demo a={a}></Demo>
    </>
  );
}
const Demo = memo(({ a }) => {
  console.log("re-rendered");
  return <div>hi there {a} </div>;
});

export default App;
