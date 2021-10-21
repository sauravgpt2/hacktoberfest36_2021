package com.company;

import java.util.Scanner;

public class Currency_converter {
    public static void main(String[] args)
    {
        float rup;
        Scanner ip = new Scanner(System.in);
        rup = ip.nextFloat();
        float usd = rup / 75;
        System.out.println(usd);
    }
}
