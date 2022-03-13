#include <iostream>
using namespace std;
int insertionSort(int arr[], int number, int &location, int &moves);
int main()
{
    int test_cases = 0;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        int unsorted[100] = {};
        int number = 0;
        int location = 0;
        int moves = 0;
        int data_size = 0;
        cin >> data_size;
        int copy[data_size];
        for (int i = 0; i < data_size; i++)
        {
            cin >> unsorted[i];
            copy[i] = unsorted[i];
        }
        int retInt = insertionSort(unsorted, data_size, location, moves);
        for (int i = 0; i < data_size; i++)
        {
            if (copy[i] == retInt)
                location = i;
        }
        cout << "# " << retInt << ' ' << location << ' ' << moves << endl;
        if (data_size > 1)
        {
            for (int i = 0; i < data_size; i++) // print the insertionSort
            {
                if (i == 0)
                {
                    cout << "# " << unsorted[i] << " ";
                }
                else if (i == data_size - 1 || i == 0)
                {
                    cout << unsorted[data_size - 1] << endl;
                }
                else
                {
                    cout << unsorted[i] << " ";
                }
            }
        }
        else
        {
            cout << "# " << unsorted[0] << endl;
        }
    }
}

int insertionSort(int arr[], int number, int &location, int &moves)
{
    bool found = false;
    for (int i = 1; i < number; i++)
    {
        int key = arr[i];
        int j = i - 1; // previous number
        while (key > arr[j] && j >= 0) // now reading number compared with previous one
        {
            arr[j + 1] = arr[j];
            moves++;
            found = true;
            j--;
        }
        if (found == true)
        {
            arr[j + 1] = key;
            moves++;
        }
        else
            continue;
    }
    // comparison
    int first = arr[0];
    for (int i = 0; i < number; i++)
    {
        if (arr[i] > first)
        {
            first = arr[i];
        }
    }
    
    int second = INT_MIN;
    bool findSec = false;
    for (int i = 0; i < number; i++)
    {
        if ((arr[i] > second && arr[i] < first )|| arr[i] == second)
        {
            second = arr[i];
            findSec = true;
        }
    }
    
    if (findSec == false) // means no second Largest
    {
        second = first;
    }
    
    int third = INT_MIN;
    bool findThd = false;
    for (int i = 0; i < number; i++)
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
    return third;
}
