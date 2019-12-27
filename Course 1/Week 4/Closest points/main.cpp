#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
long double getDistance(pair<int64_t,int64_t> a, pair<int64_t,int64_t> b)
{
    return sqrt(pow((a.first - b.first), (long double)2) + pow((a.second - b.second), (long double)2));

}

long double FindMinDistance(vector<pair<long double,long double>> points)
{
    vector<pair<long double,long double>> vec1;
    vector<pair<long double,long double>> vec2;
    int m = points.size() / 2;
    long double d, d1, d2;
    if (points.size() == 2)
    {
        d = getDistance(points[0], points[1]);
    }
    else
    {
        if (points.size() % 2 == 1)
        {
            for (int i =0; i <m; i++)
            {
                vec1.push_back(points[i]);
            }
            for (int i =m+1; i <points.size(); i++)
            {
                vec2.push_back(points[i]);
            }
            d1 = FindMinDistance(vec1);
            d2 = FindMinDistance(vec2);
            d = min(d1,d2);
        }
        else
        {
            for (int i =0; i <m; i++)
            {
                vec1.push_back(points[i]);
            }
            for (int i =m; i <points.size(); i++)
            {
                vec2.push_back(points[i]);
            }
            d1 = FindMinDistance(vec1);
            d2 = FindMinDistance(vec2);
            d = min(d1,d2);
        }
    }

    return d;
}

int main()
{
    int n;
    int64_t a, b;
    vector<pair<long double,long double>> points;
    vector<long double> lengths;
    cin >> n;
    for (int64_t i =0; i <n; i++)
    {
        cin >> a >> b;
        points.push_back(make_pair(a,b));
    }
    sort(points.begin(), points.end());


    return 0;
}
