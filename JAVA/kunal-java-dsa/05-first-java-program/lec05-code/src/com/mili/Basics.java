package com.mili;

public class Basics {
    public static void main(String[] args) {
        // IF condition
//        int a = 10;
//        if (a == 10) { // if we explicitly say (i.e in brackets) it is true then it will show output or else for false it wil not show the output
//            System.out.println("noting");
//        }
        // if we add a else statement then it will print the stuff inside the else statement if the if statement is true
//        else{
//            System.out.println("byeeeeeeeeeee");
//        }

        // WHILE loop
//        int count = 1; // 1. declare the count as 1 (starting point)
//        while ( count != 5 ){ // 2. Is count ka value not equal to 5, if yes then print the following
//            System.out.println(count); // 3. print the no in count
//            count++; // 4. continue the loop by adding (i.e increase) the above mentioned declaration value by 1 and then continue printing using part 3

        // FOR loop (remember for loop is just like cpp)
        for ( int count = 1 ; count != 5; count++ ){ // int declaration can be inside or outside
            System.out.println(count);
        }
    }
}
