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

- An example of promise that immediately resovles:

```javascript
let p = new Promise(function (resovles) {
  resovles("hi there");
});

p.then(function () {
  console.log(p);
});
```

- output: `Promise { 'hi there'}` because the p gets an instance of the promise, so it prints out like that. If we give a param to store the value of p inside the `.then(function(param))` then printing out the var gives the actual value i.e: hi there

- An example of a function having a promise inside that immediately resovles:

```javascript
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
```

- output: `hi there` because we give a param to store the value of the promise and then return it to the asyncFunction() which uses the `.then(function(param))` to print out the var which gets the resolved value and prints out the actual value i.e: hi there

- **Why even make an async function in the above, we could have used a simple function for the above**: Because that works as desired, for example: If we're to make a async function that waits for 2 secs and then resovle, in that case we can do this like the following

1. Async function(promisified version of the simple function given below)

```javascript
function asyncFunction() {
  let p = new Promise(function (resolve) {
    setTimeout(resolve, 2000);
  });
  return p;
}

const value = asyncFunction();
value.then(function () {
  console.log("hi there");
});
```

2. Simple function

```javascript
function asyncFunction() {
  setTimeout(callback, 2000);
}

asyncFunction(function () {
  console.log("hi there");
});
```

### Async Await: The real benefit of promises, why everyone loves it

- It is again syntactical sugar but it still uses callbacks/promises, call-stack, event loop and other stuff under the hood.

- the normal syntax goes something like

```javascript
function asyncFunction() {
  let p =  new Promise(function (resovles) {
    // do some async logic here only then it makes sense to use async
    resovles("hi there2");
  });
  return p;
}

function main() {
  asyncFunction().then(function(resolve){
    console.log(resolve);
  })
});

main();
```

- The async await syntax goes something like the following

```javascript
function asyncFunction() {
  let p = new Promise(function (resovles) {
    // do some async logic here only then it makes sense to use async
    resovles("hi there");
  });
  return p;
}

async function main() {
  let value = await asyncFunction(); // if we don't add await then it prints something out of the three such as pending undefined or anything else according to the promise and the logic inside since the function call of the promise only returns an instance of the promise
  console.log(value);
}

main();
```

- first of all we need to make the function that will contain the promise
- Then we'll need to add the function "main" which we can specify it to be 'async' by just adding the keyword to the front, then remove the .then() and then let value = the function and in front if we add await which then prints out the final result of the resolved variable and if we don't log out then the control will not go beyond it.
- As such we won't have to use the callbacks even if we are using an async function and the `.then()` function too
- This is a more clearer version of promise
- note: in the let value where the await happens, the thread gets stuck for the async stuff that is happening inside the async function but the main thread is always available for sync stuff so if there is anything synchronous outside after the main function then it'll run it first regardless of what happens with the async. But in case of `.then()` if something inside its function has some logic that can run immediately then it'll run regardless of the. (more clear exaplanation below with some examples)
- note: When main() is called at the end of the file, it initializes the async operation and then proceeds to execute the next statement (console.log("hello out side of the main")). Since it is not inside the async function, it is executed immediately after the main() is invoked, irrespective of the asynchronous operation inside the asyncFunction.

- more examples

```javascript
function asyncFunction() {
  let p = new Promise(function (resovles) {
    // do some async logic here only then it makes sense to use async
    resovles("hi there1");
    setTimeout(function () {
      console.log("hi there2");
    }, 3000);
  });
  return p;
}

async function main() {
  let value = await asyncFunction();
  console.log(value)
  // asyncFunction().then(function (data) {
  // console.log(data);
  // });
  console.log("hello");
}

main();
console.log("hello out side of the main");


// -- output --
hello
hello out side of the main
hi there1 // waits here till 3 secs then runs the next
hi there2
```

- In the above examples we are using both the async await and the promise syntax, but there is a notable difference between them

  - First is that the async await waits i.e somewhere put in the webAPI, and while it is there the stack continues and the controle reaches after the main function and prints the log outside and after the promise is resolved it runs the rest of the code after the await function inside its scope, sure the logic is stuck but its a decision that the JS people made. When we do async await it is the same as the promise with .then function then its value in this case it also waits for the setTimeout timing to complete in order to print what's next in the .then function
  - because it wants the logic after that to wait ofcourse we are talking within the scope of the braces of the promise and the async-await respectively

- Again it is just syntactical sugar, makes the code more readable and than callbacks/promises and usually used on the caller side, and not on the side where we define an async function, the caller needs to be an async function with async been written explicitly so as to use await, since it needs to be used in an async function.

- synchronous log does not output first, even when using a promise inside the async function, is because the asynchronous code inside the asyncFunction is non-blocking. In the code, the asyncFunction returns a Promise and schedules a setTimeout to execute after 3 seconds. The main function then executes asyncFunction() and logs "hello". However, since the asyncFunction uses setTimeout, the logging of "hi there2" will be queued to execute after 3 seconds, and the main function, being asynchronous, will continue to execute without waiting for the setTimeout to complete. This means that the "hello" log will be displayed before the "hi there2" log, even though the "hi there2" log is queued to execute after the "hello" log, due to the non-blocking nature of setTimeout. If you want to ensure that "hello" is only displayed after "hi there2", you can use the await keyword to pause the execution of the main function until the Promise returned by asyncFunction is resolved. This would ensure that "hi there2" is logged before "hello".

