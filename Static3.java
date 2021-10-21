package com.company;

import javax.swing.*;

public class Static3 {
  public static void main(String[] args) {
    String name = JOptionPane.showInputDialog(null, "Please enter your name: ");
    JOptionPane.showMessageDialog(null, "Welcome " + name);
  }
}
