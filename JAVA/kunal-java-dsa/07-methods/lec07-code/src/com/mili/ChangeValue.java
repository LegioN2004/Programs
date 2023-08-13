package com.mili;

import java.util.Arrays;

public class ChangeValue {
	public static void main(String[] args) {
		// array will be taught in the next vid
		// create an array(more on that in the next video), for now array is just a data
		// structure having a collection of something
		// say an integer array will contain a data structure having a collection of
		// integers, string is a collection of letters/ characters

		int[] arr = { 1, 3, 2, 45, 6 };
		change(arr);
		System.out.println(Arrays.toString(arr)); // toString() takes just an integer array and returns the string value
													// of it
	}

	// the question was will the 0th index value change or not. Since this type of
	// function call creates a copy of the object and the original one remains
	// intact so the 0th index value will not change
	static void change(int[] nums) { // passing an array with the nums variable
		nums[0] = 99; // nums[0], here 0 is the index number, since arrays start from the 0th index as
						// the position number and here we want to change the 0th index value to 99
		// if you make a change to the object via this reference variable same object
		// will be changed
	}
}
