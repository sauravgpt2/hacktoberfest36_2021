package com.company;

class Class2{
    int a = 10;
    final int b = 20;
    final int c = 30;
    void fun(){
        System.out.println("Non-static method!");
    }
}
public class NonStatic1 {
    public static void main(String[] args) {
        Class2 obj = new Class2();
        System.out.println(obj.a);
        System.out.println(obj.b);
        System.out.println(obj.c);
        obj.fun();
        obj.a = 30;
//        obj.b = 30;
//        obj.c = 30;//Error
    }
}
