#include<stdio.h>

int main(){
    int a =16;
    float b = 2.5, c;
    // explicit typecasting: forcefully changing one datatype to another, here we are changing from int to float
    c = a * b;
    printf(" the answer is %f", c);
    return 0;
}