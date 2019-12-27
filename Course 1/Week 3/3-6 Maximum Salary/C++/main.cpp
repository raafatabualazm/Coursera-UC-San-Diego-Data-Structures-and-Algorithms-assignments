#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include <utility>
using namespace std;

bool sortAlg(string num1, string num2)
{
    string num3 = num1.append(num2);
    string num4 = num2.append(num1);

    return num3.compare(num4) > 0 ? true:false;
}

int main()
{
    string num = "-1";
    int n;
    cin >> n;
    vector<string> numbers2;
    while (num != NULL)
    {
        cin >> num;
        numbers2.push_back(num);
    }
    sort(numbers2, numbers2+n, sortAlg);

    for (auto i: numbers2)
    {
        cout << i;
    }
    return 0;
}
