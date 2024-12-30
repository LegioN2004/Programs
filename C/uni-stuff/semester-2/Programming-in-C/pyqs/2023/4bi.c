// write a C program to swap two numbers using pointers and function.
#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *x, int *y) {
  int temp;
  temp = *x;  // Store the value of x in temp
  *x = *y;    // Assign the value of y to x
  *y = temp;  // Assign the value of temp (original x) to y
}

int main() {
  int a, b;

  // Input two numbers from the user
  printf("Enter the value of a: ");
  scanf("%d", &a);
  printf("Enter the value of b: ");
  scanf("%d", &b);

  // Display the values of a and b before swapping
  printf("Before swapping:\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  // Call the swap function
  swap(&a, &b);

  // Display the values of a and b after swapping
  printf("After swapping:\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}
