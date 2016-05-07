package com.company;

import java.util.Scanner;

/**
 * Created by cy on 16/5/7.
 * input:abc
 *       123456789
 * output:abc00000
 *        12345678
 *        90000000
 */
public class SubString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            String str = sc.next();
            while (str.length() >= 8) {
                System.out.println(str.substring(0,8));
                str = str.substring(8);
            }
            if (str.length() > 0 && str.length() < 8) {
                str += "00000000";
                System.out.println(str.substring(0,8));
            }
       }
        sc.close();
    }
}
