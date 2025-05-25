#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {1, 2, 3};

  try {
    // Accessing out of bound element
    v.at(10);
  } catch (out_of_range e) {
    cout << "Caught: " << e.what();
  }
  return 0;
}