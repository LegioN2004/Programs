#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
  string name;
  int id;
  int age;

public:
  void getBasicInfo() {
    cout << "\nEnter Name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Age: ";
    cin >> age;
  }

  void displayBasicInfo() {
    cout << "Name: " << name << ", ID: " << id << ", Age: " << age << endl;
  }
};

class Arts : public Student {
public:
  void showDetails() {
    displayBasicInfo();
    cout << "Stream: Arts" << endl;
    cout << " Subjects: History, Literature, Political Science" << endl;
    cout << "Lab Hours: None" << endl;
  }
};

class Medical : public Student {
public:
  void showDetails() {
    displayBasicInfo();
    cout << "Stream: Medical" << endl;
    cout << " Subjects: Biology, Chemistry, Anatomy" << endl;
    cout << "Lab Hours: 8 hours/week" << endl;
  }
};

class Engineering : public Student {
public:
  void showBase() {
    displayBasicInfo();
    cout << "Stream: Engineering" << endl;
  }
};

class Mechanical : public Engineering {
public:
  void showDetails() {
    showBase();
    cout << "Mechanical Engineering" << endl;
    cout << "Subjects: Thermodynamics, Fluid Mechanics, Design" << endl;
    cout << "Lab Hours: 10 hours/week" << endl;
  }
};

class Electrical : public Engineering {
public:
  void showDetails() {
    showBase();
    cout << "Electrical Engineering" << endl;
    cout << "Subjects: Circuits, Electromagnetics, Control Systems" << endl;
    cout << "Lab Hours: 9 hours/week" << endl;
  }
};

class Civil : public Engineering {
public:
  void showDetails() {
    showBase();
    cout << "Civil Engineering" << endl;
    cout << "Subjects: Structural Analysis, Surveying, Construction" << endl;
    cout << "Lab Hours: 8 hours/week" << endl;
  }
};

int main() {
  cout << "Academic Classification System\n";

  Arts a;
  cout << "\n--- Enter details for Arts student ---\n";
  a.getBasicInfo();
  a.showDetails();

  Medical m;
  cout << "\n--- Enter details for Medical student ---\n";
  m.getBasicInfo();
  m.showDetails();

  Mechanical mech;
  cout << "\n--- Enter details for Mechanical student ---\n";
  mech.getBasicInfo();
  mech.showDetails();

  Electrical elec;
  cout << "\n--- Enter details for Electrical student ---\n";
  elec.getBasicInfo();
  elec.showDetails();

  Civil civ;
  cout << "\n--- Enter details for Civil student ---\n";
  civ.getBasicInfo();
  civ.showDetails();

  return 0;
}
