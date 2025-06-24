#include<iostream>
using namespace std;

// class Exchange1 {}; // empty declaration, so error of inaccessible since it shows that the thing has not been made i.e undefined
class Exchange1; // this is correct, forward declaration. Necessary when we have classes that refer to each other. It is somewhere but will be defined later

class Exchange2 {
    int a;
    public:
        Exchange2(int a = 0) {
            this -> a = a;
        }

        friend void exFunction(Exchange2&, Exchange1&);
};

class Exchange1 {
    int b;
    public:
        Exchange1(int a = 0) {
            this -> b = a;
        }

        friend void exFunction(Exchange2&, Exchange1& );
};

void exFunction(Exchange2& e2, Exchange1& e1){
    cout << "Before a: " << e2.a << " b: " << e1.b;
    int temp;
    temp = e2.a;
    e2.a = e1.b;
    e1.b = temp;
    cout << "\nAfter a: " << e2.a << " b: " << e1.b;
}

int main(){
    Exchange2 e2(2);
    Exchange1 e1(3);
    exFunction(e2, e1);

    return 0;
}