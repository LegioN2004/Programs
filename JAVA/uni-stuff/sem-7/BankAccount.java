public class BankAccount {
    String depositorName;
    long accountNumber;
    String accountType;
    double balance;

    void initialize(String name, long accNum, String type) {
        depositorName = name;
        accountNumber = accNum;
        accountType = type;
        balance = 0.0;
    }

    void initialize(String name, long accNum, String type, double initialBalance) {
        depositorName = name;
        accountNumber = accNum;
        accountType = type;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    void deposit(double amount, String chequeNumber) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount + " via cheque #" + chequeNumber);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Invalid withdrawal amount.");
        } else if (amount > balance) {
            System.out.println("Insufficient balance! Withdrawal failed.");
        } else {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        }
    }

    void display() {
        System.out.println("Depositor Name: " + depositorName);
        System.out.println("Balance: " + balance);
    }

    public static void main(String[] args) {
        BankAccount acc = new BankAccount();

        acc.initialize("Narendar Modi", 1234567890L, "Savings", 5000.0);

        acc.deposit(15000.0);

        acc.withdraw(2000.0);

        acc.withdraw(10000.0);

        acc.display();
    }
}
