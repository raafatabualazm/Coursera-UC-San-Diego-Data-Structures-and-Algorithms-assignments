#include <iostream>
#include <vector>

using namespace std;

int ComputeLCS(vector<int> a, vector<int> b)
{
    int LCSmap[a.size()+1][b.size()+1];
    for (int i =0; i < a.size()+1; i++)
    {
        for (int j =0; j < b.size()+1; j++)
        {
            if (i == 0 || j == 0) LCSmap[i][j] = 0;
            else if (a[i-1] == b[j-1]) LCSmap[i][j] = LCSmap[i-1][j-1] + 1;
            else LCSmap[i][j] = max(LCSmap[i][j-1], LCSmap[i-1][j]);
        }
    }
    return LCSmap[a.size()][b.size()];

}

int main()
{
    int a, b;
    int y;
    vector<int> as, bs;
    cin >> a;
    for (int i =0; i < a; i++)
    {
        cin >> y;
        as.push_back(y);
    }
    cin >> b;
    for (int i =0; i < b; i++)
    {
        cin >> y;
        bs.push_back(y);
    }
    cout << ComputeLCS(as, bs);
    return 0;
}
