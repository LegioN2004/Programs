#include <iostream>
using namespace std;

class Book {
  string title;
  int pages;

public:
  // Constructor
  Book(string t, int p) : title(t), pages(p) {}

  // Copy Constructor
  Book(const Book &b) {
    title = b.title;
    pages = b.pages;
    cout << "Copy constructor called!\n";
  }

  void display() const {
    cout << "Title: " << title << ", Pages: " << pages << endl;
  }
};

int main() {
  Book b1("C++ Basics", 300); // normal constructor
  Book b2 = b1;               // copy constructor is called here

  b1.display();
  b2.display();

  return 0;
}
