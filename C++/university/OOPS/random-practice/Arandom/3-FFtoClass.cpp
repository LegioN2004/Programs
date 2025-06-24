// friend functions that are friendly with classes
#include<iostream>
using namespace std;

class ABC;

class XYZ{
    int x;
    public:
        void setValue(int i) { x = i;}
        friend void max(XYZ, ABC);
};

class ABC {
    int a;
    public:
        void setValue(int i) { a = i;}
        friend void max(XYZ, ABC);
};

void max(XYZ m, ABC n) {
    if(m.x >= n.a) {
        cout << m.x;
    }else {
        cout << n.a;
    }
}

int main(){
    ABC a;
    a.setValue(10);
    XYZ x;
    x.setValue(20);
    max(x, a);

    return 0;
}


