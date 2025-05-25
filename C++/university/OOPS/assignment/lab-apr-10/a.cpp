#include<iostream>
using namespace std;

class Rectangle {
	float length, breadth;
	public: 
		Rectangle(float l, float b) {
		length = l;
		breadth = b;
}
float getArea() {
return length * breadth;
}
};


int main() {
float l, b;
cout << "enter the length and breadth of the reactangle";
cin >> l >> b;

Rectangle rect(l,b);
cout << "Area of the rectangle: "<< rect.getArea() << endl;
return 0;
}
