package com.company;

import java.util.Scanner;

public class IntCalculator {
    public  static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Two Numbers to Calculate Sum:");
        int fno = sc.nextInt();
        int sno = sc.nextInt();
        float sum;
        sum = fno + sno;
        System.out.println("Sum of two number is:" + sum);
    }
}
