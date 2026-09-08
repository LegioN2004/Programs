import java.util.Scanner;

public class DoWhileSwitch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int value = 0;

        do {
            System.err.println("select your choice no \n 1. Attendence \n 2. Admission");

            value = in.nextInt();

            switch (value) {
                case 1: {
                    int att = 0;

                    System.out.print("input your attendence percentage: ");
                    att = in.nextInt();

                    if (att >= 80) {
                        System.out.println("Attendence okay");
                        break;
                    } else if (att < 80 && att >= 70) {
                        System.out.println("NC fine offer added to attendence");
                        break;
                    } else { // if (att < 65)
                        System.out.println("DC offer added to attendence");
                        break;
                    }
                }

                case 2: {
                    int cee = 0, jee = 0, pcmPercentage = 0;

                    System.out.print("Enter pcm percentage: ");
                    pcmPercentage = in.nextInt();

                    System.out.print("Enter cee marks: ");
                    cee = in.nextInt();

                    System.out.print("Enter jee percentile: ");
                    jee = in.nextInt();

                    if (pcmPercentage >= 45) {
                        System.out.println("Board marks Eligible");
                        if (cee >= 40) {
                            System.out.println("CEE marks Eligible \n Application accepted");
                            break;
                        } else if (jee >= 60) {
                            System.out.println("JEE marks Eligible \n Application accepted");
                            break;
                        } else {
                            System.out.println("Application rejected due to CEE/JEE marks not fulfilled");
                            break;
                        }
                    } else {
                        System.out.println("Application rejected");
                        break;
                    }
                }

                default:
                    System.out.println("Give a proper case");
                    break;
            }

        } while (value != 3);

        in.close();
    }
}
