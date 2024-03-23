#include<stdio.h>

int main(){
    int a =7;
    float result;
    // explicit typecasting: forcefully changing one datatype to another, here we are changing from int to float
    result =(float) a/ 2;
    printf(" the answer is %f", result);
    return 0;
}