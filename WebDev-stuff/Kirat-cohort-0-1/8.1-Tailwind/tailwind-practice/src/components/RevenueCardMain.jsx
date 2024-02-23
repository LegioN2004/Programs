import React from "react";
// this card will not try to restrict the card to be of any width, it'll give us the full width card, but it is upto the main App who is using to set the card width with some grid, flex, etc.
export const RevenueCardMain = ({ title, orderCount, amount, date }) => {
  return (
    <>
      <div className="shadow-md border-8 hover:bg-cardComponent bg-lightCardComponent rounded-md">
        <div className=" p-4">
          <div className="text-bold text-slate-100 flex flex-between">
            <div>{title}</div>
            <div className="ml-2">
              <svg
                xmlns="http://www.w3.org/2000/svg"
                fill="none"
                viewBox="0 0 24 24"
                stroke-width="1.5"
                stroke="currentColor"
                class="w-5 h-5"
              >
                <path
                  stroke-linecap="round"
                  stroke-linejoin="round"
                  d="M9.879 7.519c1.171-1.025 3.071-1.025 4.242 0 1.172 1.025 1.172 2.687 0 3.712-.203.179-.43.326-.67.442-.745.361-1.45.999-1.45 1.827v.75M21 12a9 9 0 1 1-18 0 9 9 0 0 1 18 0Zm-9 5.25h.008v.008H12v-.008Z"
                />
              </svg>
            </div>
          </div>
          <div className="flex justify-between items-center font-semibold pt-3 b-2">
            <div className="text-bold text-3xl text-white">₹ {amount}</div>
            <div className="text-slate-100">
              {orderCount ? (
                <div className="flex justify-between cursor-pointer underline">
                  {orderCount}Orders
                  <svg
                    xmlns="http://www.w3.org/2000/svg"
                    fill="none"
                    viewBox="0 0 24 24"
                    stroke-width="1.5"
                    stroke="currentColor"
                    class="w-6 h-6"
                  >
                    <path
                      stroke-linecap="round"
                      stroke-linejoin="round"
                      d="m8.25 4.5 7.5 7.5-7.5 7.5"
                    />
                  </svg>
                </div>
              ) : null}
            </div>
          </div>
        </div>
        <div className="flex justify-between py-2 px-5   bg-cardComponent rounded-md">
          <h2 className="text-slate-100">Next payment date </h2>
          <h3 className="text-slate-100">{date}</h3>
        </div>
      </div>
    </>
  );
};
