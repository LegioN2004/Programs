package MissionFailed;

import java.util.Scanner;

public class CalcCGPAExtended {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            System.out.print(
                    "Calculating the CGPA, these are the prerequisites : Five subjects(choose min 3 and max 5), five grades 1.from A to E, 2.  from the numbers 91 to 100 gives grade 10 and so on; the respective grade points go from 10.0 to 5.0, 5.0 begin the lowest ");
            String gradeSystem = in.next();
            if (gradeSystem.equals("marks")) {
                System.out.print("Give the name and marks of the subjects you are interested in(enter 0 to the ones not interested): ");
                String subjects = in.next().trim();
                double marks;
                int gradePts1 = 0, gradePts2 = 0, gradePts3 = 0, gradePts4 = 0, gradePts5 = 0;
                switch (subjects) {
                    case "English" : {
                        System.out.print("Give your marks secured in the english subject: ");
                        marks = in.nextDouble();
                        if (marks <= 100 && marks >= 91) {
                            System.out.println("You have got an A grade with grade points 10");
                            gradePts1 = 10;
                        } else if (marks >= 81 && marks <= 90) {
                            System.out.println("You have got an B grade with grade points 9");
                            gradePts1 = 9;
                        } else if (marks >= 71 && marks <= 80) {
                            System.out.println("You have got an C grade with grade points 8");
                            gradePts1 = 8;
                        } else if (marks >= 61 && marks <= 70) {
                            System.out.println("You have got an D grade with grade points 7");
                            gradePts1 = 7;
                        } else if (marks >= 51 && marks <= 60) {
                            System.out.println("You have got an D grade with grade points 6");
                            gradePts1 = 6;
                        } else {
                            System.out.println("You have failed the exam so grade points will be 0");
                            gradePts1 = 0;
                        }
                    }
                    case "Mathematics" : {
                        System.out.print("Give your marks secured in the maths subject: ");
                        marks = in.nextDouble();
                        if (marks <= 100 && marks >= 91) {
                            System.out.println("You have got an A grade with grade points 10");
                            gradePts2 = 10;
                        } else if (marks >= 81 && marks <= 90) {
                            System.out.println("You have got an B grade with grade points 9");
                            gradePts2 = 9;
                        } else if (marks >= 71 && marks <= 80) {
                            System.out.println("You have got an C grade with grade points 8");
                            gradePts2 = 8;
                        } else if (marks >= 61 && marks <= 70) {
                            System.out.println("You have got an D grade with grade points 7");
                            gradePts2 = 7;
                        } else if (marks >= 51 && marks <= 60) {
                            System.out.println("You have got an D grade with grade points 6");
                            gradePts2 = 6;
                        } else {
                            System.out.println("You have failed the exam so grade points will be 0");
                            gradePts2 = 0;
                        }
                    }
                    case "Physics" : {
                        System.out.print("Give your marks secured in the physics subject: ");
                        marks = in.nextDouble();
                        if (marks <= 100 && marks >= 91) {
                            System.out.println("You have got an A grade with grade points 10");
                            gradePts3 = 10;
                        } else if (marks >= 81 && marks <= 90) {
                            System.out.println("You have got an B grade with grade points 9");
                            gradePts3 = 9;
                        } else if (marks >= 71 && marks <= 80) {
                            System.out.println("You have got an C grade with grade points 8");
                            gradePts3 = 8;
                        } else if (marks >= 61 && marks <= 70) {
                            System.out.println("You have got an D grade with grade points 7");
                            gradePts3 = 7;
                        } else if (marks >= 51 && marks <= 60) {
                            System.out.println("You have got an D grade with grade points 6");
                            gradePts3 = 6;
                        } else {
                            System.out.println("You have failed the exam so grade points will be 0");
                            gradePts3 = 0;
                        }
                    }
                    case "Chemistry" : {
                        System.out.print("Give your marks secured in the Chemistry subject: ");
                        marks = in.nextDouble();
                        if (marks <= 100 && marks >= 91) {
                            System.out.println("You have got an A grade with grade points 10");
                            gradePts4 = 10;
                        } else if (marks >= 81 && marks <= 90) {
                            System.out.println("You have got an B grade with grade points 9");
                            gradePts4 = 9;
                        } else if (marks >= 71 && marks <= 80) {
                            System.out.println("You have got an C grade with grade points 8");
                            gradePts4 = 8;
                        } else if (marks >= 61 && marks <= 70) {
                            System.out.println("You have got an D grade with grade points 7");
                            gradePts4 = 7;
                        } else if (marks >= 51 && marks <= 60) {
                            System.out.println("You have got an D grade with grade points 6");
                            gradePts4 = 6;
                        } else {
                            System.out.println("You have failed the exam so grade points will be 0");
                            gradePts4 = 0;
                        }
                    }
                    case "Computer Science" : {
                        System.out.print("Give your marks secured in the Computer subject: ");
                        marks = in.nextDouble();
                        if (marks <= 100 && marks >= 91) {
                            System.out.println("You have got an A grade with grade points 10");
                            gradePts5 = 10;
                        } else if (marks >= 81 && marks <= 90) {
                            System.out.println("You have got an B grade with grade points 9");
                            gradePts5 = 9;
                        } else if (marks >= 71 && marks <= 80) {
                            System.out.println("You have got an C grade with grade points 8");
                            gradePts5 = 8;
                        } else if (marks >= 61 && marks <= 70) {
                            System.out.println("You have got an D grade with grade points 7");
                            gradePts5 = 7;
                        } else if (marks >= 51 && marks <= 60) {
                            System.out.println("You have got an D grade with grade points 6");
                            gradePts5 = 6;
                        } else {
                            System.out.println("You have failed the exam so grade points will be 0");
                            gradePts5 = 0;
                        }
                    }
                    default :
                        System.out.print("The above are the subjects chosen and so to calc CGPA enter the no of subjects you have chosen");
                        double noOfSubj = in.nextInt();
                        double cgpa = (gradePts1 + gradePts2 + gradePts3 + gradePts4 + gradePts5) / noOfSubj;
                        System.out.println("The cgpa is " + cgpa);
                        System.out.println("Give the name of the subjects carefully with the first letter as capital");
                }
            } else if (gradeSystem == "grades") {
                System.out.println("Give the no of subjects you are interested in and also choose the subjects");
                String subjects = in.next().trim();
                if (subjects.equals("English")) {
                    System.out.println("notoanrstoniar");
                }
            } else {
                System.out.println("Give what you need to do, marks or grades but only in small case letters");
            }
    }
}
