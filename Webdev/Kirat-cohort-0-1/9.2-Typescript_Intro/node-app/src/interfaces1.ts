interface User {
  firstName: string;
  lastName: string;
  age?: number;
}

function isLegal(user: User) {
  return user.age >= 18
    ? console.log("legal hai yar")
    : console.log("illegal hai yar");
}

function greet(user: User) {
  console.log("heloooo there " + user.firstName + " " + user.lastName);
}

isLegal({
  firstName: "harkirat",
  lastName: "singh",
  age: 20,
});

greet({
  firstName: "harkirat",
  lastName: "singh",
});
