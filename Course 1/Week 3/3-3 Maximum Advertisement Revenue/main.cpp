#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int64_t n, input, output = 0;
    cin >> n;
    int64_t ads[n]; //Revenue per click for ith ad
    int64_t clicks[n]; //Avergae number of clicks of ith slot
    for (int i=0; i < n; i++)
    {
        cin >> input;
        ads[i] = input;
    }
    for (int i=0; i < n; i++)
    {
        cin >> input;
        clicks[i] = input;
    }
    sort(ads,ads+n);
    sort(clicks,clicks+n);
    for (int i=0; i < n; i++)
    {
        output += ads[i]*clicks[i];
    }
    cout << output;
    return 0;
}
