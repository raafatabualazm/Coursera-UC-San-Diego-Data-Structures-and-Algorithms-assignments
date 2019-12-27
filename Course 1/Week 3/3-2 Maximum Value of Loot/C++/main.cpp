#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool sortAlg(pair<double, pair<uint64_t,uint64_t>> item1, pair<double, pair<uint64_t,uint64_t>> item2)
{
    return (item1.first >= item2.first);
}
int main()
{
    uint64_t n, index = 0;
    double W, val;
    cin >> n >> W;
    pair<double, pair<uint64_t,uint64_t>> items[n];
    for (int i=0; i <n; i++)
    {
        cin >> items[i].second.first >> items[i].second.second;
        items[i].first =  (double)items[i].second.first / (double)items[i].second.second;
    }
    sort(items,items+n, sortAlg);
//    for (int i=0; i <n; i++)
//    {
//       cout << items[i].first << " " << items[i].second.first << " " << items[i].second.second << endl;
//    }
    while(W > 0 && n > 0)
    {
        if (items[index].second.second <= W)
        {

            val += items[index].second.first;
            W -= items[index].second.second;
            index++;
            n--;
        }
        else
        {
            val += items[index].first * W;
            W = 0;
            index++;
            n--;
        }
    }
    printf("%.4f",val);
    return 0;
}
