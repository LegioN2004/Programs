score = input("Enter the student score (0-100): ");
if score >= 75 then
    grade = "Star";
elseif score >= 60 then
    grade = "First Division";
elseif score >= 45 then
    grade = "Second Division";
elseif score >= 30 then
    grade = "Third division";
elseif score < 30 then
    grade = "fail";
end
disp("The student grade is: " + grade);
