type keyPressed = "up" | "down" | "left" | "right";

// enum Direction {
//   Up = "up",
//   Down = "down",
//   Left = "left",
//   Right = "right",
// }

enum Direction {
  Up = 1,
  Down,
  Left,
  Right,
}

function doSomething(keyPressed: Direction) {
  if (keyPressed == Direction.Up) {
    console.log("going up and its value is ", Direction.Up);
  } else if (keyPressed == Direction.Down) {
    console.log("going down and its value is ", Direction.Down);
  }
}

// doSomething('Enter');
// doSomething('tur mur tu');
doSomething(Direction.Up);
doSomething(Direction.Down);
