// if conditions
package com.mili;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner a = new Scanner(System.in);
        long salary = a.nextLong();
        // using nested if else statments ignore line 10 and line 18 to 23
        if ( salary < 100000 ) {
            if (salary > 10000) {
                salary += 2000; // salary = salary + 2000;
            } else if (salary > 20000) {
                salary += 3000;
            } else {
                salary += 1000;
            }
            System.out.println("too less salary, you suck get the hell outta here and get a better job");
        }
        else {
            System.out.println("too good salary,mauj karo zindagi meinnn");
        }
        System.out.println(salary);
    }
}