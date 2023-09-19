package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno15VolumeOfPrism {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Volume of Rectangular Prism Calculator");
		System.out.print("Enter the length of the prism: ");
		double length = input.nextDouble();
		System.out.print("Enter the width of the prism: ");
		double width = input.nextDouble();
		System.out.print("Enter the height of the prism: ");
		double height = input.nextDouble();
		double volume = calculatePrismVolume(length, width, height);
		System.out.println("The volume of the rectangular prism is: " + volume);
	}

	// Function to calculate the volume of a rectangular prism
	static double calculatePrismVolume(double length, double width, double height) {
		// Volume = length * width * height
		double volume = length * width * height;
		return volume;
	}
}
