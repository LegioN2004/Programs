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

// ------------- pass by reference -----------------

// void change(Cricketer &c){
//   c.name = "Tatti IPL"; // this will change the value of c1 class
// }

void change(Cricketer *c) {
  //  (*c).name = "Tatti IPL";
  c->name =
      "Tatti IPL"; // this will change the value of c1 class, same as above line
}

// ------------ pass by value ------------------
// void change(Cricketer c) { c.name = "Tatti IPL"; } // this will not change
// the original value of c1 class

int main() {
  Cricketer c1("Sachin", 10000, 44.5);
  Cricketer c2("Dravid", 12000, 50.0);

  Cricketer *p1 = &c1; // taking pointer object to address of object c1

  // p1 is a pointer variable so it'll need the following syntax to access
  cout << (*p1).name << endl;
  /*
    accessing the name of c1 using dot operator same as our normal pointer
    variable but it'll need the parentheses to dereference the pointer variable
    so (*p1) does is go to the address of c1 and then access the values using
    `.`
  */

  // (*p1).name = "gargu"; // globally changes the value of c1 class using
  // reference

  p1->name = "gargu"; // means same as above line but using arrow operator

  cout << (*p1).name << endl; // accessing the name of c1 using pointer

  // change(c1); // when using the & object as the input argument

  change(&c1); // or we can do this and pass the reference as parameter and take the argument as pointer

  // in all of the object pointers, the left p1 should alwyas be the pointer variable
  cout << c1.name;
  return 0;
}