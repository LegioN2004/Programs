var a = 1;
{
    console.log(a); // Your prediction: Prints 1. What happens in reality?
    var a = 2;
    let b = 3;
}
console.log(a); // Your prediction: Prints 2. Correct!
console.log(b); // Your prediction: Throws ReferenceError. Correct!
