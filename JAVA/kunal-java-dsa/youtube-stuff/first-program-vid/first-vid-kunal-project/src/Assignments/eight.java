// find if given string is palindrome or not
package Assignments;
import java.util.Scanner;
public class eight {
    public static void main(String[] args) {
        Scanner str = new Scanner(System.in);
        System.out.print("Write the string: ");

        String r1 = str.next(); // remember index starts from 0
        String r2 = "";
        int l = r1.length();
        for (int m = l - 1; m >= 0; m--) {
            r2 = r2 + r1.charAt(m); // i.e why here we get i for 7th index
        }
        System.out.println("String reversed is " + r2);
        if (r1.equals(r2)) { // always use == instead of = to show equality and here use
            // .equals(_variable_) for equality of strings . In Java, the == operator checks for
            // reference equality for objects, not the content equality of strings. To check if two
            // strings have the same content, you should use the .equals() method instead.
            System.out.println("string is palindrome");
        }
        else {
            System.out.println("string is not palindrome");
        }
    }
}