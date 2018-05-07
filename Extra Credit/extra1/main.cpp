#include <iostream>
#include "dayType.h"
using namespace std;

int main() 
{
    dayType myDay("Monday");
    dayType temp("Sunday");

    myDay.print();
    cout << endl;

    myDay.addDay(9);
    myDay.print();
    cout << myDay.prevDay() << endl;

    cout << myDay.nextDay() << endl;
    temp.print();
    cout << endl;

    cout << temp.prevDay() << endl;

    cout << temp.nextDay() << endl;

    return 0;
}
