package com.company;

import java.util.Scanner;

public class DeDupAndSort {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = 0;
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            int[] arr = new int[1001];

            for (int i = 0; i < n; i++) {
                arr[sc.nextInt()] = 1;
            }

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == 1) {
                    System.out.println(i);
                }
            }
        }
        sc.close();
    }
}
