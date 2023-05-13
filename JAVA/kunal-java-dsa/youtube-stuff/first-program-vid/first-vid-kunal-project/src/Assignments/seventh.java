package Assignments;
public class seventh {
    public static void main(String[] args) {
        long n = 100000;
        int a = 0;
        int b = 1;
        int c = 0;
        while (c <= n) {
            a = b;
            b = c;
            c = a + b;
            System.out.println(c);
        }
    }
}
