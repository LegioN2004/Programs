// Base Class
 class BankAccount2 {
    // Data members
    String depositorName;
    long accountNumber;
    String accountType;
    double balance;

    // 1. Assign initial values
    void initialize(String name, long accNum, String type, double bal) {
        depositorName = name;
        accountNumber = accNum;
        accountType = type;
        balance = bal;
    }

    // 2. Deposit an amount (Normal Cash Deposit)
    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
    }

    // METHOD OVERLOADING: Same method name 'deposit', different parameters (Cheque
    // Deposit)
    void deposit(double amount, String chequeNo) {
        balance += amount;
        System.out.println("Deposited: " + amount + " via cheque " + chequeNo);
    }

    // 3. Withdraw an amount after checking balance
    void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Insufficient balance!");
        } else {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        }
    }

    // 4. Display the name and balance
    void display() {
        System.out.println("Depositor Name: " + depositorName);
        System.out.println("Balance: " + balance);
    }

// Main class to run the program
    public static void main(String[] args) {
        // Create an object of the child class
        SavingsAccount acc = new SavingsAccount();

        // Assign initial values
        acc.initialize("Rahul Sharma", 123456789L, "Savings", 5000.0);

        // --- METHOD OVERLOADING DEMO ---
        acc.deposit(1000.0); // Calls deposit(double)
        acc.deposit(2000.0, "CHQ01"); // Calls deposit(double, String)

        // Withdraw
        acc.withdraw(1500.0);
        acc.withdraw(10000.0); // Fails (insufficient)

        // --- METHOD OVERRIDING DEMO ---
        acc.display(); // Calls SavingsAccount's overridden display()
    }
}

// Child Class to demonstrate Method Overriding
class SavingsAccount extends BankAccount2 {

    // METHOD OVERRIDING: Same method name and same parameters, redefined in
    // subclass
    @Override
    void display() {
        System.out.println("--- Account Details ---");
        System.out.println("Depositor Name: " + depositorName);
        System.out.println("Account Type: " + accountType);
        System.out.println("Balance: " + balance);
    }
}
