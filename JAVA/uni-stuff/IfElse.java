import java.util.Scanner;

public class IfElse {

    static Scanner in = new Scanner(System.in);

    static void attendence() {
        int att = 0;

        System.out.print("input your attendence percentage: ");
        att = in.nextInt();

        if (att >= 75)
            System.out.println("Attendence okay");
        else if (att < 75 && att > 65)
            System.out.println("NC fine offer added to attendence");
        else // if (att < 65)
            System.out.println("DC offer added to attendence");
    }

    static void admission() {
        int cee = 0, jee = 0, pcmPercentage = 0;

        System.out.print("Enter pcm percentage: ");
        pcmPercentage = in.nextInt();

        System.out.print("Enter cee marks: ");
        cee = in.nextInt();

        System.out.print("Enter jee percentile: ");
        jee = in.nextInt();

        if (pcmPercentage >= 45) {
            System.out.println("Board marks Eligible");
            if (cee >= 40)
                System.out.println("CEE marks Eligible \n Application accepted");
            else if (jee >= 60)
                System.out.println("JEE marks Eligible \n Application accepted");
            else
                System.out.println("Application rejected due to CEE/JEE marks not fulfilled");
        } else
            System.out.println("Application rejected");

    }

    public static void main(String[] args) {
        attendence();
        admission();

        in.close();
    }

}
