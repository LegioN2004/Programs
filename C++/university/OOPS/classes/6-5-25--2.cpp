#include<iostream>
using namespace std;

class Student {
  private:
    string name;
    int age;
    public:
      friend istream& operator>>(istream& in, Student s);
      friend ostream& operator<<(ostream& in, const Student s);
};

int main(){

  return 0;
}