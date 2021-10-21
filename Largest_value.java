package com.company;

import java.util.Scanner;

public class Largest_value {
    public static void main(String[] args)
    {
        int a,b;
        Scanner op = new Scanner(System.in);
        System.out.println("Please enter two numbers:");
        a = op.nextInt();
        b = op.nextInt();
        if(a>b){
            System.out.println("the largest number is: " +a );
        }
        if(a<b){
            System.out.println("the largest number is: " +b );
        }
        if(a==b){
            System.out.println("both are similler." );
        }
    }
}
