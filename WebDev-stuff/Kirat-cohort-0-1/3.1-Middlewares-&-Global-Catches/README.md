# Middlewares and Global-Catches

Example: Assume you are in a hospital, where you have one doctor doing all the prechecks like insurance check, blood test, bp check and once these are passed successfully then the patient is allowed to enter the doctor's cabin otherwise he/she is pushed out. So the doctor here is working like the main JS thread and the patients that come are from the requests from the callback. The equivalent code is as follows

```js
const express = require("express");
const app = express();

app.get("/health-checkup", (req, res) => {
  res.send("your heart is healthy");
});
```

The prechecks, where should they happen, should they happen in the requests itself or somewhere else, here comes the concept of middlewares.
In the real world, the real use case of "middlewares" is usually to do prechecks like the above bp test, blood test, etc, but in the world of webdev, the prechecks consists of either "authentication"(to check if the person is properly logged in the website) and then something called "input validation"(i.e they are trying to access this logic but has the user sent the right input). So these two happen before the actual logic starts running. So this is the usecase of middlewares, they are used to do these prechecks

## Middlewares

So how to do these checks, below is a very ugly way of doing what middlewares do without using middlewares

```js
const express = require("express");
const app = express();

app.get("/health-checkup", function (req, res) {
  const kidneyId = req.query.kidneyId;
  const username = req.headers.username;
  const password = req.headers.password;

  if (username != "harkirat" && password != "pass") {
    res.status(400).json({
      msg: "user doesn't exist",
    });
  }
  if (kidneyId != 1 && kidneyId != 2) {
    res.status(411).json({
      msg: "wrong inputs",
    });
    return;
  }

  res.send("your heart is healthy");
});
```

- _Misc stuff_: in a conditional statement like `(username != "harkirat" && password != "pass")` you can also do something like adding the not exclamation mark on the very front and then enclose the real statement with parentheses removing the exclamation mark used two times like this `!(username == "harkirat" && password == "pass")`

- Again if it is asked to do some kidney replacement then you will have to do the same checks again, you can just copy paste the previous code of the get request in the post request and that'll be done, but we are breaking the DRY rule, since if we want to do those 20 times there will be lot of unneccessary stuff. So we could just introduce a function that does all the checks and the returns true or false and according to those we can do the checks and replacement. But still the function has some code that is being repeated and as such the problem of DRY doesn't fade away.
- So the real opitimum in express and in other languages where you will have to do a bunch of prechecks are to use middlewares.
- How it is done? In a method request we can send a bunch of callbacks or directly write functions inside the request method itself, so the middlewares are initialized in that way and then we can define those functions inside or run them as a callback and write the names inside the request method itself and then we can apply the precheck logic that we did inside the request method, outside of the method inside the function that will be made outside but called as a middleware inside the request method params.

```js
// here the username and other credential logic is not written
// defining middlewares is just like another function
function userMiddleware(req, res, next) {
  if (username !== "harkirat" && password !== "pass") {
    res.status(400).json({
      msg: "user doesn't exist",
    });
    return;
  } else {
    next();
  }
}

function kidneyValidator(req, res, next) {
  if (kidneyId !== 1 && kidneyId !== 2) {
    res.status(400).json({
      msg: "inccorect inputs",
    });
    return;
  } else {
    next();
  }
}

app.get(
  "/health-checkup",
  userMiddleware,
  kidneyValidator,
  function (req, res) {
    res.send("your heart is healthy");
  },
);

app.get(
  "/kidney-checkup",
  userMiddleware,
  kidneyValidator,
  function (req, res) {
    res.send("your kidney is healthy");
  },
);

app.get("/heart-checkup", userMiddleware, function (req, res) {
  res.send("your heart is healthy");
});
app.listen(3000);
```

### explanation of how to use middlewares

- This is how a middleware is initialized, here in the method request we can write as many functions as we want by separating them with commas as per usage, but for our prechecks we only need two. So we'll define two functions and they'll take two params as the main logic function took inside the method requests.
- So when we run we can see that the control enters the first request in order and then runs the first function and waits till it gets a res.json
- But we'll need the second one, so we need to provide something that will route the control to the second function, then the third and so on as per needed. Here comes `next()`, which is a function itself that routes the control thread to the next function and you can add and ultimately call them if things are fine in the function. What is to be done is that we need to pass the `next` as parameter in the function itself and then call the next function using `next()` after the end of the logic at the end of the function and things are okay
- This 'next' is express's way of chaining through the middlewares, so that control reaches the next function and so on. And the last one doesn't need next since it is the end and that contains the `res.something` to send something or else.

