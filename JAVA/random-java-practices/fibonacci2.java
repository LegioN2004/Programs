import java.util.Scanner;

public class fibonacci2 {
    public static void main(String[] args) {
        int a = 0, b = 1, c, term;
        Scanner in  = new Scanner(System.in);
        System.out.print("enter the value of term ");
        term = in.nextInt();
        for (int i = 0; i <= term; i++) {
        System.out.print(a + " ");
        c = a + b;
        a = b;
        b = c;    
        }
    }
}
