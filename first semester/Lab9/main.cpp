#include <iostream>
#include <string>
using namespace std;
void solution(int len, string str);
int main()
{
    string str;
    int test_cases = 0;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> str;
        int len = str.length();
        solution(len, str);
    }
}
void solution(int len, string str)
{
    int count = 1;
    for (int i = 0; i < len; i++)
    {                            // A a , a A
        if (i == 0)
            cout << "# " << str[i];
        if (str[i] == str[i + 1] || str[i] + 32 == str[i + 1] || str[i] - 32 == str[i + 1]) 
            count++;
        else
            count = 1;
        if (count == 2)
            cout << str[i + 1];
        else if (count == 1) 
            cout << str[i + 1];
        else  
            continue;  
        if (i == len - 1)
            cout << endl;
    }
}
