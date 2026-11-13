// create a map function that takes 2 inputs, an array and a transformation callback/function and transforms the array into a new one using the transformation function

let array = [1, 2, 3, 4, 5];
let transform_function = (n) => {
  if (array[i] % 2 == 0) {
    return array[i];
  }
};

const map = (a, callback) => {
  let newArray = [];
  for (let i = 0; i < a.length; i++) {
    if (a[i] % 2 == 0) {
      console.log(newArray.push(callback));
    }
  }
};

map(array, transform_function);

// function customMap(array, transformation) {
//   const newArray = [];

//   for (let i = 0; i < array.length; i++) {
//     newArray.push(transformation(array[i]));
//   }

//   return newArray;
// }

// // Example usage:

// const originalArray = [1, 2, 3, 4, 5];

// // Transformation function to double each element
// const doubleTransform = (num) => {
//   if (num % 2 == 0) {
//     return num;
//   }
// };

// // Using the customMap function to create a new array with doubled elements
// const newArray = customMap(originalArray, doubleTransform);

// console.log(newArray); // Output: [2, 4, 6, 8, 10]
