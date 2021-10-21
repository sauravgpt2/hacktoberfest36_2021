package com.company;

import java.util.Scanner;

public class NextChar {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        System.out.println("Enter character:");
        char ch = in.next().charAt(0);
        ch++;
        System.out.println(ch);
    }
}
