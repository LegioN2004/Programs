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

## Zod

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

## Authentication

- Since anyone can send requests to the backend, how can we ensure that this user has access to a certain resource
- Dumb way: Ask user to send username and password in all requests as headers
- Slightly better way:
  - give the user back a token on signup/signin
  - Ask the user to send back the token in all future requests(this token is stored on the local storage).The site checks for the email password the first time and returns a token, then the token is only used for subsequent requests.
    - We cannot store a password and email in the local storage since it is very open, but a token can be stored and can also be revoked by the backend when needed but you cannot change the email/password from the backend
    - So once you are logged-in in a website, then the website sends either a authorization header which is a token(details will be in the next class)
  - When the user logs out, ask the user to forget the token(or revoke in from the backend)

##### ended first class of the week here

# Fetch, Authentication and Databases

1. Fetch represents how can we send http requests from real websites, until now we have been using postman and a browser but how can we do that using a real website like chatgpt, etc when you click on a button
2. Authentication so as to make better security, since in our previous projects we are using some
3. Databases, where we store our stuff, mongoDB, high level differences

## The Fetch API

When in the chatgpt website we write something in the prompt and press the send button and a request goes out to slash conversation route and this is what triggers the backend chatgpt AI model to do something with the prompt and send back a response. How it is done is what we need to understand, the browser provides a function which is part of the JS runtime and whoever created the browser spec said that there will always bee a need to hit the backend servers and so they exposed a function called fetch which as the name suggest lets us fetch data from the backend

Up until now we were sending requests using postman and browser, but there is a third way of doing that. Let's say we create an html page where we can see the list of names of 10 people and we just need to make sure that we get these data from an API call. We can do that by writing the frontend, give a request and send that data back and show it in the frontend.

- In html there is a button tag, which has a property `onclick="function_name"` which takes a function defined in the javascript file.
- By default the fetch api sends a get request, but you can specify if you need anything else
- Since it fetching data and it takes some time, so it is an asynchronous function, therefore it returns a promise and as such it needs `.then()` to do something. Similarly when we enter the next iteration with the `response.json()` then another promise gets returned and as such we need another `.then()` with a function to print the final thing which is the json data we receive after hitting the api written by some good people
- So we have written a frontend code that gets some data back from backend written by others and shows it to the frontend
- We can also use the async await to do the same, and it is the preferred way to do async calls. Just add async to the function that will contain the async code and put await before the async calls before getting the data

## Authentication

- before authentication there are a few core CS security concepts to know about before learning authentication

1. Hashing: So when we login to a website lets say facebook.com and we enter our username/email and password, the inputs hits the backend and the password gets stored there but it doesn't gets stored as it is as entered, it gets converted to a hash which is some gibberish combination of characters before it is stored.

- But there are some constraints to a hash i.e it must be the same everytime it is called for the concerned password and the username.
- But why do we need to hash passwords before storing them in the database, because people repeat passwords and there is a high chance that some of the facebook passwords may have been same, so it is converted to a hash.
- Also even if the facebook databases are breached then only the hash will be present and so any private info will not be revealed.
- Hashing is what converts the password by passing it to a hashing function and generating the same hash everytime and the others will never be able to guess what is the password by just looking at the has.
- Also everytime we re-enter the password the backend checks the hash that gets created when re-entering to the hash that was originally stored in the database since the hash always remains the same.
- So the database stores the username and hashed password and whenever they send future requests converts the new password hash with the original one
- It is one way only, you can always convert a string to a hash but you can never convert a hash back to a string
- changing the input a little bit, changes the output by a lot

2. Encryption: Then comes encryption, which is the same as hashing, gets converted the thing to a hash stores that, has the same gibberish but we can convert back the gibberish to the original credential. But for that you need a key, to locks the main password.

