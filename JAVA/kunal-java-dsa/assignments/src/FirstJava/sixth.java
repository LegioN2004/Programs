package FirstJava;
//Input currency in rupees and output in USD.

import java.util.Scanner;

public class sixth {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);

        System.out.print("write the amount of money in Rupees: ");
        float a = x.nextFloat();

        float b = a / 82.06f;
        System.out.println("The amount converted to USD is: " + b);
    }
}
