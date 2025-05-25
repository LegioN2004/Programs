#include <iostream>
using namespace std;

class MyException {
public:
  void display() { cout << "Custom exception occurred!" << endl; }
};

int main() {
  try {
    throw MyException();
  } catch (MyException e) {
    e.display();
  }

  return 0;
}
