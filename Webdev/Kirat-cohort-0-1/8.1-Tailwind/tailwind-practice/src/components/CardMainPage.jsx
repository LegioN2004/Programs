export function CardMainPage() {
  return (
    <>
      <div className="border-black m-6 p-3 bg-blue-600 rounded-lg ">
        <h3 className="text-slate-100">Next Payout ?</h3>
        <div className="flex justify-between font-semibold">
          <h2 className="text-2xl text-white">RS 2312.23</h2>
          <h3 className="text-slate-100">23 Orders {">"} </h3>
        </div>
        <div className="flex justify-between">
          <h2 className="text-slate-100">Next payment date </h2>
          <h3 className="text-slate-100">Today, 4:00 PM </h3>
        </div>
      </div>
    </>
  );
}
