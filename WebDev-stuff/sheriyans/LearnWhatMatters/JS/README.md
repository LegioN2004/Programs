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

- functions are mainly used for three:
  - When you don't want to run the code the same time but in the future
  - When you want to reuse your code
  - When you want to run the same code with different data
