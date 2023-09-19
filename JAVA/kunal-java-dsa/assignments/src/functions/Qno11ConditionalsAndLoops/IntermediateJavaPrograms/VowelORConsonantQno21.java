package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class VowelORConsonantQno21 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a letter: ");
        char letter = in.next().charAt(0);
        type(letter);
    }

    static void type(char letter) {
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
            System.out.print("The letter is a vowel");
        } else {
            System.out.print("The letter is a consonant");
        }
    }
}