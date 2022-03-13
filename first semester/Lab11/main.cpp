#include <iostream>
#include <string>
using namespace std;

void sortFunc(int intList[], int number);
void sortFunc(double doubleList[], int number);
void sortFunc(string strList[], int number);

template <typename T>
void sortFuncTempt(T anAry[], int eleNum)
{
    T temp = anAry[0];
    for (int j = eleNum - 1; j > 0; j--)
    {
        for (int i = 0; i <= j - 1; i++)
        {
            if (anAry[i + 1] > anAry[i])
            {
                temp = anAry[i];
                anAry[i] = anAry[i + 1];
                anAry[i + 1] = temp;
            }
        }
    }
    
}
template <typename T>
void printArray(T eleList[], int eleNum)
{
    for (int i = 0; i < eleNum; i++)
    {
        if (i % 10 == 0)
        {
            cout <<  "#";
        }
        cout << " " << eleList[i];
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    if (eleNum % 10 != 0)
    {
        cout << endl;
    }
}

int main()
{
    int test_cases;
    int intList[100] = {};
    double doubleList[100] = {};
    string strList[100] = {};
    
    int eleNum = 0; //element number
    string dataType;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> dataType;
        cin >> eleNum;
        if (dataType == "int")
        {
            for (int i = 0; i < eleNum; i++)
            {
                cin >> intList[i];
            }
            sortFuncTempt(intList, eleNum);
            printArray(intList, eleNum);
            sortFunc(intList, eleNum);
            printArray(intList, eleNum);
        }
        else if (dataType == "double")
        {
            for (int i = 0; i < eleNum; i++)
            {
                cin >> doubleList[i];
            }
            sortFuncTempt(doubleList, eleNum);
            printArray(doubleList, eleNum);
            sortFunc(doubleList, eleNum);
            printArray(doubleList, eleNum);
        }
        else
        {
            for (int i = 0; i < eleNum; i++)
            {
                cin >> strList[i];
            }
            sortFuncTempt(strList, eleNum);
            printArray(strList, eleNum);
            sortFunc(strList, eleNum);
            printArray(strList, eleNum);
        }
        cout << endl;
    }
    return 0;
}
void sortFunc(int intList[], int number)
{
    int temp;
    for (int j = number - 1; j > 0; j--)
    {
        for (int i = 0; i <= j - 1; i++)
        {
            if (intList[i] > intList[i + 1])
            {
                temp = intList[i];
                intList[i] = intList[i + 1];
                intList[i + 1] = temp;
            }
        }
    }
}
void sortFunc(double doubleList[], int number)
{
    double temp;
    for (int j = number - 1; j > 0; j--)
    {
        for (int i = 0; i <= j - 1; i++)
        {
            if (doubleList[i] > doubleList[i + 1])
            {
                temp = doubleList[i];
                doubleList[i] = doubleList[i + 1];
                doubleList[i + 1] = temp;
            }
        }
    }
    
}
void sortFunc(string strList[], int number)
{
    string temp;
    for (int j = number - 1; j > 0; j--)
    {
        for (int i = 0; i <= j - 1; i++)
        {
            if (strList[i] > strList[i + 1])
            {
                temp = strList[i];
                strList[i] = strList[i + 1];
                strList[i + 1] = temp;
            }
        }
    }
    
}
