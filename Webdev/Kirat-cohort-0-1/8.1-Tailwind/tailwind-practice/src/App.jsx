import "./App.css";
import { RevenueCardMain } from "./components/RevenueCardMain";
import { RevenueCardNotMain } from "./components/RevenueCardNotMain";
import { Navbar } from "./components/Navbar";

function App() {
  return (
    <>
      <div className="grid grid-cols-1 lg:grid-cols-3 md:grid-cols-2 sm:grid-cols-1">
        <div className="cols-span-3">
          <Navbar className="cols-span-3"></Navbar>
          <h2 className="font-bold cols-span-1">Overview</h2>
        </div>
        <RevenueCardMain
          className="cols-span-1"
          title="Next Payout "
          amount="2,312.23 "
          orderCount="23 "
          date="Today, 4:00PM "
        ></RevenueCardMain>
        <RevenueCardNotMain
          className="cols-span-1"
          title="Amount Pending "
          amount="92,312.20 "
          orderCount="13 "
        ></RevenueCardNotMain>
        <RevenueCardNotMain
          className="cols-span-1"
          title="Amount Processed "
          amount="23,92,312.19 "
        ></RevenueCardNotMain>
      </div>
    </>
  );
}

export default App;
