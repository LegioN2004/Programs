// find the area of a triangle
#include <stdio.h>

int main() {
  float area, base, height;
  printf("enter the three sides ");
  scanf("%f%f", &base, &height);
  area = (base * height) / 2;
  printf(" the area is %f", area);
}
