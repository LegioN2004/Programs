# Creating payTM end to end

## express routing

- how to do it:
  - First make a new routes folder and then make a file there with the name index.js and then setup the router there

```js
const router = express.Router();
module.exports = router;
```

- Then import the router in index.js and route all requests from /api/v1 to the router in the routes folder, by using the `app.use` and the required router inside it. This router will handle all the requests coming there. By giving the route and then the place where to route separated with commas, we'll make all the requests route to the mainRouter path i.e the index file in the routes folder

```js
const mainRouter = require("./routes/index");
app.use('/api/v1', mainRouter)
```

- Why are we doing this, so as to maintain structure in our backend such that we can route users coming to our site using this route, where the old ones gets to v1 and the new ones go to v2 and so on. We can better structure our backend using this express router. That's what express does when we pass in two arguments, one for the route path and the second is the middleware/actual logic that will happen for the routerPath.

- our requests will eventually look like `/api/v1/user`, `/api/v1/user/signup`, `/api/v1/user/signin`, `/api/v1/user/signin` or our requests will be like this `/api/v1/account/transferMoney`, `/api/v1/account/balance`.
  - now we can do the above by adding the user and account routes to the main index file itself or we can do something like using the main index file as our center file which routes the v1/v2/v3... requests to the routes index file of our backend and the we can use different file for the user requests and account requests respectively.
  - So we can structure a chunk of our api's to a single file and another chunk to another file all through routing it through the main index file

  ```js
  // backend's main index.js file
  const mainRouter = require("./routes/index");
  app.use('/api/v1', mainRouter); // uses /api/v1 endpoint to the mainRouter which is the route's main index file

  // route's main index.js file
  const userRouter = require("./user");
  router.use('/user', userRouter); // routes all the /user endpoint to the userRouter which is the route's user router file

  // and then the above line routes the user requests for various user specific things like signup signin to the router's user file, as we have done before all in the main file itself
  router.get('/signup', (req,res) => {
      console.log("signup router");
  });
  ```
  
- Then setup some routes and in that we have used the user route which routes all the user requests and it has the middlewares imported that will handle all the authentication, signin, signup, update, delete and will have all of their logic

- The zod object returns a success object which we can destructure and use it directly or we can take the object in a variable and use the `.` to get the success object which returns true or false based on the parsing of the output. 

- why are we using Bearer in token: For security reasons we should make sure that the Authorization header has the expected content. We simply should not accept a header that does not start with Bearer if we are expecting it ("Bearer" is a recommendation in the RFC, it is not mandatory) ".
  - Ideally what we should do this authentication is by sending out an otp to the user kind of a verification email which the user will click on and they can actually signup. But here we are assuming that the user will send in an actual correct email
  - The authenticator applications does this pretty well which is another way to verify users for signup and signin.
  - `Bearer` tells us what type of token, there are various types of tokens that can be used for authenticating requests. Api key is another popular option then the api_key will be there instead of the bearer.

