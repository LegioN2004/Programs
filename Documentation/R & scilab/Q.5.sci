function result = number_operations(num)
    if num < 10 then
        result = factorial(num);
    elseif num >= 10 & num <= 20 then
        result = num ^ 2;
    else
        result = "Wrong number";
    end
endfunction
num = input("Enter a number: ");
result = number_operations(num);
disp("The result is: " + string(result));

