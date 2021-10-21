package com.company;

import java.util.Scanner;

public class Calculator_of_two_Numbe {
    public static void main(String[] args)
    {
        char operation;
        Scanner op = new Scanner(System.in);
        int a = 15;
        int b = 20;

        operation = op.next().charAt(0);

        if(operation == '+')
        {
            System.out.println(a + b);
        }
        else if(operation == '-')
        {
            System.out.println(a - b);
        }
        else if(operation == '*')
        {
            System.out.println(a * b);
        }
        else if(operation == '/')
        {
            System.out.println(a / b);
        }
        else
        {
            System.out.println("Please check the input.");
        }



    }
}
