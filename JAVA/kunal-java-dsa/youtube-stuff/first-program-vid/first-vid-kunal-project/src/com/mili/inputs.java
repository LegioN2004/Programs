package com.mili;

import java.util.Scanner;

public class inputs {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // System.in takes keyb(in) input and then passes it to the input var (since we need another var to get the input)
        System.out.print("enter the input = "); // prints output
        int rollno = input.nextInt(); // rollno takes value from keyb using input.nextInt
        System.out.println("your roll no is " + rollno ); // + is used to join together the sentence string in "" as well as the value of the variable
//                                                             '+' more on that later on how to convert types from one to another

//         integer inputs for example
        int a = 10; // here 10 is literal and a is a identifier
//        int b = 100_000_000; // use _ to have long no output in int , here underscores are ignored
        System.out.println(a); // prints the output

         String name = input.nextLine(); // then it passes the name var what type of value to take from the input var(after the input._____ part) by putting the nextInt()/any-other type
        System.out.println(name); // then prints the value of the name variable

        Float no = input.nextFloat(); // this will take float (notice the _nextFloat()_ ) values
        System.out.println(no); //  and will print the output in this line
    }
}