```js
app.get(
  "/health-checkup",
  function (req, res) {
    console.log("hello from the first function/ req1");
  },
  function (req, res) {
    console.log("This is the log from req2");
  },
);
```

- Things to note:

1. you cannot respond back to a http request twice, if you have send a res.json once in one middleware, if you send another one in another middleware then it'll show error
2. `return` just ends the control so that it doesn't go to something after that logic ends with `return`
3. middleware functions are not like standard functions and so it doesn't take values and return an output, it takes req and res and next objects as input

### last in middleware: `app.use(express.json())`

- when we used this line in our previous code, it is the only option to send json data to send back info in the body of the request otherwise the request gets undefined as the body which is not readable
- This `app.use(middleware)` is a request and the use means that the param it takes is a middleware and it will apply to all the method requests to any route "after", after this app.use line. It is the same as writing that middleware to be applied to every request respectively if we know that that middleware will be applied to every request and as such we can use the `app.use()` instead
- Note:

1. We don't need to call middleware that are defined by us, only if there are special cases like the `express.json()` which itself returns a function and not a value and as such we need to call this as a middleware in the `app.use()`
2. Also the user defined middleware needs to have a `next()` function called in all cases be it in the `app.use()` or in the method request, otherwise the control will not go forward, i.e in cases of `app.use()` where it needs to be defined before the request, if there is no next then it'll not reach the method and thus nothing will work

## Input validation

- Why we need it: What if the user sends the wrong body. Since our backend is out on the internet the end user can do anything they like and it is our job to make it fool proof so that the backend doesn't break on some petty inputs. This is why is we need "Input Validation" so that some random user doesn't break our app.
- The following is one way of handling prechecks, using if else statements which is as visible very annoying and DRY prone. As such there are better ways to do so incoming later on like the Zod library, etc.

```js
app.use(express.json());
app.post("/health-checkup", function (req, res) {
  const kidney = req.body.kidney;

  // very bad validation checks using if-else statements
  if (!kidney) {
    return res.status(404).json({
      msg: "wrong input",
    });
  } else {
    const kidneyLength = kidney.length;
    res.send("your kidney length is " + kidneyLength);
  }
});
```

### Global-Catches middleware

Error handling middleware in Express.js is used to handle errors that occur during the processing of a request or response. These middleware functions have four parameters: `(err, req, res, next)`. When an error occurs in a route or in a previous middleware, Express jumps to the next error-handling middleware in the middleware chain.

Here's an example of how you can define error-handling middleware:

```javascript
const express = require("express");
const app = express();

// Regular middleware
app.get("/example", (req, res, next) => {
  // Some processing that might cause an error
  try {
    // Some code that might throw an error
    throw new Error("This is an example error");
  } catch (error) {
    // Pass the error to the next middleware
    next(error);
  }
});

// Error-handling middleware
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).send("Something went wrong!");
});

// Start the server
app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
```

In this example:

1. The regular middleware in the `/example` route simulates an error by throwing an `Error` object.
2. The error is caught using the `catch` block, and it's then passed to the next middleware using `next(error)`.

The error-handling middleware comes into play:

```javascript
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).send("Something went wrong!");
});
```

Here's a breakdown:

- `(err, req, res, next)` are the parameters of the error-handling middleware.
- `err`: The error object that was passed to `next(error)` in the previous middleware.
- `req`: The request object.
- `res`: The response object.
- `next`: The next middleware in the chain. In error-handling middleware, it's not required, but you can use it if you want to pass the error to the next middleware.

In the error-handling middleware:

- The error is logged (you might want to log it to a file or external service in a production environment).
- The response status is set to `500 Internal Server Error`.
- A generic error message is sent to the client.

You can have multiple error-handling middleware functions, and Express will call the next one in the stack if needed. Remember to place error-handling middleware at the end of your middleware stack.

