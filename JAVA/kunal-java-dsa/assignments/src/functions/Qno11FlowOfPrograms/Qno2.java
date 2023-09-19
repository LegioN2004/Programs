package functions.Qno11FlowOfPrograms;

import java.util.Scanner;

public class Qno2 {
        public static void main(String[] args) {
                Scanner in = new Scanner(System.in);
                int a = in.nextInt();
                int b = in.nextInt();
                System.out.println(sum(a, b));
        }

        static int sum(int a, int b) {
                int c = a + b;
                return c;
        }
}
