package com.company;

import java.util.Scanner;

public class Check_The_Case {
    public static void main(String[] args)
    {
        //Q.Check the type of character.
        Scanner in = new Scanner(System.in);
        /*What is trim and charAt?
            trim means that are remove all extra spaces that are the end of the word.
            charAt means give me the index of the string its array type*/
        char ch = in.next().trim().charAt(0);

        if(ch > 'a' && ch <= 'z')
        {
            System.out.println("Lowercase");
        }
        else{
            System.out.println("Uppercase");
        }

        System.out.println(ch);
    }
}
