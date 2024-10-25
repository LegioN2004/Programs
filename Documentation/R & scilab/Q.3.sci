function result = positive_or_negative(num)
    if num > 0 then
        result = "Positive";
    elseif num < 0 then
        result = "Negative";
    else
        result = "Zero";
    end
endfunction

num = input("Enter a number: ");
disp("The number is: " + positive_or_negative(num));

