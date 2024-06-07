#include <stdio.h>

void print() {
  int a[5], b;
  for (int i = 0; i < 5; i++) {
    a[i] = i;
    printf("%d", a[i]);
  }
  printf("\n");
}

void reverse() {
  int a[5];
  for (int i = 0; i < 5; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}

void pattern1() {
  printf("right half pyramid\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
}

void pattern2() {
  int rows = 5;
  printf("\n");
  for (int i = 1; i <= rows; i++) {
    for (int j = i; j < rows; j++) {
      printf(" ");
    }
    for (int k = 1; k <= i; k++) {
      printf("*"); // print the Star
    }
    printf("\n");
  }
}

void armstrong() {
  int a = 153, b = a, c, d = 0, i = 0;
  // scanf("%d", &a);
  // find the number of digits
  for (; a != 0; a /= 10, ++i)
    ;
  a = b;

  while (a != 0) {
    c = a % 10;
    d = pow(c, i) + d;
    a = a / 10;
  }

  if (b == d) {
    printf("The number given is an armstrong number\n");
  } else {
    printf("The number given is not an armstrong number\n");
  }
}

void palindrome() {
  int a, b = a, c, d = 0;
  // scanf("%d", &a);
  while (a != 0) {
    c = a % 10;
    d = c + d * 10;
    a = a / 10;
  }
  if (b == d) {
    printf("The number given is a palindrome number\n");
  } else {
    printf("The number given is not a palindrome number\n");
  }
}

void array1() {
  // print sum of the elements of the array
  int arr[5] = {1, 2, 3, 4, 5}, a = 0;
  for (int i = 0; i < 5; i++) {
    a = a + arr[i];
  }
  printf("%d", a);
  printf("\n");
}

void array2() {
  // addition of matrices 3*3
  int col[3][3], row[3][3], res[3][3];
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &col[i][j]);
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &res[i][j]);
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      res[i][j] = col[i][j] + row[i][j];
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d", res[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void array3() {
  //
  int arr[5] = {1, 2, 3, 4, 5}, a = 0;
  for (int i = 0; i < 5; i++) {
    a = a + arr[i];
  }
  printf("%d", a);
  printf("\n");
}

int main() {
  print();
  reverse();
  pattern1();
  pattern2();
  armstrong();
  palindrome();
  array1();
  array2();
  // array3();
  return 0;
}
