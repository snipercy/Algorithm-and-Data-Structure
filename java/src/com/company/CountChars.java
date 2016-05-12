package com.company;

import java.util.Scanner;

/**
 * Created by cy on 16/5/12.
 * 字符个数统计
 * 编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
 */
public class CountChars {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine())
        {
            int[] arr = new int[128];
            String line = sc.nextLine();
            int len = line.length();
            int cnt = 0;

            for (int i = 0; i < len; i++)
            {
                if (arr[line.charAt(i)] ==0)
                {
                    cnt++;
                }
                arr[line.charAt(i)]++;
            }
            System.out.printf("%d\n", cnt);
        }
    }
}
