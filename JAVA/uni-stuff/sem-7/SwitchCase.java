import java.util.Scanner;

public class SwitchCase {

    static Scanner in = new Scanner(System.in);

    static void attendence() {
        int att = 80;

        System.out.print("input your attendence percentage: ");
        att = in.nextInt(); // 80

        switch (true) {
            case (att >= 80):
                System.out.println("attendence okay");
                break;

            case (att > 70 && att < 80):
                System.out.println("NC applied");
                break;

            case (att < 70):
                System.out.println("DC applied okay");
                break;

            default:
                System.out.println("Failed");
                break;
        }

    }

    // static void admission() {
    // int cee = 0, jee = 0, pcmPercentage = 0;

    // System.out.print("Enter pcm percentage: ");
    // pcmPercentage = in.nextInt();

    // System.out.print("Enter cee marks: ");
    // cee = in.nextInt();

    // System.out.print("Enter jee percentile: ");
    // jee = in.nextInt();

    // if (pcmPercentage >= 45) {
    // System.out.println("Board marks Eligible");
    // if (cee >= 40)
    // System.out.println("CEE marks Eligible \n Application accepted");
    // else if (jee >= 60)
    // System.out.println("JEE marks Eligible \n Application accepted");
    // else
    // System.out.println("Application rejected due to CEE/JEE marks not
    // fulfilled");
    // } else
    // System.out.println("Application rejected");

    // }

    public static void main(String[] args) {
        attendence();
        // admission();

        // in.close();
    }

}
