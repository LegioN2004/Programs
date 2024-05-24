// read two matrices and add them
#include <stdio.h>

void readMatrix(int m, int n, int matrix[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("Enter element [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
}

void addMatrix(int m, int n, int matrix1[m][n], int matrix2[m][n],
               int result[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void printMatrix(int m, int n, int matrix[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int m, n;
  printf("Enter the number of rows for the first matrix: ");
  scanf("%d", &m);
  printf("Enter the number of columns for the first matrix: ");
  scanf("%d", &n);
  int matrix1[m][n];
  int matrix2[m][n];
  int result[m][n];

  // Read the first matrix
  printf("Enter the elements of the first matrix:\n");
  readMatrix(m, n, matrix1);

  // Read the second matrix
  printf("Enter the elements of the second matrix:\n");
  readMatrix(m, n, matrix2);

  // Add the two matrices
  addMatrix(m, n, matrix1, matrix2, result);

  // Print the resulting matrix
  printf("The resulting matrix is:\n");
  printMatrix(m, n, result);

  return 0;
}
