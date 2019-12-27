package com.raafat;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int a, b;
        String as = "";
        String bs = "";
        String y;
        Scanner scn = new Scanner(System.in);
        a = scn.nextInt();
        for (int i = 0; i < a; i++) {
            y = scn.next();
            as += y;
        }
        b = scn.nextInt();
        for (int i = 0; i < b; i++) {
            y = scn.next();
            bs += y;
        }
        System.out.println(ComputeLCS(as, bs));
    }
    public static int ComputeLCS(String a, String b)
    {
        int[][] LCSmap = new int[a.length()+1][b.length()+1];
        for (int i =0; i < a.length()+1; i++)
        {
            for (int j =0; j < b.length()+1; j++)
            {
                if (i == 0 || j == 0) LCSmap[i][j] = 0;
                else if (a.charAt(i-1) == b.charAt(j-1)) LCSmap[i][j] = LCSmap[i-1][j-1] + 1;
                else LCSmap[i][j] = Math.max(LCSmap[i][j-1], LCSmap[i-1][j]);
            }
        }
        return LCSmap[a.length()][b.length()];

    }
}
