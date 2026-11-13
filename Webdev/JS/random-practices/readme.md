when it's called, it gets pushed to the call stack until the function execution ends and clears the internal memory off of the call
stack. What if a function references data from outside the function i.e outside of
it's own scope, like a global env or an outer function? That leads us with an
open expression that references other free variables throughout the environment.

```js
let b = 3;

function impureFun(a) {
    return a + b;
}
```

Now in order for the interpreter to call this function and also know the value of these free variables, it creates a closure to
store them in a place in memory where they can be accessed later and that area of
memory is called the heap.

And unlike the call stack, which is short lived, it can keep data and
memory, and then decide when you get rid of it later with the garbage collector.

So a closure is not just a function. It's a function combined with its outer
state or Lexical environment. As one might imagine, closures require more memory and
processing power than a pure function, but we'll come across many practical
reasons as to why use them. The most important one being data encapsulation, to prevent leaking or exposing data where it's not needed.

```js
function outer() {
    let state = "1";

    function inner() {
        return `Hello ${state}`;
    }
}
```

the outer function that contains the state and inner function that operates on the data
contained here will not leak out to the surrounding environment. Inner function
has access to data defined in the outer function, but the outer function does
not have access to the inter function.

In addition many Java script, APIs are callback based. you can use closures to create a function factory that takes an
argument and returns a new function which can then be passed along to other functions that expect a call back.

```js
function alertFun(message) {
    return () => {
        alert(`${message}`);
    };
}

const alertMom = alertFun("hi mom");

alertMom();
```
