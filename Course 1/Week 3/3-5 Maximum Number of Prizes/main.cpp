#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int change;
    int changed;
    int num;
    int subtract = 0;
    vector<int> nums;
    cin >> num;
    while (true)
    {
        subtract++;
        num -= subtract;
        nums.push_back(subtract);
        if (num < 0)
        {
            nums.pop_back();
            num = abs(num);
            change = subtract - num;
            change = abs(change);
            changed = change + *(nums.end()-1);
            nums.pop_back();
            nums.push_back(changed);
            break;
        }
        if (num == 0)
        {
            break;
        }

    }
    cout << nums.size() << endl;
    for (int ele : nums)
    {
        cout << ele << " ";
    }
    return 0;
}
