const express = require("express");
const app = express();
const { createTodo, updateTodo } = require("./types.js");
const { todoSchema } = require("./db.js");
const cors = require("cors");

app.use(express.json());
app.use(
  cors({
    origin: "http://localhost:5173",
  })
);

// body {
//   title: String
//   description: String
// }
//
// {
// id: string // that is to be marked as completed
// }

app.post("/todo", async function (req, res) {
  const createPayload = req.body;
  const parsedPayload = createTodo.safeParse(createPayload);
  if (!parsedPayload.success) {
    return res.status(411).json({
      msg: "wrong inputs",
    });
  } else {
    const todo = await todoSchema.create({
      title: createPayload.title,
      description: createPayload.description,
      completed: false,
    });
    todo.save();
    res.json({
      msg: "Todos created successfully",
    });
  }
});

app.get("/todos", async function (req, res) {
  const todosFromDb = await todoSchema.find({});
  res.json({
    todos: todosFromDb,
    msg: "The above are your todos",
  });
});

app.put("/completed", async function (req, res) {
  const updatePayload = req.body;
  const parsedPayload = updateTodo.safeParse(updatePayload);
  if (!parsedPayload.success) {
    return res.status(411).json({
      msg: "wrong inputs",
    });
    return;
  }

  await todoSchema.update(
    {
      _id: req.body.id,
    },
    {
      completed: true,
    }
  );
  res.json({
    msg: "todo marked as completed",
  });
});

app.listen(3000, () => {
  console.log("server is running in port 3000");
});

app.use(function (err, req, res, next) {
  // arsoeitnartn
});
