// TYPECASTING AND TYPECONVERSION

package com.mili;

import java.util.Scanner;

public class TypeCasting {
    public static  void main(String[] args){
        // some conditions need to be met to auto convert types , see note2.org
//         Scanner num = new Scanner(System.in);
        // float input = num.nextFloat();
        // System.out.println(input);

        // type casting
//      int num = (int)(89.5f);
//      System.out.println(num);

        // auto type promotion in expression
//      int a = 257;
//      byte b = (byte)(a); // remember the max value that can be stored in a byte is 256
//      // since the max value of byte is less than the given value, so it cannot print the value 257 and instead gives the remainder i.e 257 % 256 = 1
//      System.out.println(b);

//        byte a = 40;
//        byte b = 50;
//        byte c = 100;
//        int d = (a * b) / c; // java auto converts the byte value to int when it evaluates the expression (a*b) so that 'd' its able to store it
//        System.out.println(d);

//        byte b = 50;
//        b = b * 2; // since b is being converted to an int so the byte variable b can't store the value now and it will throw error
        // so you will need to explicitly convert it into the int data type

//        int number = 'A'; // this is also an example of auto type conversion where it converts the value of int to ascii type
//        System.out.println(number);

        // java has got unicode support so you can print special characters, letter, and languages
//        System.out.println("'🥞👏👏' emojis" + " as well as 'こんにちはジャワ' language support " + "special characeter support in java");
        System.out.println(3 * 5.620389472987f); // prints output as float
    }
}