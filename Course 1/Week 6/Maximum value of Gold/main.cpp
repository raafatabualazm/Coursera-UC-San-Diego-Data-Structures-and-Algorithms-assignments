#include <bits/stdc++.h>

using namespace std;
int solve(uint64_t W, uint64_t n, int weights[])
{
    int dpw[n+1][W+1];
    for (uint64_t i = 0; i <= n; i++)
   {

       for (uint64_t w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               dpw[i][w] = 0;
           else if (weights[i] <= w)
                 dpw[i][w] = max(weights[i] + dpw[i-1][w-weights[i]],  dpw[i-1][w]);
           else
                 dpw[i][w] = dpw[i-1][w];
       }
   }

   return dpw[n][W];
}
int main()
{
    uint64_t w, n;
    cin >> w >> n;
    int weights[n + 1];
    weights[0] = 0;
    for (uint64_t i =0; i <n; i++) cin >> weights[i];
    sort(weights, weights + n + 1);
    cout << solve(w, n, weights);
    return 0;
}
