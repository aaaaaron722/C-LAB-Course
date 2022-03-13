#include<iostream>
using namespace std;

int main()
{
    int number1, number2, number3; // declare three integers
    
    cin >> number1 >> number2 >> number3;
    int first_result = number1 * number2;
        
    if (number2 != 0) // if number2 == 0 , it means some results are not available.
    {
        int second_result = number1 / number2;
        if (number3 != 0)
        {
            int third_result = number2 % number3;
            int fourth_result = number1 + number2 + number3;
            int sum = first_result + second_result + third_result + fourth_result;
            cout << sum << endl;
        }
        else
            cout << "Some results are not available!" << endl;
    }
    else
        cout << "Some results are not available!" << endl;

    return 0;
}

