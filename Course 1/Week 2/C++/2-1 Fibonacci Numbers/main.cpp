#include <iostream>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;
    uint64_t fibList[n+1];
    fibList[0] = 0;
    fibList[1] = 1;
    for (uint64_t i = 2; i < n+1; i++)
    {
        fibList[i] = fibList[i-1] + fibList[i-2];
    }
    cout << fibList[n];
    return 0;
}
