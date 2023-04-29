package com.mili;

import java.util.Scanner;

public class TypeCasting {
  public static  void main(String[] args){
	// some conditions need to be met to auto convert types , see note2.org
	// Scanner num = new Scanner(System.in);
	// float input = num.nextFloat();
	// System.out.println(input);

	int num = (int)(89.5f);
	System.out.println(num);
  }
}
