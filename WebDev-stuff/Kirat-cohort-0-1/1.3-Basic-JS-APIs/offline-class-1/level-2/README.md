# level 2 notes

OOPS ig

## classes

- Classes let you put a bunch of properties of a certain type together, like metadata functions that have been done previously, only the data is assigned by not with the assignment operator `=` but with colons `:`

```javascript
const dog = {
  name: "doggie",
  legCount: 2,
  speaks: "bhow",
};

const cat = {
  name: "mequrie",
  legCount: 2,
  speaks: "meow",
};

console.log("animal " + dog["name"] + " " + dog["speaks"]);
console.log("animal " + cat["name"] + " " + cat["speaks"]);
```

- now what we are seeing here is that for animal we know that they'll have the same set of properties and they'll have some similar functions they need to run only the body of the functino will change and also here these properties are being used two times but separately and logged out two times separately as well. The same goes for functions too, even if we use them they'll still be needed to call two times as well. So to solve this issue we can use classes, i.e why not combine this together and give a structure to every animal and provide that.

- Class in CS means give out a structure of something that is reusable and can used in multiple places
- Object is the one that is created after the class declaration and then called accordingly to create the object that'll do some work

- This is how classes are created

```javascript
class Animal {
  constructor(name, legCount, speaks) {
    this.name = name;
    this.legCount = legCount;
    this.speaks = speaks;
  }
  speak() {
    console.log("hi there" + this.speaks);
  }
}
// instead you shold make a new class like this since this creates a new object
let dog = new Animal("doggie", 4, "bhow"); // this is how we create an object
let cat = new Animal("mequrie", 4, "meowwwwwwwwwwwwww"); // this is an object

dog.speak(); // call function on object
```

- What this class contains
  1. first it'll have some attributes (say eg: no of flooors, color, etc)
  2. the functions that will do some work that is happening in the object(say eg: flush the sewerage down the drain out of the building)
- This is good because there are a few functions that we know that will contain the same kind of properties, for eg: speak() function that both of them will have, etc.
- This is cool because everything that has been created is in the blueprint and we won't have to make a no of separate functions and call them separately to make these work, rather we can say that everything that we need has been put together in the class and who needs to create an animal (in our example) can call this class with the required values.

- You should not do the following, instead of this do the above declaration which is the dog var because this is creating an object of the class.

```javascript
// you shouldn't do this when making a class
let dog = {
  name: "doggie",
  legCount: 4,
  speaks: "bhow",
};
```

- A class is a blueprint, lets say a person created a blueprint of a building but the actual building was created in many other places. That blueprint(dog in our case) can be converted to real object multiple times and that is the object and the main class is the blueprint.
-

### static methods

```javascript
class Animal {
  constructor(name, legCount, speaks) {
    this.name = name;
    this.legCount = legCount;
    this.speaks = speaks;
  }
  static myType() {
    // this is the static class declaration
    console.log("animal");
  }
  speak() {
    console.log("hi there" + this.speaks);
  }
}

console.log(Animal.myType());
// console.log(Animal.speak()); wrong
```

- it is a type of method, which says that I am an animal this method is not associated to an object it is associated to a class itself, so we can directly log out the output and the other objects are not related anyhow
- but the speak function can be called on an object of the class but not directly on the class and as such to directly call with the class you need to make it of the `static` type
- With the static type a function can be called without instantiating an object if you don't have a static method then you will need the object to invoke that.

## global Date time class

- global class means that it is present to use out of the box, it is not specifically a keyword but it is a premade class that has been given by the JS people for ease of use.
- The way you use it is by creating an object.

### Date class

```javascript
const currentDate = new Date();

console.log(currentDate);
console.log(currentDate.getMonth());
console.log(currentDate.getDate());
console.log(currentDate.getYear());
console.log(currentDate.getFullYear());
console.log(currentDate.getTime());
```

- Create a new object in the first line using java like syntax
- To get the current month: log the output using the currentDate object with a dot operator with the `getMonth()` inbuilt function which prints the current month using local time but it is 0-indexed so you need to add 1 to get the correct month
- To get the current date: log the output using the currentDate object with a dot operator with the `getDate()` inbuilt function which prints the current date using local time
- To get the current year: log the output using the currentDate object with a dot operator with the `getYear()` inbuilt function which is an integer representing the year for the given date according to local time, minus 1900. Returns NaN if the date is invalid. But by using the `getFullYear()` function we get the correct year accordingly
- output of currentDate directly gives a string input of all the current date and time
- You can also get the current time in the 24 hour format, by using `getHour()` `getMinutes()` `getSeconds()`
- To change the current stuff of the above you can use set instead of get and then you can set something by yourself
- This `console.log(currentDate.getTime());` is a special one because it prints the no of time in ms elapsed since the year 1970, it is called 'epoch timestamp'. Why 1900 because you will have to pick some starting date eventually and using 0 as the starting year is a too far fetched.

