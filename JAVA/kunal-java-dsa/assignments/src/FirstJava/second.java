package FirstJava;
// Take name as input and print a greeting message for that particular name.

import java.util.Scanner;

public class second{
    public static void main(String[] args){
        Scanner name = new Scanner(System.in);
        String c = name.nextLine();
//        System.out.print(c + " Okairinasaimasen, aarji-dono/hime-sama");
        System.out.print(c + " is the required gretting message");
    }
}
