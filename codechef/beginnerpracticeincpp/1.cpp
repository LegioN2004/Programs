#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (x < 80) {
      cout << "No" << endl;
    } else
      cout << "Yes" << endl;
  }
  return 0;
}