- We should hash passwords before storing them in the database, since if we don't then storing passwords directly in the database will create a huge security flaw which we don't want. So a  good practice is to use hashing libraries which stores the converted hash of the password in the database
  - Important concept "salt":
  - Why we should do this because it is one way and now people who maintain the database can never login to our account, people repeating passwords is another reason why we should hash passwords
  - But it will still cause security flaws if the password is the same for two different persons since the hashes will be the same. So there is this concept of "salt" which adds like a random string or anything with the combination of the password and then generates a hash which will always be unique to everyone in the world and so in that way it'll be more secure.
  - So the authentication happens in this manner. First signup generates a token (for the user's browser to login anytime) and hash (for the database storage), token works as long as the cookie remains i.e signin works and the hash will be generated for the person everytime it needs to signup and the same hash will generated for the same user

- explanation of the code below
 
     ```js
    const updatedBody = zod.object({
        firstName: zod.string().optional(),
        lastName: zod.string().optional(),
        password: zod.string().optional(),
    })

    const {success} = updatedBody.safeParse(req.body);
    try {
        if (!success) {
            res.status(411).json({
                message: "Error while updating information"
            })
        }
        await User.updateOne({_id: req.userId}, req, body)
        next();
    }
    ```
  - we can do the updatedBody like that where we take in the zod object with all the schema defined in there and 
    then that will auto get the main values from the success destructured object and that updatedBody will take in the 
1. **Request Body Parsing and Validation**:
    - The `safeParse` method of the `updatedBody` schema is invoked with `req.body` as its argument. This method 
      parses and validates the request body against the defined schema.
    - The `safeParse` method returns an object containing two properties: `success` and `data`.
    - The `success` property is a boolean indicating whether the parsing and validation were successful. If successful, `success` is `true`; otherwise, it's `false`.

2. **Destructuring the `success` Object**:
    - The `{success}` syntax is a form of destructuring assignment in JavaScript. It extracts the `success` property from the object returned by `safeParse`.
    - With this destructuring assignment, we directly access the `success` property without having to reference the entire object (`{success: boolean}`).

3. **Error Handling based on Success Flag**:
    - If `success` is `false`, it means that the parsing and validation failed. In this case, the server responds with an error status (411) and an error message.
    - If `success` is `true`, it indicates that the parsing and validation were successful, and the request body conforms to the expected schema.

4. **Updating User Information**:
    - If the parsing and validation are successful (`success === true`), the server proceeds to update the user information in the database.
    - The `updateOne` method of the `User` model is used to update the user document based on the provided `_id`. The update data is taken from the request body (`req.body`).
    - There seems to be a typo in the code where `req, body` is written instead of `req.body`. It should be `req.body`.

- **Searching** part: We can do that by the following way


## not notes

### how to keep mongodb url in a different file and then connect it with mongoose, so that if i push the code to github my db credential doesn't go to the github

To keep your MongoDB URL in a separate file and prevent it from being pushed to GitHub along with your code, you can follow these steps:

1. Create a file to store your MongoDB URL. Let's name it `dbConfig.js`:

   ```javascript
   // dbConfig.js
   const mongoose = require('mongoose');

   const DB_URL = 'your_mongodb_url';

   module.exports = DB_URL;
   ```

   Replace `'your_mongodb_url'` with your actual MongoDB URL.

2. In your main application file (e.g., `app.js`), require the `dbConfig.js` file and use the exported URL to connect with Mongoose:

   ```javascript
   // app.js
   const mongoose = require('mongoose');
   const DB_URL = require('./dbConfig');

   mongoose.connect(DB_URL, { useNewUrlParser: true, useUnifiedTopology: true })
     .then(() => console.log('MongoDB connected'))
     .catch(err => console.error('MongoDB connection error:', err));
   ```

3. Add `dbConfig.js` to your `.gitignore` file to prevent it from being pushed to GitHub:

   ```
   # .gitignore
   dbConfig.js
   ```

By following these steps, your MongoDB URL will be stored in a separate file (`dbConfig.js`), which will not be pushed to GitHub due to the `.gitignore` configuration. Therefore, your database credentials will remain private.

### second doubt

```js
app.get('/users', async (req, res) => {
 const user = await User.find();
 res.json({
  msg: user,
 });
});
```

why I got a Typeerror on not using await in the find function, does express return a promise on using find

Yes, in Mongoose, the `find()` function returns a Query object, not a promise directly. However, Mongoose provides a way to execute the query and obtain a promise using `exec()`. Therefore, to use `find()` with `await`, you need to call `exec()` after `find()`.

Here's how you can fix your code:

```javascript
app.get('/users', async (req, res) => {
    try {
        const users = await User.find().exec();
        res.json({ users });
    } catch (error) {
        res.status(500).json({ error: 'Internal server error' });
    }
});
```

In this code, `await User.find().exec()` will execute the query and return a promise that resolves to the array of users. If there's an error during the execution, it will be caught in the `catch` block and a 500 status response will be sent back.

### third doubt

```json
{
  users: [
    {
      _id: new ObjectId('65d9ce2160c314dc4802580f'),
      firstName: 'hello',
      lastName: 'byeee',
      __v: 0
    },
    {
      _id: new ObjectId('65d9d4bbfb23acd846620b22'),
      firstName: 'bye',
      lastName: 'good',
      __v: 0
    }
  ]
}
// why do we get the above output when we destructure users and use the .exec() and get the following when we don't do it
[
  {
    _id: new ObjectId('65d9ce2160c314dc4802580f'),
    firstName: 'hello',
    lastName: 'byeee',
    __v: 0
  },
  {
    _id: new ObjectId('65d9d4bbfb23acd846620b22'),
    firstName: 'bye',
    lastName: 'good',
    __v: 0
  }
]
```

When you call `await User.find().exec()`, Mongoose returns a Mongoose Query object. This object has methods like `exec()` which allows you to execute the query and obtain the result.

By using `.exec()`, you're explicitly telling Mongoose to execute the query and return a promise that resolves to the array of documents (users in this case). This is why you see an object with a `users` property containing the array of users.

On the other hand, when you don't use `.exec()`, Mongoose returns a Query object instead of executing the query immediately. This is why you see the array of documents directly, as the Query object itself contains the results when you log it.

### fourth doubt

``` js
async function signupMiddleware(req, res, next) {
 const firstName = req.body.firstName;
 const lastName = req.body.lastName;
 const password = req.body.password;
 const userExists = await User.find({
  firstName: req.body.firstName,
  lastName: req.body.lastName,
  password: req.body.password,
 });

 // credential logic
 try {
  if (!userExists) {
   const user = new User({
    firstName: firstName,
    lastName: lastName,
    password: password,
   });
   await user.save();
   next();
  } else {
   res.status(400).json({
    msg: 'User exists or name exists in database, change your credentials',
   });
  }
 } catch (error) {
  res.status(500).json({
   msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
  });
 }
}
```

Why am i not able to enter the input to mongodb here, what am I doing wrong. I always get the message that my user exists but it doesn't

In your `signupMiddleware` function, you're using `await User.find()` to check if the user already exists. However, `User.find()` returns an array of documents, not a single document. So even if there's no user found, `userExists` will still be an empty array, which evaluates to truthy in JavaScript.

To fix this, you should use `User.findOne()` instead of `User.find()`. `User.findOne()` returns a single document or `null` if no document is found. Here's how you can modify your code:

```javascript
async function signupMiddleware(req, res, next) {
 const firstName = req.body.firstName;
 const lastName = req.body.lastName;
 const password = req.body.password;
 const userExists = await User.findOne({
  firstName: req.body.firstName,
  lastName: req.body.lastName,
  password: req.body.password,
 });

 // credential logic
 try {
  if (!userExists) {
   const user = new User({
    firstName: firstName,
    lastName: lastName,
    password: password,
   });
   await user.save();
   next();
  } else {
   res.status(400).json({
    msg: 'User exists or name exists in database, change your credentials',
   });
  }
 } catch (error) {
  res.status(500).json({
   msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
  });
 }
}
```

With this change, `userExists` will be `null` if no user is found, and the condition `if (!userExists)` will work as expected.

### fifth doubt

``` js
async function updateMiddleware(req, res, next) {
 const userName = req.body.userName;
 const firstName = req.body.firstName;
 const lastName = req.body.lastName;
 const password = req.body.password;
 const userExists = await User.findOne({
  userName: req.body.userName,
 });

 // credential logic
 try {
  if (userExists) {
   User.push({
    firstName: firstName,
    lastName: lastName,
    password: password,
   });
   await user.save();
   next();
  } else {
   res.status(400).json({
    msg: 'User does not exist, cannot be replaced. Create one first',
   });
  }
 } catch (error) {
  res.status(500).json({
   msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
  });
 }
 console.log('Hello');
}
```

Is this the correct way to do the update stuff in express mongoose

sol:
No, the approach you're using in the `updateMiddleware` function is incorrect for updating a document in MongoDB using Mongoose. Here are the corrections:

1. Use `findOneAndUpdate` method provided by Mongoose to find and update a document.
2. Make sure to handle the update operation correctly based on whether the user exists or not.

Here's the corrected version of your code:

```javascript
async function updateMiddleware(req, res, next) {
 const userName = req.body.userName;
 const firstName = req.body.firstName;
 const lastName = req.body.lastName;
 const password = req.body.password;

 try {
  // Check if the user exists
  const userExists = await User.findOne({ userName: userName });

  if (userExists) {
   // Update the user's information
   await User.findOneAndUpdate(
    { userName: userName },
    { firstName: firstName, lastName: lastName, password: password }
   );
   next();
  } else {
   // User does not exist, return an error
   res.status(400).json({
    msg: 'User does not exist, cannot be updated. Create one first',
   });
  }
 } catch (error) {
  // Handle server error
  res.status(500).json({
   msg: 'Server error, please try again later',
  });
 }
}
```

This code will attempt to find the user by `userName`. If the user exists, it will update the user's information using `findOneAndUpdate` method. If the user does not exist, it will return an error message.
