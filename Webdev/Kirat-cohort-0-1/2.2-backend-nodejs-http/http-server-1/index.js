const express = require("express"); // this is the statement to import the express library
const bodyParser = require("body-parser");
const app = express(); // then make an object
const port = 3000;

// middlewares code(will be explained later)
app.use(bodyParser.json());

// app.get("/route-first", function (req, res) {
//   res.json({
//     name: "Harkirat",
//     age: 21,
//   });
// });

app.get("/", (req, res) => {
  console.log(req.headers.authorization);
  res.send("<h1>fuGGGGGGGGG JS is hard");
});

// app.post("/conversation", (req, res) => {
//   let message = req.query.message;
//   console.log(message);
//   res.send("<h1>fuGGGGGGGGG JS is hard");
// });

// how to handle a post request more specifically the body of a post request, what are the headers and how do you get one, authentication etc
app.post("/conversation", (req, res) => {
  // console.log(req.headers["authorization"]);
  console.log(req.body);
  res.send({
    msg: "2 + 2 = 4",
  });
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
