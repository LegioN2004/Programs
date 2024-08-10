import java.util.Scanner;

public class AllPatterns {

    static void pattern1(int n) {
        /*
         ****
         ****
         ****
         ****
         */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    static void pattern2(int n) {
        /*
         *
         **
         ***
         ****
         */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    static void pattern3(int n) {
        /*
         * 1
         * 1 2
         * 1 2 3
         * 1 2 3 4
         */
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }

    static void pattern4(int n) {
        /*
         * 1
         * 2 2
         * 3 3 3
         * 4 4 4 4
         */
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    static void pattern5(int n) {
        /*
         * * * * *
         * * * *
         * * *
         * *
         *
         */
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n - i + 1; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    static void pattern6(int n) {
        /*
         * 1 2 3 4 5
         * 1 2 3 4
         * 1 2 3
         * 1 2
         * 1
         */
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n - i + 1; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }

    static void pattern7(int n) {
        /*
             *
            ***
           *****
          *******
         *********
        */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < i * 2 + 1; j++) {
                System.out.print("*");
            }
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    static void pattern8(int n) {
        /*
         *********
          *******
           *****
            ***
             *
         */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < (2 * n) - (2 * i + 1); j++) {
                System.out.print("*");
            }
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    static void pattern9(int n) {
        /*
             *
            ***
           *****
          *******
         *********
         *********
          *******
           *****
            ***
             *
         */
        // here you can just combine them, there's no need to write the code again
        pattern7(n);
        pattern8(n);
    }

    static void pattern10(int n) {
        /*
         *
         **
         ***
         ****
         ***
         **
         *
         */
        for (int i = 1; i <= 2 * n - 1; i++) {
            int stars = i;
            if (i > n)
                stars = 2 * n - i;
            for (int j = 1; j <= stars; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    static void pattern11(int n) {
        /*
         * 1
         * 0 1
         * 1 0 1
         * 0 1 0 1
         * 1 0 1 0 1
         */
        for (int i = 0; i < n; i++) {
            int start = 1;
            if (i % 2 == 0)
                start = 1;
            else
                start = 0;
            for (int j = 0; j <= i; j++) {
                System.out.print(start + " ");
                start = 1 - start; // to flip the value
            }
            System.out.println();
        }
    }

    static void pattern12(int n) {
        /*
         * 1 _ _ _ _ _ _ 1
         * 1 2 _ _ _ _ 2 1
         * 1 2 3 _ _ 3 2 1
         * 1 2 3 4 4 3 2 1
         */
        // here '_' represents spaces, since it is getting cleared due to code's
        // autoformatting so added that instead of spaces
        int space = 2 * (n - 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j);
            }
            for (int j = 1; j <= space; j++) {
                System.out.print(" ");
            }
            for (int j = i; j >= 1; j--) {
                System.out.print(j);
            }
            System.out.println();
            space -= 2;
        }
    }

    static void pattern13(int n) {
        /*
         * 1
         * 2 3
         * 4 5 6
         * 7 8 9 10
         * 11 12 13 14 15
         */
        int a = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(a++ + " ");
            }
            System.out.println();
        }
    }

    static void pattern14(int n) {
        /*
         * A
         * A B
         * A B C
         * A B C D
         * A B C D E
         */
        for (int i = 0; i < n; i++) {
            for (char ch = 'A'; ch <= 'A' + i; ch++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }

    static void pattern15(int n) {
        /*
         * A B C D E
         * A B C D
         * A B C
         * A B
         * A
         */
        for (int i = 0; i < n; i++) {
            for (char ch = 'A'; ch <= 'A' + n - i - 1; ch++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }

    static void pattern16(int n) {
        /*
         * A
         * B B
         * C C C
         * D D D D
         * E E E E E
         */
        for (int i = 0; i < n; i++) {
            char ch = (char) ('A' + i);
            for (int j = 0; j <= i; j++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }
    static void pattern17(int n) {
        /*
         *      A
         *     ABA
         *    ABCBA
         *   ABCDCBA
         */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }
            char ch = 'A';
            // breakpoint gives 1 3 5 7 9
            int breakPoint = (2 * i + 1) / 2; // 1/2 = 0, 3/2=1, 5/2=2, 7/2=3
            for (int j = 1; j <= i * 2 + 1; j++) {
                System.out.print(ch);
                if (j <= breakPoint) ch++;
                else ch--;
            }
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt();
            pattern17(n);
            System.out.println();
        }
    }
}
