package FirstJava;

import java.util.Scanner;

public class reverseAno {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        System.out.print("Print the number: ");
        int n = x.nextInt(), r;
//        reverse no logic can use while or do while loop
        while(n > 0){ // here condition is given that the loop will run only in case of +ve numbers
            r = n % 10; // always find the remainder then finding the remainder, dividing with 10 removes
            // the numbers one by one so we divide it by 10
//            System.out.println("Reverse order is " + r); // the reverse order line is added to show the steps in which it is printed
            System.out.print(r);
            n = n / 10; // then this part removes the last no we just reversed and printed to get the next
            //one using a decimal and due to int datatype the decimal part gets ignored and then the loop prints
            // the nos in reverse order as expected. Here first 123 -> 12.3 (gets 12 only prints 2) -> 1.23 (prints 1)
        }
    }
}
