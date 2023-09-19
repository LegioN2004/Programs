// A person is eligible to vote if his/her age is greater than or equal to 18. Define a method to find out if he/she is eligible to vote.
package functions;

import java.util.Scanner;

public class Qno3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        if (isEligible(a) >= 18) {
            System.out.println(isEligible(a) + ", so eligible to vote");
        } else{
            System.out.println(isEligible(a) + ", so not eligible to vote");
        }
    }

    static int isEligible(int a){
        return a;
    }
}