- following are my notes
- Note: Also whenever we send a wrong input(as per the above code), the user is able to read through the server logs(kind of logs), exceptions and some logic(which it should not be) as such it makes it more prone to attacks since it is now more specific and easy how to break the server. The end user should see some kind of server error message instead of those and a status code. Express does take care of it in production level

1. But another way of handling those are by using **global-catches** which is written at the end of all the logic and routes and is a middleware, if there is an exception in the above logic of requests, routes, etc.
2. And it is done by a function that takes four arguments in the following manner, err, req, res, next. This suggests that the function is a global-catch
3. In the above example, we are reading kidney's length but since it is a thing given in the body and it has erred it shows out in the site as server error, this is an 'exception'. And since it should be avoided being shown in all costs, so if we have the global-catchor a function that takes four inputs, then the control reaches there and it automatically invokes itself removing those errors from the site and instead sends a cleaner message and the exception gets hidden
4. Other than the convention middlewares that takes three inputs, there are these '_error-handling middlewares_'(or called something like that) which takes four inputs and they are always at the end of the main request methods and logic but before the port listening and if there is an exception then the control flow reaches those.
5. In this global-catch, devs can send these messages to some other place instead to keep track of stuff and to debug.

```js
app.use(function (err, req, res, next) {
  res.json({
    msg: "Sorry, something is wrong with our server, will be fixed soon :)",
  });
});
```

# Authentication & Zod

- The above examples had if else statements as the input validation but they're very hard to scale and is very limited
- Whenever we are handling auth requests, we have to do multiple checks and for signup/signin they'll send an email(only gmail), password (strong 6 characters, should have small and caps letters) and so on, and the amount of validation checks are very hard to keep track of.
- So there came a bunch of input validation libraries, which do all the things internally and the devs don't need to worry about the logic. You only need to send one call and tell the structure.
- The most popular library is "**Zod**" in node.js and to use that we need to install it like we did with express
- It has something called 'schema validation' and that is what we'll learn
- By importing zod `const zod = require("zod"); // importing zod` we can use zod to parse the input from the end user to see if the user is sending the right input or not
- The zod library has a lot of functions which we can call using the dot operator and that gives us ways to parse different types of data. So we need to do something like `const schema = zod.string()` then we can tell zod that the input taken should consist of string and then we can use the `schema.safeParse("string")` it either returns `{success: true; data: "given_string" }` or `{success: false; error: ZodError }`. This schema variable is used to define a function provided by zod to do all the validation/parsing.
- For our file kidneys, we can do something like the following to define the structure of our input to zod
- And to parse the input using the variable we need to do, `const response = schema.safeParse(kidney);`

```js
const express = require("express");
const zod = require("zod"); // importing zod
const app = express();

// telling zod that the datatype sent by the user will be of array of numbers
const schema = zod.array(zod.number());
app.post("/health-checkup", function (req, res) {
  const kidney = req.body.kidney;
  // this is how to parse the input
  const response = schema.safeParse(kidney);
  <!-- const kidneyLength = kidney.length; -->
  <!-- res.send("your kidney length is " + kidneyLength); -->
  if (!response.success) {
    res.status(411).json({
      msg: "Input invalid",
    });
  }else{
    res.status(200).json({
      msg: "Input invalid",
    });

    }
  res.send({
    response,
  });
});
app.listen(3000);
```

- by running the above code we get the output as and it is very useful for devs as well as end user. Now we can use the error messages to do diefferent stuff since it is in json

```html
{"response":{"success":false,"error":{"issues":[{"code":"invalid_type","expected":"array","received":"undefined","path":[],"message":"Required"}],"name":"ZodError"}}}k
```

- The main stuff is how to do complex validation checks like email that contains various types of characters as well as passwords which is naturally complex and also needs to be of certain length. eg:

```js
{
  email: string => email containing @/numbers/etc
  password: atleast 8 letters
  country: "IN"/"US",etc
}

```

then the schema would look like:

```js
const schema = zod.object({
  email: zod.string().email(), // to parse emails too
  password: zod.string().min(8), // to make it minimum 8 letters
  country: zod.literal("IN").or(z.literal("US")),
  kidney: zod.array(zod.numbers()),
});
```

It can get more and more nested and so we should be very well versed with writing those since they are necessary and then using them is a breeze. It has a bunch of other validation schemas and should be read for reference at [zod.dev](https://zod.dev)
