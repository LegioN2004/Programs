
#include<iostream>
using namespace std;

class BankAccount {
    public:
        int amount, acno;
        BankAccount() {
          amount = 0;
          acno = 0;
        }

        BankAccount(int a, int ac){
            amount = a;
            acno = ac;
        }

        BankAccount(const BankAccount &b){
            cout << "Copy constructor called";
        }

        void displayDetails() {
            cout << "Amount: " << amount << ", AC no: " << acno << endl;
        }
};

int main(){

    BankAccount b(10000, 1234);
    b.displayDetails();
    BankAccount c = b;
    // BankAccount c, b(c);

    return 0;
}