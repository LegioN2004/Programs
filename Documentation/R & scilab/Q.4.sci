function grade = determine_grade(percentage)
    if percentage >= 75 then
        grade = "Star";
    elseif percentage >= 60 then
        grade = "First Division";
    elseif percentage >= 45 then
        grade = "Second Division";
    elseif percentage >= 30 then
        grade = "Third Division";
    else
        grade = "Fail";
    end
endfunction
percentage = input("Enter the percentage: ");
disp("The grade is: " + determine_grade(percentage));

