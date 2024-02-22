import React from "react";
// this card will not try to restrict the card to be of any width, it'll give us the full width card, but it is upto the main App who is using to set the card width with some grid, flex, etc.
export const RevenueCard = ({ title, orderCount, amount, date }) => {
  return (
    <>
      <div className="shadow-md border-black m-6 p-4 bg-blue-600 rounded ">
        <h3 className="text-slate-100">{title} ?</h3>
        <div className="flex justify-between font-semibold">
          <h2 className="text-2xl text-white">₹ {amount}</h2>
          <h3 className="text-slate-100">
            {orderCount ? (
              <div>
                {orderCount} orders(s) {">"}
              </div>
            ) : null}
          </h3>
        </div>
        <div className="flex justify-between">
          <h2 className="text-slate-100">Next payment date </h2>
          <h3 className="text-slate-100">{date}</h3>
        </div>
      </div>
    </>
  );
};
