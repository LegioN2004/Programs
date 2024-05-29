
#include <stdio.h>
void main() {
  int n, avg = 0;

  printf("Enter n:");
  scanf("%d", &n);

  int x[n];
  printf("Enter all the elements:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  for (int i = 0; i < n; i++) {
    avg += x[i];
  }
  avg /= n;
  printf("Averge:%d", n);
}
