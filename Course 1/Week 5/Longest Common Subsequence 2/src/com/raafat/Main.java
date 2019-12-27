package com.raafat;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        int a, b, c;
        ArrayList<Integer> as = new ArrayList<>();
        ArrayList<Integer> bs = new ArrayList<>();
        ArrayList<Integer> cs = new ArrayList<>();
        int y;
        Scanner scn = new Scanner(System.in);
        a = scn.nextInt();
        for (int i = 0; i < a; i++) {
            y = scn.nextInt();
            as.add(y);
        }
        b = scn.nextInt();
        for (int i = 0; i < b; i++) {
            y = scn.nextInt();
            bs.add(y);
        }
        c = scn.nextInt();
        for (int i = 0; i < c; i++) {
            y = scn.nextInt();
            cs.add(y);
        }
        System.out.println(ComputeLCS(as, bs, cs));
    }
    public static int ComputeLCS(ArrayList<Integer> a, ArrayList<Integer> b, ArrayList<Integer> c)
    {
        int[][][] LCSmap = new int[a.size()+1][b.size()+1][c.size()+1];
        for (int i =0; i < a.size()+1; i++)
        {
            for (int j =0; j < b.size()+1; j++)
            {
                for (int k = 0; k <c.size()+1; k++) {
                    if (i == 0 || j == 0 || k ==0) LCSmap[i][j][k] = 0;
                    else if (a.get(i-1) == b.get(j-1) && b.get(j-1) == c.get(k-1)) LCSmap[i][j][k] = LCSmap[i-1][j-1][k-1] + 1;
                    else LCSmap[i][j][k] = Math.max(Math.max(LCSmap[i][j-1][k], LCSmap[i-1][j][k]), LCSmap[i][j][k-1]);
                }

            }
        }
        return LCSmap[a.size()][b.size()][c.size()];

    }
}
