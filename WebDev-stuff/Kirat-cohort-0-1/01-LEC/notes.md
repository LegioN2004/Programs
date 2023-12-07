# NOTES

- JS is an interpreted language, it doesn't need a separate compilation step.
- This code is not going into the ram i.e not worried about a high level compilation step as such and it is just focused on running the code line by line, in C++ it would first compile and become an executable and then it'll run the whole program. In JS it just converts one line into zeroes and ones and then runs it, then does the same to the next line and so on and so forth.

## Primitives

- var, let are some variable declaration primitives that can be defined more than once but let can be defined only once in its lifetime. **note**: you will be using let and const, let for something that changes more than once and const for the variable that'll not change.

## Datatypes

- String, boolean, int, char etc automatically initializes since you don't have the hassle to declare types everytime you declare any variable but do remember to use double quotes for string/char(no hassle for single quotes as well) since it is a norm for every other language out there.

- Arrays are declared using third/square brackets '[]' instead of curly braces and as such remember

### note: Complex Objects or objects

```javascript
const user1 = {
  firstName2: "mili",
  genderArray2: "male",
};
```

- The above is the syntax of complex object, it the args are separted by commas and they get the values with colon
- The values in an array is known as index and the values in an object is termed as keys and the way to access this is `user1["firstName2"]`.
- This tells us that objects are a way to aggregate data together.

#### Complex objects

- Now if we combine the obects and an array together, then we'll get something like

```javascript
const allUsers = [
  {
    firstName3: "mili",
    genderArray3: "male",
  },
  // more nested one
  //  {
  //   firstName: 'mili',
  //   genderArray: 'male',
  //   metadata: [
  //    {
  //     age: 21,
  //     height: 6,
  //    },
  //   ],
  //  },
  {
    firstName3: "bye",
    genderArray3: "female",
  },
  {
    firstName3: "nonastain",
    genderArray3: "female",
  },
];
```

This is better because we now don't need two arrays to show name and gender separately and as such this approach. You can make it more nested to add more stuff and the syntax remains the same as the initial part, parent array then index of it, then the next object inside that array, then if there is more objects inside of the object of one of the index then add those using square braces, so on and so forth.

### Functions

Function let you do

1. Abstract out logic in your computer
2. Take arguments as an input
3. Return value as an input
4. You can think of them as an independent program that is supposed to do something given an input
5. Functions CAN take other functions as input - _confusions will start here_ **callbacks**

- How to define a function

```javascript
function name_of_fn(arguments, arguments, ..){ // .. means more agrs if you want to add separated by commas
    return something_with_operation_with_args;
}

const some_var = name_of_fn(arguments, arguments, ..) // to store the value of the function
console.log(some_var);
```

- Once a function is defined, it will run and come till the function and skip till the function call and once it is called it'll check the values with the function run everything inside then return the output to the variable or directly printout.

#### Callbacks

- What it means is that we can pass a function as an argument to another function and as a result run two or more functions with a single function call

- Why is it good? : Because now we can change what function should get called, pass it as an argument and that will get called

- example is in the [function.js](WebDev-stuff/Kirat-cohort-0-1/01-LEC/functions.js) file.
  - What's happening in the file is that we are passing a function `displayResult(data)` which is to be used another in the main function's `sum(num1, num2, fnToCall)` call by making this variable `fnToCall` in the sum function and then pass the displayResult function in the call as an argument and as such it'll be taken inside the sum function as a parameter by that var and then execute inside then also execute the displayResult function by going outside and taking the value inside sum and then take it's value and print out ultimately.

##### setInterval() & setTimeout() inbuilt functions

```javascript
function setTimeout(function_name, duration) {
  // sleeps for some duration something like
  sleep(duration);
  function_name(); // that same function call taken as an argument
}

function setInterval(function_name, duration) {
  function_name(); // that same function call taken as an argument
}
```

- The above is an example of two inbuilt functions that run the same as callback functions under the hood, these are global functions provided by JS people

```javascript
function greet() {
  console.log("In the JS hell");
}
setTimeout(greet, 9 * 1000);
setInterval(greet, 0.1 * 1000);
```

- First one means after how much time the greet function will run, in this case 9 secs i.e it is supposed to call a function after a certain duration, this is also an example of callback
- Second, we have setInterval which runs the function after every interval, in this case there is a repetition after every 0.1 second.
- one thing to note is that never call a function inside the inbuilt function since that means that it'll get the value that function passes.

#### metadata functions stuff

```javascript
const user = {
name = "hello",
age = 21,
address = {
houseNumber = "21",
street = 1,
}
};

console.log(user["address"]["houseNumber"])
// or we can do something like
const address = user["address"]
const houseNumber = address["houseNumber"]
```

This is how we create metadata inside the functions and access them, they first console-log way feels crammed with all the details but separating half of them using variables make it much easier to use when they are really big

```

```
