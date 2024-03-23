#include<stdio.h>

int main(){
    float a,b,c;
    printf("enter the three sides ");
    scanf("%f %f %f", &a, &b, &c);
    float d = a + b + c;
    printf(" the perimeter is %f", d);
}