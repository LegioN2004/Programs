#include<iostream>
using namespace std;

class Distance {
	float feet;
	public: 
		Distance(float f) {
		feet = f;
}
void show() {
cout << "Distance: " << feet << " feet" << endl;
}
};


int main() {
float d;
cout << "enter the length and breadth of the reactangle";
cin >> d;

Distance dist(d);
dist.show();
return 0;
}