- When using async/await and promises in JavaScript, there are several key points to keep in mind:

1. Async/Await

- The async keyword is used to define an asynchronous function, which enables the use of the await keyword inside it.
- The await keyword is used to pause the execution of the async function until the promise is resolved, and it can only be used inside an async function.
- Async functions always return a promise, and the resolved value of the promise will be the value returned by the async function.
- Async/await simplifies the syntax for writing asynchronous code and makes it look more like synchronous code.
  Promises

2. Promises

- Promises are used to handle asynchronous operations in JavaScript.
- They represent a value that may be available now, or in the future, or never.
- A promise can be in one of three states: pending, fulfilled, or rejected.
- When the asynchronous operation is completed, the promise is either resolved (fulfilled) with a value, or rejected with a reason (an error).
- Promises provide a cleaner way to organize and handle asynchronous code compared to traditional callback functions.

3. Differences between async/await and Promises:

- Syntax: Async/await uses a more synchronous-style syntax, making the code easier to read and maintain. Promises use a more explicit chaining syntax with .then() and .catch() methods.
- Error Handling: With async/await, error handling is done via try/catch blocks, making it more intuitive and clearer. Promises handle errors via the .catch() method, which requires separate error handling logic.
- Chaining: Promises are generally used with chaining .then() and .catch() for multiple asynchronous operations. Async/await makes it easier to write and understand asynchronous code by allowing sequential and easier error handling.

### Some misc stuff found after solving the week 0 problems

#### Regex

Regular expressions (regex) are powerful tools for pattern matching and string manipulation. Here are some commonly used regex patterns and concepts that can be helpful in solving various problems:

1. **Literal Characters:**

   - Matching a specific character: `a` matches the character 'a' exactly.

2. **Character Classes:**

   - `[aeiou]` matches any vowel.
   - `[^aeiou]` matches any non-vowel.
   - `\d` matches any digit (equivalent to `[0-9]`).
   - `\D` matches any non-digit.
   - `\w` matches any word character (equivalent to `[a-zA-Z0-9_]`).
   - `\W` matches any non-word character.
   - `\s` matches any whitespace character.
   - `\S` matches any non-whitespace character.

3. **Quantifiers:**

   - `*` matches 0 or more occurrences.
   - `+` matches 1 or more occurrences.
   - `?` matches 0 or 1 occurrence.
   - `{n}` matches exactly n occurrences.
   - `{n,}` matches n or more occurrences.
   - `{n,m}` matches between n and m occurrences.

4. **Anchors:**

   - `^` asserts the start of a line.
   - `$` asserts the end of a line.
   - `\b` asserts a word boundary.

