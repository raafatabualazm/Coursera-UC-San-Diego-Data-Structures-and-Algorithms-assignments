#include <iostream>
#include <vector>

using namespace std;

int ComputeLCS(vector<int> a, vector<int> b, vector<int> c)
{
    int LCSmap[a.size()+1][b.size()+1][c.size()+1];
    for (int i =0; i < a.size()+1; i++)
    {
        for (int j =0; j < b.size()+1; j++)
        {
            for (int k=0; k < c.size()+1; k++)
            {
            if (i == 0 || j == 0 || k == 0) LCSmap[i][j][k] = 0;
            else if ((a[i-1] == b[j-1]) && (a[i-1] == c[k-1])) LCSmap[i][j][k] = LCSmap[i-1][j-1][k-1] + 1;
            else LCSmap[i][j][k] = max(max(LCSmap[i][j-1][k], LCSmap[i-1][j][k]),LCSmap[i][j][k-1]);
            }

        }
    }
    return LCSmap[a.size()][b.size()][c.size()];

}

int main()
{
    int a, b, c;
    int y;
    vector<int> as, bs, cs;
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
    cin >> c;
    for (int i =0; i < b; i++)
    {
        cin >> y;
        cs.push_back(y);
    }
    cout << ComputeLCS(as, bs, cs);
    return 0;
}
