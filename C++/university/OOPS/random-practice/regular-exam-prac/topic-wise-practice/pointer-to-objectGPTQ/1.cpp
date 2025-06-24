// Create a class Book with title and price. Create an array of 3 Book objects using a pointer and input/display their values using the pointer.

#include<iostream>
using namespace std;

const int array_size = 3;

class Book {
    public:
        string title;
        int price;

        void getDetails(string t = "book", int p = 1000) {
            this -> title = t;
            this -> price = p;
        }

        void showDetails() {
            cout << "Title: " << title << ", price: " << price << endl;
        }
};


int main(){

    Book b[array_size];
    for (int i = 0; i < array_size; i++)
    {
        string title; int price;
            cout << "enter the title: ";
            cin >> title;
            cout << "\nenter the price";
            cin >> price;
            cout << endl;
        b[i].getDetails(title, price);
    }

    for (int i = 0; i < array_size; i++)
    {
        b[i].showDetails();
    }


    return 0;
}