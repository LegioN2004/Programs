
#include <stdio.h>

void pattern1() {
  printf("--------- left half pyramid ---------\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void pattern2() {
  printf("--------- right half pyramid ---------\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 5; j <= i; j--) {
      printf("*");
    }
    printf("\n");
  }
}

void pattern3() {
  printf("--------- ulta left half pyramid ---------\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 5; j >= i; j--) {
      printf("*");
    }
    printf("\n");
  }
}

void pattern4() {
  printf("--------- left half pyramid but with numbers ---------\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d", j);
    }
    printf("\n");
  }
}

void pattern5() {
  printf("--------- full left and right half pyramid joined ---------\n");
  int n = 5;
  for (int i = 0; i < 2 * n; i++) {
    int totalCols = (i > n) ? (2 * n - i) : i;
    for (int j = 0; j < totalCols; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void pattern6() {
  printf("--------- rhombus with star ---------\n");
  int n = 5;
  for (int i = 0; i < 2 * n; i++) {
    int totalCols = (i > n) ? (2 * n - i) : i;

    int noOfSpaces = n - totalCols;
    for (int i = 0; i < noOfSpaces; i++) {
      printf(" ");
    }

    for (int j = 0; j < totalCols; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

int main() {
  pattern1();
  // pattern2();
  pattern3();
  pattern4();
  pattern5();
  pattern6();
  return 0;
}
