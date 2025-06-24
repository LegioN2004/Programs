#include<iostream>
using namespace std;

class BookList{
    string title, author;

    public:
    BookList() {}
        void displayDetails(string t, string a){
            title = t; author = a;
            cout << "Title: " << title << " | Author: " << author << endl;
        }
};


int main(){
    BookList *ptr = new BookList[3];

    for (int i = 0; i < 3; i++)
    {
        string s, a;
        cout << "Give author and title one by one: ";
        cin >> s >> a;
        cout << endl;
        ptr[i].displayDetails(s, a);
    }
    delete[] ptr;

    return 0;
}