#include <iostream>
using namespace std;

class Animal {
public:
  virtual void sound() { cout << "Some animal sound" << endl; }
  void compileSound(string animal) {
    if (animal == "Dog") {
      cout << "Dog" << endl;
    } else if (animal == "Cat") {
      cout << "Cat" << endl;
    } else {
      cout << "unknown animal" << endl;
    }
  }
};

class Dog : public Animal {
public:
  void sound() override { cout << "Dog" << endl; }
};

class Cat : public Animal {
public:
  void sound() override { cout << "Cat" << endl; }
};

int main() {
  Animal a;
  a.compileSound("Dog");
  a.compileSound("Cat");

  Animal *b;
  Dog d;
  Cat c;
  b = &d;
  b->sound();

  b = &c;
  b->sound();
}
