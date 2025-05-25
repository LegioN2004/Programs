#include<iostream>
using namespace std;

class Number {
	int value;
	public: 
		Number(int v) {
		value = v;
}
float getValue() {
return value;
}
};


int main() {
int a, b, c;
cout << "enter three numbers";
cin >> a >> b >> c;

Number n1(a), n2(b), n3(c);
int sum = n1.getValue() + n2.getValue() + n3.getValue();
cout << "Sum of three numbers: " << sum << endl;

return 0;
}
