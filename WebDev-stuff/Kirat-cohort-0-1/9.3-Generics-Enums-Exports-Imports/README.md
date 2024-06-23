# Lecture 9.3, continued from the previous lecture

This lecture is all about Generics, Enums, Exports, and Imports.

## Enums

Enums (short for enumerations) in TypeScript are a feature that allows you to define a set of named constants. The concept behind an enumeration is to create a human-readable way to represent a set of constant values, which might otherwise be represented as numbers or strings.

Now we are trying to create a game that will take certain inputs and as such we'll have to optimize it accordingly

```ts
function doSomething(keyPressed: string) {
  if (keyPressed == "up") {
    console.log("going up");
  } else if (keyPressed == "down") {
    console.log("going down");
  } else if (keyPressed == "left") {
    console.log("going left");
  } else if (keyPressed == "right") {
    console.log("going right");
  }
}

doSomething("up");
doSomething("down");
doSomething("left");
doSomething("right");
doSomething("tur mur tu");
```

- Now the first three inputs gets proper values but the last input is not an expected input and it would be nice to just ignore that input in the first place instead of doing anything with it.

  - The type of ways that can be done is by using `type` for the type of input we expect like the following:

  ```ts
  type keyInput = "up" | "down" | "left" | "right";

  function doSomething(keyPressed: keyInput) {
    // the same code as above but this time the type of input is restricted to the type of input we expect
  }

  doSomething("up");
  doSomething("down");
  doSomething("left");
  doSomething("right");
  doSomething("tur mur tu");
  ```

- But the best thing to do here is to use `enums` which is more human readable and as strict as `type`.

What should the type of keyPressed be? Should it be a string? (UP , DOWN , LEFT, RIGHT) ? Should it be numbers? (1, 2, 3, 4) ?

The best thing to use in such a case is an enum, when we have a limited set of inputs to this specific function and they are constant functions. It is a way to give more friendly names to sets of numeric values. It starts with the enum keyword followed by the name of the enum (Direction in this case) and then the names of the values in curly braces, separated by commas.

```ts
enum Direction {
  Up,
  Down,
  Left,
  Right,
}

function doSomething(keyPressed: Direction) {
  // do something.
}

doSomething(Direction.Up);
```

> 💡 This makes code slightly cleaner to read out. The final value stored at runtime is still a number (0, 1, 2, 3).

Reasons it is better that types

- It is more easier to just set the value to the enum and it will automatically set the value to the enum, instead of doing something like
- Enums are named constants so when not assigned a value, it will automatically assign a value to it which goes from 0 to the number of things present.
- Also do note that this concept is not present in JavaScript, it is a TypeScript feature. So when we look into the compiled js file we'll see some function and other code which is not enum and as such using enum is much better than writing those.
- Enums can be assigned string values as well, and a lot of stuff so that can be pretty much anything.
  - But once you assign a value you will have to assign some value(can be of any type) to the other members as well.
  - special case: if you want them to start from 1 or any other value, then you can assign that value to the first member of the enum and the rest will be automatically assigned the following values.
- So the use of the enums is that it is a way to give more friendly names to sets of numeric values. We don't ever use constant literals like directly giving values to the variables, instead we use enums like Direction.Up, Direction.Down, etc, for a more cleaner code.

A common usecase in express is to use the http status codes, so instead of using the status codes directly, we can use the enums for the status codes.

```ts
enum ResponseStatus {
Success = 200,
NotFound = 404,
Error = 500
}

app.get("/', (req, res) => {
if (!req.query.userId) {
res.status(ResponseStatus.Error).json({})
}
// and so on...
res.status(ResponseStatus.Success).json({});
})
```

Why this is better:

- First of all it is more readable, the dev can read through the code and understand what is happening, instead of status codes whoso meaning might not be known to everyone and may change over time.
- Secondly it reduces code duplication, if we have to change the status code at multiple places, we can just change it in the enum and it will be reflected everywhere.

## Generics

Generics are a language independent concept (exist in C++ as well)
Let’s say you have a function that needs to return the first element of an array. The array can be of type either string or integer. How would you solve this problem?
Solution

- User can send different types of values in inputs, without any type errors. But since Typescript isn’t able to infer the right type of the return type so it will throw errors on cases where we want to do some single type related stuff like say we want to convert the string to upper case using the inbuilt string function `toUpperCase()`, but the input is like `["harkiratSingh", 2]` then it will throw an error since it is not able to infer the type of the input. It'll still take the input but can't process single type related stuff.
- That will not work since TS is only able to infer the types and since we have setup the type to be of string or number, it will expect both type of values so using such type of functions will throw an error.
- Also if the user sends mixed types of values, then also it will not complain but it is surely not what we want.
- Also we can fix it by not using a type and instead using unions to separate the type of values, but that is not a good solution since it still expects any one type and it'll still throw error if we send a mixed set of values.

In such cases Generics enable you to create components that work with any data type while still providing compile-time type safety. The key is to use generics to define the type of the input and the output.

