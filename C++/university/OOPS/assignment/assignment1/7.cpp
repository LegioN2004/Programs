// default argument
#include <iostream>
using namespace std;

void greet(string name = "sum") { cout << "Hello, " << name << endl; }

int main() {
  greet();
  greet("John");
  return 0;
}