hello();

console.log("A");

function hello() {
    console.log("printed hello function B");
}

console.log("C");

console.log("---------");

var a = 1;
{
    console.log(a);
    var a = 2;
    let b = 3;
}
console.log(a);
console.log(b);

console.log("What happens when u convert the var to let ----------");

let a = 1;
{
    console.log(a);
    let a = 2;
    let b = 3;
}
console.log(a);
console.log(b);
