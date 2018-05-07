
#ifndef DAYTYPE_H
#define DAYTYPE_H
#include <iostream>
#include <string>
using namespace std;
class dayType
{
private:
    string weekDay;
public:
	static string weekDays[7];
	dayType();
   	dayType(string d);
	void setDay(string d);
   	string getDay() const;
    void print() const;
    string nextDay() const;
    string prevDay() const;
    void addDay(int nDays);
};
#endif
