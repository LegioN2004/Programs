#include <iostream>
using namespace std;

int main() {
  string a = "hello world\0";
  int b = 0;
  for (int i = 0; a[i] != '\0'; i++) {
    b++;
  }
  cout << b;
  return 0;
}