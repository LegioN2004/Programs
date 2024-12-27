clc;
a = 5;

function result = fct(a)
    if modulo(a, 2) == 0 then
        result = "the no is even"
    else 
        result = "the no is odd"
    end
endfunction

disp(fct(a));
disp(%e)
disp(%pi)
disp(10:-2:1)

disp(factorial(5))
x = [1, 2, 3, 4], y = [5, 6, 7, 8]
disp(x == y)
