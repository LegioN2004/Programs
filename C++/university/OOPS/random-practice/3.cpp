#include <iostream>
using namespace std;

class Student {
private:
  string name;
  int rollNo;

public:
  void setDetails(string n, int r) { name = n, rollNo = r; }
  void display() { cout << "Name: " << name << "\n Roll: " << rollNo << endl; }
};

int main() {
  Student student[5];
  student[0].setDetails("guggi", 21);
  student[1].setDetails("gargi", 21);
  student[2].setDetails("guggu", 21);
  student[3].setDetails("milu", 41);
  student[4].setDetails("lobbsu", 2141);

  for (int i = 0; i < 5; i++) {
    student[i].display();
  }

  return 0;
}
