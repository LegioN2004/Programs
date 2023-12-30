# Offline lec 1.5

## Async functions vs Sync functions

| What does synchronous mean              | What does asynchronous mean                              |
| --------------------------------------- | -------------------------------------------------------- |
| Together, one after another, sequential | Opposite of synchronous                                  |
| Only one thing is happening at a time   | happens in parts, things are happening parallely somehow |
|                                         | Multiple things are context switching with each other    |

- Context switching
- So JS is also single threaded but it can delegate tasks to other threads thereby doing more than one work at a time like we humans do
- so like human brains which is single threaded we can only do one thing at a time, but while boiling water we can chop some veggies then again bring some potatoes and again start chopping, etc etc and as such we can do some context switching in our work, but at a time we can only do single work
- Some other ways can be we can call another person to do the work, so while we chop the veg, the other person can go boil the water or bring something. So somehow our brain can context switch, and **the same is true for javascript it can context switch and delegate task to other threads**

## Synchronous vs Asynchronous task completion for the task of creating noodles

### Synchronous

waiting for every task one by one till it finishes

1. first boiling water and waiting till it boils - 5min
2. then opening maggi packet - 2min
3. then chopping vegetables - 10min
4. going to buy ketchup at shop - 20min
   total time 22mins

- So in Synchronous everything is done one at a time without delegating

eg:

```javascript
functions findSum(n){
  let ans = 0;
  for(let i = 0; i < n; i++){
    ans += i;
  }
  return ans;
}
console.log(findSum(1000))

```

### Asynchronous

not waiting for every task but context switching between tasks or parallelizing tasks

1. first boiling water and just turns on the gas and doesn't wait - 2s
2. tells other person to buy ketchup at shop
3. checking water again - 1s
4. then chopping vegetables - 8min
5. ketchup arrived and still cutting veggies - 2min extra = 10min
   total time 12mins

- context switching between 1, 2, 3 tasks

- Real world example of asynchronous task by nodejs is reading files from the files system, you don't want to make that run for like some time on the main js thread since that will make it the main thread busy and other imp stuff will not work. Rather you can delegate the task to someone else so that the main thread is doing the important task and whenever the reading finishes it'll get to the main thread.

- How JS does this: By using asynchronous functions

```javascript
functions findSum(n){
  let ans = 0;
  for(let i = 0; i < n; i++){
    ans += i;
  }
  return ans;
}

//console.log(findSum(1000))
// till here it is doing the whole process with the main js thread and as such it cannot do other tasks

function findSumTill100(){
return findSum(100);
}
setTimeout(findSumTill100, 100); // here it is calling a asynchronous function
// and this setTimeout function (a global function provided by JS(more appropriately a webAPI)) runs the function after some duration (in ms)
console.log("hello"); // so this line first runs since the above function will run after 1000ms and as such this is asynchronous
```

- the above example fall in the async category because once the JS thread reaches the setTimeout function it'll not wait there till the given time, it'll print the next line and when the setTimeout's time limit is up then the thread will go back to the function it was supposed to run after the 1000ms and as such qualifies as an asynchronous function example. NOTE: we can make the setTimeout function as a synchronous function but by default js provides it in a asynchronous nature

- to make the program synchronous somehow, you can make a loop that iterates but shows nothing and in that way you can delay the printing of hello if you want since the main JS thread reaches that loop and keeps on running until that finishes

- Some common async functions that JS provides out of the box: setTimeout: as said above, fs.readFile: to read file from the filesystem, Fetch: To fetch some data from an API endpoint

  - The readFile function is an async function that reads from the filesystem but it only supports js or txt files. The reason it is async because any file cannot be readily available to access, it may have some permission issues or some password locks, etc and as such the JS thread delegates it to another thread to try its best to retrieve data from that specific file while the main thread runs the remaining logic thereafter

