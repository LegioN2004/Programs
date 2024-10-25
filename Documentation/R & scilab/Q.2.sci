a = input("Enter the first number: ");
b = input("Enter the second number: ");
c = input("Enter the third number: ");
d = input("Enter the fourth number: ");

function max_num = largest_of_four(a, b, c, d)
    max_num = max([a, b, c, d]);
endfunction

disp("The largest number is: " + string(largest_of_four(a, b, c, d)));

function [x, y]=myfct(a, b)
x=a+b
y=a-b
endfunction

disp([x,y]=myfct(3,2));