- so we can make something like a low budget watch

```javascript
function currentTime() {
  console.clear(); // to clear the tty output everytime
  console.log(
    new Date().getHours() +
      ":" +
      new Date().getMinutes() +
      ":" +
      new Date().getSeconds(),
  );
}
// setInterval(currentTime, 1000)
setInterval(currentTime, 1000);
```

- some misc stuff
  - The issue with the code setInterval(currentTime()) is that when you add the function brackets (), you're actually calling the function currentTime immediately rather than passing it as a reference to be called at intervals by setInterval. To fix this, you should pass the function reference without the brackets, like this: setInterval(currentTime, 1000). This way, the currentTime function will be executed at intervals of 1000 milliseconds.

## one of the most important parts of JS, JSON = JavaScript Object Notation

Why is it used: What if you want to send this data to a different place, the way you do that is by converting it to a string since if we use an object no one will understand but everyone understands string, especially JSON for data stuff

```javascript
const users = ' {"name": "hello", "age": 24, "gender": "male"} '; // this converts the object to a string, it still looks like an object but this is actually a string

// console.log(users["name"]); // prints the output for the name in the case of objects only but not in case of the string

console.log(JSON.parse(users)["name"]);

// after the conversion using parse it becomes something like

const users2 = { name: "hello", age: 24, gender: "male" };

console.log(JSON.stringify(users2));
// using stringify we can convert the above object into a string
// like this {"name":"hello","age":24,"gender":"male"}
```

- The above users variable contains this string which looks like an object but it is actually a string and by sending it to the other side can parse it to take in the data and by doing that we are not restricting any javascript object types when we are sending out data. This is a good thing to be able to convert an object to a string that looks something like the above example and vice versa to be able to pass a string like this back into an object. Since the other side may not know what is a javascript object and as such we converted that object to a string that looks similar to that of an object
- As such we cannot use the log output for the name in the case of users' objects since it is a string
- So we'll frequently need to interchange between a JS object and a JS string and as such we have this JSON class which gives us two high level functions `JSON.parse` and `JSON.stringify`, it's name is self explanatory
- NOTE: to convert the object to string, you need to give the attributes(say for now, eg: name, gender, age, etc) and values inside the double quotes otherwise it'll not be able to parse them, since it assumes everything to be of the string type
- stringify: you can use the `JSON.stringify` to do the reverse of the parse function, i.e convert the object to a string

- some misc stuff
  - There is an error occurring trying to access the "name" property from the JSON string users after the parse using square brackets as if it were an object, but it is actually a string when you directly access within the parenthesis. To fix this, you can initialize it to a variable and then access the "name" property using dot notation or the brackets or you can do the same after the the parenthesis containing the users variable. Here's the corrected code: `console.log(JSON.parse(users).name;` or `console.log(JSON.parse(users)["name"];` .
  - what is that dot for: In JavaScript, the dot notation is used to access/modify properties and methods of an object.

## Math global class

Math object in JavaScript is not a class; it's a built-in object that provides a set of mathematical functions and constants. The functions and properties provided by the Math object are static, meaning you don't need to create an instance of Math to use them. The Math object includes various methods for common mathematical operations, such as trigonometry, logarithms, rounding, random number generation, and more.

1. **`Math.round(value)`**

   - Rounds the given `value` to the nearest integer.
   - Example: `Math.round(4.56)` results in `5`.

2. **`Math.ceil(value)`**

   - Returns the smallest integer greater than or equal to the given `value`.
   - Example: `Math.ceil(4.56)` results in `5`.

3. **`Math.floor(value)`**

   - Returns the largest integer less than or equal to the given `value`.
   - Example: `Math.floor(4.56)` results in `4`.

4. **`Math.random()`**

   - Returns a random floating-point number between 0 (inclusive) and 1 (exclusive).
   - Example: `Math.random()` might result in `0.7294829101`.

5. **`Math.max(...values)`**

   - Returns the largest value among the provided arguments.
   - Example: `Math.max(5, 10, 15)` results in `15`.

6. **`Math.min(...values)`**

   - Returns the smallest value among the provided arguments.
   - Example: `Math.min(5, 10, 15)` results in `5`.

7. **`Math.pow(base, exponent)`**

   - Returns the value of the base raised to the power of the exponent.
   - Example: `Math.pow(4.56, 2)` results in `20.8036`.

8. **`Math.sqrt(value)`**
   - Returns the square root of the given `value`.
   - Example: `Math.sqrt(4.56)` results in `2.1354`.

These functions are part of the `Math` object in JavaScript and are useful for various mathematical calculations in your code.

### Objects

- The syntax for an object using an object initializer is:

```javascript
const obj = {
  property1: value1, // property name may be an identifier
  2: value2, // or a number
  "property n": value3, // or a string
};
```

