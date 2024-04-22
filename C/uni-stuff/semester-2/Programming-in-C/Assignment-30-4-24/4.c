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

#include <math.h>
#include <stdio.h>

int main() {
  int a = 4, newValue = 0;
  for (int i = 0; i <= a; i++) {
    newValue = newValue + pow(10, i);
    printf("%d \n", newValue);
  }
  return 0;
}
