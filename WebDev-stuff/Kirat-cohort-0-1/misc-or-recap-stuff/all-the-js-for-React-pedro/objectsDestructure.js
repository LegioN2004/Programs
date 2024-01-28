const naam = "hello";
const person = {
  // name: name, // no neeed to do this instead
  naam,
  age: 20,
  isMarried: false,
  address: {
    city: "city nothing",
    state: "state nothing",
    street: "street nothing",
  },
};
const person1 = {
  // name: name, // no neeed to do this instead
  naam: "second",
  age: 22,
  isMarried: true,
  address: {
    city: "city second",
    state: "state second",
    street: "street second",
  },
};
const {
  naam: firstName,
  age,
  address: { street },
} = person;
console.log(person);
console.log(naam); // gives "hello"
console.log(age); // gives 20
console.log(firstName); // gives "hello"
// console.log(address); // doesn't give all the objects with the key value pairs as output, it errs out since address is not defined there
console.log(street); // you can get the street output in that way as well

const person3 = { ...person, ...person1 }; // this basically says that join both the arrays in order and if there is same key value pairs in both the arrays then replace the first with the second array in order
console.log(
  "replacing with second in the strings and 2 in number for the replacing array",
);
console.log(person3);

// output;
// {
//   naam: 'hello',
//   age: 20,
//   isMarried: false,
//   address: {
//     city: 'city nothing',
//     state: 'state nothing',
//     street: 'street nothing'
//   }
// }
// hello
// 20
// hello
// street nothing
//
// output after replacing using spreads
