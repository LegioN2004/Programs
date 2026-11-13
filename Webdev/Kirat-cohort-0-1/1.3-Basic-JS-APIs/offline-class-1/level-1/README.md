# offline class 1

## Inbuilt functions for Strings

- These are some inbuilt functions and other stuff which are accessible whenever necessary, you can totally write the underlying logic yourself but it is recommmended to use these as they'll save a lot of time.

### length, but it is not a function

Whenever we have a string datatype or string variable or string object, we can do the length using `string.length` and it'll give the length of that string

### indexOf() function

- example

```javascript
// indexOf
function findIndexOf(str, target) {
  console.log("Original String:", str);
  console.log("Index:", str.indexOf(target));
}
findIndexOf("Hello World", "World");
```

Whenever we have a string, we can call the `indexOf()` function using `string.indexOf(target)` and it'll give the index of that string.
How does it work, we'll need to pass the arguments to the declared parameters of the function just as we normally do and as such we'll need to use them in the inbuilt function as needed, so here we are taking the params as str and target where str contains the main string and target is the one we are using this function where str contains the main string and target is the one we are using this function and the arguments are passed accordingly using the function name, and then we use the str to print out the original string and then to use the inbuilt functions we use the dot operator followed by the name of that inbuilt function `indexOf()` and `lastIndexOf()` in our case

- remember the index starts from 0
- spaces are also counted in the index
- it is case sensitive, anything other than the char of the string will give the result as -1 i.e it couldn't find anything
- If the same target is present 2 times then it'll print the first occurence's index

### lastIndexOf() function

```javascript
// lastIndexOf
function findLastIndexOf(str, target) {
  console.log("Original String:", str);
  console.log("Index:", str.lastIndexOf(target));
}
findLastIndexOf("Hello World World", "World");
```

To find the last index if the string is present for a number of times we'll use the `lastIndexOf(target)`

### slice() function

```javascript
// slice
function getSlice(str, start, end) {
  console.log("Original String:", str);
  console.log("After slice:", str.slice(start, end));
}
getSlice("Hello World", 0, 5);
```

To find the string starting from one index until other index, 0 to 5 here in our case, we can use the slice function. It takes a `slice(start,end)`, start and end argument and in the int type. One thing to note is that the index starts from the starting position but goes only till one position before the end, i.e in our case it takes from 0 to 5 so it'll print from 0th to 4th index.

- we also have `substr(start, no)` which is now deprecated, but this does slightly different stuff, it just prints output from the starting index but the next arugment says no which means that it'll print from the start index and the 'no' of characters after that

### replace() function

```javascript
function replaceString(str, target, replacement) {
  console.log("Original String:", str);
  console.log("After replace:", str.replace(target, replacement));
}
replaceString("Hello World", "World", "JavaScript");
```

To replace a string we'll use this, takes the arugments in the same manner as the above ones and the syntax goes something like, `str.replace("hello", "world");` where the first argument is the target where the changes have to be made and replacement consists of the string which is to be replaced with. **note**: We can directly use the replace function or we can call it to a variable containing a string using the dot operator or we can do something like the above function which takes an argument as the main string, target and replacement.

### split() function

What if we want to convert string into an array using something called a delimiter, we can then use the `split()` function. What it does is that it takes the delimiter as an input to it and then the string that it is called into, it just goes there and splits the stuff based on that delimiter.

- Delimiter is a string which helps split function cut off those parts and separate them in an array
- for eg: If we applied the delimiter as o to hello world, then this happens -> Original String: Hello World; After split: [ 'Hell', ' W', 'rld' ]
- If the delimiter contains something that is not present in the string, then it just prints the whole string as a single element (as index 0) in the array.

```javascript
function splitString(str, separator) {
  console.log("Original String:", str);
  console.log("After split:", str.split(separator));
}
splitString("Hello World", " ");
```

### trim() function

Sometimes we may add some spaces at the beginning or the end of the string, as the name suggests we can then use the `trim()` function it helps out trim out those extra spaces. **NOTE** it only does that for the beginning and the end and it doesn't interfere with the spaces in between the strings.

### toUpperCase() and toLowerCase() function

self explanatory, converts the whole string into upper or lower case as required

## Inbuilt functions for Numbers

### parseInt()

- It is a inbuilt function that converts the string into an integer
- **note**: It can also convert a number with text considering the letters/text comes after the number, or else the compiler will not be able to understand what it is if the letter comes before or in the middle of the number and as a result it prints NaN(idk what it means, maybe undefined?)
- Also it does not parse decimal numbers so anything that is written before the dot of the decimal will not be parsed so if the text comes in between the first number and the decimal then the no will get successfully printed

### parseFloat()

