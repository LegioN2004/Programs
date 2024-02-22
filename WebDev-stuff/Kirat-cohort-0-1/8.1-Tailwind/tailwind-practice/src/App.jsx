import "./App.css";
import { RevenueCard } from "./componenents/RevenueCard";
// import { RevenueCard } from "./componenents/RevenueCard";

function App() {
  return (
    <>
      <div className="grid grid-cols-1 lg:grid-cols-3 md:grid-cols-2 sm:grid-cols-1">
        <div className="bg-red-500">heloooooooooo</div>
        <div className="bg-green-500">heloooooooooo</div>
        <div className="bg-blue-500">heloooooooooo</div>
        <RevenueCard
          className="cols-span-1"
          title="Next Payout ?"
          amount="2,312.23"
          orderCount="23"
        ></RevenueCard>
        <RevenueCard
          className="cols-span-1"
          title="Amount Pending "
          amount="92,312.20"
          orderCount="13"
        ></RevenueCard>
        <RevenueCard
          className="cols-span-1"
          title="Amount Pending "
          amount="92,312.20"
          orderCount="13"
        ></RevenueCard>
      </div>
    </>
  );
}

export default App;
