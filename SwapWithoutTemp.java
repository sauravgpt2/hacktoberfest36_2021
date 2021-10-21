package com.company;

import java.util.Scanner;

public class SwapWithoutTemp {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Please enter first number: ");
    int a = in.nextInt();
    System.out.println("Please enter second number: ");
    int b = in.nextInt();
    a = a + b;
    b = a - b;
    a = a - b;
    System.out.println("After swapping first number is: " + a);
    System.out.println("After swapping second number is: " + b);
  }
}
