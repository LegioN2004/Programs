// Write a function to find if a number is a palindrome or not. Take number as parameter.
package functions;

public class Qno10 {
    public static void main(String[] args) {
        int a = 101;
        if(palindrome(a)){
            System.out.println("The no is palindrome");
        }
        else
            System.out.println(" not palindrome");
    }

    static boolean palindrome(int n){
        int original = n, reversed = 0;
        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }

        return original == reversed;
    }
}
