#include <stdio.h>

int main() {
  int arr[100], n, element, position;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);  // 5

  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);  // 1 2 3 4 5
  }

  printf("Enter the element to be inserted: ");
  scanf("%d", &element);

  printf("Enter the position where the element is to be inserted: ");
  scanf("%d", &position);

  if (position < 0 || position > n) {
    printf("Invalid position! Please enter a position between 0 and %d\n", n);
    return 1;
  }

  for (int i = n; i > position; i--) {
    arr[i] = arr[i - 1];
  }

  arr[position] = element;

  n++;

  printf("Array after insertion:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
