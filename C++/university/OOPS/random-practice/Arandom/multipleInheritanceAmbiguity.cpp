#include <iostream>

class dog {
public:
  void display() { std::cout << "dog class"; }
};

class bird : public dog {
public:
  void display() { std::cout << "bird class"; }
};

class Animal : public dog, public bird {
public:
  void display() { std::cout << "Animal class"; }
};

int main() {

  bird obj;
  obj.dog::display();

  return 0;
}