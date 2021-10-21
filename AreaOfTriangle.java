package com.company;

import java.util.Scanner;

public class AreaOfTriangle {
  public static void main(String[] args) {
    System.out.println("Please enter a: ");
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    System.out.println("Please enter b: ");
    int b = in.nextInt();
    System.out.println("Please enter c: ");
    int c = in.nextInt();
    int s = (a + b + c) / 2;
    double area = Math.sqrt(s * ((s + a) * (s + b) * (s + c)));
    System.out.println("Area of triangle is: " + area);
  }
}