- The biggest difference between the two is that hashing is one way, but encryption is two way
- Encryption does require a password, while hashing doesn't
- If someone gets the encryption key, they can decrypt the password, but in case of hashing no one can convert the hash back to original data
- eg: when facebook gets a photo it encrypts it before storing in the db, and to see that back it decrypts that photo and sends back to the frontend facebook

3. JSON web tokens(JWT): This is also some hashing function but it only works for JSON input.

- It takes some json as an input, and it gives back a very long string of data. It is significantly different from encryption and hashing.
- It works on the web and it was introduced for the use case of web
- It creates a token at the end, the long string formed is called a token
- It is not hashed/protected in any way. Whoever has the output i.e the token can see the input. It just converts a complex object into a long string. You can see it in the authorization headers of the chatgpt website when you open the network tab.
- The complex object maybe something credentials json that contains a lot of details about the person logged in and that just gets converted to a big string of gibberish, that is JWT.
- You can copy the header JWT and search it in the [jwt.io](jwt.io) website to see the complex object that gets converted to the JWT. This proves that we can convert back the JWT to the original credentials that were stored in the db
- This "conversion" can be done by anyone, but the "verification" can be done by the website where it is stored only
- We have some json data and we take a password, then we pass this json data to a function jwt.encode and we get back a string. If we pass the string and pass it through a function called jwt.verify and also need to pass it the password as well only then we'll get the original output. The chatgpt server whenever we send a request also sends a jwt along it, and it does the same above "verification"
- The "verification" happens only with the correct password combination

4. Local Storage: A place in your browser where you can store some data. Usually things that are stored in the local storage include:

- Authentication tokens
- User language preference
- User theme preference

## assignment

- project: let people sign up in the website and only allow signed in users to see people(by creating a dummy people list)
- It has two endpoints,
  - a post one which when sent to the route /signin, requires a body that has the username and the password, and it returns a json webtoken with the username encrypted
  - a get request with the route /users which has the headers authorization and returns an array of all users if user is signed in (token is correct). Returns a 403 status code if not
- We are using in-memory database, i.e a variable that stores all the data
- in the function userExists we check if the username and password is of the in-memory db as given in the body in json or not and if not then it returns an error. If yes it returns a jwt token which can be used to find out who the details(not the password of course) by using the [jwt.io](jwt.io) website.
- And we are using that same token to send a get request which gives us the all the users(if not removed the current one of the jwt) if the correct jwt is provided in the authorization header

- We have used the jwt.sign and jwt.verify functions that provide some functionality and they are as follows

### jwt.sign

- **Purpose**: Generate a JSON Web Token (JWT) based on the provided payload and secret key.

- **Syntax**:

  ```javascript
  jwt.sign(payload, secretOrPrivateKey, [options, callback]);
  ```

- **Parameters**:

  - `payload`: The data you want to include in the token.
  - `secretOrPrivateKey`: A secret key used to sign the token.
  - `options` (optional): Additional options like expiration time, algorithm, etc.
  - `callback` (optional): A callback function to handle the result asynchronously.

- **Example**:

  ```javascript
  const jwt = require("jsonwebtoken");

  const username = { user: "john.doe" };
  const password = "yourSecretKey";

  const token = jwt.sign(username, password);
  ```

- **Options**:

  - `algorithm`: The signing algorithm, default is 'HS256'.
  - `expiresIn`: Token expiration time. It can be a string (like '2 days', '10h', '7d') or a number representing seconds.
  - `issuer`: Issuer of the token.
  - `subject`: Subject of the token.

- **Returns**:
  - A string representing the signed JWT.

---

### jwt.verify

- **Purpose**: Verify the integrity and authenticity of a received JWT.

- **Syntax**:

  ```javascript
  jwt.verify(token, secretOrPublicKey, [options, callback]);
  ```

- **Parameters**:

  - `token`: The JWT to be verified.
  - `secretOrPublicKey`: The secret key or public key to verify the token.
  - `options` (optional): Additional options like algorithms, issuer, etc.
  - `callback` (optional): A callback function to handle the result asynchronously.

