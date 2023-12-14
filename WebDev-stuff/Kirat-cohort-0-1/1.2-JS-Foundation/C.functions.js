// function sum(a, b) {
// defining a function
// do things with the input and return an output
// 	return a + b;
// }

// const value = sum(1, 2);
// const value2 = sum(1, 22);
// console.log(value);
// console.log(value2);

// goal is to show everything in a single function call 
// but you are only allowed to do a single function call
function sum(num1, num2, fnToCall) {
	let result = num1 + num2;
	fnToCall(result); // and as such we can directly do a fnToCall(result) which will run all the functions
}

function displayResult(data) {
	console.log('Result of the sum is: ' + data);
}

function displayResultPassive(data) {
	console.log("sum's result is: " + data);
}

const ans = sum(1, 2, displayResult); // a function goes as an argument to another function as a arg
// displayResult(ans);
// why is this good: Bc now we can change what function should get called, pass it as an argument and that will get called
