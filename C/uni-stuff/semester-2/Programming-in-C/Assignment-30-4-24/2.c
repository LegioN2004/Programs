// Write a C program that calculates the HCF and LCM of two numbers.

#include <stdio.h>

int main() {
  int a, b;
  printf("Enter the two numbers: ");
  scanf("%d%d", &a, &b);

  int large = (a > b) ? a : b;
  int hcf = 1;

  // find the HCF
  for (int i = 1; i <= large; i++) {
    if (a % i == 0 && b % i == 0) {
      hcf = i;
    }
  }
  printf("The HCF of %d and %d is %d \n", a, b, hcf);

  // find the LCM
  int lcm = (a * b) / hcf;
  printf("The LCM of %d and %d is %d \n", a, b, lcm);
  return 0;
}
