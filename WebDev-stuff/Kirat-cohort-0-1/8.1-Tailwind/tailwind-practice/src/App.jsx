import { useState } from "react";
// import "./App.css";

function App() {
  const [count, setCount] = useState(0);

  return (
    <>
      <div style={{ display: "flex", justifyContent: "space-between" }}>
        <div style={{ backgroundColor: "red" }}>heloooooooooo</div>
        <div style={{ backgroundColor: "green" }}>hi</div>
        <div style={{ backgroundColor: "blue" }}>bye</div>
        <div style={{ backgroundColor: "yellow" }}>bye</div>
        <div style={{ backgroundColor: "yellow" }}>bye</div>
      </div>
    </>
  );
}

export default App;
