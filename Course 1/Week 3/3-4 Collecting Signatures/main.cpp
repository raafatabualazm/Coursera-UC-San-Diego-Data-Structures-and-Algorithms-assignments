#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    vector<int> time;
    cin >> n;
    pair <int,int> times[n];
    for (int i=0; i <n; i++)
    {
        cin >> times[i].first >> times[i].second;
    }

    sort(times, times+n);

    time.push_back(times[0].second);
    for (int i=1; i<n; i++)
    {
        if (!(times[i].first <= *(time.end()-1)))
            {
                time.push_back(times[i].second);

            }
        if (times[i].second <= *(time.end()-1))
        {
            time.pop_back();
            time.push_back(times[i].second);

        }
    }
    cout << time.size() << endl;
    for (int num : time)
    {
        cout << num << " ";
    }
    return 0;
}
