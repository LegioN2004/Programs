// find the roots of a quadratic equation

/* #include <math.h> */
/* #include <stdio.h> */

/* int main() { */
/*   float a = 0, b = 0, c = 0, root1, root2; */
/*   printf("enter the roots a, b and c serially: "); */
/*   scanf("%f%f%f", &a, &b, &c); */
/*   float d = b * b - 4 * a * c; */
/*   if (d > 0 && a != 0) { */
/*     root1 = (-b + sqrt(d)) / (2 * a); */
/*     root2 = (-b - sqrt(d)) / (2 * a); */
/*     printf("the roots are %d,%d", root1, root2); */
/*   } else if (d < 0 && a != 0) { */
/*     root1 = (-b + sqrt(-d)) / (2 * a); */
/*     root2 = (-b - sqrt(-d)) / (2 * a); */
/*     printf("the roots are %d,%d", root1, root2); */
/*   } else if (d == 0 && a != 0) { */
/*     root1 = -b / (2 * a); */
/*     root2 = 0; */
/*     printf("the roots are %d,%d", root1, root2); */
/*   } else if (a == 0) { */
/*     printf("the roots are %d,%d", root1, root2); */
/*   } */
/*   return 0; */
/* } */

#include <math.h>
#include <stdio.h>

int main() {
  float a = 0, b = 0, c = 0, root1, root2;
  printf("Enter the coefficients a, b, and c: ");
  scanf("%f%f%f", &a, &b, &c);
  float d = b * b - 4 * a * c;

  if (d > 0 && a != 0) {
    root1 = (-b + sqrt(d)) / (2 * a);
    root2 = (-b - sqrt(d)) / (2 * a);
    printf("The roots are %.2f, %.2f\n", root1, root2);
  } else if (d == 0 && a != 0) {
    root1 = -b / (2 * a);
    printf("The roots are %.2f, %.2f\n", root1, root1);
  } else if (a != 0) {
    float realPart = -b / (2 * a);
    float imaginaryPart = sqrt(fabs(d)) / (2 * a);
    printf("The roots are %.2f + %.2fi, %.2f - %.2fi\n", realPart,
           imaginaryPart, realPart, imaginaryPart);
  } else if (a == 0 && b != 0) {
    printf("It's a linear equation. The root is %.2f\n", -c / b);
  } else {
    printf("It's a constant equation. No roots.\n");
  }

  return 0;
}
