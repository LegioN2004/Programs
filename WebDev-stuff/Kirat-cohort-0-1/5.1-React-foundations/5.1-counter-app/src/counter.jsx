import { useState } from "react"; // this is the hook to define the so that we can use it

function App() {
  const [count, setCount] = useState(0);
  // return <button onClick={onClickHandler}>Counter {count}</button>; // we  can now not use this and just render our own custom button which has turned into an elements
  return (
    <div>
      <CustomButton count={count} setCount={setCount}></CustomButton>
    </div>
  );
}

// component
function CustomButton(props) {
  function onClickHandler() {
    // count++; // this is not the right way to set
    props.setCount(props.count + 1);
  }
  return <button onClick={onClickHandler}>Counter {props.count}</button>;
}

export default App;
