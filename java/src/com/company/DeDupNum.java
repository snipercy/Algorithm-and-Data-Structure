package com.company;

import java.util.Scanner;

/**
 * Created by cy on 16/5/12.
 * 提取不重复的整数
 * 输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
 * eg:  输入: 9876673
 *      输出: 37689
 */
public class DeDupNum {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[10];
        while (sc.hasNextLine())
        {
            String str = sc.nextLine();
            int len = str.length();

            for (int i = len - 1; i >= 0; i--)
            {
                if (arr[str.charAt(i) - '0'] ==0)
                {
                    System.out.printf("%c",str.charAt(i));
                }
                arr[str.charAt(i) - '0']++;
            }
            System.out.printf("\n");
        }
    }
}
