#include <iostream>
#include <vector>
using namespace std;

vector<uint64_t> fibList;
vector<uint64_t> pisanoSequence;
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
    fibList.push_back(0);
    fibList.push_back(1);
    pisanoSequence.push_back(0);
    pisanoSequence.push_back(1);
    generatePisanoSequence(10);
//    for(auto i : fibList)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//    for(auto i : pisanoSequence)
//    {
//        cout << i << " ";
//    }
    uint64_t n;
    cin >> n;
    n = n % (pisanoSequence.size() - 2);
    cout << (pisanoSequence[n] * pisanoSequence[n+1]) % 10;
    return 0;
}
