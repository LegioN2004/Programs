// filtering

// give me  back all the even values from an input array

const arr = [1, 2, 3, 4, 5];
// ans  should be: [2, 4]

// ugly way of doing it without using filter
// const newArray = [];
// for (let i = 0; i < arr.length; i++) {
//   if (arr[i] % 2 == 0) {
//     newArray.push(arr[i]);
//   }
// }
// console.log(newArray);

// the filter way of creating it

// function filterLogic(n) {
//   if (n % 2 == 0) {
//     return true;
//   } else {
//     return false;
//   }
// }

const ans = arr.filter(function (n) {
  if (n % 2 == 0) {
    return true;
  } else {
    return false;
  }
});
console.log(ans);
