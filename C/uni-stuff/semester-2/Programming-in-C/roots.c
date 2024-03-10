#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main()
{
  int a, b, c;
  float d, root1, root2;
  printf("Enter the numbers\n");
  scanf("%d %d %d", &a, &b, &c);
  d = (int)b * b - 4 * a * c;

  if (d > 0)
  {
    root1 = (-b + sqrt(d)) / (2 * a);
    root2 = (-b - sqrt(d)) / (2 * a);
    printf("The roots are real and different: %f, %f", root1, root2);
  }
  else if (d == 0)
  {
    root1 = root2 = -b / (2 * a);
    printf("The roots are real and equal: %f, %f", root1, root2);
  }
  else
  {
    printf("The roots are complex and different");
  }

  return 0;
}
