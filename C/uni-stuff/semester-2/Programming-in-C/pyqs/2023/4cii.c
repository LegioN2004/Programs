#include <stdio.h>

#define MAX_SIZE 10

int main() {
  int matrix[MAX_SIZE][MAX_SIZE];
  int rows, cols;

  // Read the dimensions of the matrix
  printf("Enter the number of rows and columns of the matrix (max %d): ",
         MAX_SIZE);
  scanf("%d %d", &rows, &cols);

  // Check if the matrix is square
  if (rows != cols) {
    printf(
        "Error: The matrix must be square (number of rows = number of "
        "columns).\n");
    return 1;  // Return with error code 1
  }

  // Read the elements of the matrix
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter element [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  // Calculate the sum of diagonal elements
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    sum += matrix[i][i];  // Add the diagonal element at position [i][i]
  }

  // Print the sum of diagonal elements
  printf("The sum of diagonal elements of the matrix is: %d\n", sum);

  return 0;
}
