package com.company;

import org.junit.Test;

import static org.junit.Assert.*;

public class RandomNumberTest {

    RandomNumber obj = new RandomNumber();

    @Test
    public void rand1to5() throws Exception {
        int times = 10;
        while (times-- > 0) {
            int randnum = obj.rand1to5();
            assertTrue(randnum <= 5 && randnum >= 1);
            assertFalse(randnum > 5 && randnum < 0);
        }
    }

    @Test
    public void rand1toM() throws Exception {
        int times = 10;
        while (times-- > 0) {
            int m = 10;
            int randnum = obj.rand1toM(m);
            assertTrue(randnum <= m && randnum >= 1);
            assertFalse(randnum > m && randnum < 1);
        }
    }

    @Test
    public void rand01p() throws Exception {
        int times = 10;
        while (times-- > 0) {
            int randnum = obj.rand01p();
            assertTrue(randnum == 0 || randnum == 1);
        }
    }

    @Test
    public void rand01() throws Exception {
        int times = 10000;
        int a = 0;
        int b = 0;
        while (times-- > 0) {
            if (obj.rand01() == 1) {
                a++;
            } else{
                b++;
            }
        }
        System.out.println("a= " + a + "\nb = " + b);
    }


}