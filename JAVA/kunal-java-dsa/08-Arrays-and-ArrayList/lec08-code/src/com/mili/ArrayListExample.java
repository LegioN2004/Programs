package com.mili;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListExample {
   public static void main(String[] args) {
      Scanner in = new Scanner(System.in);

      // Syntax
      ArrayList<Integer> list = new ArrayList<>(10);

      // list.add(67);
      // list.add(69);
      // list.add(68);
      // list.add(69);
      // list.add(66);

      // to check if specified no (object) is present here or not
      // System.out.println(list.contains(68)); // this gives true
      // System.out.println(list.contains(90)); // this gives false

      // to replace a present number with another
      // System.out.println(list);
      // list.set(3, 900);

      // to remove a number and replace it with another, use the index no
      // list.remove(2);

      // System.out.println(list);

      for (int i = 0; i < 5; i++) {
         list.add(in.nextInt());
      }

      // get item at any index
      for (int i = 0; i < 5; i++) {
         System.out.println(list.get(i)); // pass the index here, list[index] syntax will not work here
      }

      // print part
      System.out.println(list);
   }
}
