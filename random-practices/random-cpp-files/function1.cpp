#include <iostream>
using namespace std;

int Multiply(int c, int d) { return c * d; }

void MultiplyAndChange(int a, int b)
{
  int multiply = Multiply(a, b);
  cout << multiply << endl;
}

int main()
{
  MultiplyAndChange(10, 10);
  MultiplyAndChange(0, 0);
  MultiplyAndChange(1, 2);
  int c, d;
  int multiply = Multiply(9, 8);
  int multiply1 = Multiply(8, 8);
  int multiply2 = Multiply(7, 8);
  cout << multiply << "\n"
       << multiply1 << "\n"
       << multiply2;
  return 0;
}
