#include <iostream>

class Number {
  int a;

public:
  Number() {
    // default value
    a = 0;
  }
  Number(int num) { a = num; }
  // copy constructor
  Number(Number &obj) { // it's own reference
    std::cout << "copy constructor called \n";
    a = obj.a;
  }

  void display() {
    std::cout << "The number for this object is " << a << std::endl;
  }
};

/* copy constructor is such a constructor which creates a copy of another object
 */

int main() {
  Number x, y, z(21), z2;
  x.display();
  y.display();
  z.display();

  // but using this with the constructor commented out also works and runs as it
  // is, just like the copy constructor. And it works with any x/y/z.
  Number z1(z); // copy constructor called gets printed since it is written as the output statement to run when the copy constructor will be called
  z1.display(); // z1 is the new object made, z1 ko jo value pass kiya gaya hai, so uss function ka a ka value is equal, to the value of the passed variable

  // z2 = z; // this shows error, and the copy constructor is not called

  Number z3 = z;
  z3.display(); // this works, and the copy constructor is called

  return 0;
}

/*
The copiler gives a default copy constructor to every class that is created. So
everytime we run it like the above, it first checks if there is an explicit copy
constructor there or not, if not then the compiler supplies it's own copy
constructor. Default copy constructor is called "shallow copy"

imp NOTE: When no copy constructor is found, compiler supplies its own copy
constructor

When a new object is created using the old object as the argument then a copy
constructor of that
*/