#include <iostream>

int count = 0;

class Num {
public:
  Num() {
    count++;
    std::printf("\ndefault constructor called for object no: %d\n", count);
  }
  ~Num() {
    std::printf("\ndestructor called for object no: %d\n", count);
    count--;
  }
  // void display() {
  //   std::cout << "The number for this object is " << a << std::endl;
  // }
};

// destructor doesn't take any arguments and doesn't return anything, so no need
// to write it like the constructor with the parameters
int main() {
  std::cout << "inside main function \n";
  std::cout << "Creating first object \n";

  Num n1;
  // creating a block here, so everything that will be created inside this block
  // will be destroyed when the block scope ends
  {
    std::cout << "\nEntering the inner block \n";
    std::cout << "Creating two more objects \n";
    Num n2, n3;
    std::cout << "Exiting the inner block \n";
  }

  std::cout << "Back to the main \n";


  // When objects is created, constructor is called, and when the compiler knows that there is no need of an object, it calls the destructor.

  return 0;
}