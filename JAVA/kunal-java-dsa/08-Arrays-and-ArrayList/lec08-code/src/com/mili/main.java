package com.mili;

import java.util.Arrays;

// import javax.swing.JOptionPane;

public class main {
    public static void main(String[] args) {
        int[] rollno = new int[5]; // this forms the array internally as {0, 0, 0, 0, 0}
        // JOptionPane.showMessageDialog(null, rollno[1], "hello",
        // JOptionPane.INFORMATION_MESSAGE);
        System.out.println(rollno[1]);

        String[] arr = new String[4];
        System.out.println(arr[1]); // this prints null
        // String a; // null can be initialized
        // System.out.println(a);

        // for(String[] b : a){
        //     System.out.println(Arrays.toString(b));
        // }

        for (String element : arr) {
            System.out.println(element);
        }
    }
}
