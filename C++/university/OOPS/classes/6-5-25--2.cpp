// cout and cin remake using >> << overloaded
#include<iostream>
using namespace std;

class Student {
  private:
    string name;
    int age;
    public:
      friend istream& operator>>(istream& in, Student& s);
      friend ostream& operator<<(ostream& out, const Student& s);
};

istream& operator >>(istream& in, Student& s){
  cout << "\nEnter the name and age of the student: ";
  in >> s.name >> s.age;
  return in;
}

ostream& operator <<(ostream& out, const Student& s){
  out << "\nname of the student is: " << s.name;
  out << "\nage of the student is: " << s.age;
  return out;
}


int main(){
  Student s;
  cin >> s;
  cout << s ;
  return 0;
}