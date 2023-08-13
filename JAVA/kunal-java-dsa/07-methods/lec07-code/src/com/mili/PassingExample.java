package com.mili;

public class PassingExample {
    public static void main(String[] args) {
        String name = "kunal";
        greet(name);
    }

    // what this program shows is that the variables names that are used in the main function call
    // and the function declaration can be same or different as they don't depend on each other for
    // storing values
    static void greet(String naam) {
        System.out.println(naam);
    }
}
