#include <iostream>
using namespace std;

class Widget {
  static int count;

public:
  Widget() { count++; }

  static void getCount() {
    cout << "no of widegt objects created: " << count << endl;
  }
};
int Widget ::count = 0;

class Logger {
  static int LogLevel;

public:
  static void setLogLevel(int level) { LogLevel = level; }

  static int getLogLevel(int) { return LogLevel; }

  void log(string message, int level) {
    if (level >= LogLevel) {
      cout << message << endl;
    }
  }
};
int Logger::LogLevel = 0;

class test {
  int code;
  static int count;

public:
  void setCode() { code = ++count; }
  void showCode() { cout << "Object number: " << code << endl; }
  static void showCount() { cout << "count is: " << count << endl; }
};

void testFunctionBook() {
  test t1, t2;
  t1.setCode();
  t2.setCode();

  test::showCount();

  test t3;
  t3.setCode();

  t1.showCode();
  t2.showCode();
  t3.showCode();

}

int main() {

  Widget w1, w2, w3;
  Widget::getCount();

  Logger l1, l2;
  Logger::setLogLevel(2);
  l1.log("INFO", 1);
  l2.log("warning", 2);
  l2.log("danger", 3);

   testFunctionBook();

  return 0;
}