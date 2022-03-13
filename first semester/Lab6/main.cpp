#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
using namespace std;

string seed;
int test_cases = 0;
int tap_arr[10];
int length = 0;
int period = 0;
int a = 0;

string lfsr_fib(string bit, int *tap_arr) // After right shift then get a newbits 
{
    int sumtap = 0;
    string newbits = bit;
    for (int i = 0; i < 4; i++) 
    {
        if (newbits[tap_arr[i] - 1] == '1')
            sumtap++;
    }
    for (int i = newbits.length() - 2; i >= 0; i--)
        newbits[i + 1] = newbits[i];

    if (sumtap % 2 == 0 || sumtap == 0) //odd
        newbits[0] = '0';
    else if (sumtap % 2 == 1) // even
        newbits[0] = '1';
    return newbits;
}
int loop_lfsr(string seed) // 算一個a 代表經過a次一個循環
{
    int a = 1;
    string newbits = seed;
    newbits = lfsr_fib(newbits, tap_arr);
    while (newbits != seed)
    {
        newbits = lfsr_fib(newbits, tap_arr);
        a++;
    }
    return a;
}
int main()
{
    cout << "Number of test cases: ";
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        cout << "Length of LFSR: " ;
        cin >> length;
        cout << "Tap bits: ";
        for (int i = 0; i < 5; i++) 
        {
            cin >> tap_arr[i];
            if (tap_arr[i] == 0) 
                break;
            if (cin.get() == '\n')
                break;
        }
        cout << "Seed for LFSR: ";
        cin >> seed;
        cout << "Number of pseudo random numbers needed to be generated: ";
        cin >> period;
        cout << "# Average number of occurrences per pseudo random number: " << period / (pow(2, length)) << endl;
        cout << "# Maximum number of occurrences: " << ceil( double(period) / double(loop_lfsr(seed))) << endl;
        cout << "# Minimum number of occurrences: " << floor( double(period) / double(loop_lfsr(seed))) << endl;
        cout << "# Number of no occurrences: " << pow(2, length) - loop_lfsr(seed) << endl;
    }
    
}


