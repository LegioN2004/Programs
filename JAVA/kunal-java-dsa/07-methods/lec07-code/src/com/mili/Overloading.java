package com.mili;

public class Overloading {
    public static void main(String[] args) {
        // fun(67);
        // fun("Rahul");
        int ans = sum(3, 4, 88); // after giving outputs till 3 this will run function second sum, if we give more than 3 outputs it'll show error
        System.out.println(ans);
        // sum(3, 4);
    }

    static int sum(int a , int b){
        // can print directly in the function call or in here
        // int c = a + b;
        // System.out.println(c);
        // return c;
        return a + b;
    }
    // both the above and below functions are same but after providing the int c value below, the function became different and hence no error
    static int sum(int a , int b, int c){
        return a + b + c;
    }

    static void fun(int a) {
        System.out.println(a);
    }

    static void fun(String name) {
        System.out.println(name);
    }
}
