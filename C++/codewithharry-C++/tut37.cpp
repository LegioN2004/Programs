#include <iostream>

class employee {
private:
  // int id;

public:
  int id;
  float salary;
  employee() {}
  employee(int id) {
    this->id = id;
    salary = 34.0;
  }
};

/*
class derived_class : visibility_mode base_class {
.............
.............
.............
statements
};

check the readme for more.
*/

// class programmer : employee {
class programmer : public employee {
public:
  programmer(int id) { this->id = id; }
  int languageCode = 9;

  void getData() { std::cout << "The id is " << id << std::endl; }
};

int main() {
  employee harry(101), rohan(102);
  std::cout << harry.salary << std::endl;
  std::cout << rohan.salary << std::endl;

  programmer skillf(12);
  // std::cout << skillf.salary << std::endl; // can't be access because it is
  // public in the base class and so private in the derived class and can't be
  // accessed outside the class
  std::cout << skillf.languageCode << std::endl;
  std::cout << skillf.salary << std::endl;
  skillf.getData();
  return 0;
}