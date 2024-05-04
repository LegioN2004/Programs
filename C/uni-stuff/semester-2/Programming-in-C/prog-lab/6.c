// simple interest
#include <stdio.h>

int main() {
  float P, R, T, SI;
  printf("Enter the Principal amount:\n");
  scanf("%f", &P);
  printf("Enter the Rate of interest:\n");
  scanf("%f", &R);
  printf("Enter the Time:\n");
  scanf("%f", &T);
  SI = P * R * T / 100;
  printf("Simple Interest = %f\n", SI);
  return 0;
}
