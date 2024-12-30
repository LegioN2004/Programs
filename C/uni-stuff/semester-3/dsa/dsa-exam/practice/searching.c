#include <stdio.h>

int binarySearch(int *arr, int n, int element) {
  int low = 0, mid, high = n - 1;
  while (low <= high) {
    mid = (high + low) / 2;
    if (arr[mid] == element) {
      return mid;
    } else if (arr[mid] < element) {
      low = mid + 1;
    } else if (arr[mid] > element) {
      high = mid - 1;
    } else {
      printf("element not found");
      return -1;
    }
  }
  return -1;
}

int main() {
  int n = 0, element = 0;
  printf("enter the size: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array: \n");
  for (int i = 0; i < n; i++) {
    printf("\nelement(%d):", i);
    scanf("%d", &arr[i]);
  }

  printf("\nEnter the element you want to find from the array: ");
  scanf("%d", &element);
  // int index = linearSearch(arr, n, element);
  // run the sorting code before doing the binary search okay
  // bubbleSortArray(arr, n);
  int index = binarySearch(arr, n, element);
  if (index) {
    printf("\nElement %d found at index %d", element, index);
  } else {
    printf("Element not found");
  }

  return 0;
}