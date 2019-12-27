#include <iostream>

using namespace std;

int main()
{
    int num, counter = 0;
    cin >> num;
    while (num != 0)
    {
        if (num >= 10)
        {
            num-=10;
            counter++;
        }
        else if (num >= 5)
        {
            num-=5;
            counter++;
        }
        else if (num >= 1)
        {
            num-=1;
            counter++;
        }
    }
    cout << counter;
    return 0;
}
