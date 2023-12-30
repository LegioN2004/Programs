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
  return new Promise(function (resolve) {
    fs.readFile("a.txt", "utf-8", function (err, data) {
      resolve(data);
    });
  });
}

function onDone(data) {
  console.log(data);
}

hello().then(onDone);
