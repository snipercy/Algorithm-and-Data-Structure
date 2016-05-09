package com.company;

import java.util.Scanner;

/**
 * Created by cy on 16/5/9.
 */
public class ReverseStr
{
    private static char[] reverse(char[] str)
    {
        int len = str.length;
        int i = 0;
        int j = len - 1;

        while (i < j)
        {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i++;
            j--;
        }
        return str;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine())
        {
            String str = sc.nextLine().toString();
            System.out.println(reverse(str.toCharArray()));
        }
    }
}
