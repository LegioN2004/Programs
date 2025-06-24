#include <iostream>
using namespace std;

class Student {
protected:
  string name, id;
  int age;

public:
  void studentDetails() {
    cout << "\nenter the name: ";
    cin >> name;
    cout << "\nenter the age: ";
    cin >> age;
    cout << "\nenter the id: ";
    cin >> id;
  }

  void studentInfo() {
    studentDetails();
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "ID: " << id << "\n";
  }
};

class Arts : public Student {
public:
  void allDetails() {
    studentInfo();
    cout << "\nArts subjects\n";
  }
};

class Medical : public Student {
public:
  void allDetails() {
    studentInfo();
    cout << "\nMedical subjects\n";
  }
};

class Engineering : public Student {
public:
  void allDetails() {
    studentInfo();
    cout << "\nEngineering subjects\n";
  }
};

class Mechanical : public Engineering {
public:
  void showDetails() {
    allDetails();
    cout << "\nmecha bros\n";
  }
};

class Electrical : public Engineering {
public:
  void showDetails() {
    allDetails();
    cout << "\nElectrical bros\n";
  }
};

class Civil : public Engineering {
public:
  void showDetails() {
    allDetails();
    cout << "\nCivil bros\n";
  }
};

int main() {
  Student p;
  p.studentInfo();

  cout << "\n--------- Arts --------\n";
  Arts a;
  a.allDetails();

  cout << "\n--------- Medical --------\n";
  Medical m;
  m.allDetails();

  cout << "\n--------- Engineering --------\n";
  Engineering e;
  e.allDetails();

  cout << "\n--------- Mechanical --------\n";
  Mechanical mech;
  mech.showDetails();

  cout << "\n--------- Civil --------\n";
  Civil civ;
  civ.showDetails();

  cout << "\n--------- Electrical --------\n";
  Electrical elec;
  elec.showDetails();
  return 0;
}