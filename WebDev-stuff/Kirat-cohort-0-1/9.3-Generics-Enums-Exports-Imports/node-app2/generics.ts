type Input = number | string;

// function firstElement(arr: Input[]) {
//   return arr[0];
// }

function identity<T>(arg: T): T {
	return arg;
}
let output1 = identity<string>('myString');
let output2 = identity<number>(100);

const hello = output1.toLowerCase();
console.log(output1);
console.log(output2);
console.log(hello);

// const a = firstElement([1, 2, 3]); // number
// const b = firstElement(["hello", "hi"]); // string
// console.log(b);
