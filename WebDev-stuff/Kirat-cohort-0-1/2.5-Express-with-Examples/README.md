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

## stuff from nodejs assignments

- If the url consists of the route /files/example.txt like some file name after the route folder, then we need to catch that(haven't been taught till now).
- How to catch every file after a route, which is called wildcard, i.e if there is anything after the route in the get request or any other request, then the control should always reach in the logic part. We can do this by adding the `"/files/:fileName"` after the route so that anything that comes after the route folder gets caught by the request and then gets read, this `fileName` parameter can then be mapped to a variable inside the function of that request and it does s using the `const fileName = req.parameter.fileName` and then this variable can be used further to continue with some logic. note: the variable name should be the same. And if you bind that data in res.json, then you can send the output to the frontend localhost in the form of json
- note the query parameters come by giving a comma after the route ending, but normal parameters comes directly after the route ending slash

- Errors in the fileServer.js assignment: The issue in your code appears to be related to how the file path is constructed when reading the file using `fs.readFile`. The `fs.readFile` function expects the file path to be an absolute or relative path, not just the file name. When you only provide the file name, the function might not find the file in the expected location.

Here's a corrected version of your code:

```javascript
const path = require("path");

app.get("/files/:fileName", function (req, res) {
  const filename = req.params.fileName;
  const filePath = path.join(__dirname, "files", filename); // Assuming files are in the "files" directory

  fs.readFile(filePath, "utf8", (err, data) => {
    if (err) {
      console.error(err); // Log the error for debugging purposes
      return res.status(500).json({
        error: "Internal server error",
      });
    }
    res.status(200).json({ data });
  });
});
```

Key changes and explanations:

1. **Added `path` Module:**

   - Required the `path` module to handle file paths in a platform-independent way.

2. **Constructed Absolute File Path:**

   - Used `path.join` to construct the absolute file path based on the current directory (`__dirname`) and the provided file name.
   - Assumed that the files are located in a "files" directory. Adjust this based on your project structure.

3. **Logging Errors:**

   - Added a `console.error(err)` statement to log the error for debugging purposes.

4. **Updated Response:**
   - Changed the response to include the file content inside an object for better structure (`res.status(200).json({ data });`).

Ensure that the "files" directory is in the correct location relative to your script, and adjust the file path accordingly. If the issue persists, check the actual error message logged to the console for more details on what went wrong.

- What is path.join: The `path.join` function is a method provided by the Node.js `path` module. It is used to join together one or more path segments into a single string, forming a valid path. This is particularly useful for constructing file paths in a cross-platform manner, ensuring that the resulting path is correctly formatted for the operating system on which the code is running.

The basic syntax of `path.join` is as follows:

```javascript
const path = require("path");

const resultPath = path.join([path1], [path2], [...]);
```

- `path1`, `path2`, etc.: The path segments that you want to join together.

- `resultPath`: The resulting path after joining the provided segments.

### Example:

```javascript
const path = require("path");

const directory = "/usr";
const subdirectory = "local";
const filename = "example.txt";

const fullPath = path.join(directory, subdirectory, filename);
console.log(fullPath);
```

In this example, `path.join` concatenates the three path segments ("/usr", "local", and "example.txt") to form the full path. The output may vary depending on the operating system, but it ensures a correct and platform-specific path.

### Why Use `path.join`?

- **Platform Independence:**

  - Different operating systems use different conventions for file paths (e.g., backslashes on Windows and forward slashes on Unix-like systems). `path.join` takes care of these differences, producing paths that work seamlessly across platforms.

- **Avoiding Manual Concatenation:**

  - Instead of manually concatenating path segments with string manipulation (which might lead to incorrect paths), `path.join` provides a safer and more reliable alternative.

- **Normalization:**

  - `path.join` also performs path normalization, resolving any ".." or "." segments in the path, ensuring a clean and valid path.

- **Readability:**
  - Using `path.join` makes the code more readable and maintainable.

In the context of the previous code snippet I provided, `path.join(__dirname, "files", filename)` is used to construct the absolute path to the file by joining the current directory (`__dirname`), the "files" directory, and the specified filename.

- what is the difference between `res.json(data);` and `res.json({data})`: when you give the data directly in the parentheses, then the json returns directly the data, and if it is sent in the form of object, then it returns the key value pair. In the context of Express.js, `res.json(data);` and `res.json({ data });` are two ways to send JSON responses, but they have different implications:

1. **`res.json(data);`:**

   - This form is used when you want to send the `data` as the top-level JSON response.

   ```javascript
   const data = { key: "value" };
   res.json(data);
   ```

   - The response will be a JSON object with properties directly corresponding to the keys and values of the `data` object.

   ```json
   {
     "key": "value"
   }
   ```

2. **`res.json({ data });`:**

   - This form is used when you want to wrap the `data` in another object within the JSON response.

   ```javascript
   const data = { key: "value" };
   res.json({ data });
   ```

   - The response will be a JSON object where the `data` key contains the original `data` object.

   ```json
   {
     "data": {
       "key": "value"
     }
   }
   ```

### Practical Example:

```javascript
const express = require("express");
const app = express();

app.get("/example1", (req, res) => {
  const data = { key: "value" };
  res.json(data);
});

app.get("/example2", (req, res) => {
  const data = { key: "value" };
  res.json({ data });
});

app.listen(3000, () => {
  console.log("Server is listening on port 3000");
});
```

- When you access `http://localhost:3000/example1`, you will get a JSON response directly containing the properties of the `data` object:

  ```json
  {
    "key": "value"
  }
  ```

- When you access `http://localhost:3000/example2`, you will get a JSON response with an object that has a `data` property containing the original `data` object:

  ```json
  {
    "data": {
      "key": "value"
    }
  }
  ```

Choose the appropriate form based on how you want to structure your JSON responses. If the `data` itself is the primary content of the response, use `res.json(data);`. If you want to provide additional context or structure, you can wrap it using `res.json({ data });`.
