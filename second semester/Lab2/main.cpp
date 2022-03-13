#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
    private:
        int hour; // 0 - 23 
        int minute; // 0 - 59 
        int second; // 0 - 59
    public:
        Time();
        void setTime(int , int , int);
        void printUniversal();
        void printStandard();
        void resetTime();
        void compareTime(Time);
        void advanceTime(int);
};
Time::Time(){ // is called scope operator
    hour = minute = second = 0;
}
void Time::setTime(int h, int m, int s){
    hour = (h >= 0 && h < 24)?h :0; // ? is true otherwise : is false
    minute = (m >= 0 && m < 60)?m :0;
    second = (s >= 0 && s < 60)?s :0;
}
void Time::printUniversal(){
    cout << "Universal Time: " << setfill('0') 
    << setw(2) << ((hour > 24)?hour%24:hour) << ":" << setw(2) 
    << minute << ":" << setw(2) << second 
    << endl;
}
void Time::printStandard(){
    cout << "Standard  Time: " << setfill('0') << setw(2) 
    << ((hour == 0 || hour == 12)? 12 : hour % 12) << ":" 
    << setw(2) << minute << ":" << setw(2) << second 
    << ( (hour < 12 )? " AM" : " PM" ) << endl;
}
void Time::resetTime(){
    hour = minute = second = 0;
}
void Time::compareTime(Time t2){
    if (hour > t2.hour){ // hour equals the hour who called 這邊的hour等於傳進來的hour
        cout << "Later\n";
    }
        
    else if (hour == t2.hour){
        if (minute > t2.minute){
            cout << "Later\n";
        }
        else if (minute == t2.minute){
            if (second > t2.second){
                cout << "Later\n";
            }
            else if (second == t2.second){
                cout << "Same\n";
            }
            else
                cout << "Earlier\n";
        }
        else
            cout << "Earlier\n";
    }
        
    else{
        cout << "Earlier\n";
    }
}
void Time::advanceTime(int numMinutes){
    hour += numMinutes / 60;
    minute += numMinutes % 60; 
}
int main(){
    Time t, t1; //####################
    Time &tRef = t;//####################
    Time *tPtr = &tRef; //###################

    t.printUniversal(); 
    t.printStandard(); 
    t.setTime( 22, 22, 22 ); //#####################
    t.printUniversal(); 
    t.printStandard(); 
    tRef.printUniversal();
    tRef.printStandard(); 

    tPtr->printUniversal(); 
    tPtr->printStandard();
    tPtr->advanceTime(360); 
    tPtr->printUniversal(); 
    tPtr->printStandard();
    tRef.resetTime();
    t.printUniversal();
    t.printStandard();
    t1.setTime( 23, 23, 23 ); 
    t1.printUniversal();
    t1.printStandard();

    t1.compareTime(tRef); //************************
    tPtr->compareTime(t1); //***********************
    t1.compareTime(t1); 
}
    
