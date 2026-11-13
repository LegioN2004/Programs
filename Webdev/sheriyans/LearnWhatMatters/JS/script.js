// word vs keyword

// 'for', 'else', 'if, etc are keywords so it can't be used as we wish but other words such as names, etc can be done so

// to store any type of data we use variables

var hello = 10;
console.log(hello + hello);

// this is known as hoisting
console.log(a);
var a = 12;

var b = [1, 2, 3, 4];
var c = b;
b.pop();
console.log(c);

// this is the way to write a function statement
function hui(){
		console.log("Helo");
		console.log("Helo");
		console.log("Helo");
		console.log("Helo");
}

// how to run, use the following
hui();

function hi(a, b){ // we need to give vars for taking this args from functions
		console.log(a, b); // and we can directly print too
}

hi(21, 22); // the things written in the brackets are arguments

// arrays
var e = [1,2]; // when we use the live server, the dev tools console also tells us that the array is this, the value at the 0th and 1th index is this and it is using a length of 2
console.log(e) // this prints the whole array and about the array
console.log(e[0]) // this will print the data at the 0th index which in case here is 1

e.push(9);
console.log(e) // after the push statement we'll see the changes in the array of push, 9 is added

e.pop();
console.log(e) // after the pop statement we'll see the changes in the array of pop, 9 is removed

e.unshift(0);
console.log(e) // after the unshift statement we'll see the changes in the array of pop, 0 is added at the starting

e.shift();
console.log(e) // after the shift statement we'll see the changes in the array of pop, 0 will be removed

e.splice(0,2);
console.log(e) // after the shift statement we'll see the changes in the array of pop, 0 will be removed

console.log(watch);

var watch = {
		brand: "Casio",
		price: 5000,
		color: "silver",
		type: "automatic",
		digital: false,
		kuchbolo: function(){},
}

watch.brand = "nakli Casio";