- It is a inbuilt function that converts the string into an float, i.e it can have both integer and decimal numbers
- **note**: It can also convert a number with text considering the letters/text comes after the number, or else the compiler will not be able to understand what it is if the letter comes before or in the middle of the number and as such it prints NaN(idk what it means, maybe undefined?)
- Also it does parse decimal numbers so anything that is written before the dot of the decimal will be parsed now so if the text comes in between the first number and the decimal then the first numbers only get printed and the rest of the letters/text and the numbers from the dot will not get printed

## Inbuilt array functions

### push(), shift(), unshift() and pop() function

- The push function adds a number to the end of the array, and that number is taken from the argument passed in the brackets eg: `initialArray.push(2)` you can add more using commas and they'll take place accordingly one after another
- The pop function removes a element from the extreme end of the array
- The shift function removes a element from the extreme front of the array
- The unshift function adds an element to the extreme front of the array and that can be done in the same way as the push function and you can add more using commas and they'll take place accordingly one after another

### concat() function

Assume we have two arrays and we want to merge them, then we'll use the `concat()` function. How it is done

```javascript
const initialArray = [1, 2, 3, 4, 5];
const secondArray = [6, 7, 8, 9, 10];

const mergedArray = initialArray.concat(secondArray);
console.log(mergedArray);
```

- or you can do this in the crackhead way using for loop
- To iterate over an array, you

### forEach()

`forEach()` function says that give it a function(user defined one logThing()) that takes a string as an input and it is going to call this function for every element(if element is [1, 2, 3] then it'll call three) of this array. It is similar to a for loop but its syntax is a little complex because it expects a function as an argument i.e callbacks

- The forEach method in JavaScript is used to iterate over the elements of an array and applies a provided function to each element. It takes a callback function as an argument, and this callback function is called once for each element in the array.
  Here's the basic syntax of forEach:

```javascript
array.forEach(callback(currentValue, index, array) {
  // Your logic here
});
```

- callback: The function to execute for each element.
- currentValue: The current element being processed in the array.
- index: The index of the current element.
- array: The array that forEach is being applied to.

```javascript
const initArray = [1, 2, 3];
function logThing(arr) {
  console.log(arr);
}
initArray.forEach(logThing);
```

- weird javascript logic

### splice()

The `splice()` function in JavaScript is used to modify the contents of an array by removing or replacing existing elements and/or adding new elements. Here are some key points about the `splice()` function:

1. **Syntax:**

   ```javascript
   array.splice(start, deleteCount, item1, item2, ...);
   ```

2. **Parameters:**

   - **start:** The index at which to start changing the array.
   - **deleteCount:** The number of elements to remove from the array.
   - **item1, item2, ...:** Elements to add to the array at the specified index.

3. **Return value:**

   - An array containing the deleted elements.

4. **Modifying the array:**

   - The `splice()` method changes the original array in place.

5. **Removing elements:**

   - To remove elements, set `deleteCount` to the number of elements you want to delete. If `deleteCount` is 0, no elements are removed.
   - The index is added at first from where the deletion will start and the next arg determines how many times the deletion should happen from the specified index(note: the deletion starts from the index itself and not after the index)
   - If there are many items that are added then it'll be added after the specified index, if the no of items are equal to the no of deletions that will happen then the new additons will just take place of the old ones and if not then it will get added after the specified index before the old elements.

6. **Adding elements:**

   - You can add elements by specifying them as additional arguments after `deleteCount`.

7. **Example:**

   ```javascript
   const fruits = ["apple", "banana", "orange", "grape"];
   const removed = fruits.splice(1, 2, "kiwi", "melon");

   // Result:
   // fruits: ['apple', 'kiwi', 'melon', 'grape']
   // removed: ['banana', 'orange']
   ```

8. **Dynamic use:**
   - You can use variables to dynamically determine the `start`, `deleteCount`, and elements to be added or removed.

The `splice()` function is a powerful and versatile method for manipulating arrays in JavaScript.

### map() filter() find() and sort() important in the next video

## find() using chatgpt

Certainly! The `find` function in JavaScript is a method available for arrays. It is used to find the first element in an array that satisfies a given condition. The basic syntax of the `find` method is:

```javascript
array.find(callback(element[, index[, array]])[, thisArg])
```

- `callback`: A function that is called for each element in the array. It takes three parameters:

  - `element`: The current element being processed in the array.
  - `index` (optional): The index of the current element being processed in the array.
  - `array` (optional): The array on which the `find` method is called.

- `thisArg` (optional): Object to use as `this` when executing the `callback` function.

The `find` method returns the first element in the array for which the callback function returns `true`. If no such element is found, it returns `undefined`.

Here's a simple example:

```javascript
const numbers = [1, 2, 3, 4, 5];

const foundNumber = numbers.find((num) => num > 2);

console.log(foundNumber); // Output: 3
```

In this example, the `find` method is used to find the first element in the `numbers` array that is greater than 2.

Remember that the `find` method stops iterating through the array as soon as the callback function returns `true` for the first time, so it only finds the first matching element. If there are multiple elements that match the condition, only the first one encountered will be returned.
