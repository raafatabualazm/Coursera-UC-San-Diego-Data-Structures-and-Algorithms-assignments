#include <iostream>

using namespace std;
uint64_t rem;
uint64_t gcdCalc(uint64_t a, uint64_t b)
{
    if (b == 0) return a;
    if (b > a) swap(a,b);
    rem = a % b;
    gcdCalc(b, rem);
}

int main()
{
    uint64_t m, n;
    cin >> n >> m;
    cout << gcdCalc(m,n);
    return 0;
}
