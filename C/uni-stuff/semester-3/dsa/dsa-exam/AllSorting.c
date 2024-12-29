#include <stdio.h>

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
}

void bubbleSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {  // for no of passes
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void SelectionSort(int *arr, int n) {
  // first iteration for traversing through the array, n - 1 cause the times
  // required to sort is n - 1
  for (int i = 0; i < n - 1; i++) {
    // unsorted part ka starting index and the smallest number gets assigned
    // index
    int smallestIndex = i;
    // to traverse through the remaining parts of the unsorted array and check
    // the smallest index
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[smallestIndex]) {
        smallestIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[smallestIndex];
    arr[smallestIndex] = temp;
  }
}

void InsertionSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {  // 0 1
    int curr = arr[i + 1];           // 9 3
    int prev = i;                    // 0 1

    while (prev >= 0 && arr[prev] > curr) {
      arr[prev + 1] = arr[prev];
      prev--;  // -1, 0
    }
    // placing the current element in the correct position
    arr[prev + 1] = curr;  // 0 1
  }
}

int main() {
  int arr[] = {12, 9, 3, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);  // printing the array before sorting
  // bubbleSort(arr, n);
  // SelectionSort(arr, n);
  InsertionSort(arr, n);
  printf("\n");
  printArray(arr, n);  // printing the array before sorting
  return 0;
}
