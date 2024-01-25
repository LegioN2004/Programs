import { useState } from "react";
import "./App.css";

function App() {
  return (
    <div>
      <HeaderWithButton></HeaderWithButton>
      <Header title={"heloooo"}></Header>
      <Header title={"heloooo1"}></Header>
      <Header title={"heloooo2"}></Header>
      <Header title={"heloooo3"}></Header>
      <Header title={"heloooo4"}></Header>
    </div>
  );
}

function HeaderWithButton() {
  const [title, setTitle] = useState("My name is harkirat");
  function onClick() {
    setTitle("My name is " + Math.random());
  }
  return (
    <>
      <button onClick={onClick}>change name</button>;
      <Header title={title}></Header>
    </>
  );
}

const Header = React.memo(function ({ title }) {
  return (
    <div>
      {/* <button onClick={onClick}>click me</button> <br></br> */}
      {title}
    </div>
  );
});

export default App;
