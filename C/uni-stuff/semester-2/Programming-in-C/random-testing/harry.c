#include <stdio.h>

/* struct employee { */
/*   int eId; */
/*   char name; */
/*   float salary; */
/* }; */

union money {
  int rice;
  char firstChar;
  float salary;
};

// now in the main function we can do something like

int main(void) {
  /* struct employee mili; */
  /* mili.eId = 1; */
  /* mili.name = 'm'; */
  /* mili.salary = 1000; */

  /* printf("------------ struct part --------------\n"); */
  /* printf("%d\n%c\n%.2f\n", mili.eId, mili.name, mili.salary); */

  /* printf("------------ union part --------------\n"); */
  /* union money m1; */
  /* m1.rice = 34; */
  /* m1.firstChar = 'h'; */
  /* printf("value should be 34 but %d\n", m1.rice); */
  /* printf("value should be h but it is still %c\n", m1.firstChar); */

  enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

  int m2 = Monday;
  printf("%d\n", m2);

  return 0;
}
