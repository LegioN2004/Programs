package com.mili;

public class reverseNo {
    public static void main(String[] args) {
        System.out.println("Kunal's version of reverse a No problem ");
        int num = 28479;
        int ans = 0;
        while (num > 0) {
            int rem = num % 10; // 9
            num /= 10; // 2847
            ans = ans * 10 + rem; // 90 + 7  
        }
        System.out.print(ans);
    }
}
