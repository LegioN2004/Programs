// Write a program that will ask the user to enter his/her marks (out of 100). Define a method that will display grades according to the marks entered as below:
package functions;

import java.util.Scanner;

public class Qno8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if(grades(n) != "Fail") {
            System.out.println("Your grades for your marks " + n + " is " + grades(n));
        }
        else
            System.out.println("Sorry you failed");
    }

    static String grades(int n){
       String marks = "";
        if(n <= 100 || n >= 91) {
            marks = "AA";
        }
        if(n <= 90 || n >= 81) {
            marks = "AB";
        }
        if(n <= 80 || n >= 71) {
            marks = "BB";
        }
        if(n <= 70 || n >= 61) {
            marks = "BC";
        }
        if(n <= 60 || n >= 51) {
            marks = "CD";
        }
        if(n <= 50 || n >= 41) {
            marks = "DD";
        }
        if(n <= 40) {
            marks = "Fail";
        }
        return marks;
        }
    }
