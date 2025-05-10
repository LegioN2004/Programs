#include <iostream>
using namespace std;

// find the greatest of four numbers
int main() {
  int arr[4] = {1, 17, 19, 2}, greatest = 0;
  for (int i = 0; i < 4; i++) {
    if (greatest < arr[i]) {
      greatest = arr[i];
    }
  }
  cout << "The greatest is " << greatest;
  return 0;
}