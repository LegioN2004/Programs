package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.nextLine();
        if (greeting(a).equals("mili")) {
            System.out.println(greeting(a) + " Greetings my dear");
        } else {
            System.out.println("The '" + greeting(a) + "' name is wrong, get the hell out of here");
        }
    }

    static String greeting(String a) {
        String name = " ";
        if (a.equals("mili")) {
            name = a;
        } else {
            return a;
        }
        return name;
    }

}
