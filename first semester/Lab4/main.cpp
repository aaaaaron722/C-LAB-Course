#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int num; // number of test cases
    string str;
    cin >> num; 
    for (int i = 0; i < num; i++)
    {
        cin >> str;
        int strLen = str.length();
        int runs = 0;
        int count = 0;
        int c = 0; 
        int Max = 0;
        int numMax = 0;
        int count2 = 0;
        for (int j = 0; j < strLen; j++) //We need to get the elements of the array. 
        {
            if (toupper(str[j]) != toupper(str[j + 1])) // To consider weather upper'char' is equal to lower'char'
                runs += 1; // If not, that means runs be changed
            /*↓ ------------------following is the second part.*/
            if (toupper(str[j]) == toupper(str[j + 1])) // For example, To consider weather the char is the same.
            {
                count += 1; // If yes, then the count + 1
                c = count;
            }
            else if (toupper(str[j]) != toupper(str[j + 1]))//It's means that runs was changed so count should be reset, and record the count.
            {   
                if (c > Max)
                {
                    Max = c;
                }
                count = 0;
            }
        }
        // ↓ -------------the third part
        for (int s = 0; s < strLen; s++)
        {
            if (toupper(str[s]) == toupper(str[s + 1]))
            {
                count2 += 1; 
            }
            else if (toupper(str[s]) != toupper(str[s + 1]))
            {
                count2 = 0; 
            }
            if (Max == count2) 
                numMax += 1;
        }
        cout << "# Number of runs= " << runs << endl;
        cout << "# Longest run length= " << Max + 1 << endl;
        cout << "# Number of longest runs= " << numMax << endl;
    }
    
    return 0;
}
