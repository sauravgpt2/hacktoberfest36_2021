package com.company;

import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
 //Take input from user till user does not press
        Scanner in = new Scanner(System.in);
        int ans = 0;
            while (true) {
                //take operator as input
                System.out.println("Enter the operator:");
                char op = in.next().trim().charAt(0);
                if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {

                    //input the no
                    System.out.println("Enter two numbers:");
                    int num1 = in.nextInt();
                    int num2 = in.nextInt();

                    if (op == '+') {
                        ans = num1+num2;
                    }
                    if (op == '-') {
                        ans = num1-num2;
                    }
                    if (op == '*') {
                        ans = num1*num2;
                    }
                    if (op == '/') {
                        if (num2 != 0)
                        {
                            ans = num1/num2;
                        }
                    }
                    if (op == '%') {
                        ans = num1%num2;
                    }

                }else if(op == 'x' || op == 'X')
                {
                    break;
                }else{
                    System.out.println("Invalide operation!");
                }
                System.out.println("Ans is:" +ans);
        }

    }
}
