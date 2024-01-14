const express = require("express");

const app = express();

// returns a boolean if the age of the person is more than 14

function appChecker(req, res, next) {
  if (!(req.query.age >= 14)) {
    res.status(411).json({
      msg: "You are not of the right age yet",
    });
  } else {
    next();
  }
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

app.listen(3000);
