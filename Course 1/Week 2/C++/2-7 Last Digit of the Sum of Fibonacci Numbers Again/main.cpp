#include <iostream>
#include <vector>
using namespace std;

vector<uint64_t> fibList; // Fibonacci numbers List
vector<uint64_t> pisanoSequence; // Pisano Sequence list
void generatePisanoSequence(int mod)
{
    fibList.push_back((*(fibList.end()-1) + *(fibList.end()-2)) % mod); // Get the last digits of the next Fibonacci number depending on the modulp.
    pisanoSequence.push_back(*(fibList.end()-1)); //Put the last digit of the last Fibonacci number in the Pisano Sequence
    if (*(pisanoSequence.end() - 1) == 1 && *(pisanoSequence.end() - 2) == 0) // If we return to having 0 then 1 as inputs to the Pisano sequence that mean we have reached the end of the period of the sequence
    {
        pisanoSequence.pop_back();
        pisanoSequence.pop_back();
        return; // Stop Generating entries
    }
    else
    {
        generatePisanoSequence(mod); // Calculate the next entry.
    }
}
int main()
{
    fibList.push_back(0); // Put 0 to the Fibonacci sequence
    fibList.push_back(1); // Put 1 to the Fibonacci sequence
    pisanoSequence.push_back(0); // Put 0 to the Pisano Sequence
    pisanoSequence.push_back(1); // Put 1 to the Pisano sequence
    generatePisanoSequence(10); // An Examplry Modulos of 1000
    uint64_t n, m; // Input Fibonacci numbers
    cin >> n >> m;
    if (m == n) //If the same number entered for both, simply get the last digit of that number/
    {
        m  = m % pisanoSequence.size(); //Find its place in the Pisano sequence
        cout << pisanoSequence[m] % 10; // Get the number and print and its units digits
        return 0;
    }
    if (m > n) swap(m,n); //If m is bigger than n, i.e the second Fibonacci is bigger than the first, swap them.
    n = n + 2; //Get Fn+2
    m = m + 1; //Get Fm+1
    n = n % (pisanoSequence.size()); // Get its position in Pisano Sequence
    m = m % (pisanoSequence.size()); // Get its position in Pisano Sequence
    uint64_t n2 = pisanoSequence[n]; //Get the number
    uint64_t m2 = pisanoSequence[m]; //Get the number
    int64_t z = n2 - m2; //Subtract the numbers to find the partial sum
    z = (z % 10 + 10) % 10; //If negative make it positive because the sum is +ve and the subtraction might yield negative.
    cout << z % 10; // Print the units of the sum

    return 0;
}



