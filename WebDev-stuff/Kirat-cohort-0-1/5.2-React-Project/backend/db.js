const mongoose = require("mongoose");

mongoose.connect(
  "mongodb+srv://milindabarua04:legion@firstmongodbinstance.l4lglul.mongodb.net/5-2-todo-app"
  // mongoose no longer accepts a callback
  // () => {
  //   console.log("connected to db");
  // },
);

const todoSchemaModel = new mongoose.Schema({
  title: String,
  description: String,
  completed: Boolean,
});

const todoSchema = mongoose.model("todos", todoSchemaModel);
module.exports = { todoSchema };
