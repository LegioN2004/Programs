#include <iostream>
using namespace std;

int main() {
  string type;
  float price;
  char rating;
  cout << "Enter the type of tea, price per kg and its rating you want(in a "
          "serial manner): ";
  cin >> type >> price >> rating;

  cout << "The type of tea is \"" << type << "\"\n" << endl;
  cout << "The price of tea per kg is " << price << "\n" << endl;
  cout << "The rating of tea per kg is " << rating << "\n" << endl;
  return 0;
}