#include <stdio.h>

int main() {
  int size = 0;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int a[size];
  for (int i = 0; i < size; i++) {
    printf("Enter the elements of the array (%d): ", i);
    scanf("%d", &a[i]);
  }
  printf("\nArray elements before sorting\n");
  for (int i = 0; i < size; i++) {
    printf("%d: %d\n", i, a[i]);
  }

  // main logic for selection sort
  for (int i = 0; i < size; i++) {
    int min = i;
    // start comparison of the minimum
    for (int j = i + 1; j < size; j++)
    // this inner for loop is used to find the position of the lowest element
    {
      // checking the value of the array at the min index position
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }
  printf("\nArray elements after sorting\n");
  for (int i = 0; i < size; i++) {
    printf("%d: %d\n", i, a[i]);
  }
  return 0;
}
