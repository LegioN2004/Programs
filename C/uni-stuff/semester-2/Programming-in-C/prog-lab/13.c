#include <stdio.h>

int main() {
  double p;
  printf("Enter your percentage: ");
  scanf("%lf", &p);
  if (p <= 100 && p >= 75) {
    printf("Grade: A");
  } else if (p <= 75 && p >= 60) {
    printf("Grade: B");
  } else if (p <= 60 && p >= 50) {
    printf("Grade: C");
  } else if (p <= 45 && p >= 0) {
    printf("Grade: D");
  } else {
    printf("FAIL");
  }
  return 0;
}