- **Example**:

  ```javascript
  const jwt = require("jsonwebtoken");

  const token = "yourJWTString";
  const secretKey = "yourSecretKey";

  try {
    const decoded = jwt.verify(token, secretKey);
    console.log(decoded); // Decoded payload
  } catch (error) {
    console.error("Invalid token");
  }
  ```

- **Options**:

  - `algorithms`: List of allowed algorithms for token verification.
  - `issuer`: Expected issuer of the token.
  - `subject`: Expected subject of the token.
  - `ignoreExpiration`: If true, it won't check the token expiration.

- **Returns**:
  - If the token is valid, returns an object containing the decoded payload.
  - If the token is invalid, throws an error.

---

# chatgpt given explanation for the authenticationAssignment code

### Code Overview:

```javascript
const express = require("express");
const jwt = require("jsonwebtoken");
const jwtPassword = "123456";

const app = express();
app.use(express.json());

const ALL_USERS = [
  // Array of users with username, password, and name
];

// Function to check if a user with the given username and password exists
function userExists(username, password) {
  for (let i = 0; i < ALL_USERS.length; i++) {
    if (
      username == ALL_USERS[i].username &&
      password == ALL_USERS[i].password
    ) {
      return true;
    }
  }
  return false;
}

// Sign-in route to generate JWT token
app.post("/signin", function (req, res) {
  const username = req.body.username;
  const password = req.body.password;

  if (!userExists(username, password)) {
    return res.status(403).json({
      msg: "User doesn't exist in our in-memory database",
    });
  }

  var token = jwt.sign({ username: username }, jwtPassword);
  return res.json({
    token,
  });
});

// Route to get a list of users (excluding the current user)
app.get("/users", function (req, res) {
  const token = req.headers.authorization;
  try {
    const decoded = jwt.verify(token, jwtPassword);
    const username = decoded.username;

    res.status(200).json({
      users: ALL_USERS.filter(function (value) {
        return value.username !== username;
      }),
    });
  } catch (err) {
    return res.status(403).json({
      msg: "Invalid token",
    });
  }
});

app.listen(3000);
```

### `jwt.sign`:

- **Purpose**: Generates a JSON Web Token (JWT) for a user upon successful sign-in.

- **Syntax**:

  ```javascript
  jwt.sign(payload, secretOrPrivateKey, [options, callback]);
  ```

- **Usage**:

  - `payload`: `{ username: username }` - The data to be included in the token.
  - `secretOrPrivateKey`: `'123456'` - The secret key used to sign the token.
  - `options`: `{}` - Additional options (not used in the provided code).
  - `callback`: Optional callback function.

- **Example**:
  ```javascript
  var token = jwt.sign({ username: username }, jwtPassword);
  ```

### `jwt.verify`:

- **Purpose**: Verifies the authenticity of a received JWT.

- **Syntax**:

  ```javascript
  jwt.verify(token, secretOrPublicKey, [options, callback]);
  ```

- **Usage**:

  - `token`: The JWT to be verified.
  - `secretOrPublicKey`: `'123456'` - The secret key used for verification.
  - `options`: `{}` - Additional options (not used in the provided code).
  - `callback`: Optional callback function.

- **Example**:
  ```javascript
  try {
    const decoded = jwt.verify(token, jwtPassword);
    // Handle decoded payload (e.g., get the username)
  } catch (err) {
    // Handle invalid token
  }
  ```

### Overall Notes:

- The code is an Express.js server with two endpoints:

  1. `/signin`: Generates a JWT token upon successful user sign-in.
  2. `/users`: Retrieves a list of users (excluding the current user) using a valid JWT.

- User information is stored in the `ALL_USERS` array.

- JWT is signed during sign-in and verified during the `/users` endpoint.

- Error handling is implemented for invalid tokens and user existence checks.

