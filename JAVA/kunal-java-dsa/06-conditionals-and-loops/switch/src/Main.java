import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // in strings,
        // String a = "hello";
        // fixme: This is an important part
        // String b = "hello"; // how to know that both a and b is pointing to the same object "hello"
        // or and b might have their own hello object,
        // System.out.println(a == b);
        // System.out.println(a.equals(b));

        //  if(fruit.equals("mango")) {
        //      System.out.println("King of the fruits");
        //  }
        //  if(fruit.equals("apples")) { // can use else if but since fruit string are some fruits so it'll definitely not be something else
        //      System.out.println("A sweet red fruit");
        //  }

        Scanner in = new Scanner(System.in);

        // String fruit = in.next();
        // -------------- older style switch case --------------------------------------
        //  switch(fruit){ // doing alt enter on this converts this into a much better syntax version where we also don't need a break;
        //     case "Mango":
        //         System.out.println("King of the fruits");
        //         break;
        //     case "Apple":
        //         System.out.println("A sweet red fruit");
        //         break;
        //     case "Orange":
        //         System.out.println("A sweet orange fruit");
        //         break;
        //     case "Grapes":
        //         System.out.println("A small and sweet round fruit");
        //         break;
        //     default: // default is the last statement, we don't need a break after this
        //         System.out.println("Please enter a fruit from these options only(case sensitive): Mango, Apple, Orange, Grapes");
        // }


       // -------------- newer style switch case syntax --------------------------------------
       //  switch (fruit) { //done alt+enter on this, converted to a much better and cleaner version
       //     case "Mango" -> System.out.println("King of the fruits");
       //     case "Apple" -> System.out.println("A sweet red fruit");
       //     case "Orange" -> System.out.println("A sweet orange fruit");
       //     case "Grapes" -> System.out.println("A small and sweet round fruit");
       //     default -> // default is the last statement, we don't need a break after this
       //             System.out.println("Please enter a fruit from these options only(case sensitive): Mango, Apple, Orange, Grapes");


        // more stuff can be done using this switch case statements
        System.out.print("Print the day number in a week to find the corresponding day: ");
        int day = in.nextInt();

        // switch (day) {
        //     case 1 -> System.out.println("Monday");
        //     case 2 -> System.out.println("Tuesday");
        //     case 3 -> System.out.println("Wednesday");
        //     case 4 -> System.out.println("Thursday");
        //     case 5 -> System.out.println("Friday");
        //     case 6 -> System.out.println("Saturday");
        //     case 7 -> System.out.println("Sunday");
        // }

        switch (day) {
            case 1, 2, 3, 4, 5 -> System.out.println("Weekday"); // directly printing weekday, if used any of these numbers
            case 6, 7 -> System.out.println("Weekend"); // directly printing weekend when used 6 / 7
        }
    }
}