1. Problem Statement

   ```ts
   function getFirstElement(arr: (string | number)[]) {
     return arr[0];
   }
   const el = getFirstElement([1, 2, 3]);
   ```

What is the problem in this approach?

- The `const` doesn't know whether the getFirstElement is sending in a string or a number since a union is used and as such there we'll have errors as said above.

```ts
function getFirstElement(arr: (string | number)[]) {
  return arr[0];
}
const el = getFirstElement([1, 2, "3"]);
```

```ts
function getFirstElement(arr: (string | number)[]) {
  return arr[0];
}
const el = getFirstElement(["harkiratSingh", "ramanSingh"]);
console.log(el.toLowerCase());
```

2. Solution - Generics

   - Can you modify the code of the original problem now to include generics in it?
     - User can send different types of values in inputs, without any type errors
     - Typescript isn’t able to infer the right type of the return type
     - When we used type it was supposed to figure itself out if it is a number or a string, but since it expects both so we can't apply certain type specific stuff and there are many more problems.
        - So in such cases we can use generics to define the type at the starting, that's what that `<T>` represents.
        - So that functions is like it can be called with a generic value i.e any value. identity has a generic type and it can get anything i.e during definition it won't know the type of anything i.e it will be generic function, anyone can call it and when calling they should just define, it can be a number, string, object, etc. It is a placeholder for the type of the input and the output.
        - And when we want to use it, we can use it like `identity<string>(["harkiratSingh", "ramanSingh"])` and it will automatically infer the type of the input and the output and as such we can use the type specific functions as well.

       Simple example -

      ```ts
      function identity<T>(arg: T): T {
        return arg;
      }
      let output1 = identity<string>("myString");
      let output2 = identity<number>(100);
      ```

      - It can be seen as being able to create multiple variations of your function one for number, one for string and so on, that takes in a value and returns the same value, but the type of the value can be anything, so it is a generic function.

      ```ts
      function identity(arg: string) {
        return arg;
      }
      function identity(arg: number) {
        return arg;
      }
      let output1 = identity1("myString");
      let output2 = identity2(100);
      ```

3. Solution to original problem

   ```ts
   function getFirstElement<T>(arr: T[]) {
     return arr[0];
   }
   const el = getFirstElement(["harkiratSingh", "ramanSingh"]);
   console.log(el.toLowerCase());
   ```

   Did the issues go away?

   ```ts
       function getFirstElement<T>(arr: T[]) {
       return arr[0];
       }
       const el = getFirstElement<string>(["harkiratSingh", 2])
       console.log(el.toLowerCase())
       function getFirstElement<T>(arr: T[]) {
       return arr[0];
       }
       const el = getFirstElement(["harkiratSingh", "ramanSingh
       console.log(el.toLowerCase())
   ```

What are the usecases and benefits

 ```ts
 function identity<T>(arg: T): T {
   return arg;
 }
 let output1 = identity<string>("myString");
 let output2 = identity<number>(100);
 ```

- Since it is being called with a generic the type is specific as to what will be returned, In the above example we can say that it'll return string because it is being called with a type string then the arg will also take the same type(bc it has a generic type) and the return is also arg so its the same string, so overall it is string everywhere.
  - So now we can easily use the `toLowerCase()`, `toUpperCase()`, etc functions on the output and it will work fine.
  - But the explicit definition of the generic type while calling is not necessary because TS infers it from the type of values you are giving and hence it is not necessary to define the type explicitly. So if it as a string or a number, the generic type will automatically tell the type of the input and the output and it will work fine. I think it would be better to define them explicitly just in case.
  - You can still give mixed values but then explicit type definition will be necessary, otherwise it will throw an error on certain usage and it assumes that the type is `(string | number)`.
  - You can also set a interface in the generic type while calling so it can be extended to many complex sort of datas.

  ```ts
  interface User {
    name: string;
    age: number;
  }

  const User1 = origProblem<User>([
    { name: 'John', age: 25 },
    { name: 'Doe', age: 30 },
  ]);
  ```

## Exports and Imports

```ts
const express = require("express");
```

From the first we have been following the above syntax to import the modules, this is correct in some way but there are better ways to do this imports and exports and they are by using the `import` and `export` keywords. So TypeScript follows the ES6 module system(the more modern system), using import and export statements to share code between different files. Here's a brief overview of how this works:

```ts
import express from "express"
// also you will need to install @types/express for using types in express as well alongwith the express package obviously
```

and the following is the export syntax, rather than using `module.exports = { a = 1}` this will be the better syntax

```ts
export const a = 1;
export const b = 1;

// and for importing it you can use the following syntax
import { a, b } from "./a"; // object destructuring
```

Also if you are exporting a default value then you can use the following syntax

```ts
const a = 1;
export default a;
// and for importing it you can use the following syntax
import a from "./a"; // no object destructuring
```

- do note that the default imports can be named anything so you don't need to keep the smae name but it would be a good practice to keep the same name.
- Since we can name the default import anything, so we should know that there can be only one default export and import

for importing both the default and the named exports you can use the following syntax

```ts
import a, { b } from "./a";
```