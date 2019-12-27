#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    uint64_t n;
    cin >> n;
    uint64_t arr[n];
    for (uint64_t i =0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << arr[n-1]*arr[n-2];
    return 0;
}
