# structs, enums and unions

We have used arrays to store multiple values of the same type. We can also store multiple values of different types in a single variable using structs, enums and unions but this approach gives more dynamic usage of types unlike arrays which we'll see below.

## Structs

We have used only arrays for this long to store the same type of data but when we'll have to store multiple values of different types in a single variable, we use structs. Structs are user-defined data types that can store multiple values of different types. The values stored in a struct are called members. The members of a struct can be of any data type.

```c
struct employee {
int eId;
char name;
float salary;
}

// now in the main function we can do something like
struct employee mili;
mili.eId = 1;
mili.name = 'mili';
```

we can create as many variables(here names) of struct as we want, and we can give different values so as to create many different types of datas and this reduces the problem of DRY more.

## Unions

Union is a user-defined data type that can store multiple values of different types similar to structures but only one value at a time. The memory occupied by a union will be large enough to hold the largest member of the union. The values stored in a union are called members.

```c
union money {
  int rice; // 4
  char firstChar; // 1
  float salary; // 2
};

```

In the above example, we have created a union with the name “money” in which we have declared three variables of different data types (rice, car, pound). The main thing to note here is that:

- We can only use 1 variable at a time otherwise the compiler will give us a garbage value
- The compiler chooses the data type which has maximum memory for the allocation.

For eg in the above struct example we have used a total of lets say 9 bytes(4 for int, 1 for char and 4 for float as well), so the memory allocated will be 9 bytes. But in the case of unions, the one which will take the max memory will be allocated ( here it'll be 4 bytes as int takes the maximum memory) and so the others will be able to use those memory as well since they take less and as such we'll be able to use only one variable at a time and there'll be better memory management.

```c
int main(void) {
  union money m1;
  m1.rice = 34;
  m1.firstChar = 'h';
  printf("value should be 34 but %d\n", m1.rice);
  printf("value should be h but it is still %c\n", m1.firstChar);
  return 0;
}
```

Now if we try to do the above i.e first assigning the value of rice and then firstChar, the output will be garbage value as the memory is overwritten by the firstChar and the value of rice is lost.

## Enums

Enums are user-defined types which consist of named constants. Enums are used to make the program more readable. An example program for enums is shown below

```c
int main(){
    enum Meal{ breakfast, lunch, dinner};
    Meal m1 = lunch;
    cout<<m1;
    return 0;
}
```

As shown in Code Snippet, 1st we have created an enum “Meal” in which we have stored three named constants (breakfast, lunch, dinner). 2nd we have assigned the value of “lunch” to the variable “m1” and at the end, we have printed “m1”. The main thing to note here is that (breakfast, lunch, dinner) are constants; the value for “breakfast” is “0”, the value for “lunch” is “1” and the value for “dinner” is “2”. The output for the following program is shown in figure 2.
