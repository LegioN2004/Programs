#include<iostream>
using namespace std;

class Animal {
    public:
        virtual void speak() {
            cout << "Animal speaks something";
        }
};

class Dog: public Animal {
    public:
      void speak(){
        cout << "Dog bhowk bhowk";
      }
};

int main(){
    Dog d;
    Animal * ptr = &d;
    ptr->speak();

    return 0;
}