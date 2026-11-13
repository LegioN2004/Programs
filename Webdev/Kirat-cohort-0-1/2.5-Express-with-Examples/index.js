const express = require("express");
const app = express();
const port = 3000;

function calculationSum(n) {
  let ans = 0;
  for (let i = 0; i <= n; i++) {
    ans += i;
  }
  return ans;
}

app.get("/", function (req, res) {
  const n = req.query.n;
  console.log(n);
  res.send(" hi your answer is " + calculationSum(n).toString());
});

app.listen(port, function () {
  console.log(`listening on ${port}`);
});
