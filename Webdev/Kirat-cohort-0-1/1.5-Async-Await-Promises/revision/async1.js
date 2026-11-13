function findSum(n) {
  let ans = 0;
  for (let i = 0; i < n; i++) {
    ans = i;
    console.log(ans);
  }
  return ans;
}

// console.log(findSum(1000))
// till here it is doing the whole process with the main js thread and as such it cannot do other tasks

function findSumTill100() {
  return findSum(100);
}
setTimeout(findSumTill100, 1000); // here it is calling a asynchronous function
// and this setTimeout function (a global function provided by JS(more appropriately a webAPI)) runs the function after some duration (in ms)
console.log("hello"); // so this line first runs since the above function will run after 1000ms and as such this is asynchronous
