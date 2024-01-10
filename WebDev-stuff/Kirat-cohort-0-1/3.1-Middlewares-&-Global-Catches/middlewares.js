const express = require("express");
const app = express();

// normal logic using functions
// function checkId(username, password) {
//   if (username === "harkirat" && password === "pass") {
//     return true;
//   } else {
//     return false;
//   }
// }

// function kidneyValidator(kidneyId) {
//   if (kidneyId === 1 && kidneyId === 2) {
//     return true;
//   } else {
//     return false;
//   }
// }

// app.get("/health-checkup", function (req, res) {
//   const kidneyId = req.query.kidneyId;
//   const username = req.headers.username;
//   const password = req.headers.password;

//   //  username, password and id check from the slide example
//   if (!(checkId(username) && checkId(password))) {
//     res.status(400).json({
//       msg: "user doesn't exist",
//     });
//     return;
//   }
//   if (!kidneyValidator(kidneyId)) {
//     res.status(411).json({
//       msg: "wrong inputs",
//     });
//     return;
//   }
//   res.send("your heart is healthy");
// });

// app.post("/replace-kidney", function (req, res) {
//   const kidneyId = req.query.kidneyId;
//   const username = req.headers.username;
//   const password = req.headers.password;

//   //  username, password and id check from the slide example
//   if (username != "harkirat" && password != "pass") {
//     res.status(400).json({
//       msg: "user doesn't exist",
//     });
//     return;
//   }
//   if (kidneyId != 1 && kidneyId != 2) {
//     res.status(411).json({
//       msg: "wrong inputs",
//     });
//     return;
//   }
//   res.send("your heart is healthy");
// });

// middlewares logic

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
