package com.mili;

public class Swap {
    public static void main(String[] args) {
        int a = 10;
        int b = 20;

        // swapping values code
        // int temp = a;
        // a = b;
        // b = temp;

        swap(10, 20);
        System.out.println(a + " " + b);

        String name = "hello";
        changeName(name);
//        System.out.println(naam); // cannot print naam here since it is out of the scope
    }

    static void changeName(String naam) {
        naam = "Rahul"; // creating a new object, which gets cancelled due to the nature of java string
                        // being a final class
    }

    static void swap(int a, int b) {
        // this will not swap since the return type of this function is of the void type
        int temp = a;
        a = b;
        b = temp;

    }
}
