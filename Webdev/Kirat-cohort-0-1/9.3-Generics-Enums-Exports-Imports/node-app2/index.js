"use strict";
var Direction;
(function (Direction) {
    Direction[Direction["Up"] = 0] = "Up";
    Direction[Direction["Down"] = 1] = "Down";
    Direction[Direction["Left"] = 2] = "Left";
    Direction[Direction["Right"] = 3] = "Right";
})(Direction || (Direction = {}));
function doSomething(keyPressed) {
    if (keyPressed == Direction.Up) {
        console.log('going up');
    }
    else if (keyPressed == Direction.Down) {
        console.log('going down');
    }
    // // } else if (keyPressed == 'down') {
    // 	console.log('going down');
    // } else if (keyPressed == 'left') {
    // 	console.log('going left');
    // } else if (keyPressed == 'right') {
    // 	console.log('going right');
    // }
}
// doSomething('Enter');
// doSomething('tur mur tu');
doSomething(Direction.Up);
doSomething(Direction.Down);
