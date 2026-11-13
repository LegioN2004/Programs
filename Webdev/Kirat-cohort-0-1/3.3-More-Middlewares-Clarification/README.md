# Middlewares

- Express is a routing and middleware web framework that has minimal functionality of its own: An Express application is essentially a series of middleware function calls. Express is a very minimalistic thing and is not meant to be a framework.

  - In the amusement park example, the ticket collector is the middleware which stays in the middle to see who has the legit access or a ticket and those who don't have it they are kicked out. According to express' documentation the last point(function, since it has nothing to pass on to the next so it doesn't take a next var nor does it call it in the end) is also a middleware, technically everything that is present here can be called a middleware, even though it is in the end. Also can be called the route handler since it is the last thing that the user wants to access.

- Middleware functions are functions that have access to the request object (req), the response object (res), and the next middleware function in the application's "request-response cycle". The next middleware function is commonly denoted by a variable named next

  - the request-response cycle means the cycle which checks if the person has a proper legit ticket or not or gets kicked out if not. And then they get access to the park. This means that the request-response cycle does a bunch of prechecks to check everything before a proper outcome happens

- Middleware functions can perform the following tasks:

  - Execute any code
  - Make changes to the request and the response objects.
  - End the request-response cycle.
  - Call the next middleware function in the stack

- The main high level goal of middlewares and their chaining is to each of them will do something specific and then the end contains what they want but for that they will have to go through a bunch of prechecks which are again those middlewares
- But why not do this in a single big middleware function, the reason is that middlewares can be reused again and again. Lets say for different parks you will have different ticket checkers(can have same, for just our case), but you can have a single ticket sellers who sells those tickets and as such you are reusing the ticket seller middleware again and again.
- The only bad usecase of middlewares is making different types of middleware having the same logic and then using them. For the example, making different ticket sellers as well as ticket checkers for different amusement parks and that violates DRY as well

#### Some doubt fixing using chatGPT but to be noted here

- query

---

```js
const express = require("express");

const app = express();

// returns a boolean if the age of the person is more than 14

function appChecker(req, res, next) {
  if (!(req.query.age >= 14)) {
    res.status(411).json({
      msg: "You are not of the right age yet",
    });
  } else {
    res.json({
      msg: "You are of the right age welcome",
    });
  }
  next();
}

app.get("/ride1", appChecker, function (req, res) {
  res.json({
    msg: "You have successfully rode the ride 1",
  });
});
app.get("/ride2", appChecker, function (req, res) {
  res.json({
    msg: "You have successfully rode the ride 1",
  });
});
```

I am not getting next(), res.send, res.status, and res.json; what does even happen here?
Here are my assumptions based on what I have learnt about them. Please tell if I am correct or not
next(): It is like a break statement and just helps to move to the next consecutive function but when in a conditional statement if there is a res.send or res.status before it and the condition gets fulfilled then it doesn't go to the next following function.
res.send: it just says that your request was correct and sends an ok like response much like return 0 in cpp
res.status: is used to send a status code with the response and then can be joined with a json response to show some extra messages in a json output

---

- response

---

Your understanding is close, but there are some nuances to clarify:

1. **`next()`:** Your analogy with a break statement is quite fitting. In Express.js, `next()` is used to pass control to the next middleware function in the stack. If `next()` is not called, the request-response cycle is terminated, and subsequent middleware in the stack won't be executed.

2. **`res.send()`:** This method is indeed used to send a response to the client. It can send any kind of response, not just "OK." It automatically sets the `Content-Type` header based on the response content, and it can send strings, HTML, or JSON. It also terminates the request-response cycle unless `next()` is called.

3. **`res.status()`:** This method is used to set the HTTP response status code. It does not send the response on its own. If you chain it with another method like `json()`, then it will send the response. For example, `res.status(200).json({ message: 'Success' })` will set the status code to 200 and send a JSON response.

Now, looking at your code:

```javascript
function appChecker(req, res, next) {
  if (!(req.query.age >= 14)) {
    res.status(411).json({
      msg: "You are not of the right age yet",
      // it just ends the request-response cycle
    });
  } else {
    // but if the above is not true then it returns this message
    res.json({
      msg: "You are of the right age welcome",
    });
  }
  next();
}
```

Here, the `next()` is always called regardless of the age condition. If you want to prevent further middleware from running when the age condition is not met, you should place `next()` inside the `else` block.

```javascript
function appChecker(req, res, next) {
  if (!(req.query.age >= 14)) {
    res.status(411).json({
      msg: "You are not of the right age yet",
    });
  } else {
    res.json({
      msg: "You are of the right age welcome",
    });
    next(); // This ensures that next is only called when the age condition is met.
  }
}
```

Remember, the order in which you place middleware functions in your Express application matters. Middleware functions are executed in the order they are declared

- `res.json()` is a method in Express.js that is used to send a JSON response to the client. It does a bit more than just sending an "OK" message. Here's what it does:

1. **Set Content-Type Header:** It automatically sets the `Content-Type` header of the response to `application/json`. This indicates to the client that the response contains JSON data.

2. **Converts to JSON:** It converts the given object into a JSON string. If you pass an array or an object to `res.json()`, it will be converted to a JSON string and sent as the response body.

3. **Sends the Response:** It sends the JSON response to the client.

Here's a simple example:

```javascript
app.get("/example", (req, res) => {
  res.json({ message: "Hello, JSON!" });
});
```

In this example, when a GET request is made to `/example`, the server responds with a JSON object: `{"message": "Hello, JSON!"}`.

It doesn't necessarily mean "OK"; it just means the server is responding with JSON data. The HTTP status code associated with the response depends on the method you chain with it. If you chain it with `res.status()`, like `res.status(200).json(...)`, it will set a specific status code (in this case, 200 for "OK"). If you don't chain it, it defaults to 200.

---

- So after the middleware logic is written you just need to add the prechecks there. Rest of the status ok message will be sent from the last function of the request.

### Assignment stuff

---

## 02-ratelimiter.js

In JavaScript, when you want to access an object property with a name that includes characters not allowed in variable names (such as a hyphen `-`), you must use square brackets notation.

So, in the case of `const userId = req.headers["user-id"];`, the `headers` object has a property named `"user-id"`, and using square brackets allows you to access the value associated with that property. If you were to use dot notation (`req.headers.user-id`), JavaScript would interpret it as an attempt to access a property named `user` on the `headers` object, followed by the subtraction of `id`.

In short, when dealing with property names that include special characters, spaces, or reserved words, you should use square brackets notation to access those properties in JavaScript.

2. **Middleware:**

   ```javascript
   app.use(function requests(req, res, next) {
     if (numberOfRequestsForUser[req.headers["user-id"]]) {
       numberOfRequestsForUser[req.headers["user-id"]]++;
       if (numberOfRequestsForUser[req.headers["user-id"]] > 5) {
         res.status(404).send("bhaad me jaaon");
       } else {
         next();
       }
     } else {
       numberOfRequestsForUser[req.headers["user-id"]] = 1;
       next();
     }
   });
   ```

   - The middleware function checks if there is an entry for the user in `numberOfRequestsForUser`.
   - If the user already exists, it increments the request count for that user. If the count exceeds 5, it sends a 404 response.
   - If the user is not found, a new entry is created for the user, and the request is allowed to proceed.
   - In both cases, the `next()` function is called to move to the next middleware or route.

---

---

## 03-errorcount.js

- what is an errro in js?: Whenever we do something like finding the length of a variable that is undefined much like `const a; console.log(a.length)`, then it throws a big error. But in the case of express applications you cannot show that to the end user because that may introduce security issues by exposing the server stuff. So a new thing comes into the picture mainly to show error messages instead of showing what happenend in the actual code in detail.
- By default, express shows the server logs and an error code of 500 if there is an exception error
- The error that is thrown in the client side which should not be shown, the error middleware gets access to that in the first err variable defined in it.

---
