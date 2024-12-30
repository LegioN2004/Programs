#include <stdio.h>
int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  printf("%d\n", arr[2]);
  printf("%d\n", *(2 + arr));
  printf("%d\n", *(arr + 2));
  return 0;
}