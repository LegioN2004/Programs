#include <iostream>
#include <vector>

class Chai {
public:
  // std::string teaName; // taking pointer in the next
  std::string *teaName; // so this allocates memory dynamically, and so it is
                        // supposed to freed using destructor as well
  int servings;
  std::vector<std::string> ingredients;

  // whenever an object of this class is created, a constructor will be called
  // automatically and if there is none written by us to change the defaults,
  // then compiler does it for us bts but we'll not know that. But to modify
  // stuff, we need to write our own constructor.

  // constructor(default)
  // Chai() {
  //   teaName = "Unknown";
  //   servings = 0;
  //   ingredients = {"Water", "milk", "tea leaves", "sugar"};
  //   std::cout << "Default constructor called\n";
  // }

  // parameterized constructor, when we want to send some details directly
  // whenever creating an object for the constructor call, also it'll expect
  // something so create some arguments for the parameters;
  Chai(std::string name, int serv, std::vector<std::string> ing) {
    teaName = new std::string(name);
    servings = serv;
    ingredients = ing;
    std::cout << "parameterized constructor called\n";
  }

  // copy constructor, when we want to create a new object from an existing one
  // i.e a copy of the existing one
  Chai(const Chai &copyConst) { // copyConst has the reference of the whole Class Chai
    teaName = new std::string(*copyConst.teaName); // deep copy, so we need to
                                                  // allocate memory for the
                                                  // new object as well

    servings = copyConst.servings;
    ingredients = copyConst.ingredients; // copying the values of the
                                            // existing object to the new one
    std::cout << "copy constructor called\n";
  }


  // destructor, same as constructor but with a ~ before the class name, and it
  // the constructors get cleared from the memory when the object goes out of scope
  // and the destructor is called automatically. It is used to free up the memory is being taken but sometimes it might try to to free up memory that is already freed up
  ~Chai() {
    delete teaName; // free the memory allocated for the teaName pointer
    std::cout << "Destructor called\n";
  }

  // display function to show the details of the tea
  void displayDetails() {
    std::cout << "Tea Name: " << *teaName << std::endl;
    std::cout << "Servings: " << servings << std::endl;
    std::cout << "Ingredients: ";
    for (std::string ingredient : ingredients) {
      std::cout << ingredient << " ";
    }
    std::cout << "\n";
  }
};

int main() {
  // Chai chai1;

  Chai lemonTea("lemon tea", 2,
                {"water", "lemon",
                 "honey"}); // parameterized constructor, when we want to send
                            // some details directly whenever creating an object
                            // for the constructor call
  lemonTea.displayDetails();

  // copies the above object to a new one, but this is not a copy constructor,
  // this is just a normal assignment operator. It is valid but not the same as
  // a copy constructor. This is called shallow copy.
  Chai copiedChai =
      lemonTea; // copy constructor called, copiedChai is a new object created
                // and takes the values of the existing one
  copiedChai.displayDetails(); // chai2 is the new object made

  // changing the values
  // lemonTea.teaName = "modified green tea";
  // std::cout << "\nlemon tea\n";
  // lemonTea.displayDetails();

  // std::cout << "\ncopied tea\n";
  // copiedChai.displayDetails();

  return 0;
}