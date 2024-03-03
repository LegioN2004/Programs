#include<iostream>
#include<string>
// for not writing std:: everytime we use the cout cin and all
using namespace std;
    
int main(){
    int a = 0;
    char b = 'c';
    float floatNumber;
    string name;
    cin >> floatNumber;
    cout << floatNumber << endl;
    // for output you need to use the cout statement with the << angled brackets pointing to the left side
    cout << "this the second input" << endl;
    return 0;
}