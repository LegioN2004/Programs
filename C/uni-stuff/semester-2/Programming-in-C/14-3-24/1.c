// wap to compute the given series till n
// 1 + 2 + 3 + 4 +  ................ + n

#include <stdio.h>

int main() {
  int n, i = 1, c = 0;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  while (i <= n) {
    c += i;
    i++;
  }
  printf("The sum of the first %d numbers is %d\n", n, c);
  return 0;
}

// notes
// why does not setting the value of c to 0 give a very different and wrong
// answer ChatGPT In the provided code, c is used to accumulate the sum of the
// series. If you don't initialize c to 0 before starting the loop, it will
// contain some garbage value initially. This garbage value may affect the final
// result of the summation because you are adding the loop counter i to c
// without guaranteeing its initial value.

// By initializing c to 0 before the loop, you ensure that it starts with a
// known value (0), and then you incrementally add each value of i to c. This
// approach accurately calculates the sum of the series from 1 to n.

// Here's why not initializing c to 0 can give incorrect results:

// 1. If c initially contains a garbage value, adding i to it will result in an
// incorrect sum.
// 2. The garbage value in c could be large or small, leading to unpredictable
// results.
// 3. Without initializing c to 0, you have no control over its initial value,
// which may introduce errors in the summation. Therefore, it's essential to
// initialize c to 0 before starting the loop to ensure accurate calculation of
// the sum of the series.