- The server listens on port `3000`.

This code provides a basic authentication mechanism using JWT in an Express.js server.

# Databases

up until now we were creating in-memory objects which are bad for a few reaons

1. Data can't be dynamic, if you update in memory objects, the updates are lost if the process restarts
2. There are multiple servers in the real world, known as "clusters", in which data is kept in a shared manner for sending data as far as possible. And so using in-memory objects there is far from possible

So in the real world we send a request to a backend server which can be many as per configuration, but the database is mostly one, if there are more than one databases then they would be synced together pretty well so as to not cause any issues. For the scope of this cohort, we'll assume that there is always one single database storing stuff

- The backend servers will do all the authentication stuff but the next storing stuff will be done by a database. If the backend needs data then it'll need to ask the database to get so.
- There are various types of databases:
  - Graph DBs : For very specific niche usecases
  - Vector DBs : For machine learning
  - SQL DBs : usually used by full stack applications and open source projects
  - NoSQL DBs : new trend and popular, but simpler than SQL and easy to use
- For our class we'll look at one NoSQL database called MongoDB

## MongoDB

- It lets you create multiple databases: A single mongoDB machine, can create multiple databases
- In each DB, it lets you create tables(collections): And each database has multiple tables
- In each table, it lets you dump whatever data you want: i.e you can dump anything, whereas SQL DBs has a very strict schema system for defining what data is being entered
- It is schemaless: you can change the schema very quickly
- It scales well and is a decent choice for most use cases

How does backend connect to the database?
Using libraries

1. Express lets u create an HTTP server
2. JWT library lets you creatse JWTs
3. Mongoose, one of many, libraries that lets you connect to your database

### Assignment regarding mongoDB

we have to create the backend logic for a server that is somehow connected to this database. the end users can send one fo three requests1

1. /singup: where they give us username, password and first name and when they give us this we have to keep it in the database provided someone with the same data already doesn't exist.
2. /signin: our backend need to check does this user exist in the db and is the password correct and if both of the conditions meet then send them the jwt. else stop them
3. /user: where we expect a header to send us the jwt that they got here, hit the db and return back the data to the user that is asking for it.

By building these with this we'll learn how a backend application talks to the mongoDB database

### Mongoose

The following lines of code are enough to write in a mongoDB database

```js
const mongoose = require("mongoose");
mongoose.connect("mongodb://127.0.0.1:27017/test");

const Cat = mongoose.model("Cat", { name: String });

const kitty = new Cat({ name: "Zildjian" });
kitty.save().then(() => console.log("meow"));
```

Mongoose is an Object Data Modeling (ODM) library for MongoDB and Node.js. It provides a straightforward, schema-based solution to model your application data and interact with MongoDB. Here are key concepts and features of Mongoose:

#### Key Concepts:

1. **Schema:**

   - Mongoose allows you to define a schema for your MongoDB documents. Schemas define the structure, data types, and validation rules for documents.

   ```javascript
   const userSchema = new mongoose.Schema({
     name: String,
     email: { type: String, unique: true },
     age: { type: Number, min: 18 },
   });
   ```

2. **Model:**

   - Models in Mongoose represent the documents stored in MongoDB. They are created from schemas and provide an interface to interact with the database. Since mongoDB lets you put any type of data and at times you will want to verify that you're putting a certain format of data there, for that reason mongoose is very useful since it asks when we write data that firstly what is the model, what are you expecting to put in there, only then we'll be allowed to write data. Schema is already defined above and used in after the model name with a comma

   ```javascript
   const User = mongoose.model("User", userSchema);
   ```

- // ingnore the rest of the info, explanation starting after the same //

3. **Connection:**

   - Mongoose establishes a connection to the MongoDB server using `mongoose.connect`.

   ```javascript
   mongoose.connect("mongodb://localhost:27017/mydatabase", {
     useNewUrlParser: true,
     useUnifiedTopology: true,
   });
   ```

