package com.company;

import javax.swing.*;

public class Static4 {
  public static void main(String[] args) {
    // Addition of two number
    String s1, s2;
    s1 = JOptionPane.showInputDialog(null, "Enter first number: ");
    s2 = JOptionPane.showInputDialog(null, "Enter second number: ");

    // Convert it into int
    int a = Integer.parseInt(s1);
    int b = Integer.parseInt(s2);

    // Taking sum of Integer
    int sum = a + b;

    JOptionPane.showMessageDialog(null, "Addition of " + a + " and " + b +
                                            " is " + sum);
  }
}
