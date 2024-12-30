// find if numbers is armstrong or not

#include <math.h>
#include <stdio.h>

int main()
// using for loop
// {
//     int main, number, toStore = 0, numberCopy;
//     printf("Enter a number: ");
//     scanf("%d", &number); // 153
//     numberCopy = number;  // 153
//     for (int i = 0; i < number; i++)
//     {
//         main = number % 10;            // 3 5 1
//         number = number / 10;          // 153 15 1
//         toStore += main * main * main; // 27 + 125 + 1 = 153
//     }
//     printf("The number is %d\n", toStore);
//     if (toStore == numberCopy)
//     {
//         printf("The number is an armstrong number");
//     }
//     else
//     {
//         printf("The number is not an armstrong number");
//     }
//     return 0;
// }
{
  int n1, n2, arm = 0, rem;
  printf("Enter a number: ");
  scanf("%d", &n1);
  n2 = n1;
  while (n1 != 0) {
    rem = n1 % 10;
    arm = arm + pow(rem, 3);
    n1 = n1 / 10;
  }
  if (arm == n2) {
    printf("The number is an armstrong number");
  } else {
    printf("The number is not an armstrong number");
  }
}