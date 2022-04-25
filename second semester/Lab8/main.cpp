#include <iostream>
#include <cctype>
using namespace std;
class HugeInt
{
    friend ostream & operator<<(ostream &, const HugeInt &);
public:
    static const int digits = 30;
    HugeInt(long = 0);
    HugeInt(const string &);

    HugeInt operator+(const HugeInt &)const;
    HugeInt operator+(int)const;
    HugeInt operator+(const string &)const;
private:
    short integer[ digits ];
};
HugeInt::HugeInt(long value)
{
    for(int i = 0 ; i < digits ; i++)
        integer[i] = 0;
    for(int i = digits - 1; value != 0 && i >= 0; i--)
    {
        integer[i] = value % 10;
        value /= 10; 
    }
}

HugeInt::HugeInt(const string &number)
{
    for(int i = 0 ; i < digits ; i++)  
        integer[i] = 0;
    int len = number.size();
    for(int i = digits - len, k = 0; i < digits; i++, k++)
    {
        if(isdigit(number[k]))
            integer[i] = number[k] - '0';
    }
}

HugeInt HugeInt::operator+(const HugeInt &op2)const
{
    HugeInt temp;
    int carry = 0;
    for(int i = digits - 1; i >= 0; i--)
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;

        if(temp.integer[i] > 9)
        {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
            carry = 0;
    }
}

HugeInt HugeInt::operator+(int op2)const
{
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+(const string &op2)const
{
    return *this + HugeInt(op2);
}
ostream & operator<<(ostream &output, const HugeInt &number)
{
    int i;
    for(int i = 0 ; (number.integer[i] == 0) && (i <= HugeInt::digits); i++){;}
    if(i == HugeInt::digits) 
        output << 0;
    else
        for(; i < HugeInt::digits; i++)
            output << number.integer[i];
    return output;
}
int main()
{
    HugeInt n1(87654321);
    HugeInt n3("9999999999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5(n4);
    cout << "n1 is " << n1 << "\nn3 is " << n3 
    << "\nn4 is " << n4 << "\nn5 is " << n5 << "\n\n";
    cout << "n3 is " << n3 << endl;
    HugeInt n6;
    cout << "n6 = " << n6 << endl;
    cout << "n6 = n3 + n4 = " << n3 << "+" << n4 << "="
    << n3 + n4 << "\n\n";
    cout << "9 + n1 = " << 9 + n1 << " " << "9" + n1 << " "
    << n1 + 9 << endl;
    cout << "n4 + 100 + 900 + n5 = " << n4 + 100 +"900"+n5 << endl;

    cout << "n3++= " << n3++ << endl;
    cout << "n3= " << n3 << endl;
    cout << "++n3 = " << ++n3 << endl;
    cout << "n3 = " << n3 << endl;
    n3+= 119;
    cout << "n3=+119: " << n3 << endl;
    HugeInt n7, n8, n9;
    n7 = 1000000001;
    n8 = "10000000000000000000000000000000000000000000009";
    n9 = n6 + n4;
    cout << "n7 = " << n7 << " n8 = " << n8 << " n9 = " << n9 << endl;
    cout << "\nn7+n8+n9 = " << n7+n8+n9 << endl;
    cout << "\nTotal number of digits = " << n1.getNumDigits()+n3.getNumDigits()+n4.getNumDigits()+
    n5.getNumDigits()+n6.getNumDigits()+n7.getNumDigits()+n8.getNumDigits()+n9.getNumDigits() << endl;
    if(n3 <= n1)
        cout << "\nyes - 1" << endl;
    else
        cout << "\nno - 1" << endl;
    if(n3 <= 100)
        cout << "yes - 2" << endl; 
    else
        cout << "no - 2" << endl;
    if(100 <= n3)
        cout << "yes - 3" << endl;
    else 
        cout << "no - 3" << endl;
    if(n3 <= "100")
        cout << "yes - 4" << endl;
    else
        cout << "no - 4" << endl;
    if("100" <= n3)
        cout << "yes - 5" << endl;
    else
        cout << "no - 5" << endl;
    if(n3 <= n3)
        cout << "yes - 6" << endl;
    else
        cout << "no - 6" << endl;
    return 0;
}
