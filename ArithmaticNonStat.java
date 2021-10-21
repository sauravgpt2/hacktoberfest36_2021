package com.company;

import java.util.Scanner;

public class ArithmaticNonStat {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter first no: ");
        int num1 = in.nextInt();
        System.out.println("Enter Second no: ");
        int num2 = in.nextInt();
        System.out.println("Addition = " +(num1+num2));
        System.out.println("Substraction = " +(num1-num2));
        System.out.println("Multiplication = " +(num1*num2));
        System.out.println("Division = " +(num1/num2));
    }

}
