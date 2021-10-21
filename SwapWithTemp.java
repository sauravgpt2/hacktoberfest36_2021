package com.company;

import java.util.Scanner;

public class SwapWithTemp {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Please enter first number: ");
    int num1 = in.nextInt();
    System.out.println("Please enter second number: ");
    int num2 = in.nextInt();
    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
    System.out.println("After swapping first number is: " + num1);
    System.out.println("After swapping second number is: " + num2);
  }
}
