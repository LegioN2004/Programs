// this file contains all the scope related examples of loops, functions, etc from the video.
package com.mili;

public class Scope {
    public static void main(String[] args) {
        // Another important topic known as scoping
        int a = 10, b = 20; // 1* // initialized outside the block in the same method, so cannot initialize again in the block
//        System.out.println(num); // we can't access num from the random() function down there
//        System.out.println(marks); // 1 // we can't print marks (which is from the argument of the random function)
        String name = "Kunal";

        // block scoping
        {
//            int a = 0; // 1
            a = 100;
            int d = 10;
            System.out.println(a);
            int c = 0;
            name = "Rahul";
            System.out.println(name);
            // values initialized in this block will remain in this block
        }
        System.out.println(a);
        System.out.println(name);
//        System.out.println(c); // cannot use c outside the block

        // scoping in for loops
        for (int i = 0; i < 4; i++) {
            System.out.println(i);
            a = 99;
//            int num = 90, a = 10;
        }
//        System.out.println(i); // we get an error here because for loop's i is only defined in
        // this for loop and we cannot use it outside that loop block
    }

    static void random(int marks) {
//        System.out.println(a);
        int num = 67;
        System.out.println(num); // this line shows that we can access num since we are inside the random()
                                 // function
        System.out.println(marks); // 1* // but we'll be able to print it here
    }
}
