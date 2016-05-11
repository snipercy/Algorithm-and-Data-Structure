package com.company;

import java.util.*;

/**
 * Created by cy on 16/5/11.
 * 功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
 */
public class PrimeFactor {

    public static String getResult(long ulDataInput)
    {
        StringBuffer strbuf = new StringBuffer();

        while (ulDataInput > 1)
        {
            for (int i = 2; i <= ulDataInput; i++)
            {
                if ( ulDataInput % i == 0 )
                {
                    ulDataInput /= i;
                    strbuf.append(i).append(' ');
                    break;
                }
            }
        }

        return strbuf.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long in = sc.nextLong();

        if (in < 2) {
            sc.close();
            return;
        }

        String res = getResult(in);
        System.out.println(res);
        sc.close();
    }
}
