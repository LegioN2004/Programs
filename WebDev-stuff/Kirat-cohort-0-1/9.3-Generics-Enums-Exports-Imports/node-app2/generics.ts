type Input = number | string;

// function firstElement(arr: Input[]) {
//   return arr[0];
// }

function identity<T>(arg: T): T {
  return arg;
}
let output1 = identity<string>("myString");
let output2 = identity<number>(100);

// const a = firstElement([1, 2, 3]); // number
// const b = firstElement(["hello", "hi"]); // string
// console.log(b);
