const express = require("express");
const mongoose = require("mongoose");
const jwt = require("jsonwebtoken");
const app = express();

// mongoose logic, connectin the db and making a model in it
mongoose.connect(
  "mongodb+srv://milindabarua04:legion@firstmongodbinstance.l4lglul.mongodb.net/user_app" // give the correct database name by adding that after the end like a route after '.net/'
);
const Users = mongoose.model("Users", {
  name: String,
  email: String,
  password: String,
});

// starts the express http logic

function middleware(req, res, next) {
  const username = req.body.username;
  const password = req.body.password;
  const token = req.headers.authorization;
  if (!token) {
    return res.status(403).json({
      msg: "Unauthorized token not provided ",
    });
  }

  jwt.verify(token, password, (err, decoded) => {
    if (err) {
      return res.status(403).json({
        message:
          "Forbidden: Invalid token, or token doesn't exist get a new one by signing up :)",
      });
    }
    // req.user = decoded; // Attaches the decoded user information to the request object, better to not do this since it exposes the password to the backend
  });
  next();
}
app.use(express.json());
app.get("/user", middleware, async function (req, res) {
  try {
    const allUsers = await Users.find({}, { password: 0 }); // this line just prints all the users so it doesn't take any input at the first brace and the second brace indicates that it should not show any password
    res.status(200).json({ allUsers });
  } catch (err) {
    res.status(500).json({ message: "Internal Server Error" });
  }
});

app.post("/signup", async function (req, res) {
  const name = req.body.name;
  const username = req.body.username;
  const password = req.body.password;

  const existingUser = await Users.findOne({ email: username });
  if (existingUser) {
    return res.status(403).send("username already exists");
  }

  const user = new Users({
    name: name,
    email: username,
    password: password,
  }); // in-memory object for pushing it to the mongoDB db
  user.save(); //.then(() => console.log("data sent to the database")); // to push it to the mongoDB
  res.json({
    msg: "user created successfully",
  });
});

app.post("/signin", async function (req, res) {
  const username = req.body.username;
  const password = req.body.password;
  // if username already exists just ask the password
  const existingUser = await Users.findOne({
    email: username,
    password: password,
  });
  var token = jwt.sign({ email: username, password: password }, password);
  if (existingUser) {
    return res.send({
      msg: "Correct entry, you will get the token",
      token,
    });
  } else {
    return res.status(403).json({
      msg: "password is wrong or the user doesn't exist in our database, you need to signup first",
    });
  }
});

app.listen(3000);
