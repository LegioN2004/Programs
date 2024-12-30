// swapping of 2 numbers

#include <stdio.h>

void withoutThird(int a, int b)  // 4 5
{
  a = a + b;  // a = 4 + 5 = 9
  b = a - b;  // b = 9 - 5 = 4
  a = a - b;  // a = 9 - 4 = 5
  printf(
      "swapping the values without using third variable are a = %d and b = %d "
      "\n",
      a, b);
}

int main() {
  int a, b, temp;
  printf("Enter the first number a = ");
  scanf("%d", &a);
  printf("Enter the second number b = ");
  scanf("%d", &b);
  withoutThird(a, b);
  temp = a;
  a = b;
  b = temp;
  printf("swapping the values using a third variable are a = %d and b = %d \n",
         a, b);
  return 0;
}
