package com.mili;

import java.util.Scanner;

public class sum2nos {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int a = 10;
        int b = 100;
        float c = input.nextFloat(); //remember whenever you change the declaration datatype,
        // also change the next____() <- datatype here as it defines which type of datatype values to take
        float sum = a + b - c;
        // after getting the output we see the value as 105.0 ( for c = 5), after a int input we get the value converted to float, this is type conversion and type casting see note2.org
        System.out.println("Sum is " + sum + " byee " + "run hogya hai ab kya dekh rha hai phli fursat mein nikal bhaaaaaaaaag ");
    }
}