- example async functions

  - fs.readFile(): we need to import one module here and make assign it to a variable so as to use it, more on that later. Then the next line uses the variable and with a '.' dot operator uses the readFile function given by JS. Then inside in the first quotes it'll have the filename, then the file encoding(many different types for reading all sorts of data), then we'll take another anonymous function that will take params in the format err, data and then rest of the logic inside the function(should follow this syntax style, it's what the JS people decided)
  - Also since the function readFile is async i.e it is expensive on the resources, the main thread context switches to the next logic and pass this async to another thread and as such the sync stuff runs first and then the file reading happens
  - What if there is a long logic that takes very long even longer than the file reading, Then the JS thread will not context switch to the async function it'll run till the sync stuff finishes, then it'll go to the callback function i.e the async function. So even if the thread is busy somewhere, and in that program a callback(or any other async stuff) has resolved, then the thread doesn't go to the callback and instead runs till the thread becomes _idle_.
    - When does it become idle - when the thread finishes running all the sync stuff then the thread becomes idle and then it moves to the pending callbacks

  ```javascript
  const fs = require("fs"); // this is how to import a module to different tasks, for now no details this just helps to read and write in a file

  fs.readFile("a.txt", "utf-8", function (err, data) {
    console.log(data);
  });

  console.log("heello");

  let a = 0;
  // a loop that takes very long, longer than the file read function above
  for (let i = 0; i <= 100000000; i++) {
    a++;
  }
  console.log("hi there 2");
  ```

#### More about asynchronous JS

Example:

```javascript
console.log("Hi!");

setTimeout(function timeout() {
  console.log("Click the button!");
}, 20000); // takes 20s

setTimeout(function timeout() {
  console.log("Click the button!");
}, 5000); // takes 5 secs

console.log("Welcome to loupe.");

for (let i = 0; i < 10; i++) {
  a += 1;
}

console.log(a);
```

From the [latentflip](http://latentflip.com/loupe) site, we can visualize the way async works and it shows us the four things at a high level in the JS architecture which makes JS async, and makes the above stuff talked about eariler possible. If we have only synchronous code then we don't need to worry about webAPIs or callback queues or event loop, the only thing that we should be worried about is the call stack.

- Call back: Every line of code that we run reaches the call-stack. It means what is being called next, what is being put on to the stack to actually run. We can also think of it as the line of code that is actually runnning presently. All the code that is synchronous gets placed here

  - Eg: in case of a for loop, every part of it goes to the call stack one by one partly, but why is it called a stack.
  - Eg: if we use a function, then in the stack there will the part where the function is called, that will remain in the stack plus the stuff that is inside that function that is running until the function finishes and then the stack will clear out

- Web APIs: Here the callbacks start, to which JS thread context switches the async task to. These are handled by the browsers and they aren't a part of javascript out of the box, these APIs were introduced by the websites/web, but people realized that it has become common so they decided to provide it out of the box.

  - Eg: In the above example the sync stuff runs first, then the thread context switches the function(anonymous) to webAPI and it runs and finishes then it coes(if it finishes early, if not it still waits till the sync finishes) in the callback queue and waits until the sync finishes. After the thread finishes everything i.e the thread becomes idle then the async stuff goes to call stack with something called the event loop.

- Callback queue: Where the async stuff stays after finishing its work till the event loop takes it to the call stack. The callback queue makes the position as first come first go, so even if a function is called later or whenever, if it finishes first it will come to the queue first and so on and as such the event loop will also take it to the call stack first and so forth.
- Event loop: Its main work is after the thread becomes idle, check if there is something latest in the callback queue that needs to be put back in the call stack, if there is any async stuff that has completed then it takes it from there and puts it in the call stack, and that function gets called which in our case is the anonymous function above.

### Promises

Promises are a pretty way to write a callback queue, it still uses the same callback function style i.e call stack, callback queue, event loop, under the hood. It is a syntactical sugar that makes the above example code in async more readable because without it the synax of the code is ugly.
Until now we have only used async functions written by other people, but we can also create our own. The following example is an ugly way of writing our own async functions, by wrapping a real async function with our own function. Usually all the async functions written by us will be a wrapper on top of the JS provided async functions like setTimeout or fs.readFile

```javascript
const fs = require("fs");

// ugly way to write our own asynchronous function
function readMyFile(cb) {
  // readMyFile then says to read the file
  fs.readFile("a.txt", "utf-8", function (err, data) {
    cb(data); // and pass the file contents to the data variable by calling the cb function(with the data) to which the onDone function has been callbacked
  });
}
function onDone(data) {
  // then the data from cb(data) comes here and runs the logic inside {} which is to log it out and then it is finished
  console.log(data);
}
readMyFile(onDone); // control reaches here and then goes to the readMyFile
```

ChatGPT provided comments for further clarification

```javascript
const fs = require("fs");

// Define an asynchronous function, readMyFile, which takes a callback (cb) as a parameter.
function readMyFile(cb) {
  // Inside readMyFile, read the contents of the file "a.txt" using fs.readFile.
  // Specify "utf-8" encoding for the file content.
  // Provide a callback function to handle errors and data.
  fs.readFile("a.txt", "utf-8", function (err, data) {
    // Call the provided callback function (cb) and pass the file contents (data) to it.
    cb(data);
  });
}

// Define a callback function, onDone, which will be invoked when file reading is complete.
function onDone(data) {
  // Inside onDone, log the file contents to the console.
  console.log(data);
  // The onDone function represents the completion of file reading and logging.
}

// Call the readMyFile function and provide the onDone function as the callback.
// This initiates the process of reading the file asynchronously.
readMyFile(onDone);
```

- First thing to notice is that there are no callbacks because the main reason promises were introduced was to remove callbacks, also because callbacks are an ugly way to write asynchronous code due to some reasons like callback hell, etc.

```javascript
// syntax of promises
function hello() {
  // let p = new Promise(function (resolve) { // or you can assign a variable to the object value and then return that to the call
  // console.log("hello from inside the function");
  return new Promise(function (resolve) {
    // console.log("hello from inside the promise");
    fs.readFile("a.txt", "utf-8", function (err, data) {
      // console.log("hello from before resolve");
      resolve(data);
    });
    // return p;
  });
}

function onDone(data) {
  console.log(data);
}

hello().then(onDone);
// let a = hello(); // you can assign a variable to the hello function and *
// console.log(a);
// a.then(onDone); // *can do this too

// ------------- the output of the above code
hello from inside the function
hello from inside the promise
Promise { <pending> }
hello from before resolve
hi there byeeeeeeeeeeeeeeeeeeeeeeeeeeee
```

- **syntax breakdown**

  1. When the control reaches the function call `hello()` then it will go to the function, then
  2. return new promise: creates an instance of the promise class i.e creating an object(with the new keyword), just like a new Date
  3. first parameter(`function(resolve)`): promises takes a "function" as a parameter and that function takes "resolve"(can be any other name) as a parameter
  4. and a return statement with resolve which passes the param to the then as an arg to run then do the further stuff from then as a arg
  5. It is a class(which makes callbacks and async functions slightly more readable) like Date but only when you define it then it'll need the first argument function as an argument and the first argument of function as a variable which can be of any name.
  6. You can also define a promise outside of a function, it doesn't need a function to be used.
  7. At a high level, promises have three stages pending, resolved and rejected

  - if a promise shows "pending", it means that the function arg hasn't been called
  - if a promise shows "undefined", then it means that the function arg has been called but hasn't returned any data.
  - The function call returns an instance of the promise and as such it prints the `Promise { <pending> }` output in the console and it means literally waiting for the next stuff
  - on the parent function call of promise it synchronously returns a promise to the call so we can log it, but the data of resolve comes asynchronously
  - Then it runs the `.then()` (which says where to send that resolve argument/data) with an argument as a function which means that if the logic inside the promise is done i.e if fs has done reading the file then it'll run go to resolve (which is a callback to the then function which itself callbacks to another function that was passed as an argument to then i.e onDone and at last it logs itself out).
  - `.then()` is called when the async function resolves
  - Resolve and then(function/anything) is closely related, whatever passes into the resolve reaches inside the then() and then it runs the corresponding logic be it another function and its logic or data.

- An example promise that immediately resovles:

```javascript
let p = new Promise(function (resovles) {
  resovles("hi there");
});

p.then(function () {
  console.log(p);
});
```

- output: `Promise { 'hi there'}`
