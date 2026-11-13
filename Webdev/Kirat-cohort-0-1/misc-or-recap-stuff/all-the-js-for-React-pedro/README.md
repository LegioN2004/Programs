# as the name says

from this [youtube](https://youtu.be/m55PTVUrlnA?si=hQY0wqbKQ9CxWOya) video from PedroTech channel

## Arrow functions

it makes it easy to work with callback functions and also to give file excess using export we can just do `export` followed by the arrow function definition

## ternary operators

In react we will need to use conditional statements and the way to reduce the amount of verbosity they contain can be done by using ternary operators.Instead of using if-else statements we can use the alternative

- `&&` is the AND operator which means that if true then change to that "value"(given after the operator) or else show `false`. Note that you neeed to provide something as the value after the operator. Acc to the following example if it is true that age is greater than or equal to 10 then it'll just change or set it to the variable

```js
// define var already or do that below
// let naam = "eoairnst";
// naam = age >= 10 && "byee";
let age = 10;
let naam = age >= 10 && "byee";
```

- `||` is the OR operator which means the opposite to the above, i.e if the condition is not true or false then it'll do the following stuff. In the following example since the condition is not true so it just replaces the `naam` variable to `byeee`

```js
let naam = "Hello";
let age = 10;
let naam = age > 10 || "byee"; // prints byee
let naam = age < 10 || "byee"; // also prints byee
```

- and the last one is the full if else statement which is something like this

````js
let age = 16;
let name = age > 10 ? "yes" : "no";

here `?` means `if` and `:` means `else` . So if true then it'll print the thing after `?` and for else it'll print the thing after `:`. This is cleaner and concise than writing `if-else` statement

## Objects destructuring

In React we'll always use object destructuring to assign values from objects to variables so that we don't have to use more verbose way of doing that. The following example demonstrates what are the differences

```js
const person = {
  name: "hello",
  age: 20,
  isMarried: false,
  };

// put the thing that you want to destructure at the right and in the correct order use the variables that you want to get the values from person and to the variables.
const {name, age, isMarried } = person

// instead of doing the following we can do the above one line code

// can have different variable name for the values of the object
  const name = person.name
  const age = person.age
  const isMarried = person.isMarried
````

Also if you already have the same variable defined outiside an object but you want that variable to be inside that object as well with the same value then you can just add it these without any value like the following

```js
const name = "hello";
const person = {
  // name: name, // no neeed to do this instead
  name,
  age: 20,
  isMarried: false,
};
```

more example usecases

```js
const name = "hello";
const person = {
  // name: name, // no neeed to do this instead
  name,
  age: 20,
  isMarried: false,
  address: {
    city: "city nothing"
    state: "state nothing"
    street: "street nothing"
    }
};
const person1 = {
  // name: name, // no neeed to do this instead
  naam: "second",
  age: 22,
  isMarried: true,
  address: {
    city: "city second",
    state: "state second",
    street: "street second",
  },
};
const { name: firstName, age, address: { street } } = personTwo; // you can assign a new variable to the one key value that you get in this way and then you can print it individually, so here the value of name is  given to firstName so we can print it there. We can also assign this destructure values to a variable and then print it accordingly. we can also use the destructuring for the nested objects that may be present there.
console.log(personTwo);
console.log(name); // gives "hello"
console.log(age); // gives 20
console.log(firstName); // gives "hello"
console.log(address); // gives all the objects with the key value pairs as output
console.log(street); // you can get the street output in that way as well

const person3 = { ...person, ...person1 }; // this basically says that join both the arrays in order and if there is same key value pairs in both the arrays then replace the first with the second array in order
console.log(
  "replacing with second in the strings and 2 in number for the replacing array",
);
console.log(person3);
```

```js
const person = {
  name: "name",
  age: 20,
  isMarried: false,
  address: {
    city: "city nothing"
    state: "state nothing"
    street: "street nothing"
    }
};

// function user(person){
   // console.log(`Name is ${person.name} and age is ${person.age}`)
// instead of doing the above we can do array destructuring here as well so it becomes easy to do stuff, more specifically in React
function user({ name, age }){
    console.log(`Name is ${name} and age is ${age}`)
  }

```

## Array destructuring

It also works the same way as the object destructuring and as such we need to just add the correct order of variables to get the values from an array

```js
const alphabet = ["A", "B", "C", "D", "E", "F"];

const a = alphabet[0];
const b = alphabet[1];
// the above and below are the same
// but the below part is more easier to write and understand and is clean
const [a, b] = alphabet; // this auto gives the first index in the constants array i.e `a` the value of first index of the `alphabet` array, similarly  `b` gets the value of the 2nd index i.e `B`. Note this doesn't make a and b an array as said but it just the way of taking the values individually. Now we can individually print them
console.log(a); // gives us A
console.log(b); // gives us B
```

more usecase examples

```js
const alphabet = ["A", "B", "C", "D", "E", "F"];
const numbers = ["1", "2", "3", "4", "5", "6"];
const [a, , c, ...rest] = alphabet; // to not get the second index value, just skip it like here with blanks with commas. Then using ...rest we can print all the rest of the stuff in the array with rest variable
console.log(a);
console.log(b);
console.log(rest);
const newArray = [...alphabet, ...numbers]; // to combine two different arrays. Also can be done using concat
const newArray = alphabet.concat(numbers);
// these kind of things can be done with return statement also

function SumNdMultiple(a, b) {
  return [a * b, a + b];
}

// instead of giving the value to another variable we can destructure it to give to multiple ones
const [multiple, sum, division = "no division"] = SumNdMultiple(2, 3);
console.log(sum);
console.log(multiple);
console.log(division); // this will print "no division" unless we pass in some actual value in the return of the function statement. This destructure can default to stuff not already present and can also print them. Works for objects as well
```

## spreads operator

The spread operator (`...`) in JavaScript is a powerful feature that allows you to spread elements of an iterable (like an array or a string) or object properties into another array or object. It provides a concise and clean syntax for various tasks, such as copying arrays, merging arrays, and creating shallow copies of objects.

Here are some common use cases and examples of the spread operator:

### Spreading Elements of an Array:

#### Copying an Array:

```javascript
const originalArray = [1, 2, 3];
const copiedArray = [...originalArray];

console.log(copiedArray); // Output: [1, 2, 3]
console.log(originalArray === copiedArray); // Output: false
```

#### Concatenating Arrays:

```javascript
const array1 = [1, 2, 3];
const array2 = [4, 5, 6];
const concatenatedArray = [...array1, ...array2];

console.log(concatenatedArray); // Output: [1, 2, 3, 4, 5, 6]
```

### Spreading Elements of an Object:

#### Copying an Object:

```javascript
const originalObject = { name: "John", age: 25 };
const copiedObject = { ...originalObject };

console.log(copiedObject); // Output: { name: 'John', age: 25 }
console.log(originalObject === copiedObject); // Output: false
```

#### Merging Objects:

```javascript
const object1 = { name: "John" };
const object2 = { age: 25 };
const mergedObject = { ...object1, ...object2 };

console.log(mergedObject); // Output: { name: 'John', age: 25 }
```

### Function Arguments:

#### Passing Elements of an Array as Arguments:

```javascript
const numbers = [1, 2, 3];
const sum = (a, b, c) => a + b + c;

console.log(sum(...numbers)); // Output: 6
```

### Rest Parameter:

The spread operator can also be used as the rest parameter in function parameters to collect remaining arguments into an array.

```javascript
const numbers = [1, 2, 3, 4, 5];

const sum = (a, b, ...rest) => {
  let result = a + b;
  rest.forEach((num) => (result += num));
  return result;
};

console.log(sum(...numbers)); // Output: 15
```

### Shallow Copy vs. Deep Copy:

It's important to note that the spread operator performs a shallow copy. If you are working with nested arrays or objects, only the top-level structure is copied, and nested elements are still references. If deep copying is required, additional techniques like the `JSON.parse()` and `JSON.stringify()` combination or external libraries may be needed.

```javascript
const originalArray = [
  [1, 2],
  [3, 4],
];
const copiedArray = [...originalArray];

copiedArray[0][0] = 99;
console.log(originalArray); // Output: [[99, 2], [3, 4]]
```

In the example above, modifying `copiedArray` also affects `originalArray` because they share references to the same nested arrays.

The spread operator is widely used in modern JavaScript, and it simplifies many common operations with arrays and objects. It enhances code readability and reduces the need for manual iteration and manipulation.

## Map function

Say we want to iterate over an array containing names and we want to add 1 after every element in the array, then using for loop would be pretty verbose. So it'll be better to use map for that because map iterates over every element of the array in the following manner

- It is used by using dot notation with the array name.
- Then it takes a function as an input which gets an argument in the function and this argument is a variable taht gets all the element of the array where the map function is applied to and using that variable we can write some logic to apply to the array by iterating over it
- in the following example we are doing just that to concatenate the elements of the array with the number 1
- **NOTE**: It doesn't replace the original array, it just makes a new array and puts the new stuff there

```js
let names = ["hello", "hi", "bye"];

console.log(
  names.map((name) => {
    // return name + 1; // adding with string auto makes the number as string
    return name + "1"; // or we can do this directly
  }),
);
```

## Filter function

It is a function that gets some logic for filtering stuff using the function that it gets inside it and also using the argument just like map.

- **NOTE**: It doesn't replace the original array, it just makes a new array and puts the new stuff there

## more about map and filter here by chatGPT

`map` and `filter` are two array methods in JavaScript, and they have different purposes and behaviors.

### `map` Method:

1. **Purpose:**

   - The `map` method is used for transforming each element of an array based on a provided function.

2. **Behavior:**

   - It creates a new array with the same length as the original array.
   - It applies a provided function to each element of the original array.
   - It returns a new array containing the results of applying the function to each element.

3. **Does it modify the original array?**

   - No, the `map` method does not modify the original array. It creates a new array with the transformed values.

4. **Example:**

   ```javascript
   const numbers = [1, 2, 3];
   const doubledNumbers = numbers.map((num) => num * 2);

   console.log(doubledNumbers); // Output: [2, 4, 6]
   console.log(numbers); // Output: [1, 2, 3] (original array is unchanged)
   ```

### `filter` Method:

1. **Purpose:**

   - The `filter` method is used for creating a new array with elements that satisfy a certain condition.

2. **Behavior:**

   - It creates a new array containing only the elements that pass a provided test function.
   - It returns a new array with the selected elements.

3. **Does it modify the original array?**

   - No, the `filter` method does not modify the original array. It creates a new array with the selected elements.

4. **Example:**

   ```javascript
   const numbers = [1, 2, 3, 4, 5];
   const evenNumbers = numbers.filter((num) => num % 2 === 0);

   console.log(evenNumbers); // Output: [2, 4]
   console.log(numbers); // Output: [1, 2, 3, 4, 5] (original array is unchanged)
   ```

### Key Differences:

1. **Transformation vs. Selection:**

   - `map` is used for transforming each element of an array based on a provided function.
   - `filter` is used for selecting elements that satisfy a certain condition.

2. **Returned Array:**

   - `map` returns a new array containing the results of applying the provided function to each element.
   - `filter` returns a new array containing only the elements that pass the provided test function.

3. **Original Array:**

   - Neither `map` nor `filter` modifies the original array. Both create a new array.

4. **Use Cases:**
   - Use `map` when you want to transform each element in the array.
   - Use `filter` when you want to create a new array with elements that meet a specific condition.

In summary, both `map` and `filter` are non-destructive array methods. They create new arrays based on the transformation or selection criteria, leaving the original array unchanged.
