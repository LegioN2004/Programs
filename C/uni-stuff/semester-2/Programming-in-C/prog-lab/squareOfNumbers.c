#include <stdio.h>
#include <math.h>

int main() {
  int a = 0, b = 0;
 printf("enter the numbers till where you want to find the square of the numbers: ");
 scanf("%d", &a);  // 1234
  for (int i = 1; i <= a; i++) {
   b = b + pow(i, 2);
  }
      printf("%d \n", b );
}
