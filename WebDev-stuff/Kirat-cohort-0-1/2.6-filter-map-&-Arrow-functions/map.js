// given an array, give back a new array in which every value is multiplied by 2
// if input = [ 1, 2, 3,, 4, 5 ];  output = [ 2, 4, 6, 8 , 10 ]

// ugly way to solve the above problem (debatable)
// const input = [1, 2, 3, 4, 5];
// const newArray = [];
// for (let i = 0; i < input.length; i++) {
//   newArray.push(input[i] * 2);
// }
// console.log(newArray);

// prettier way to solve the problem
const input = [1, 2, 3, 4, 5];
function transform(i) {
  return i * 2;
}
const ans = input.map(transform);
console.log(ans);
// syntax
