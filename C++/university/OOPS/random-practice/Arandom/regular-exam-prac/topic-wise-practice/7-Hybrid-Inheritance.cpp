#include<iostream>
using namespace std;

class Student {
    protected:
        int rollno;
        public:
            void getNumber(int a) {
                rollno = a;
            }
            void showNo() {
                cout << "Roll: " << rollno << endl;
            }
};

class test: public student {
    protected:
        float part1, part2;
        public
};

int main(){

    return 0;
}