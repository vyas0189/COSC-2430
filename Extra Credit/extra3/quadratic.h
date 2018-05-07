#ifndef H_quadraticEq  
#define H_quadraticEq  
#include <iostream>
using namespace std;

class quadraticEq 
{   friend ostream& operator<< (ostream&, const quadraticEq&);
    friend istream& operator>> (istream&, quadraticEq&);
public:
    const quadraticEq& operator=(const quadraticEq& right); 
    void rootsType(); 
    void eqRoots();
    void setEq(double a, double b, double c);
    bool operator==(const quadraticEq& right) const;
    bool operator!=(const quadraticEq& right) const;
    quadraticEq operator+(const quadraticEq& num); 
    quadraticEq operator-(const quadraticEq& num);  

    quadraticEq(double a = 0, double b = 0, double c = 0); 
private:
    double coeffXSquare;
    double coeffX;
    double constTerm;
};
#endif

