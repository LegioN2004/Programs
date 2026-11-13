// const a = 1;
// a = 2;
// console.log(a);

let firstName = 'hello';
let age = 18;
let isMarried = true;
console.log("This person's name is " + firstName + ' and their age is ' + age);
if (isMarried == true) {
	console.log(firstName + ' is married');
} else {
	console.log(firstName + ' is not married');
}

// wap counts a program from 1 to hundred and prints everything
let answer = 0;
for (let i = 0; i <= 100; i++) {
	answer = answer + i;
}
console.log(answer);

// wap to greet a person given their first and last name
let a = 'hello';
let b = 'hello';

console.log('hi there ' + a + b);

// wap to greet a person with their gender
let c = 'female';
if (c == 'male') {
	console.log('you are a mota ' + a + b);
} else {
	console.log('you are a female ' + a + b);
}

// wap that counts from 0 to 1000 and prints it
let d = 0;
for (let i = 0; i <= 1000; i++) {
	console.log(d++);
}
