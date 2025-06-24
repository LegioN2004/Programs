#include <iostream>
using namespace std;

class Engineer {
  string name = "engg";

public:
  void showName() { cout << "\nName: " << name; }
};

class Artist {
  string name = "art";

public:
  void showName() { cout << "\nName: " << name; }
};

class MultiTalentedPerson : public Engineer, public Artist {
  string name = "goru";

public:
  void showName() { cout << "\nName: " << name; }
};

int main() {

  MultiTalentedPerson m1;
  m1.showName();
  m1.Engineer::showName();
  m1.Artist::showName();
  m1.showName();

  return 0;
}