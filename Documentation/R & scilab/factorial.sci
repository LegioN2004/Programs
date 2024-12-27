clc
number = input("Enter a number: ");
disp(res)
if number < 10 then
    factorial = 1;
    for i = 1:number
        factorial = factorial * i;
    end
    disp("The factorial of " + string(number) + " is: " + string(factorial));
elseif number>10 && number<20 then
        square = number^2;

    disp("The square of " + string(number) + " is: " + string(square));
else
    disp("Wrong number");
    end
   
  

