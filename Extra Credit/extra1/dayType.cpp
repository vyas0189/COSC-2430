#include <iostream>
#include <string>
#include "dayType.h"
using namespace std;

string dayType:: weekDays[7] ={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
dayType:: dayType(){
    weekDay = "";
}
dayType:: dayType(string d){
    weekDay = d;
}
void dayType:: setDay(string d){
    weekDay = d;
}
string dayType:: getDay() const{
    return weekDay;
}

void dayType:: print() const{
    cout << weekDay << endl;
}

string dayType:: nextDay() const{
    for(int i=0; i < 7;i++){
        if(weekDay == weekDays[i]){
            return weekDays[(i+1)%7];
        }
    }
}

string dayType:: prevDay() const{
    for(int i=0;i < 7;i++){
        if(weekDay == weekDays[i]){
            if(i == 0){
                return weekDays[6];
            }else{
                return weekDays[i-1];
            }
        }
    }
}

void dayType:: addDay(int nDays){
    for(int i=0;i<7;i++){
        if(weekDay == weekDays[i]){
            weekDay = weekDays[(i+nDays)%7];
        }
    }
}