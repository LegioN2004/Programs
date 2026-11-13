// function check(a) {
//   for (let i = 0; i < a.length; i++) {
//     for (let j = 65; j <= 90; j++) {
//       let x = {};
//       x.push(String.fromCharCode(j));

//       if (a[i] == x[i]) {
//         return false;
//       } else {
//         return true;
//       }
//     }
//   }
// }

// let a = check("5 + abc");
// console.log(a);

function checkForNonNumericalCharacters(inputString) {
  // Iterate through each character in the string
  for (let i = 0; i < inputString.length; i++) {
    // Check if the current character is not a digit
    if (isNaN(parseInt(inputString[i]))) {
      // If not a digit, throw an error
      throw new Error("Error: String contains non-numerical characters");
    }
  }

  // If no error is thrown, the string is valid
  return "String is valid";
}

// Example usage:
try {
  const result = checkForNonNumericalCharacters("5");
  console.log(result); // This line won't be reached in case of an error
} catch (error) {
  console.error(error.message); // Output: Error: String contains non-numerical characters
}
