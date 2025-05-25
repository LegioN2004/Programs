#include <iostream>
using namespace std;
class Box {
private:
    double length;
    double breadth;
    double height;
public:
    Box(double l, double b, double h) {
        length =l;
        breadth =b;
        height =h;
    }
    friend double volume(Box);
};
double volume(Box b) {
    return b.length * b.breadth * b.height;
}
int main() 
{
    double l,b,h;
    cout<<"enter the dimensions of the box (length,breadth,height):";
    cin>>l>>b>>h;
    Box box(l,b,h);
    cout << "Volume of the box: " << volume(box) << endl;
    return 0;
}

