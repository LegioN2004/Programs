package functions.Qno11FlowOfPrograms;

import java.util.Scanner;

public class Qno5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int c = 0;
        do{
                c = c + a;
                if(a == 'x'){
                    break;
                }
        } while (a != 'x');
//        System.out.println(unlimitedSum(a));
        System.out.println(c);
    }

//    static int unlimitedSum(int a){
//        return 0;
//    }
}
