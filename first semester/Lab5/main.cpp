#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string str;
    char vewel_arr[10] = {'a', 'e', 'i', 'o', 'u',
                        'A', 'E', 'I', 'O', 'U'};
    int fir_letter = 0;
    int num_word = 0;
    int len = 0;
    int repeated = 0;
    int count0 = 0, count1 = 0, count2 = 0,
        count3 = 0, count4 = 0, count5 = 0,
        count6 = 0, count7 = 0, count8 = 0,
        count9 = 0, count10 = 0, count11 = 0,
        count12 = 0, count13 = 0, count14 = 0,
        count15 = 0;
    int countA = 0, countB = 0, countC = 0, countD = 0,
        countE = 0, countF = 0, countG = 0, countH = 0,
        countI = 0, countJ = 0, countK = 0, countL = 0,
        countM = 0, countN = 0, countO = 0, countP = 0,
        countQ = 0, countR = 0, countS = 0, countT = 0,
        countU = 0, countV = 0, countW = 0, countX = 0,
        countY = 0, countZ = 0;

    while (cin >> str)
    {
        for (int x = 0;x<str.length();x++)
        {
          if (str[x] >= 65 && str[x] <= 90 || str[x] >= 97 && str[x] <= 122)
          {
            num_word++;
            break;
          }
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 33 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 126)//ignore operations
                continue;
            switch (str[i])
            {
                case 'A': case 'a':
                case 'E': case 'e':
                case 'I': case 'i':
                case 'O': case 'o':
                case 'U': case 'u':
                fir_letter++;
                break;
            }
            break;
        }
        len = str.length();
        bool found = false;
        for (int j = 0; j < len; j++)
        {
            if (str[j] >= 33 && str[j] <= 64 || str[j] >= 91 && str[j] <= 96 || str[j] >= 123 && str[j] <= 126)
                continue;
            for (int y = j; y < len; y++)
            {
                if (y != j && str[j] == str[y] || str[j] + 32 == str[y])
                {
                    repeated ++;
                    found = true;
                    break;
                }
            }
            if (found == true)
                break;
        }
        int x = 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= 33 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 126)
                x++;
        }
        switch (len - x)
        {
            case 0: count0++; break;
            case 1: count1++; break;
            case 2: count2++; break;
            case 3: count3++; break;
            case 4: count4++; break;
            case 5: count5++; break;
            case 6: count6++; break;
            case 7: count7++; break;
            case 8: count8++; break;
            case 9: count9++; break;
            case 10: count10++; break;
            case 11: count11++; break;
            case 12: count12++; break;
            case 13: count13++; break;
            case 14: count14++; break;
            case 15: count15++; break;
            default: count15++; break;
        }

        for (int i = 0; i < len; i++)
        {
            int stop = -1;
            if (str[i] >= 33 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 126)
                continue;

            switch (str[i])
            {
                case 'A': case 'a': countA++; stop = 1; break;
                case 'B': case 'b': countB++; stop = 1; break;
                case 'C': case 'c': countC++; stop = 1; break;
                case 'D': case 'd': countD++; stop = 1; break;
                case 'E': case 'e': countE++; stop = 1; break;
                case 'F': case 'f': countF++; stop = 1; break;
                case 'G': case 'g': countG++; stop = 1; break;
                case 'H': case 'h': countH++; stop = 1; break;
                case 'I': case 'i': countI++; stop = 1; break;
                case 'J': case 'j': countJ++; stop = 1; break;
                case 'K': case 'k': countK++; stop = 1; break;
                case 'L': case 'l': countL++; stop = 1; break;
                case 'M': case 'm': countM++; stop = 1; break;
                case 'N': case 'n': countN++; stop = 1; break;
                case 'O': case 'o': countO++; stop = 1; break;
                case 'P': case 'p': countP++; stop = 1; break;
                case 'Q': case 'q': countQ++; stop = 1; break;
                case 'R': case 'r': countR++; stop = 1; break;
                case 'S': case 's': countS++; stop = 1; break;
                case 'T': case 't': countT++; stop = 1; break;
                case 'U': case 'u': countU++; stop = 1; break;
                case 'V': case 'v': countV++; stop = 1; break;
                case 'W': case 'w': countW++; stop = 1; break;
                case 'X': case 'x': countX++; stop = 1; break;
                case 'Y': case 'y': countY++; stop = 1; break;
                case 'Z': case 'z': countZ++; stop = 1; break;
                default:
                    break;
            }
            if (stop == 1)
                break;
        }
    }


    cout << "# Total number of words which has at least a letter: " << num_word << endl;
    cout << "# Total number of words whose first letter is a vowel: " << fir_letter << endl;
    cout << "# Total number of words which contain some letter repeated at least twice: " << repeated << endl;
    cout << "# Distribution of words by word length: " << endl;
    cout << "# L0 = " << count0 << '\n' << "# L1 = " << count1 << '\n' << "# L2 = " << count2 << '\n'
        << "# L3 = " << count3 << '\n' << "# L4 = " << count4 << '\n' << "# L5 = " << count5 << '\n'
        << "# L6 = " << count6 << '\n' << "# L7 = " << count7 << '\n' << "# L8 = " << count8 << '\n'
        << "# L9 = " << count9 << '\n' << "# L10 = " << count10 << '\n' << "# L11 = " << count11 << '\n'
        << "# L12 = " << count12 << '\n' << "# L13 = " << count13 << '\n' << "# L14 = " << count14 << '\n'
        << "# L15 = " << count15 << '\n' << endl;
    cout << "# Distribution of words by first letter: " << endl;
    cout << "# A/a: " << countA << '\n' << "# B/b: " << countB << '\n' << "# C/c: " << countC << '\n'
        << "# D/d: " << countD << '\n' << "# E/e: " << countE << '\n' << "# F/f: " << countF << '\n'
        << "# G/g: " << countG << '\n' << "# H/h: " << countH << '\n' << "# I/i: " << countI << '\n'
        << "# J/j: " << countJ << '\n' << "# K/k: " << countK << '\n' << "# L/l: " << countL << '\n'
        << "# M/m: " << countM << '\n' << "# N/n: " << countN << '\n' << "# O/o: " << countO << '\n'
        << "# P/p: " << countP << '\n' << "# Q/q: " << countQ << '\n' << "# R/r: " << countR << '\n'
        << "# S/s: " << countS << '\n' << "# T/t: " << countT << '\n' << "# U/u: " << countU << '\n'
        << "# V/v: " << countV << '\n' << "# W/w: " << countW << '\n' << "# X/x: " << countX << '\n'
        << "# Y/y: " << countY << '\n' << "# Z/z: " << countZ << endl;

    return 0 ;
}
