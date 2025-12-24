#include <cctype> // For toupper
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string input = "Reehan";

  // 5 rows of ASCII art
  for (int row = 0; row < 5; row++) {
    string line = "";
    for (char ch : input) {
      char c = toupper(ch);
      if (c == 'A') {
        if (row == 0)
          line += "  /\\  ";
        else if (row == 1)
          line += " /  \\ ";
        else if (row == 2)
          line += "/____\\";
        else if (row == 3)
          line += "|    |";
        else
          line += "|    |";
      } else if (c == 'B') {
        if (row == 0 || row == 2 || row == 4)
          line += "|____|";
        else
          line += "|    |";
      } else if (c == 'C') {
        if (row == 0)
          line += " _____ ";
        else if (row == 1)
          line += "/     \\";
        else if (row == 2)
          line += "|      ";
        else if (row == 3)
          line += "|     /";
        else
          line += " \\____/";
      } else if (c == 'D') {
        if (row == 0 || row == 4)
          line += "|____|";
        else
          line += "|    |";
      } else if (c == 'E') {
        if (row == 0 || row == 2 || row == 4)
          line += "|______";
        else
          line += "|      ";
      } else {
        line += "     "; // Space or unknown
      }
    }
    cout << line << endl;
  }
  return 0;
}
