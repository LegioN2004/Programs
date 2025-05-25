#include <iostream>
using namespace std;

class Book {
    private:
        string title, author;
        int price;
    public:
        void setAttributes(string title, string author, int price){
            this -> title = title;
            this -> author = author;
            this -> price = price;
        }
        void getAttributes(string title, string author, int price){
            setAttributes(title, author, price);
        }

        void displayDetails() {
            cout << "Author: " << author << " Title: " << title << " Price: " << price << "\n";
        }
};

int main(){
    Book b1;
    b1.getAttributes("title1", "author1", 1000);
    b1.displayDetails();
    
    return 0;
}
