const express = require("express");
const zod = require("zod"); // importing zod
const app = express();
app.use(express.json());

// telling zod that the datatype sent by the user will be of array of numbers
// const schema = zod.array(zod.number());

// complex zod parsing
function validateObject(object) {
  const schema = zod.object({
    // email: zod.string().email(),
    // password: zod.string().min(8), // to make it minimum 8 letters
    // country: zod.literal("IN").or(zod.literal("US")),
    kidney: zod.array(zod.number()),
  });
  const response = schema.safeParse(object);
  console.log(response);
}

// app.use(express.json());
// app.post("/health-checkup", function (req, res) {
//   const kidney = req.body.kidney;

//   if (!kidney) {
//     return res.status(404).json({
//       msg: "wrong input",
//     });
//   } else {
//     const kidneyLength = kidney.length;
//     res.send("your kidney length is " + kidneyLength);
//   }
// });
// app.use(function (err, req, res, next) {
//   res.json({
//     msg: "Sorry, something is wrong with our server, will be fixed soon :)",
//   });
// });

app.post("/health-checkup", function (req, res) {
  const response = validateObject(req.body.kidney);
  // const email = validateObject(req.body.email);
  // const password = validateObject(req.body.password);
  // const country = validateObject(req.body.country);
  // const kidneyLength = kidney.length;
  // res.send("your kidney length is " + kidneyLength);
  if (!response.success) {
    res.status(411).json({
      msg: "Input invalid",
    });
  }
  res.send({
    response,
  });
});
app.listen(3000);
