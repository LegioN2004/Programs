const mongoose = require("mongoose");
mongoose.connect(
  "mongodb+srv://milindabarua04:legion@firstmongodbinstance.l4lglul.mongodb.net/",
);

const Users = mongoose.model("Users", {
  name: String,
  email: String,
  password: String,
});

const user = new Users({
  name: "Zildjian",
  email: "hello@gmail.com",
  password: "nothing",
}); // in-memory object
user.save().then(() => console.log("data sent to the database"));
