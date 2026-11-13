const fs = require("fs"); // this is how to import a module to different tasks, for now no details this just helps to read and write in a file

// fs.readFile("a.txt", "utf-8", function (err, data) {
//   console.log(data);
// });
// console.log("heello");

// let a = 0;
// // a loop that takes very long, longer than the file read function above
// for (let i = 0; i <= 100000000; i++) {
//   a++;
// }
// console.log("hi there 2");

function hello() {
  console.log("hello from inside the function");
  return new Promise(function (resolve) {
    console.log("hello from inside the promise");
    // fs.readFile("a.txt", "utf-8", function (err, data) {
    //   console.log("hello from before resolve");
    //   resolve(data);
    // });
    let a = 0;
    for (let i = 0; i < 1000000000; i++) {
      a++;
    }
    resolve(a);
  });
}

function onDone(data) {
  console.log(data);
}

let a = hello();
a.then(onDone);

// promise that instantly resovles ----------------------------------------------------------
let p = new Promise(function (resovles) {
  console.log("async function that resolves instantly");
  resovles("hi there");
});

p.then(function () {
  console.log(p); // p stores this: Promise { 'hi there' }
  // but if we give a value in .then() and then print that variable then it prints out: hi there
});

// async function with a promise that instantly resovles ----------------------------------------------------------
function asyncFunction() {
  console.log("async function that resolves instantly");
  return new Promise(function (resovles) {
    resovles("hi there2");
  });
}

asyncFunction().then(function (data) {
  console.log(data);
});
