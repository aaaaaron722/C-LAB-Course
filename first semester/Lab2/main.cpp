#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double myWeight;
    double myHeight;
    double myBMI;
    bool testing = true;
    string result;

    while (testing)
    {   
        cout << "Input Weight(kg): "; cin >> myWeight; //input Weight
        cout << "Input Height(m): "; cin >> myHeight; //input Height
        myBMI = round(myWeight / (myHeight * myHeight) * 10) / 10.0; //calculate BMI value
        
        if (myWeight < 20 or myWeight > 200)//didn't meet the requirement
        {
            cout << "# Invalid weight (>= 20kg and <= 200kg)" << endl;
            cout << endl;
        }
        else if (myHeight < 0.9 or myHeight > 2.5) //didn't meet the requirement
        {
            cout << "# Invalid height (>= 0.9m and <= 2.5m)" << endl;
            cout << endl;
        }
        else //met the requirement
        {   
            if (myBMI < 10) // determine the BMI level
                result = "Unreasonably small";
            else if (myBMI >= 10 and myBMI <= 15)
                result = "highly severely underweight";
            else if (myBMI > 15 and myBMI <= 16)
                result = "severely underweight";
            else if (myBMI > 16 and myBMI < 18.5)
                result = "underweight";
            else if (myBMI >= 18.5 and myBMI <= 25)
                result = "normal" ;
            else if (myBMI > 25 and myBMI <= 40)
                result = "overweight";
            else if (myBMI > 40 and myBMI <= 50)
                result = "obese";
            else if (myBMI > 50 and myBMI <= 60)
                result = "severely obese";
            else if (myBMI > 60 and myBMI <= 70)
                result = "highly severely obese";
            else
                result = "Unreasonably large";

            //print the result
            
            cout << "# Your Weight(kg): " << myWeight << endl;
            cout << "# Your Height(m): " << myHeight << endl;
            cout << "# Your BMI: " << myBMI << endl;
            cout << "# Your BMI level is " << result << endl;
            if (result == "normal")
                cout << endl;
            
            // Step 4 and Step 5 the additional condition
            if (myBMI < 10)
            {
                cout << "# Either weight or height might be wrongly given(Step4)." << endl;
                double H = sqrt(myWeight / 10);
                cout << "# If given weight is correct, then the given height should be at most " << H << " m (Step4)." << endl;
                double W = myHeight * myHeight * 10;
                cout << "# If given height is correct, then the given weight should be at least " << W << " kg (Step4)." << endl;
                cout << endl;
            }
            else if (myBMI > 70)
            {
                cout << "# Either weight or height might be wrongly given(Step4)." << endl;
                double H = sqrt(myWeight / 70);
                cout << "# If given weight is correct, then the given height should be at least " << H << " m (Step4)." << endl;
                double W = myHeight * myHeight * 70;
                cout << "# If gievn height is correct, then the given weight should be at most " << W << " kg (Step4)." << endl;
                cout << endl;
            }
            
            if (myBMI < 18.5 && myBMI >= 10)
            {
                double W = myHeight * myHeight * 18.5;
                cout <<"# Increase your weight to "<< W << " kg to bring your BMI value to 18.5 (Step5)." << endl;
                cout << endl;
            }
            else if (myBMI > 25 && myBMI <= 70)
            {
                double W = myHeight * myHeight * 25;
                cout <<"# Decrease your weight to "<< W << " kg to bring your BMI value to 25 (Step5)." << endl;
                cout << endl;
            }
        }
    }
    return 0;
}



