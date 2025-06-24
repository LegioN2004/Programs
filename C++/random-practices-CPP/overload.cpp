// #include <iostream>
// using namespace std;

// class Student {
//   string name;
//   int marks;

// public:
//   friend istream &operator>>(istream &in, Student &s);
//   friend ostream &operator<<(ostream &out, Student s);
// };

// istream &operator>>(istream &in, Student &s) {
//   cout << "Enter name: ";
//   in >> s.name;
//   cout << "Enter marks: ";
//   in >> s.marks;
//   return in;
// }

// ostream &operator<<(ostream &out, Student s) {
//   out << "Name: " << s.name << ", Marks: " << s.marks << endl;
//   return out;
// }

// int main() {
//   Student s;
//   cin >> s;
//   cout << s;
// }

#include <iostream>
using namespace std;

class operatorOverloading {
  int a, b;

public:
  operatorOverloading() : a(0), b(0) {}
  friend istream &operator>>(istream &in, operatorOverloading &s) {
    cout << "enter the numbers: ";
    in >> s.a;
    in >> s.b;
    return in;
  }

  friend ostream &operator<<(ostream &out, const operatorOverloading &s) {
    out << "\na is: " << s.a << endl;
    out << "b is: " << s.b << endl;
    return out;
  }
};
int main() {
  operatorOverloading o1;
  cin >> o1;
  cout << o1;
  return 0;
}
