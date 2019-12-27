#include <iostream>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;
    if (n >= 2)
    {


    uint64_t fibList[n+3];
    fibList[0] = 0;
    fibList[1] = 1;
    for (uint64_t i = 2; i < n+3; i++)
    {
        fibList[i] = (fibList[i-1] + fibList[i-2]) % 10;

    }
    cout << fibList[n+2] - 1;
    }
    else
    {
        cout << n;
    }
    return 0;
}



