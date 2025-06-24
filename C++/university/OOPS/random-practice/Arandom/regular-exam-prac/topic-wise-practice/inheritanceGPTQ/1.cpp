/*

1. Employee Management System (Hierarchical + Virtual Functions)

Create a base class Employee with fields like name, id, basic_salary.
Derive the following classes:

    Manager → adds department and bonus

    Engineer → adds specialization and project_count

    HR → adds region and recruitment_target

All derived classes must override a virtual function calculate_salary() that
returns salary with different rules.

Requirements:

    Use pointers to base class to handle objects polymorphically.

    Implement a menu-driven program to create and manage multiple employee
types.

*/

#include <iostream>
using namespace std;

class Employee {
protected:
  string name, id;
  int basic_salary;

public:
  Employee() {}
  Employee(string name, string id, int basic_salary)
      : name(name), id(id), basic_salary(basic_salary) {}

  virtual double calculate_salary() = 0;

  virtual void details() {
    cout << "ID: " << id << ", Name: " << name << ", Salary: " << basic_salary
         << endl;
  }

  virtual ~Employee() {}
};

class Manager : public Employee {
  string department;
  int bonus;

public:
  Manager(string name, string id, string dept, int basic_salary, int bonus)
      : Employee(name, id, basic_salary) {
    department = dept;
    this->bonus = bonus;
  }

  double calculate_salary() override { return basic_salary + bonus; }
  void details() override {
    Employee::details();
    cout << "Department: " << department << ", Bonus: " << bonus
         << ", Total salary: " << calculate_salary() << endl;
  }
};

class Engineer : public Employee {
  string specialization;
  int project_count;

public:
  Engineer(string name, string id, string dept, int basic_salary, string spec,
           int proj)
      : Employee(name, id, basic_salary) {
    this->specialization = spec;
    this->project_count = proj;
  }

  double calculate_salary() override {
    return basic_salary + (project_count * 1000.00);
  }
  void details() override {
    Employee::details();
    cout << "Specialization: " << specialization
         << ", Project Count: " << project_count
         << "Salary: " << calculate_salary() << endl;
  }
};

class HR : public Employee {
  string region;
  int recruitment_target;

public:
  HR(string name, string id, string dept, int basic_salary, string reg, int rec)
      : Employee(name, id, basic_salary) {
    this->region = reg;
    this->recruitment_target = rec;
  }

  double calculate_salary() override {
    return basic_salary + (recruitment_target * 500.00);
  }
  void details() override {
    Employee::details();
    cout << "Region: " << region
         << ", Recruitment Target: " << recruitment_target
         << "Salary: " << calculate_salary() << endl;
  }
};

int main() {
  Employee *employees[100];
  int count = 0;
  int choice;

  do {
    cout << "\n--- Employee Management System ---\n";
    cout << "1. Add Manager\n";
    cout << "2. Add Engineer\n";
    cout << "3. Add HR\n";
    cout << "4. Display All Employees\n";
    cout << "5. Calculate Total Salary of All Employees\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
      string name, department;
      int id;
      double basic_salary, bonus;
      cout << "Enter Manager Name: ";
      getline(cin, name);
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter Basic Salary: ";
      cin >> basic_salary;
      cout << "Enter Department: ";
      cin.ignore();
      getline(cin, department);
      cout << "Enter Bonus: ";
      cin >> bonus;
      employees[count++] =
          new Manager(name, to_string(id), department, basic_salary, bonus);
      cout << "Manager added successfully.\n";
    } else if (choice == 2) {
      string name, specialization;
      int id, project_count;
      double basic_salary;
      cout << "Enter Engineer Name: ";
      getline(cin, name);
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter Basic Salary: ";
      cin >> basic_salary;
      cout << "Enter Specialization: ";
      cin.ignore();
      getline(cin, specialization);
      cout << "Enter Project Count: ";
      cin >> project_count;
      employees[count++] = new Engineer(name, to_string(id), "", basic_salary,
                                        specialization, project_count);
      cout << "Engineer added successfully.\n";
    } else if (choice == 3) {
      string name, region;
      int id, recruitment_target;
      double basic_salary;
      cout << "Enter HR Name: ";
      getline(cin, name);
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter Basic Salary: ";
      cin >> basic_salary;
      cout << "Enter Region: ";
      cin.ignore();
      getline(cin, region);
      cout << "Enter Recruitment Target: ";
      cin >> recruitment_target;
      employees[count++] = new HR(name, to_string(id), "", basic_salary, region,
                                  recruitment_target);
      cout << "HR added successfully.\n";
    } else if (choice == 4) {
      cout << "\n--- Employee List ---\n";
      for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        employees[i]->details();
      }
    } else if (choice == 5) {
      double total = 0;
      for (int i = 0; i < count; i++) {
        total += employees[i]->calculate_salary();
      }
      cout << "Total Salary of All Employees: " << total << endl;
    } else if (choice == 6) {
      cout << "Exiting...\n";
    } else {
      cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 6);
cout << "Manager added successfully.\n";

  return 0;
}
