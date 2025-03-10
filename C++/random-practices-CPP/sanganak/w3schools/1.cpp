#include <iostream>

using namespace std;

class myClass {
 public:
  int myNum;
  string myString;
};

int main() {
  myClass myObj;

  int hello = myObj.myNum = 15;
  myObj.myString = "Some text";
  cout << "Hello World!" << endl << hello << endl;

  myClass myObj2;

  int hi = myObj2.myNum = 20;
  myObj2.myString = "helloe";
  cout << "hello" << endl << hi << endl << myObj2.myString;

  return 0;
}