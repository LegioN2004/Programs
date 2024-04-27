/*
Amicable numbers are found in pairs. A given pair of numbers is Amicable if
the sum of the proper divisors (not including itself) of one number is equal to
the other number and vice – versa. For example 220 & 284 are amicable numbers
First we find the proper divisors of 220:
220:1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110
1+ 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284
Now, 284: 1, 2, 4, 71, 142
1 + 2 + 4 + 71 + 142 = 220
*/

#include <stdio.h>

int main() {
  int a = 0, b = 0, divisors = 0, newValue = 0;
  printf("Enter the two numbers to find the amicable of(use spaces): ");
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= a; i++) {
    if (a % i == 0 && a != i) {
      divisors = i;
      newValue += divisors;
    }
  }
  if (newValue == b) {
    printf("the numbers are amicable");
  } else {
    printf("the numbers are not amicable");
  }
  return 0;
}
