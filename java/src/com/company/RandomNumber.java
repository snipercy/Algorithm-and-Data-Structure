package com.company;

import com.jwetherell.algorithms.data_structures.Matrix;

/**
 * Created by ChengYang on 16/5/14.
 */
public class RandomNumber {

    /**
     *
     * @return a random num, 1 <= num <= 5
     */
    public static int rand1to5() {
        return (int)(Math.random() * 5) + 1;
    }

    /**
     * @param m
     * @ return a random num, 1 <= num <= M
     */
    public int rand1toM(int m) {
        return (int)(Math.random() * m) + 1;
    }


    /**
     * 只允许使用 rand1to5 随机函数 产生 1~7 的随机数
     * @return 1~7之间随机数
     */
    public int rand1to7() {
        int num = 0;
        do {
            num = (rand1to5() - 1) * 5 + (rand1to5() - 1);
        } while (num > 20);

        return num % 7 + 1;
    }

    /**
     * 一个随机函数产生0的概率为p,产生1的概率为1-p
     * @return 0 or 1
     */
    public int rand01p() {
        double p = 0.8;
        return Math.random() < p ? 0 : 1;
    }

    /**
     * 如何只使用rand01p()等概率产生0、1随机数
     * 思路: 无论概率p为多少,产生01 和 10 的概率是相等的,概率都未p(1-p)
     * @return 等概率的产生 0 和 1
     */
    public int rand01(){
        int num;
        do {
            num = rand01p();
        } while (num == rand01p());

        return num ==1 ? 1 : 0;
    }

}
