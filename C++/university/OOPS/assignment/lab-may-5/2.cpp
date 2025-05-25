#include <iostream>
using namespace std;

class Animal {
public:
  Animal() { cout << "Animal constructor called\n"; }
};

class Dog : public Animal {
public:
  Dog() { cout << "Dog constructor called\n"; }
};

class Cat : public Animal {
public:
  Cat() { cout << "Cat constructor called\n"; }
};

int main() {
  cout << "Creating Dog object:\n";
  Dog d;

  cout << "\nCreating Cat object:\n";
  Cat c;
  return 0;
}