5. **Escape Characters:**

   - `\` is used to escape special characters. For example, `\.` matches a literal dot.

6. **Grouping and Capturing:**

   - `( )` is used for grouping and capturing. Captured groups can be referenced later.

7. **Alternation:**

   - `|` represents alternation, allowing the matching of either one pattern or another.

8. **Modifiers:**

   - `i` performs case-insensitive matching.
   - `g` performs a global search, finding all matches rather than stopping after the first match.

9. **Character Escapes:**

   - `\t` matches a tab character.
   - `\n` matches a newline character.
   - `\r` matches a carriage return character.

10. **Lookahead and Lookbehind:**
    - `(?=...)` is a positive lookahead.
    - `(?!...)` is a negative lookahead.
    - `(?<=...)` is a positive lookbehind.
    - `(?<!...)` is a negative lookbehind.

These are some foundational regex concepts, and mastering them can greatly enhance your ability to work with strings in programming. Remember that practice and experimentation are key to becoming proficient with regular expressions. Additionally, there are online tools and websites that allow you to test and visualize your regex patterns, making the learning process more interactive.

#### String equality and inequality

The `===` and `!==` are strict equality and strict inequality operators in JavaScript. They are similar to the more common `==` (equality) and `!=` (inequality) operators, but with an important difference.

- **`===` (Strict Equality):** This operator checks both value and type equality. It returns `true` if the operands are of the same type and have the same value. For example:

  ```javascript
  5 === "5"; // false (number and string, different types)
  5 === 5; // true (number and number, same type and value)
  ```

- **`!==` (Strict Inequality):** This operator checks both value and type inequality. It returns `true` if the operands are of different types or have different values. For example:
  ```javascript
  5 !== "5"; // true (number and string, different types)
  5 !== 5; // false (number and number, same type and value)
  ```

The key difference from `==` and `!=` is that the strict equality/inequality operators do not perform type coercion. They require both the value and the type to be the same for the comparison to be true.

- **`==` (Equality):** This operator performs type coercion, meaning it tries to convert operands to the same type before making the comparison. For example:

  ```javascript
  5 == "5"; // true (number and string, after coercion)
  ```

- **`!=` (Inequality):** This operator also performs type coercion. For example:
  ```javascript
  5 != "5"; // false (number and string, after coercion)
  ```

Using strict equality/inequality (`===` and `!==`) is generally considered good practice in JavaScript because it avoids unexpected type coercion issues. It helps write more predictable and less error-prone code. While these operators are commonly used in JavaScript, other programming languages may have similar strict equality/inequality concepts.

#### Try-Catch statements

The `try...catch` statement in JavaScript is used to handle exceptions or errors that may occur during the execution of a block of code. It allows you to define a block of code to be tested for errors while providing a mechanism to handle these errors gracefully.

Here's the basic syntax:

```javascript
try {
  // Code that might throw an exception or error
  // ...
} catch (error) {
  // Code to handle the exception or error
  // ...
} finally {
  // Code that will be executed regardless of whether an exception occurred or not
  // ...
}
```

- The `try` block contains the code that you want to monitor for errors.
- If an exception occurs within the `try` block, the control is transferred to the `catch` block.
- The `catch` block contains the code that will be executed when an exception occurs. The `error` parameter represents the exception object and can be used to obtain information about the error.
- The `finally` block contains code that will be executed regardless of whether an exception occurred or not. This block is optional.

Here's an example:

```javascript
try {
  // Code that might throw an exception
  const result = 10 / 0; // This will throw a division by zero error
  console.log(result); // This line will not be executed
} catch (error) {
  // Code to handle the exception
  console.error("An error occurred:", error.message); // Print the error message
} finally {
  // Code that will be executed regardless of whether an exception occurred or not
  console.log("This will always run");
}
```

In this example, the division by zero will throw an exception, and the control will be transferred to the `catch` block, printing an error message. The `finally` block will always run, regardless of whether an exception occurred.

It's important to note that catching specific types of errors is possible. You can have multiple `catch` blocks, each handling a specific type of exception. This allows you to handle different errors in different ways.

#### isNaN function

`isNaN` stands for "is Not-a-Number." It's a JavaScript function used to determine whether a value is not a numeric value. It returns `true` if the value is `NaN` (Not-a-Number), and `false` otherwise.

Here's how you can use `isNaN`:

```javascript
isNaN(123); // false (123 is a number)
isNaN("hello"); // true ("hello" is not a number)
isNaN(NaN); // true (NaN itself is not a number)
isNaN("123"); // false (the string "123" can be converted to a number)
```

Things to note:

- `isNaN` tries to convert the value to a number before checking if it's `NaN`.
- It returns `true` if the value cannot be converted to a number or is already `NaN`.
- When you pass a non-numeric value like a string that doesn't represent a valid number, it returns `true`.
- `NaN` is a special global value in JavaScript that represents an unrepresentable value as a number.

However, there are some behaviors to be aware of:

- `isNaN` can produce unexpected results when used with non-numeric values like empty strings (`""`) or objects. For example, `isNaN("")` returns `false`.
- To check if a value is a valid number without relying on `isNaN`, you can use `Number.isNaN()` (introduced in ECMAScript 6) or `typeof` to specifically check if the type is `'number'`.

Example:

```javascript
Number.isNaN(123); // false (123 is a number)
Number.isNaN("hello"); // false ("hello" is not a number)
Number.isNaN(NaN); // true (NaN itself is not a number)
Number.isNaN("123"); // false (the string "123" can be converted to a number)

typeof 123 === "number"; // true (123 is a number)
typeof "hello" === "number"; // false ("hello" is not a number)
```

`Number.isNaN()` is more strict and doesn't perform type coercion, making it a more reliable method to check for `NaN`.

##### fs.writeFile

The `fs.writeFile` function in Node.js is used to asynchronously write data to a file. It is part of the `fs` (file system) module, which provides an API for interacting with the file system.

Here's the basic syntax of `fs.writeFile`:

```javascript
const fs = require("fs");

fs.writeFile(file, data, options, callback);
```

- `file`: A string representing the file name or the file descriptor.
- `data`: The data to be written to the file. It can be a string or a buffer.
- `options`: An optional object that can include encoding, mode, and flag options.
- `callback`: A callback function that will be called once the file has been written or an error occurs. The callback has the signature `(err)`.

Here's an example of using `fs.writeFile`:

```javascript
const fs = require("fs");

const content = "Hello, this is some content!";
const fileName = "example.txt";

fs.writeFile(fileName, content, "utf8", (err) => {
  if (err) {
    console.error("Error writing to file:", err);
  } else {
    console.log("File has been written successfully.");
  }
});
```

In this example:

- `fileName`: The name of the file to be created or updated.
- `content`: The data to be written to the file.
- `'utf8'`: The encoding used to write the file. Here, it's UTF-8.
- The callback function is executed after the operation is complete. If there is an error, it will be passed to the `err` parameter.

Remember that `fs.writeFile` will overwrite the file if it already exists, and if the file doesn't exist, a new file will be created. If you want to append data to a file, you might want to use `fs.appendFile`.
