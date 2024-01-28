# all about map filter and arrow functions

- misc: Go to the misc directory to get more details on these js stuff of es6, React and more

## arrow functions

- normal functions

```javascript
function sum(a, b) {
  return a + b;
}
```

- mentos zindagi arrow functions: It is just another way of writing functions, but the syntax makes it clear that there is a difference between the two. They are almost very similar, but the type seems like a very good difference between the two, more on that later on.

```javascript
const sum = (a, b) => {
  return a + b;
};
```

## map function

- JS says that if you have a transformation function and an initial input array, then you can give both of them to receive the desired output, that is what map function is. The syntax goes something like `map(array, transformation_function)`.

```javascript
const input = [1, 2, 3, 4, 5];
function transform(i) {
  return i * 2;
}
const ans = input.map(transform);
console.log(ans);
```

- Whenever we are asked to transform arrays, we use this map function
- `input.map(transform)`: means that transform every value from the 'input' variable through this transform function and give the output
- We can also do something like making the function inside of the map function itself and then transform directly

```javascript
const input = [1, 2, 3, 4, 5];
const ans = input.map(function (i) {
  return i * 2;
});
console.log(ans);
```

- map is very important for react and all, you can get by but it makes the code cleaner
- It would be very nice if there was a global map function

## filter function

- the filter function works on the following logic
- if there is a filtering logic that returns true for even numbers and false otherwise based on what n is

```
function filteringLogic(n){
if(n%2==0){ return true }
else{ return false }
}

```

- So the syntax goes like `fiter(input, fitlering_function)`
- Whenever the filtering logic returns false it just removes the stuff at that index of the array

```javascript
const arr = [1, 2, 3, 4, 5];
// ans  should be: [2, 4]
function filterLogic(n) {
  if (n % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

console.log(arr.filter(filterLogic));
// might as well remove a explicit function and replace it with an anynymous function inside the filter function itself
```

```javascript
const ans = arr.filter(function (n) {
  if (n % 2 == 0) {
    return true;
  } else {
    return false;
  }
});
console.log(ans);
```

- It would be very nice if there was a global filter function
- This syntax is conventionally a more cleaner syntax

## Misc stuff

- another helper function present on the string class that helps to sort out strings that starts with the char/letter specified; `startsWith("char")` use it with the '.' operator
