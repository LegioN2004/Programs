#include <stdio.h>
void function1(int n);
void function2(int n) {
  if (n > 0) {
    printf("%d ", n);
    function1(n - 1);
  }
}
void function1(int n) {
  if (n > 0) {
    printf("%d ", n);
    function2(n - 1);
  }
}
int main() {
  int n = 5;
  function1(n);
  return 0;
}
