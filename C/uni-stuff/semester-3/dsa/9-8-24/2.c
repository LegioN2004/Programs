// wap that finds and prints the max and min value in a user defined array of
// integers. Also display their respective indices.

#include <stdio.h>

int main() {
  int arr[] = {1, 3, 5, 4, 2};
  int max = 0;
  int min = 0;
  int position = 0;
  for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
    if (arr[i] > arr[i + 1]) {
      int temp = arr[i];
      arr[i] = arr[i + 1];
      max = temp;
      position = i;
    }
  }
  printf("max value %d", max);
  printf("min value %d", min);
  printf("position %d", position);
  return 0;
}
