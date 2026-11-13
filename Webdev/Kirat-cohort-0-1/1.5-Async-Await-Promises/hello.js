function asyncFunction() {
  let p = new Promise(function (resovles) {
    // do some async logic here only then it makes sense to use async
    // resovles("hi there1");
    setTimeout(function () {
      console.log("hi there2");
    }, 3000);
  });
  return p;
}

async function main() {
  console.log("hello");
  let value = await asyncFunction();
  console.log(value);
  // asyncFunction().then(function(data){
  //   console.log(data);
  // })
}

main();
console.log("hello out side of the main");
