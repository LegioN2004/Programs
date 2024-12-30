#include <stdio.h>

void printArray(int *arr, int n) {
  printf("The array is:\n");
  for (int i = 0; i < n; i++) {
    printf("%d(%d)\t", arr[i], i);
  }
}

void bubbleSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
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
  for (int i = 0; i < n - 1; i++) {
    int smallestIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[smallestIndex] > arr[j]) smallestIndex = j;
    }
    int temp = arr[i];
    arr[i] = arr[smallestIndex];
    arr[smallestIndex] = temp;
  }
}

void InsertionSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int prev = i;
    int curr = arr[i + 1];
    while (prev >= 0 && arr[prev] > curr) {
      arr[prev + 1] = arr[prev];
      prev--;
    }
    arr[prev + 1] = curr;
  }
}

int main() {
  int arr[] = {12, 9, 3, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);  // printing the array before sorting
  /* bubbleSort(arr, n); */
  /* SelectionSort(arr, n); */
  InsertionSort(arr, n);
  printf("\n");
  printArray(arr, n);  // printing the array before sorting
  return 0;
}
