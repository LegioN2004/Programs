#include <iostream>
using namespace std;

class BankAccount {
private:
  double balance; // Private data member - hidden from outside

public:
  // Constructor to initialize balance
  BankAccount(double initialBalance) {
    if (initialBalance < 0)
      balance = 0;
    else
      balance = initialBalance;
  }

  // Public method to deposit money
  void deposit(double amount) {
    if (amount > 0)
      balance += amount;
    else
      cout << "Invalid deposit amount\n";
  }

  // Public method to withdraw money
  void withdraw(double amount) {
    if (amount > 0 && amount <= balance)
      balance -= amount;
    else
      cout << "Invalid or insufficient funds\n";
  }

  // Public method to get balance
  double getBalance() { return balance; }
};

int main() {
  BankAccount account(1000);

  account.deposit(500);  // Adds 500 to balance
  account.withdraw(200); // Subtracts 200 from balance
  cout << "Balance: " << account.getBalance() << endl; // Output: Balance: 1300

  // Direct access to balance not allowed:
  // account.balance = 5000;   // Error! balance is private

  return 0;
}
