#include <iostream>
#include <vector>
using namespace std;
vector<int64_t> fibList;
vector<int64_t> pisanoSequence;
void generatePisanoSequence(int mod)
{
    fibList.push_back((*(fibList.end()-1) + *(fibList.end()-2)) % mod);
    pisanoSequence.push_back(*(fibList.end()-1));
    if (*(pisanoSequence.end() - 1) == 1 && *(pisanoSequence.end() - 2) == 0)
    {
        return;
    }
    else
    {
        generatePisanoSequence(mod);
    }
}
int main()
{
    uint64_t n;
    cin >> n;
    fibList.push_back(0);
    fibList.push_back(1);
    pisanoSequence.push_back(0);
    pisanoSequence.push_back(1);
    generatePisanoSequence(100);
    n = n % (pisanoSequence.size() - 2);
    cout << abs(pisanoSequence[n+2] -1) % 10;
    return 0;
}
