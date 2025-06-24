#include <iostream>
using namespace std;

class Base {
public:
  virtual void Display() { cout << "\nDisplay base"; }
  virtual void show() { cout << "\nshow base"; }

  virtual ~Base() {} // Always good to make base destructors virtual
};

class Derived : public Base {
public:
  void Display() override { cout << "\ndisplay derived"; }
  void show() override { cout << "\nshow derived"; }
};

int main() {
  Base b;
  Derived d;

  cout << "\n[1] Base object:";
  b.Display(); // Base::Display
  b.show();    // Base::show

  cout << "\n\n[2] Derived object:";
  d.Display(); // Derived::Display
  d.show();    // Derived::show

  cout << "\n\n[3] Base pointer to Base object:";
  Base *ptr1 = &b;
  ptr1->Display(); // Base::Display
  ptr1->show();    // Base::show

  cout << "\n\n[4] Base pointer to Derived object:";
  Base *ptr2 = &d;
  ptr2->Display(); // Derived::Display — because it's virtual
  ptr2->show();    // Derived::show — because it's virtual

  cout << "\n\n[5] Derived pointer to Derived object:";
  Derived *ptr3 = &d;
  ptr3->Display(); // Derived::Display
  ptr3->show();    // Derived::show

  return 0;
}
