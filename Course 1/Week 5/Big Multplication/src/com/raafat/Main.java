package com.raafat;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        BigInteger A;
        BigInteger B;
        BigInteger C;
        String a;
        String b;
        Scanner input = new Scanner(System.in);
        a = input.nextLine();
        b = input.nextLine();
        A = new BigInteger(a);
        B = new BigInteger(b);
        C = A.multiply(B);
        System.out.println(C);
    }
}
