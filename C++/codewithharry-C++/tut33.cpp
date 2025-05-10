#include <iostream>
using namespace std;
// calculating the interest using class and object

class bankDeposit {
private:
  int prin, yrs;
  float interest, returnValue;

public:
  // default contstructor is necessary because without it the compiler will not know which is the constructor here and what to call and so it'll get confused and throw errors
  bankDeposit() {}                    // default constructor
  bankDeposit(int p, int y, float r); // for fractional values of percent
  bankDeposit(int p, int y, int r);   // for direct percentage values

  void show();
};

bankDeposit ::bankDeposit(int p, int y, float r) {
  prin = p, yrs = y, interest = r, returnValue = prin;

  for (int i = 0; i < yrs;
       i++) { // for all the years it'll run for that many times
    returnValue *= (1 + interest);
  }
  /*
    let's say we have RS100 i.e it's return value and for 1 yr it'll run the
    loop 1 times for the interest rate 0.4. So the value will be 104 for the
    first year. For the 2nd yr it'll be 104 * 1+r and so on.
   */
}

// for cases when the percentage will be in whole numbers
bankDeposit ::bankDeposit(int p, int y, int r) {
  prin = p, yrs = y, interest = float(r) / 100, returnValue = prin;

  for (int i = 0; i < yrs; i++) {
    returnValue *= (1 + interest);
  }
}

void bankDeposit ::show() {
  cout << endl
       << "principal amount is " << prin << " the return value after " << yrs
       << " yrs is " << returnValue << "\n";
}

int main() {
  bankDeposit bd1, bd2, bd3;
  int p, y, R;
  float r;

  // bd3.show();

  cout << "Enter the value of the p, y, r " << endl;
  cin >> p >> y >> r;
  bd1 = bankDeposit(p, y, r);
  bd1.show();

  cout << "Enter the value of the p, y, r " << endl;
  cin >> p >> y >> R;
  bd2 = bankDeposit(p, y, R);
  bd2.show();

  return 0;
}