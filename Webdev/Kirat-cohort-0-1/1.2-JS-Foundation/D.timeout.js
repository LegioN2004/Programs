// setTimeout, it is a global function that JS provides
// second arg represents the no of seconds that you need to wait

function greet() {
	console.log('In the JS hell');
}
setTimeout(greet, 9 * 1000); // it means after how much time the greet function will run, you can even directly apply the setTimeout function in the function declaration itself
// it is supposed to call a function after a certain duration, this is also an example of callback

// then we have setInterval which runs the function after every interval
setInterval(greet, 0.1 * 1000);
