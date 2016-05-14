package com.company;

import com.jwetherell.algorithms.data_structures.Matrix;

/**
 * Created by cy on 16/5/14.
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
     * 一个随机函数产生0的概率为p,产生1的概率为1-p
     * @param p 产生0的概率大小
     * @return 0 ro 1
     */
    public int rand0toP(final double p) {
        return Math.random() < p ? 0 : 1;
    }

    /**
     * @return 1到6的随机数
     */
    public int rand1to6(){

    }


}
