console.log("hello");

Promise.resolve().then(() => {
    console.log("promise resolved");
})

setTimeout(() => {
    console.log("hi after 1000ms");
}, 1000)

Promise.resolve(5)
  .then(x => x * 2)      // 10
  .then(x => x + 1)      // 11
  .then(console.log);    // 11

console.log("after everything")
