import java.util.Scanner;

public class NestedSwitch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int empId = in.nextInt();
        String dep = in.next();

        switch (empId) {
            case 1:
                System.out.println("rahul");
                break;
            case 2:
                System.out.println("karan");
                break;
            case 3:
                System.out.println(" empNo 3");
                switch (dep) {
                    case "IT":
                        System.out.println("IT department");
                        break;
                    case "Mech":
                        System.out.println("Mechnical department");
                        break;
                    case "Mgmt":
                        System.out.println("Management department");
                        break;
                    default:
                        System.out.println("Wrong dep");
                        break;
                }
                break;
            default:
                System.out.println("Enter correct empId");
                break;
        }

        // better version of the switch case statement
        switch (empId) {
            case 1 -> System.out.println("rahul");
            case 2 -> System.out.println("karan");
            case 3 -> {
                System.out.println(" empNo 3");
                switch (dep) {
                    case "IT" -> System.out.println("IT department");
                    case "Mech" -> System.out.println("Mechnical department");
                    case "Mgmt" -> System.out.println("Management department");
                    default -> System.out.println("Wrong dep");
                }
            }
            default -> System.out.println("Enter correct empId");
        }
    }
}