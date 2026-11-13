import { useState } from "react";
import "./App.css";

function App() {
  return (
    <>
      <CardWrapper>
        <CardWrapper>
          <div>hi there</div>
        </CardWrapper>
      </CardWrapper>
      <CardWrapper>
        <div>byeeeeeeeeeeeeee there</div>
      </CardWrapper>
      <CardWrapper>
        <MoreWrapper></MoreWrapper>
      </CardWrapper>
    </>
  );
}

function CardWrapper({ children }) {
  return (
    <div style={{ border: "2px solid black", padding: 17 }}>{children}</div>
  );
}

function MoreWrapper() {
  return <>hiiiiiiiiiiiiiiii from MoreWrapper</>;
}
export default App;
