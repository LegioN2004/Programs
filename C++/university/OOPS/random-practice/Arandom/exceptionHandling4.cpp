#include <iostream>
using namespace std;

int main() {

    // Code that might throw an exception
    try {
        int choice;
        cout << "Enter 1 for invalid argument, "
            << "2 for out of range: ";
        cin >> choice;

        if (choice == 1) {
            throw invalid_argument("Invalid argument");
        }
        else if (choice == 2) {
            throw out_of_range("Out of range");
        }
        else {
            throw "Unknown error";
        }

    }

    // executed when exception is of type invalid_argument
    catch (invalid_argument e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // executed when exception is of type out_of_range
    catch (out_of_range e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // executed when no matching catch is found
    catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
}