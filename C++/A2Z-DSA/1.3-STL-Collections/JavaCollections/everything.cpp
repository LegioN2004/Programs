#include <iostream>
using namespace std;

void pairs(int a) {
  pair<int, int> p = {1, 2};
  cout << p.first << " " << p.second << endl;  // prints 1 2

  // multidimensional pairs
  pair<int, pair<int, int>> p2 = {1, {3, 4}};
  cout << p2.first << " " << p2.second.first << " " << p2.second.second
       << endl;  // prints 1 3 4

  // array of pairs
  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
  cout << arr[1].second;
}

int main() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a = 0;
    cin >> a;
    pairs(a);
  }
  return 0;
}