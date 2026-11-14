// function outer(){
//     money = 500; // Look carefully: No 'var', 'let', or 'const' keyword!
//     function inner(){
//         console.log(money);
//     }
//     inner();
// }
// var money = 1000;
// outer();
// console.log(money);


function makeSDE(){
    console.log(role);
    var role = "Frontend SDE";

    {
        let salary = "Premium";
        console.log(role);
    }

    console.log(salary);
}
var role = "Architect";
makeSDE();
