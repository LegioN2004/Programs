package com.mili;

import java.util.Arrays;

public class VarArgs {
    public static void main(String[] args) {
        fun(2, 3, 4, 5, 56, 87, 23, 45); // since it is taking variable length arguments we can pass any no of arguments

        // multiple(2, 3, "kunal", "Rahul", "hello", "hi", "this", "is", "var", "length", "arg input");
        // the arguments for input will also be in the same order like the one in the initialization,
        // first of the int type, a and b, then the var length args in String type, random names........

        // demo(2, 3, 4, 5, 6); // calling this function prints {2, 3, 4, 5, 6}
        demo("Kunal", "Rahul"); // and this prints [Kunal, Rahul]

    }
    // what if there is a mix of arguments like normal arguments as well as keyword argumens, the following is the example
    static void multiple(int a, int b, String ...v){ // a, b and variable length argument v, this is also possible
    }

    static void demo(int ...v){
        System.out.println(Arrays.toString(v));
    }

    static void demo(String ...v){
        System.out.println(Arrays.toString(v));
    }

    static void fun(int ...v){
        System.out.println(Arrays.toString(v));
    }
}
