#include <iostream>
using namespace std;

class Animal {
  public:
    Animal() {
      cout << "Animal constructor called" << endl;
    }
    // Compile-time polymorphism: Function Overloading
    void sound(string type) {
      cout << "Animal type: " << type << endl;
    }

    void sound(int times) {
      cout << "Animal makes sound " << times << " times." << endl;
    }

    // Run-time polymorphism: Virtual Function
    virtual void speak() {
      cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
  public:
    // Overriding the virtual function
    Dog() {
      cout << "Dog constructor called" << endl;
    }
    void speak() override {
      cout << "Dog says: Bark!" << endl;
    }
};

int main() {
  Animal a;

  // Compile-time polymorphism: Which function is called is known at compile time
  a.sound("Dog");         // Output: Animal type: Dog
  a.sound(3);             // Output: Animal makes sound 3 times.

  // Run-time polymorphism: Function call resolved at runtime
  Animal* ptr = new Dog();
  ptr->speak();           // Output: Dog says: Bark!

  delete ptr;
  return 0;
}

