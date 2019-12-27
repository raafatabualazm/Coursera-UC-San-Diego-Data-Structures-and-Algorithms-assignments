#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int64_t s,p,a,b, counter = 0;
    vector<pair<int64_t,int64_t>> lengths;
    vector<int64_t> points;
    pair<int64_t,int64_t> myInput;
    map<int64_t,int64_t> counts;
    cin >> s >> p;
    for (int64_t i =0; i < s; i++)
    {
        cin >> a >> b;
        myInput = make_pair(a,1);
        lengths.push_back(myInput);
        myInput = make_pair(b,3);
        lengths.push_back(myInput);
    }
    for (int64_t i =0; i < p; i++)
    {
        cin >> a;
        points.push_back(a);
        myInput = make_pair(a,2);
        lengths.push_back(myInput);
    }
    sort(lengths.begin(),lengths.end());
    for (auto memb : lengths)
    {
        if (memb.second == 1) counter++;
        else if (memb.second == 3) counter--;
        else if (memb.second == 2)
        {
            if (counter < 0) counter = 0;
            counts[memb.first] = counter;
        }
    }
    for (auto point: points)
    {
        cout << counts[point] << " ";
    }
    return 0;
}
