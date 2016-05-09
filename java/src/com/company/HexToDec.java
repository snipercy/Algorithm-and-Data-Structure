package com.company;

import java.util.Scanner;

/**
 * 进制转换
 */
public class HexToDec {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            String str = sc.nextLine();
            int len = str.length();
            long res = 0;
            int bit = 0;
            for (int i = len - 1; i >= 2 ; i--) {
                if (str.charAt(i) <= '9' && str.charAt(i) >= '0') {
                    res += (str.charAt(i) - '0') * Math.pow(16, bit);
                } else {
                    res += (10 + str.charAt(i) - 'A') * Math.pow(16, bit);
                }
                bit++;
            }
            System.out.println(res);
        }
    }
}
