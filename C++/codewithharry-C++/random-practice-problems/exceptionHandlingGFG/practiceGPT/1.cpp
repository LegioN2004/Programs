// multiple catch blocks
#include <iostream>
using namespace std;

int main() {
  char a = ' ';

  try {
    throw a;
  } catch (float b) {
    cout << "Caught float exception: " << b << endl;
  } catch (int b) {
    cout << "Caught int exception: " << b << endl;
  } catch (char b) {
    cout << "Caught char exception: " << b << endl;
  } catch (...) {
    cout << "Caught unknown exception" << endl;
  }

  return 0;
}