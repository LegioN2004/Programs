clc;
a = input("first number")
b = input("second number")

function hello = largest(a,b)
    hello=max([a,b])
endfunction

disp("the largest number is" + string(largest(a,b)));
