#include <iostream>
using namespace std;

int main() {
    int a, b;
    int *ptrA, *ptrB;

    cout << "Enter value of a: ";
    cin >> a;

    cout << "Enter value of b: ";
    cin >> b;

    ptrA = &a;
    ptrB = &b;

    cout << "Value of a using pointer: " << *ptrA << endl;
    cout << "Value of b using pointer: " << *ptrB << endl;

    return 0;
}