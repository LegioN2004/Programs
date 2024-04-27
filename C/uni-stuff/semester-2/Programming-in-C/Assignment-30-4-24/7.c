/*
  - [*]  Write a C program to check if a number has three consecutive 5s. If
  yes, print YES, else print NO. Example:
    1. Number: 1353554
    Result: NO
    2. Number: 345559
    Result: YES
*/

#include <stdio.h>

int main() {
  float basicSalary = 0, hra = 0, da = 0, criteria = 0;
  printf("Enter the basic salary: ");
  scanf("%f", &basicSalary);

  if (basicSalary >= 1 && basicSalary <= 4000) {
    hra = basicSalary * 0.1;
    da = basicSalary * 0.5;
  } else if (basicSalary > 4000 && basicSalary <= 8000) {
    hra = basicSalary * 0.2;
    da = basicSalary * 0.6;
  } else if (basicSalary > 8000 && basicSalary <= 12000) {
    hra = basicSalary * 0.25;
    da = basicSalary * 0.7;
  } else if (basicSalary > 12000) {
    hra = basicSalary * 0.3;
    da = basicSalary * 0.8;
  } else {
    printf("Give a correct input for the basic salary");
  }

  float grossSalary = basicSalary + da + hra;

  printf("HRA: RS %.2f\n", hra);
  printf("DA: RS %.2f\n", da);
  printf("Gross Salary: RS %.2f\n", grossSalary);

  return 0;
}
