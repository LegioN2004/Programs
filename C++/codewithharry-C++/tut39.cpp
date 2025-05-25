#include <iostream>
using namespace std;

class Base {
	// protected members are kinda private members but are can be inherited
protected:
	int a;

private:
	int b;
};

/*
 for protected members
*/
class Derived : Base {

};

int main() {
	Derived d1;
	return 0;
}
