#include<iostream>
using namespace std;

class DB;

class DM {
    int metres;
    float centimetres;
    public:
        DM(int m = 0, float cm = 0){
            metres = m;
            centimetres = cm;
        }

        void display() const {
            cout << metres << "m and " << centimetres << "cm" << endl;
        }

        friend DM add(const DM& dm, const DB& db);
};

class DB {
    int feet;
    float inches;
    public:
        DB(int ft = 0, float in = 0){
            feet = ft;
            inches = in;
        }

        void display() const {
            cout << feet << "ft and " << inches << "in" << endl;
        }

        friend DM add(const DM& dm, const DB& db);
};

DM add(const DM& dm, const DB& db){
    float totalMetres = dm.metres + dm.centimetres / 100;
    float totalFeet = db.feet * 0.3048 + db.inches * 0.0254;

    float total = totalMetres + totalFeet;
    int m = (int) total;
    float cm = (total - m) * 100;

    return DM(m, cm);
}

int main(){

    DB d1(1,2);
    DM d2(3,4);

    DM

    return 0;
}