#include <iostream>

int main() {
  int num[] = {56, 34, 23, 45, 67, 89};
  int *ptr;

  for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
    std::cout << num[i] << ", ";
  }
  std::cout << "\n\n";

  ptr = num;

  std::cout << *ptr << std::endl;
  ptr++;
  std::cout << *ptr << std::endl;
  ptr += 2;
  std::cout << *ptr << std::endl;
  ptr--;
  std::cout << *ptr << std::endl;

  return 0;
}