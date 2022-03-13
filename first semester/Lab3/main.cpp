#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    double Weight;
    double Height;
    double BMI;
    bool testing = true;
    int disBMI[10] = {0};
    char BMI_level;
    /* initialize all variable */
    int count = 0;
    
    int USL_count = 0;
    int HSUW_count = 0;
    int SUV_count = 0;
    int UW_count = 0;
    int NW_count = 0;
    int OW_count = 0;
    int OB_count = 0;
    int SOB_count = 0;
    int HSOB_count = 0;
    int ULL_count = 0;
    int count_arr[10] = {USL_count, HSUW_count,
                            SUV_count, UW_count,
                            NW_count, OW_count,
                            OB_count, SOB_count,
                            HSOB_count, ULL_count};
    string levelname_arr[10] = {"USL", "HSUW",
                                "SUV", "UW",
                                 "NW", "OW",
                                  "OB", "SOB",
                                  "HSOB", "ULL"};

    while (testing)
    {
        count++;
        cin >> Weight >> Height;
        /* decide which BMI_level */
        if (Weight >= 20 && Weight <= 200 && Height >= 0.9 && Height <= 2.5) //met the requirement
        {
            BMI = round(Weight / (Height * Height) * 10) / 10.0;
            if (BMI < 10)
            {
                BMI_level = 'A'; // BMI_level = "USL"
            }
            else if (BMI >= 10 && BMI <= 15)
            {
                BMI_level = 'B'; // BMI_level = "HSUW"
            }
            else if (BMI > 15 && BMI <= 16)
            {
                BMI_level = 'C'; // BMI_level = "SUV"   
            }
            else if (BMI > 16 && BMI < 18.5)
            {
                BMI_level = 'D'; //BMI_level = "UW"
            }
            else if (BMI >= 18.5 && BMI <= 25)
            {
                BMI_level = 'E';//BMI_level = "NW"
            }
            else if (BMI > 25 && BMI <= 40)
            {
                BMI_level = 'F'; //BMI_level = "OW"
            }
            else if (BMI > 40 && BMI <= 50)
            {
                BMI_level = 'G'; //BMI_level = "OB"
            }
            else if (BMI >= 50 && BMI <= 60)
            {
                BMI_level = 'H'; //BMI_level = "SOB"
            }
            else if (BMI >= 60 && BMI <= 70)
            {
                BMI_level = 'I'; //BMI_level = "HSOB"
            }
            else
            {
                BMI_level = 'J'; //BMI_level = "ULL"
            }
            
            switch (BMI_level)
            {
                case 'A':
                    count_arr[0]++;
                    break;
                case 'B':
                    count_arr[1]++;
                    break;
                case 'C':
                    count_arr[2]++;
                    break;
                case 'D':
                    count_arr[3]++;
                    break;
                case 'E':
                    count_arr[4]++;
                    break;
                case 'F':
                    count_arr[5]++;
                    break;
                case 'G':
                    count_arr[6]++;
                    break;
                case 'H':
                    count_arr[7]++;
                    break;
                case 'I':
                    count_arr[8]++;
                    break;
                case 'J':
                    count_arr[9]++;
                    break;
            }
        }
        /* main output */
        else if (Weight <= 0 || Height <= 0) // if the height or weight value smaller than or equal to 0 then break
        {
            count -= 1;
            for (int i = 0; i < 10; i++)
                disBMI[i] = count_arr[i]; 
            
            for (int i = 0; i < 10; i++) //Line 1
            {
                if (i == 0)
                    cout << "#" << setw(7) << levelname_arr[i];
                else if (i == 9)
                    cout << setw(7) << levelname_arr[i] << endl;
                else
                    cout << setw(7) << levelname_arr[i]; 
            }

            for (int i = 0; i < 10; i++) //Line 2
            {
                if (i == 0)
                    cout << "#" << setw(7) << disBMI[i];
                else if (i == 9)
                    cout << setw(7) << disBMI[i] << endl;
                else
                    cout << setw(7) << disBMI[i];
            }
            // find maximum
            int Max = 0;
            int x = 0; // To record the maximum's position
            for (int i = 0; i < 10; i++)
            {
                if (Max < disBMI[i])
                {
                    Max = disBMI[i];
                    x = i; // x means the maximum position
                }
            }
            cout << "# Levels with maximum count: " << Max << endl; // Line 3
            int y = 0;
            bool status = false;
            for (int i = 0; i < 10; i++) /* To find whether has the same data in output.*/
            {
                if (Max == disBMI[i] && x != i) /* if yes,then record another data position.*/
                {
                    y = i; /* it another same data's position.*/
                }
            }
            if (y > 0)
                cout << "# level = " << levelname_arr[x] << " " << levelname_arr[y] << endl;
            else
                cout << "# level = " << levelname_arr[x] << endl;
            cout << "# Head count = " << count << endl; // Last line
            break;
        }
        /* if weight or height are not in the required reange */
        else
        {   
            count -= 1;
            continue;
        }
        
    }
    return 0;
}
