#include <iostream>
using namespace std;

class Parent {
public:
  Parent() { cout << "\nParent class called\n"; }
};

class Child : public Parent {
public:
  Child() { cout << "\nChild class called\n"; }
};

class GrandChild : public Child {
public:
  GrandChild() { cout << "\nGrandChild class called\n"; }
};

int main() {

  GrandChild g;

  return 0;
}