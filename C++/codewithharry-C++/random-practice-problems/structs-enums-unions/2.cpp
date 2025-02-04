#include <iostream>
#include <string>
using namespace std;

struct Student {
  string name;
  int rollNumber;
  int marks;
};

int main() {
  Student list[5] = {
      {"Gargi", 21, 500}, {"Milinda", 41, 750},         {"Milinda", 41, 430},
      {"uwuwu", 41, 420}, {"Gargiiiiiiiiiii", 41, 400},
  };

  for (int i = 0; i < (sizeof(list) / sizeof(list[0])); i++) {
    if (list[i].marks > list[i + 1].marks) {
      cout << list[i].name << " has the highest marks: " << list[i].marks
           << " having roll no " << list[i].rollNumber << endl;
    }
  }
  return 0;
}
