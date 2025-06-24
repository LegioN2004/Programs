#include <iostream>
using namespace std;

class item {
  int code;
  float price;

public:
  void getData(int code, float price) {
    this->code = code;
    this->price = price;
  }

  void show() {
    cout << "Code: " << code << endl;
    cout << "Price: " << price << endl;
  }
};

const int array_size = 2;

int main() {
  item *p = new item[array_size];
  item *d = p;
  int x;
  float y;

  for (int i = 0; i < array_size; i++) {
    cout << "Input code and price for the item" << i + 1;
    cin >> x >> y;
    p->getData(x, y);
    p++;
  }

  for (int i = 0; i < array_size; i++) {
    cout << "item: " << i + 1 << endl;
    d->show();
    d++;
  }

  return 0;
}