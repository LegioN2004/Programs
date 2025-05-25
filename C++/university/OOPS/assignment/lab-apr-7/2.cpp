#include <iostream>
using namespace std;
class Circle {
private:
    double radius; 
public:
    Circle(double r) : radius(r) {}
    double area(){
        return 3.14 * radius * radius; 
    }
    void displayRadius() {
        cout << "Radius: " << radius <<endl;
    }
};

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    Circle circle(r);
    circle.displayRadius();
    cout << "Area of the circle: " << circle.area() << endl;
    return 0;
}

