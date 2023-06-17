// if-else conditions
package com.mili;

import java.util.Scanner;

public class conditionals {
    public static void main(String[] args) {
        Scanner a = new Scanner(System.in);
        long salary = a.nextLong();
        // using nested if else statments ignore line 10 and line 18 to 23
        if (salary < 100000) {
            if (salary > 10000) {
                salary += 2000; // same as -> salary = salary + 2000;
            } else if (salary > 20000) { // multiple else if statments
                salary += 3000;
            } else {
                salary += 1000; // if none of the above conditions are true then execute this condition
            }
            System.out.println("too less salary, you suck get the hell outta here and get a better job");
        } else {
            System.out.println("too good salary,mauj karo zindagi meinnn");
        }
        System.out.println(salary);
    }
}
