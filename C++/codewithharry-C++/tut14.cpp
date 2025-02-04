#include <iostream>
using namespace std;

// structures--> It is that type of user defined data type which is used to
// segregate different data types in a single data type. different data types in
// one program such as int,float,char,etc
typedef struct employee
/* Using typedef with struct allows us to use 'ep' as an alias for 'struct
         employee' */
{
  /* data */
  int eid;  // here the datatypes are mentioned with the corresponding data
            // which is to be printed
  char favChar;
  float salary;
} ep;  //* end here we have to put ep so we can use shortcut*

// unions -- they are similar to structures but they provide a very good memory
// management
// 2nd part
union money {
  /* data */
  int rice;  // here we can use only one data type which help us to achieve
  int rice;  // Only one member of the union can be used at a time, which helps
             // achieve better memory optimization.
  float pounds;
};

int main()  // here the values are given for the corresponding data types with
            // the
{
  /* enum can be used to give numerical values starting from 0 to the words in
           the brakcets */

  enum Meal { breakfast, lunch, dinner };
  Meal m1 = lunch;  // here anything written after = gives the corresponding
                    // values of the words in the above brackets
  cout << (m1 ==
           0);  // here we should put the corresponding values like 0,1,2 etc of
                // the corresponding values and if we write the wrong value then
                // we will get output as 0 and if we write the correct value
                // then we will get the corresponding value

  // cout<<breakfast;
  // cout<<lunch;
  // cout<<dinner;
  //  ep mili; //* ep here instead of struct employee to make it easy ,, also
  //  the name is mili so we have to use it in int main whenever we initialise
  //  the values
  // union money m1; //2nd part
  // m1.rice=34; // here firstly we got
  // m1.car='c';
  // cout<<m1.car;

  // struct employee manuh ; //1st part
  // struct employee human ;
  // mili.eid=1;  // we have to intialise by using the name succeded by a dot
  // and then the name given to hold the values of the respective data type
  // mili.favChar='r';
  // mili.salary=1000;
  ep mili;
  mili.eid = 1;
  mili.favChar = 'r';
  mili.salary = 1000;
  cout << "\nThe value is " << mili.eid << endl;
  cout << "The value is " << mili.favChar << endl;
  cout << "The value is " << mili.salary << endl;

  return 0;
}
