clc;

//n = 5
//disp(n);
//// n = evstr(n)
//for i = 1:n
//    disp("iteration number:" + string(i));
//end
//
//// odd or even
//
//function res = oddEven(a)
//    a = input("enter")
//    if modulo(a,2) == 0 then
//        res = "even"
//    else
//        res = "odd"
//    end
//endfunction
//    
//// disp(oddEven(a))
//disp(%e)
//disp(%pi)
//disp(factorial(5))

function [x, y]=myfct(a, b)
x=a+b
y=a-b
endfunction 

disp([x,y]=myfct(3,2));


function [x,y]= moreCalc(a,b)
    x = a + b;
    y = a - b;
endfunction

disp([x,y]=moreCalc(1,2))
