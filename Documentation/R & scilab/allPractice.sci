clc;

a = 5
b = 4
c = 7
d = 9

//function hello = compare(a,b)
//    hello = max([a,b])
//    if modulo(b,2) == 0 then
//        disp("even")
//    else 
//        disp("odd")
//    end
//endfunction

// disp(compare(a,b))


largest = a;

if largest < b then
    largest = b;
end

if largest < c then
    largest = c;
end

if largest < d then 
    largest = d;
end

disp("the largest no is " + string(largest))
    



