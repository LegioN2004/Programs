package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class electricityBillQno2 {
	public static void main(String[] args) {
		// details
		Scanner in = new Scanner(System.in);
		System.out.print("Enter your consumer no: ");
		int conNo = in.nextInt();
		// units
		System.out.print("Give the number of units for the consumer no " + conNo + ": ");
		double firstUnit = 5.3, secUnit = 6.6, thirdUnit = 7.6;
		int totUnits = in.nextInt();
		double fir = totUnits - 120, sec = fir - 66, thir = sec - 16;
		fir = fir * firstUnit;
		sec = sec * secUnit;
		thir = thir * thirdUnit;
		System.out.println("First 120 units price: " + fir);
		System.out.println("Next 66 units price: " + sec);
		System.out.println("Next 16 units price: " + thir);
		double fixedCharge = 4 * 60;
		System.out.println("Fixed charge for 4 units, rate 60/unit: " + fixedCharge);
		System.out.println("for looting people CGST and SGST, we'll add anything we like, 40% i.e 500");
		double total = fir + sec + thir + fixedCharge + 500;
		System.out.println("Total bill generated: " + total);
	}
}
