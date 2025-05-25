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
  void print(int runs) {
    cout << "\n";
    cout << "Name: " << this->name << endl;
    cout << "Runs: " << this->runs << endl;
    cout << "Average: " << this->avg << endl;
    // cout << "Random runs: " << runs << endl;
  }

  int matches() { return runs / avg; }
};

// void print(Cricketer c) {
//   cout << "Name: " << c.name << endl;
//   cout << "Runs: " << c.runs << endl;
//   cout << "Average: " << c.avg << endl;
//   cout << "\n";
// }

int main() {
  Cricketer c1("Sachin", 10000, 44.5);
  Cricketer c2("Dravid", 12000, 50.0);

  // print(c1);
  // print(c2);

  c1.name = "Sachin Tendulkar"; // to change the name of c1 after class object
                                // creation

  // c1.print();
  // c2.print();

  c1.print(1);
  cout << c1.matches();
  c2.print(2);
  cout << c2.matches();
  // when a value is passed to the member function of the class having an
  // argument with the same name then the argument takes the precedence over the
  // class member. So this->name is used to access the class member variable.

  return 0;
}