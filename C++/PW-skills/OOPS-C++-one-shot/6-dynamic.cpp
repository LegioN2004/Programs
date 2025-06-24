#include <iostream>
using namespace std;

class Cricketer {
public:
  string name;
  int runs;
  float avg;

  Cricketer(string name, int runs, float avg) {
    this->name = name;
    this->runs = runs;
    this->avg = avg;
  }
};

int main() {
  Cricketer c1("Sachin", 10000, 44.5);
  // Cricketer c2("Dravid", 12000, 50.0);
  Cricketer *c2 =
      new Cricketer("Dravid", 12000,
                    50.0); // the above line can be written in this way as well

  /*
    NOTE: Now we'll always try to use the pointer object instead of the normal
    object because:
    1. It is more efficient and faster than the normal object
    2. It is very useful in many cases.
    3. It is pass by reference, so we can change the value of the object
    4. It can do everything that a normal object can do
  */

  // for c1 it is normally done using the dot operator
  cout << c1.name << endl;

  // how to access the values of c2
  cout << c2->name << endl;

  // this is static memory allocation
  int a = 10;
  cout << a << "\n";
  int *p = &a;
  cout << *p << "\n";

  // ---------- dynamic memory allocation -------------
  // allocating memory in heap, dynamically at runtime
  int *p1 = new int(1234); // this will create a new variable in the heap memory
  cout << *p1 << "\n";
  /*
    created a int pointer variable p1, which doesn't have a name but it
    stores the address of the integer
    1. use new keyword to create a new variable in the heap memory
    2. assign the address of that variable to the pointer variable
    3. dereference the pointer variable to access the value of that variable
  */
  *p1 = 100;
  cout << *p1 << "\n";
  return 0;
}
