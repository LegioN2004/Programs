#include <iostream>
using namespace std;

class Bank {
private:
  string name, acNo, typeAc;
  int balance;

public:
  void setValues(string n, string ac, string type, int bal) {
    name = n;
    acNo = ac;
    typeAc = type;
    balance = bal;
  }

  void DepositBal(int bal) {
    if (bal > 0) {
      balance += bal;
      cout << "Deposit successfull, current Balance: " << balance << endl;
    } else {
      cout << "Invalid amount" << endl;
    }
  }

  void withdrawAmt(int bal) {
    if (bal <= 0) {
      cout << "invalid withdrawal amount, try again!! " << endl;
    } else if (bal > balance) {
      cout << "Amount unavailable, try again later!! " << endl;
    } else {
      balance -= bal;
      cout << bal << " amount withdrawn. current Balance: " << balance << endl;
    }
  }

  void displayDetails() {
    cout << "Account details \n";
    cout << "Account holder name: " << name << endl;
    cout << "Balance: " << balance << endl;
  }
};

int main() {
  Bank b;
  b.setValues("name1", "1234abcd", "Savings", 1000);
  b.displayDetails();
  b.withdrawAmt(1000);
  b.displayDetails();
  b.DepositBal(1000);
  return 0;
}