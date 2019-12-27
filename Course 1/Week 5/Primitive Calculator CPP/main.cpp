#include <iostream>
#include <utility>
#include<vector>
#include <map>

using namespace std;
pair<uint64_t, vector<uint64_t>> primitiveCalc(uint64_t value, map<uint64_t, pair<uint64_t, vector<uint64_t>>> table)
{
    pair<uint64_t, vector<uint64_t>> internalPair;
    vector<uint64_t> out;
    vector<uint64_t> outTemp1;
    vector<uint64_t> outTemp2;
    vector<uint64_t> outTemp3;
    uint64_t temp1 = INT_MAX;
    uint64_t temp2 = INT_MAX;
    uint64_t temp3 = INT_MAX;
    uint64_t res;
    out.push_back(value);
    if (value <= 1)
        return make_pair(0, out);
    else
    {
        if (table.find(value) == table.end())
        {
            if (value % 3 == 0)
            {
                internalPair = primitiveCalc(value/3, table);
                temp1 = internalPair.first;
                outTemp1 = internalPair.second;
            }
            if (value % 2 == 0)
            {
                internalPair = primitiveCalc(value/2, table);
                temp2 = internalPair.first;
                outTemp2 = internalPair.second;
            }
            internalPair = primitiveCalc(value - 1, table);
            temp3 = internalPair.first;
            outTemp3 = internalPair.second;
            res = min(temp1, min(temp2, temp3)) + 1;
            if (res - 1 == temp1)
            {
                out.insert(out.end(), outTemp1.begin(), outTemp1.end());
            }
            else if (res - 1 == temp2)
            {
                out.insert(out.end(), outTemp2.begin(), outTemp2.end());
            }
            else if (res - 1 == temp3)
            {
                out.insert(out.end(), outTemp3.begin(), outTemp3.end());
            }
            pair<uint64_t, vector<uint64_t>> internalPair2 = make_pair(res, out);
            //table.insert(value, internalPair2);
        }
    }
    return table[value];


}

int main()
{

    return 0;
}