4. **Document:**

   - Documents are instances of models and represent individual records in the MongoDB collection.

   ```javascript
   const newUser = new User({
     name: "John",
     email: "john@example.com",
     age: 25,
   });
   newUser.save(); // Saves the document to the database
   ```

5. **Middleware:**

   - Mongoose supports middleware functions that are executed at various stages of the document's lifecycle, such as `pre` and `post` hooks.

   ```javascript
   userSchema.pre("save", function (next) {
     // Do something before saving
     next();
   });
   ```

6. **Validation:**

   - Schemas can define validation rules for fields, ensuring that data meets specified criteria.

   ```javascript
   const userSchema = new mongoose.Schema({
     name: { type: String, required: true },
     email: { type: String, unique: true, required: true },
   });
   ```

#### Features:

1. **Query Building:**

   - Mongoose provides a rich set of query building methods to perform CRUD operations on MongoDB.

   ```javascript
   User.find({ age: { $gte: 18 } }).exec((err, users) => {
     // Perform actions with retrieved users
   });
   ```

2. **Middleware:**

   - Middleware functions can be used for tasks like validation, data transformation, and more.

3. **Population:**

   - Mongoose supports population, allowing you to reference documents in other collections and retrieve them when needed.

   ```javascript
   const blogSchema = new mongoose.Schema({
     title: String,
     author: { type: mongoose.Schema.Types.ObjectId, ref: "User" },
   });
   ```

4. **Middleware:**

   - Mongoose simplifies working with MongoDB by providing a higher-level abstraction with features like schema validation, query building, and middleware.

5. **Plugins:**

   - You can extend Mongoose functionality using plugins to reuse and share code.

   ```javascript
   const timestampPlugin = require("./plugins/timestamp");
   userSchema.plugin(timestampPlugin);
   ```

#### Installation:

To use Mongoose in your Node.js project, install it using npm:

```bash
npm install mongoose
```

#### Example Usage:

```javascript
const mongoose = require("mongoose");

mongoose.connect("mongodb://localhost:27017/mydatabase", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

const userSchema = new mongoose.Schema({
  name: String,
  email: { type: String, unique: true },
  age: { type: Number, min: 18 },
});

const User = mongoose.model("User", userSchema);

const newUser = new User({ name: "John", email: "john@example.com", age: 25 });
newUser.save((err, savedUser) => {
  if (err) {
    console.error(err);
  } else {
    console.log(savedUser);
  }
});
```

In this example, we've defined a simple schema for a user, created a model, and saved a new user to the MongoDB database.
Remember to handle errors appropriately in real-world applications and consider using asynchronous patterns like Promises or async/await.

- explanation starting here

```js
const mongoose = require("mongoose");
mongoose.connect(
  "mongodb+srv://milindabarua04:legion@firstmongodbinstance.l4lglul.mongodb.net/",
);

const Users = mongoose.model("Users", {
  name: String,
  email: String,
  password: String,
});

const user = new Users({
  name: "Zildjian",
  email: "hello@gmail.com",
  password: "nothing",
}); // in-memory object
user.save().then(() => console.log("data sent to the database"));
```

- in the syntax, first we need to import mongoose.
- then connect the database with the correct url, username and password
- Mongoose first expects to describe the data, so after the above process we can create/initialize&assign a user model with the syntax `mongoose.model("model_name", {schema_in_object_syntax_key:value_pair})` in the above way, which says that this is what our table and schema looks like. Look into the chatgpt explanation for more examples
- Now at the last we can create a new user object with all the details to send to the database and we need to then use the `user_variable.save()` (.save is necessary) to instruct mongoose to send the data. If not nothing will reach the database. I guess it is a promise, so u can also use a `.then()` to send some other stuff as well
- We can now see that the data has been entered in the database, using MongoDBCompass.
- We can then wrap it inside a request method to get the request from the browser, and do signup/signin
