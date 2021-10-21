package com.company;

import java.util.Scanner;

public class ValidTraingle {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter Three Site of Triangle: ");
        double a = in.nextDouble();
        double b = in.nextDouble();
        double c = in.nextDouble();
        if(a+b>c && a+c>b && b+c>a){
            System.out.println("Valid Triangle.");
        }else{
            System.out.println("Invalid Triangle.");
        }
    }
}
