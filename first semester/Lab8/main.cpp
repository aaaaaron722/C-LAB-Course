#include <iostream>
using namespace std;

void solution(int arr[], int arr_size)
{
    int first = arr[0];
    int location = 1;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > first)
        {
            first = arr[i];
            location = i + 1;
        }
    }
    
    int second = INT_MIN;
    bool findSec = false;
    for (int i = 0; i < arr_size; i++)
    {
        // the first time it will run this condition (arr[i] > second && arr[i] < first)
        // the next time it will run (arr[i] == second)
        // reprsent 2 distinctive number
        if ((arr[i] > second && arr[i] < first )|| arr[i] == second)
        {
            second = arr[i];
            location = i + 1;
            findSec = true;
        }
    }
    
    if (findSec == false) // means no second Largest
    {
        second = first;
    }
    
    int third = INT_MIN;
    bool findThd = false;
    for (int i = 0; i < arr_size; i++)
    {
        // represent 3 distinctive number
        if ((arr[i] > third && arr[i] < second )|| arr[i] == third)
        {
            third = arr[i];
            location = i + 1;
            findThd = true;
        }
    }
    if (findThd == false)
    {
        third = second;
    }
    
    cout << "# " << third << " " << location << endl;
}

int main()
{
    int test_cases = 0;
    cout << "test_cases: " ;
    cin >> test_cases;
    int arr[100];
    for (int i = 0; i < test_cases; i++)
    {
        int arr_size = 10;
        for (int j = 0; j < arr_size; j++)
        {
            if (j == 0) 
            {
                cin >> arr_size >> arr[j];
            }
            else
            {
                cin >> arr[j];
            }
        }
        solution(arr, arr_size);

    }
}

