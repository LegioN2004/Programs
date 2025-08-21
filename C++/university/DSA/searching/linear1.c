#include <stdio.h>

int search(int arr[], int x, int N) {
  for (int i = 0; i < N; i++)
    if(arr[i] == x)
      return i;
   return -1;
}

int main(void) {
  int arr[] = { 1, 2, 3, 4, 5};
  int x = 3;
  int N = sizeof(arr)/ sizeof(arr[0]);

  int result = search(arr, x, N);
  (result == -1)
    ? printf("Element is not present in the array")
    : printf("Element is present at index %d", result);
  return 0;
}


