package com.mili;

import java.util.Scanner;

public class egTemp {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter a temp in celsius = ");
        float tempinC = in.nextFloat();

        float tempinF = (tempinC * 9 / 5) + 32;
        System.out.println("The temp in Fahrenheit is = " + tempinF);
    }
}
