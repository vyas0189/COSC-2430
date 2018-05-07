#include <iostream>
#include "quadratic.h"
using namespace std;


int main()
{
    quadraticEq eq1(1, 2, 1);  
    quadraticEq eq2(1, 1, 1); 
    quadraticEq eq3(2, 4, 2);

    cout << "eq1: " << eq1 << endl;
    cout << "eq2: " << eq2 << endl;
    cout << "eq3: " << eq3 << endl;

    eq1.rootsType();
    eq1.eqRoots();
    eq2.rootsType();
    eq2.eqRoots();

    cout << "eq1 + eq2 = " << eq1 + eq2 << endl;

    cout << "eq1 - eq2 = " << eq1 - eq2 << endl;

    cout << "eq1 == eq2: " << (eq1 == eq2) << endl;
    cout << "eq1 != eq2: " << (eq1 != eq2) << endl;
    cout << "eq1 == eq3: " << (eq1 == eq3) << endl;
    cout << "eq1 != eq3: " << (eq1 != eq3) << endl;
return 0;}
