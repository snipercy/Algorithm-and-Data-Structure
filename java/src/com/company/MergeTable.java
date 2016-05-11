package com.company;

import java.util.Scanner;

/**
 * Created by cy on 16/5/11.
 */
public class MergeTable {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lines = sc.nextInt();

        // for store result
        int[] hash = new int[10];

        int key, value;
        while (lines-- > 0)
        {
            key = sc.nextInt();
            value = sc.nextInt();

            hash[key] += value;
        }

        for (int i = 0; i < hash.length; i++) {
            if (hash[i] != 0) {
                System.out.printf("%d %d\n",i,hash[i]);
            }
        }
    }
}
