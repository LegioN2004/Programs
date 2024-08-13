// wap that takes an array of ints as input and reverses the array. The program
// should print the original array and then the reversed array
#include <stdio.h>

int main() {
  int n = 0;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the element %d: ", i);
    scanf("%d", &arr[i]);
  }
  printf("\n");
  printf("The original array is: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("The reversed array is: ");
  for (int i = n - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  return 0;
}