- Each property name before colons is an identifier (either a name, a number, or a string literal), and each valueN is an expression whose value is assigned to the property name. The property name can also be an expression; computed keys need to be wrapped in square brackets.

- explanations for each of the Object methods used in `objectMethods` function:

  - We can think of Object as a class and the keys as the static method on that class, so when we call this static method on this class and pass a specific input (obj) in that keys() which can be any object then it gives you an array which contains the keys for that specific object

  1. **`Object.keys(obj)`**

  - Returns an array of a given object's own enumerable property names/keys.
  - took the three keys out of the main object and put them in an array
  - Example: `Object.keys({ key1: "value1", key2: "value2" })` results in `["key1", "key2"]`.

  2. **`Object.values(obj)`**

  - Returns an array of a given object's own enumerable property values.
  - took the three values out of the main object and put them in an array
  - Example: `Object.values({ key1: "value1", key2: "value2" })` results in `["value1", "value2"]`.

  3. **`Object.entries(obj)`**

  - Returns an array of a given object's own enumerable property `[key, value]` pairs.
  - took the three `key:values` pairs from the main object and then put them in an array and put all of the pairs' array in another main array and it consists of all the values
  - Example: `Object.entries({ key1: "value1", key2: "value2" })` results in `[["key1", "value1"], ["key2", "value2"]]`.

  4. **`obj.hasOwnProperty(prop)`**

  - Returns a boolean indicating whether the object has the specified property.
  - i.e if the object has the same key(property) as the name given inside the double quotes passed in the hasOwnProperty function, then it returns true otherwise it returns false
  - Example: `obj.hasOwnProperty("key1")` returns `true` if the property exists.

  5. **`Object.assign(target, ...sources)`**

  - Copies the values of all enumerable own properties from one or more source objects to a target object.
  - This just lets you add new key:value pairs inside of the already defined object and as such gets merged in the orignal object.
  - the syntax goes like `Object.assign({}, obj, { newProperty: newValue })`, in the parenthesis firstly "{}" comes, then the object name, then the { key:value pair } in curly braces
  - Example: `Object.assign({}, obj, { newProperty: newValue })` results in `{ key1: 'value1', key2: 'value2', key3: 'value3', newProperty: 'newValue' }`.

  - the output which the code from the above/05-Object.js provides are

  ```js
  Original Object: { key1: 'value1', key2: 'value2', key3: 'value3' }
  After Object.keys(): [ 'key1', 'key2', 'key3' ]
  After Object.values(): [ 'value1', 'value2', 'value3' ]
  After Object.entries(): [ [ 'key1', 'value1' ], [ 'key2', 'value2' ], [ 'key3', 'value3' ] ]
  After hasOwnProperty(): false
  After Object.assign(): { key1: 'value1', key2: 'value2', key3: 'value3', newProperty: 'newValue' }
  ```

#### some stuff found after the solving of problems

##### hasOwnProperty()

`hasOwnProperty` is a method available on all objects in JavaScript. It is used to check whether an object has a specific property as its own property and not inherited from its prototype chain.

Here's the syntax for `hasOwnProperty`:

```javascript
object.hasOwnProperty(propertyName);
```

- `object`: The object on which to check for the property.
- `propertyName`: The name of the property to check.

The method returns a boolean value, `true` if the object has the specified property directly on itself, and `false` otherwise.

Here's an example:

```javascript
const myObject = {
  name: "John",
  age: 30,
};

console.log(myObject.hasOwnProperty("name")); // Outputs: true
console.log(myObject.hasOwnProperty("toString")); // Outputs: false (inherited from Object prototype)
```

In this example, `hasOwnProperty` is used to check whether the object `myObject` has its own property named 'name'. The first `console.log` returns `true` because 'name' is a property directly on `myObject`. The second `console.log` returns `false` because the 'toString' property is inherited from the Object prototype and is not directly on `myObject`.

##### in

In JavaScript, the `in` operator is used to check if a specified property exists in an object. It returns `true` if the property is found either directly on the object or in its prototype chain, and `false` otherwise.

Here's the basic syntax of the `in` operator:

```javascript
propertyNameOrIndex in object;
```

- `propertyNameOrIndex`: The name of the property or the index of the element to check.
- `object`: The object to check for the property.

The `in` operator is often used in conditional statements or as part of program logic to determine if an object contains a specific property.

Here's an example:

```javascript
const myObject = {
  name: "John",
  age: 30,
};

console.log("name" in myObject); // Outputs: true
console.log("gender" in myObject); // Outputs: false
```

In this example, `'name' in myObject` returns `true` because the property 'name' exists in `myObject`. On the other hand, `'gender' in myObject` returns `false` as there is no 'gender' property in `myObject`.

It's important to note that the `in` operator doesn't distinguish between properties that are directly on the object and those inherited from its prototype chain. If you specifically need to check for an own property (one that is not inherited), you might prefer using `hasOwnProperty` method, as mentioned in a previous response.
