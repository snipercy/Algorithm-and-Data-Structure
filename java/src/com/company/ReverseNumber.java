package com.company;

import java.util.Scanner;

/**
 * Created by cy on 16/5/13.
 */
public class ReverseNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            int len = line.length();

            StringBuffer res = new StringBuffer();
            for (int i = len - 1; i >=0 ; i--) {
                res.append(line.charAt(i));
            }

            System.out.println(res);
        }

    }
}
