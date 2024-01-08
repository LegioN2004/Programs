# Express with examples

Continuing from the last backend http express live video

## A little about http

- the logic is like a doctor, the following sum logic function written is the doctor logic, the main thing that can be exposed to the world, we can compare it to the chatgpt algorithm that the openai people have written a bunch of code and they can call the logic on the machine that the code current resides.
- But it's not fun until the whole world can access and use it, since the people have not written it to use it for themselves
- Writing it the one thing but exposing it to the world is another thing and this is where comes **http** to the picture and it stands for hyper text transfer protocol, a transfer protocol that lets you send data to clients. Expose your logic to the world so that other people can access it.

```javascript
const express = require("express");
const app = express();
const port = 3000;

function calculateSum(n) {
  let ans = 0;
  for (let i = 0; i <= n; i++) {
    ans += i;
  }
  return ans;
}
// let ans = calculateSum(10);
// console.log(ans);

// rest of the backend logic
app.get("/", function (req, res) {
  const n = req.query.n;
  console.log(n);
  res.send(calculationSum(n).toString());
  // res.send(calculationSum(10).toString());
});

app.listen(port, function () {
  console.log(`listening on ${port}`);
});
```

- How to create a http server, and the answer is Express for JS, springboot for Java, etc, it is not language specific, we can write it in any language of choice.
- The port should be unique for every process that starts listening, it can be from any language/framework/etc
- The above code when written in a backend side will run first only and if its a heavy one then it will keep the main thread busy because the whole code is sync
- **note**: Always send a get request in the string so that the backend doesn't interpret it some status code and send errors
- We have learnt that we can send query parameters by using question mark after the route ends and then use that same variable followed by the value you want to send, so by doing `const n = req.query.n` inside the app.get request logic we can take the query `n` and send some values by writing in the url `https://localhost:3000?n=10` which then returns the `calculateSum` value(55 for 10) to the body.

## after using the object and for updating its data

The Express.js framework gives us some boilerplate code with different methods for some operations and those methods will have different logic written.

- Using the example of kidneys.
- We will need to implement the logic but for different method there will be a different callback, and so different logic will get called
- The routes can be same for all of the methods
  - The popular input type for sending get requests are query parameters
  - The popular input type for sending post requests are the ones sent in the body of the request. What is body; It is another place to specify and say that this is my input. We can get the body using the syntax `const var_name = req.body.var_name`
- You need to send res.json({}) otherwise the server will think that the request has not been fulfilled and as such it'll just keep on going till it recieves that and will not send any input

- Below are some notes regarding the provided Express.js code. These notes cover the key concepts, methods, and requests involved in the code:
- Note, `users` is an array of objects, when you pass `users[index].kidneys.healthy` as a conditional it checks what the healthy key of the kidneys key of the specified index of the users variable has, true/false
- And isHealthy is a variable that takes a true/false string from the JSON provided by the post request from postman/any_other_place
- Put request just replaces the

### Express.js Backend with Kidney Game:

#### 1. **Express Setup:**

- `const express = require("express");`: Importing the Express.js framework.
- `const app = express();`: Creating an instance of the Express application.

#### 2. **Local Database (Memory Object - users):**

- `const users = [...]`: A simple array acting as a local database to store user data. In this case, each user has a name and an array of kidneys.

#### 3. **Middleware for JSON Parsing:**

- `app.use(express.json());`: Middleware to parse incoming JSON data, enabling handling of JSON payloads in requests.

#### 4. **GET Endpoint ("/"):**

- Retrieves and processes data related to kidneys.
- Calculates the total number of kidneys, healthy kidneys, and unhealthy kidneys for a specific user (e.g., "John").
- Demonstrates array iteration and conditional counting.

#### 5. **POST Endpoint ("/"):**

- Adds a new kidney to the user's kidneys array based on the health status provided in the request body (`req.body.isHealthy`).
- Responds with a simple message indicating the completion of the operation.

#### 6. **PUT Endpoint ("/"):**

- Updates the health status of all kidneys to be healthy (sets `healthy: true`).
- Illustrates iteration through the kidneys array to perform a bulk update.

#### 7. **DELETE Endpoint ("/"):**

