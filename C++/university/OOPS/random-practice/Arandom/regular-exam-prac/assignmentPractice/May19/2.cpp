#include<iostream>
using namespace std;

int main(){

  int a = 0, b = 0;
  cin >> a >> b;

  int *ptrA = &a, *ptrB = &b;

  cout << *ptrA << "\n";
  cout << *ptrB;

  return 0;
}