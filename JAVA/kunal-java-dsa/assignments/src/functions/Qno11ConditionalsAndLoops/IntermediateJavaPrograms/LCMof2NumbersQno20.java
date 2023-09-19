package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class LCMof2NumbersQno20 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Print the two numbers to find the LCM of: ");
        int a = in.nextInt(), b = in.nextInt(), lcm = 0;
        if (a > b){
            lcm = a;
        } else{
            lcm = b;
        }// till here the lcm gets the biggest no of the two entered
        while(true){ // here the while loop runs the if statement continuously until the if statement is true till then
            // it increments the lcm
            if(lcm % a == 0 && lcm % b == 0){ // then once both the remainder is 0, it prints the LCM and breaks out of loop.
                System.out.println("lcm of entered numbers is: " + lcm);
                break;
            }
            ++lcm;
        }
//        System.out.println("the required LCM is -> " + lcm);
    }
}
