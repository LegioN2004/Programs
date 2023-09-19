package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String a = in.next();

        // outputs
        System.out.println("approach 1 answer is: " + palindromeApproach1(a));
        if (palindromeApproach1(a).equals(a)) {
            System.out.println("The string is palindrome");
        } else {
            System.out.println("The string is not palindrome");
        }
    }

    static String palindromeApproach1(String a) {
        // logic to reverse a string
        String orig = a; // stored the main value in the orig value to compare
        String rev = ""; // declaration of the var to store the main reversed string
        int b = a.length(); // to get the length of the string and as such we can print the letters
                            // according to the index(as shown in the for looop)
        for (int i = b - 1; i >= 0; i--) {
            rev = rev + a.charAt(i); // this contains the reverse string, as well as prints the letters acc to its
                                     // index
        }
        return rev;
    }
}
