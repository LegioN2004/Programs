#include <iostream>
using namespace std;

class employee {
  char name[30];
  int age;

public:
  void getData(void);
  void showData(void);
};

void employee ::getData() {
  cout << "Enter name: ";
  cin >> name;
  cout << "Enter age: ";
  cin >> age;
}

void employee ::showData() {
  cout << "name: " << name << endl;
  cout << "age: " << age << endl;
}

const int num_employees = 3;

int main() {

  employee manager[num_employees];

  for (int i = 0; i < num_employees; i++) {
    cout << "details of the manager" << i + 1 << endl;
    manager[i].getData();
  }
  cout << "\n\n\n";
  for (int i = 0; i < num_employees; i++) {
    cout << "details of the manager" << i + 1 << endl;
    manager[i].showData();
  }
  return 0;
}