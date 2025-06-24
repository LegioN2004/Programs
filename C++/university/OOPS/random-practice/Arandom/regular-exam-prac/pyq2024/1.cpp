#include <iostream>
using namespace std;

class Book {
private:
  string title, author;
  int price;

public:
  void getDetails() {
    cout << "\nenter the title: ";
    cin >> title;
    cout << "\nenter the author: ";
    cin >> author;
    cout << "\nenter the price: ";
    cin >> price;
  }

  void showDetails() {
    cout << "\nThe title of the book is: " << title;
    cout << "\nThe author is: " << author;
    cout << "\nand the price is: " << price;
  }
};

int main() {
  Book b;
  b.getDetails();
  b.showDetails();
  return 0;
}