- Removes unhealthy kidneys from the user's kidneys array.
- Creates a new array (`newKidneys`) with only healthy kidneys and assigns it back to the user.
- Responds with a message confirming the completion of the operation.

#### 8. **Server Listening:**

- `app.listen(3000, function () { ... });`: Starts the Express server and listens on port 3000.
- Outputs a message to the console indicating that the server is listening.

#### 9. **Important Points to Note:**

- The endpoints use different HTTP methods (GET, POST, PUT, DELETE) to perform various operations.
- The code provides a simple illustration of state management in memory (with the `users` array) and array manipulation based on different requests.

#### 10. **Improvements/Considerations:**

- Error handling: Consider adding error handling mechanisms for better robustness.
- Validation: Implement input validation to ensure the integrity of incoming data.
- Modularization: As the application grows, consider modularizing the code for better maintainability.

### Code Overview:

1. **Express Setup:**

   - Import the `express` module and create an Express application.
   - Initialize an array `users` with sample user data containing kidney information.

2. **Middleware:**

   - Use `express.json()` middleware to parse JSON data in requests.

3. **Route - GET "/":**

   - Handles a GET request to the root ("/") endpoint.
   - Retrieves information about the kidneys of the first user ("John").
   - Calculates the total number of kidneys, healthy kidneys, and unhealthy kidneys.
   - Responds with a JSON object containing kidney information.

4. **Route - POST "/":**

   - Handles a POST request to the root ("/") endpoint.
   - Accepts JSON data from the request body, particularly the `isHealthy` property.
   - Adds a new kidney entry to the user's kidney array based on the health status provided.
   - Responds with a JSON object indicating that the operation is done.

5. **Route - PUT "/":**

   - Handles a PUT request to the root ("/") endpoint.
   - Iterates over the kidneys of the first user and sets the `healthy` property of each kidney to `true`.
   - Essentially replaces all kidneys, making them healthy.
   - Responds with an empty JSON object.

6. **Server Listening:**
   - The server listens on port 3000, and a message is logged when the server is started.

### Key Concepts and Notes:

- **Express Routes:**

  - Routes are defined using `app.get()`, `app.post()`, and `app.put()` methods.
  - The route paths ("/") determine the endpoint URLs.

- **Middleware (`express.json()`):**

  - Enables parsing of JSON data from the request body.
  - Essential for handling POST requests with JSON payloads.

- **Data Manipulation:**

  - Utilizes an array (`users`) to store user information.
  - Demonstrates basic data manipulation, such as counting healthy and unhealthy kidneys and updating kidney health status.

- **HTTP Methods:**

  - Uses different HTTP methods (`GET`, `POST`, `PUT`) to perform specific actions on the server.

- **Request and Response Handling:**

  - Accesses request data using `req.body` to get information from the request body.
  - Responds to clients with `res.json()` to send JSON-formatted responses.

- **Server Listening:**
  - Uses `app.listen()` to start the server on port 3000.

### Suggestions for Improvement:

- **Error Handling:**

  - Consider adding error handling mechanisms for better robustness.

- **Modularization:**

  - As the codebase grows, consider modularizing routes and logic into separate files.

- **Validation:**

  - Implement input validation to ensure that the data received in requests is as expected.

- **Documentation:**

  - Consider adding comments and documentation to explain complex or critical sections of your code.

### Edge cases

- In DELETE request method
  - Now what will happen if they try to delete a key when there is none, according to the example what happens when they try to delete even if there are no kidneys
  - So you should send a 400 series status codes more specifically the `411 status code` which stands for 'wrong input'
  - You can run an if-else statement which runs when there is one unhealthy kidney, else returns error status code
- PUT

  - Same goes for put
  - If you are trying to convert all the unhealthy kidneys to healthy ones but they are already healthy then you should send a different status code, some 411. In the real world the user will not see a button to make it healthy.
  - These are all good practices

- So we can write a function that just gives the logic to send a false or true based on the no of kidneys left and using that in the main deleter request we can return status codes as error.
- to send status codes as a response ,we can use the syntax `res.sendStatus(error_code)` to directly send the error code or to send with a mesaeg we can do something like `res.send(error_code).json({message_key: "value"})`
