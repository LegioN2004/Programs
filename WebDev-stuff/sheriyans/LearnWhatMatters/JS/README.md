# JavaScript Crash course

## word vs keyword

'for', 'else', 'if, etc are keywords so it can't be used as we wish but other words such as names, etc can be done so because they are already reserved by the language and as such cannot be used again.

## Variable declaration keywords

- var: The var keyword is used to declare a variable with function scope. Variables declared with var can be reassigned and accessed throughout the entire function in which they are defined.
- const: The const keyword is used to declare a variable that cannot be reassigned after it has been assigned a value. It is commonly used for values that are not intended to change, such as mathematical constants or configuration settings.
- let: The let keyword is used to declare a variable with block scope. Variables declared with let can be reassigned, but they are only accessible within the block in which they are defined.

## Hoisting

It means that you can use the variable before the initializng value part to it quite literally, and the following code block shows that.

- Variables and functions are hoisted which means their declaration is moved on the top of the code, so when we do something like `var a = 2;` it becomes the following

``` js
var a = 2; // this line is equal to the following two lines

var a; // this is the declaration part and
a = 2; // this is the initialization part
```

- what happens here is that the declaration part goes to the very top of the file and the initialization remains in its own place, this is known as hoisting. So if we have anything like the output statement then it will print 'undefined' and not error, **since a variable not given any value remains undefined(remember)**.
  - undefined vs not-defined : undefined is something like the `var a` which exists but its value is not known and not-defined is something that doesn't exist.
  - undefined is the default value in any declared but not initialized variable.

```js
// this is what happpens
var a;

console.log(a);
a = 2;
```

- Dont confuse it with hosting, hoisting and hosting are very very different stuff.

- If something is not defined, the printing it out gives not-defined

``` js
console.log(b); // this will print not-defined, since b is not even defined in this scope
console.log(a); // this will print undefined
var a = 12;

```

## Types in JavaScript

They are of two types: Primitives and references

### Primitives

Those values which on copying, copies the real value they're known as the primitives and the values are known as primitive type values.

- Primitives are different from traditional primitives so don't think it in the same way as you have leant in some other languages.
- Primitives: number, string, null, undefined, boolean
- Anything that doesn't have brackets of any type is a primitive

### References

Those values which on copying, doesn't get the real vaued copied and instead only the reference of the value gets passed in known as the reference value.

- You must remember this as the ones with brackets, in our keyboard we have three types of brackets `(), {}, []` and those with this three bracket types represents the reference type.

- Arrays: When we do something like `var a = [1,2,3,4];` we are initializing something called an array and by using the square brackets like this we can define an array and as such we can put more than one values.

- More understanding with an example: Lets say we have two persons 1 and 2 and 1 has a remote that is belongs to 2 too i.e to both of them. Now if 2 destroys the remote then it will be destroyed for both of them and none of them will get the remote again. This is known as the reference type.
  - So the values in []/()/{} these type of brackets cannot be directly copied but can be copied because they are of the reference types.
  - for example: here we are assigning and array and using `pop()` to b which removes the last element from an array and returns it. If the array is empty, undefined is returned and the array is not modified. So outputting b here gives the result as `[ 1, 2, 3 ]`
    - So here b has this array [1, 2, 3, 4] but c doesn't have array of [1, 2, 3, 4], it has b's array of [1, 2, 3, 4] i.e c has the reference of b having this array. So if we change something in c then it will also reflect in the main b's array.

```js
var b = [1, 2, 3, 4];
var c = b;
b.pop();
console.log(c);
// console.log(b); also gives the same output as c
```

## Conditionals (if, if-else, else-if)

- same as we have learnt in other languages, when if cond is true it runs and if false it will run the following if/else-if statements if present and if not then it'll ultimately run the else statement which runs at the end of the if statement.

- Here we also have truthy and falsy values which will come in the advanced topics and I'll summarise them in one md file as notes.

## Loops (for, while)

- for loops run the same way as in every other language
- while loops run the same way as in every other language, one condition inside the brackets which on true will run till the condition becomes false.

## Functions

Functions is a block of code which can be named and can be used whenever and however we want and as many times using that same name. There are a total of 6 styles to write functions, 3 from ES5 and 3 from ES6

- functions are mainly used for three:
  - When you don't want to run the code the same time but in the future
  - When you want to reuse your code
  - When you want to run the same code with different data

- when you want to use different data then you will use func params


## Arrays

In a variable we can only store one variable, but when we need to store more than one variable then we'll use arrays, i.e arrays gives you the freedom to use more than one values. So arrays are groups of values

- Arrays are counted always from 0.


## push pop shift unshift

- Push is used when we need to add an extra member at the end of an already defined array, lets say we want to add 7 to a number array, then we will use push like this `array_name.push(the_data)`

```js
var e = [1,2,3,4,5,6];
e.push(7) // this will add 7 to the above array
```

- Pop is used when we need to remove a member from the end of an already defined array, lets say we want to remove 7 to a number array, then we will use push like this `array_name.pop()`

```js
var e = [1,2,3,4,5,6,7];
e.pop(); // this will remove 7 from the array
```

- Unshift is used to add an extra member to the starting of an already defined array, lets say we want to add 7 to a number array, then we will use push like this `array_name.unshift(the_data)`

```js
var e = [1,2,3,4,5,6];
e.unshift(0) // this will add 0 to the front of the above array
```

- shift is used to add an extra member to the starting of an already defined array, lets say we want to add 7 to a number array, then we will use push like this `array_name.shift()`

```js
var e = [1,2,3,4,5,6];
e.shift() // this will remove 1 from the front of the above array
```

- splice: to remove anything in between from the array, we'll use splice and its syntax goes like this `array_name.splice(index_no, no_till-which-to-remove`. We need to add the array_name followed by a dot then the splice which takes params as the first index no which is to be removed and followed by the no of stuff that is to be removed after that counting from the first param as 1. Eg:


```js
var e = [1,2,3,4,5,6];
e.splice(1,2) // this will remove 2 and 2 numbers from 2 i.e till 3 from the front of the above array
```

## Objects

First an example: all the rubik's cube of a state or all the rubik's cube of a country, etc, these examples can be many of the same type and as such they are arrays. But object holds the details of an individual in a key value pair.

1. Blank object: In JavaScript, blank object is something like this `var a = {};` blank curly braces can be termed as an object in JS

2. Filled object: But a filled objects is something like `var a = {add_anything_you_like}`. One example: details of a person

```js
var a = {
age: 24,
name: "Harsh",
email: "email@gmail.com",
linkedin: "nothing",
ph_no: 012734091279407
};
```

lets say we want to add details of a watch, we can do something like

```js
var watch = {
brand: "Casio",
price: 5000,
color: "silver",
type: "automatic",
digital: false
method: function(){}
};
```

This is what objects are used for, when we have to write all details about a single identity/ individual

- And how to access these details, for the above example of watch we can use this -> `watch.price` (`name-of-var.args-inside-var`)
  - **Properties**: These args inside the vars, such as brand, price, color, etc are known as properties/prop
  - **Methods**: It is a special property which takes a function as a value. So a property inside an object which has a value as a function is known as a method

- And to change these values, you can use the same syntax like the above `name-of-var.property = "replaced-with-data";`
