import React from "react";
export const RevenueCardNotMain = ({ title, orderCount, amount, date }) => {
  return (
    <>
      <div className="shadow-md bg-white rounded-md">
        <div className=" p-4">
          <div className="font-medium text-black flex gap-2 flex-between">
            <div>{title}</div>
            <div>
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
          <div className="flex justify-between items-center font-semibold pt-2 pb-2">
            <div className="text-bold text-3xl text-black">₹ {amount}</div>
            <div className="text-lightCardComponent">
              {orderCount ? (
                <div className="flex justify-between underline cursor-pointer">
                  {/* <div className="underline-offset-1">{orderCount}Orders</div> */}
                  {orderCount} Orders
                  <svg
                    className="text-cardComponent"
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
      </div>
    </>
  );
};
