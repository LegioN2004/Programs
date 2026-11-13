const express = require("express");
const app = express();

function mainLogic(req, res, next) {}

app.get("/sum", function (req, res) {
  const a = req.query.a;
  const b = req.query.b;
  let c = parseInt(a) + parseInt(b);
  res.json(c);
});

app.listen(3000);
