#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int rollDice();
int crapsFunc();
double probability(int times , int i);
double time();
int findMax();

enum status{CONTINUE, WON, LOST};
status gamestatus;
int myPoint;
double prob[20];
clock_t t1, t2;

int main()
{
    int times;
    cout << "Enter the number of times of Craps games to be played: ";
    cin >> times;
    for (int i = 0 ; i < 20 ; ++i)
    {
        srand(time(0));
        cout << "[R" << i + 1 << "] Win probability = " << probability(times , i) << "  Time elapsed: " << time() << " " << "seconds" << endl;
        cout << "     Continue to play? (Y or y for yes): ";
        if (cin.get() == 'Y' || cin.get() == 'y')
            continue;
        else
            break;
    }
    cout << "[OUT]" << " " << "The best win probability = " << prob[findMax()] << " obtained at R" << findMax() + 1 << endl;
    cout << "[OUT]" << " " << "Score = " << 100 - abs(1.0 - prob[findMax()] / 0.65) * 1000 << endl;
}

double probability(int times , int i)
{
    double average = 0;
    double sum = 0;
    for (int i = 0; i < times ; ++i)
    {
        average = double(crapsFunc()) / double(times);
        sum += average;
    }
    prob[i] = sum;
    return sum;
}
double time()
{
    t1 = clock();
    crapsFunc();
    t2 = clock();
    double diff = (double)t2 - (double)t1;
    return diff;
}
int crapsFunc()
{
    int x = 0;
    int sumOfDice = rollDice();
    switch (sumOfDice)
    {
        case 7:
        case 11:
        case 6:
        case 8:
        case 1:
            gamestatus = WON;
            x++;
            break;
        case 2:
        case 3:
        case 12:
            gamestatus = LOST;
            break;
        default:
            gamestatus = CONTINUE;
            myPoint = sumOfDice;
            break;
    }
    while (gamestatus == CONTINUE)
    {
        sumOfDice = rollDice();
        if (sumOfDice == myPoint)
        {
            gamestatus = WON;
            x++;
            break;
        }
        else
            if (sumOfDice == 7)
            {
                gamestatus = LOST;
                break;
            }
    }
    return x;
}

int rollDice()
{
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    int sum = die1 + die2;
    return sum;
}

int findMax()
{
    double Max = 0;
    int record = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (prob[i] > Max)
        {
            Max = prob[i];
            record = i;
        }
    }
    return record;
}

