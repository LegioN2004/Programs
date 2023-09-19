// Define two methods to print the maximum and the minimum number respectively among three numbers entered by the user.
package functions;

import java.util.Scanner;

public class Qno1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        System.out.println(isMax(a, b, c) + " is the max no");
        System.out.println(isMin(a, b, c) + " is the min no");
//        isMin(a, b, c);
    }

    static int isMax(int a, int b, int c) {
        int max = a;
        if (max < b) {
            max = b;
        }
        if (max < c) {
            max = c;
        }
        return max;
    }

    static int isMin(int a, int b, int c) {
        int min = a;
        if (min > b){
            min = b;
        }
        if (min > c){
            min = c;
        }
        return min;
    }
}