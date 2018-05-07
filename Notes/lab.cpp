#include <iostream>
#include <sstream>
using namespace std;

void replaceDeletimers(string &deletimer)
{
    for (auto &c : deletimer)
    {
        if (c == ':')
        {
            c = ' ';
        }
    }
}
string convertHours(string hrs)
{
    if (hrs == "01")
    {
        return "one";
    }
    else if (hrs == "02")
    {
        return "two";
    }
    else if (hrs == "03")
    {
        return "three";
    }
    else if (hrs == "04")
    {
        return "four";
    }
    else if (hrs == "05")
    {
        return "five";
    }
    else if (hrs == "06")
    {
        return "six";
    }
    else if (hrs == "07")
    {
        return "seven";
    }
    else if (hrs == "08")
    {
        return "eight";
    }
    else if (hrs == "09")
    {
        return "nine";
    }
    else if (hrs == "10")
    {
        return "ten";
    }
    else if (hrs == "11")
    {
        return "eleven";
    }
    else if (hrs == "12")
    {
        return "twelve";
    }
}

string convertMin(string min){
    
}
void convertittoWord(string ti)
{
    istringstream iss(ti);
    string hour, min;
    string hr;
    string m;
    while (iss >> hour >> min)
    {
        hr = convertHours(hour);
        m = convertMin(min);
    }
    cout << hr << " " << min << endl;
}

int main()
{
    string ti = "12:01";
    replaceDeletimers(ti);
    convertittoWord(ti);
}