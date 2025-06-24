#include <iostream>
using namespace std;

// Recursive Fibonacci function
int fib(int n) {
  if (n == 0)
    return 0; // base case 1
  if (n == 1)
    return 1; // base case 2

  // Recursive case
  int result1 = fib(n - 1); // corresponds to first jal call
  int result2 = fib(n - 2); // corresponds to second jal call

  return result1 + result2; // add and return
}

int main() {
  int n;
  cout << "Enter n to find the nth Fibonacci number: ";
  cin >> n;

  int result = fib(n); // Call recursive function

  cout << "The Fibonacci number is: " << result << endl;

  return 0;
}
