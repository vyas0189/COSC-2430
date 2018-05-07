#include <iostream>
#include "quadratic.h"
#include <math.h>
using namespace std;

const quadraticEq& quadraticEq::operator=(const quadraticEq& right){
    //quadraticEq temp;
    if(this != &right){
        this->coeffX = right.coeffX;
        this->coeffXSquare = right.coeffXSquare;
        this->constTerm = right.constTerm;
    }

    return *this;
}

void quadraticEq:: rootsType(){
    double discriminant = pow(coeffX,2)- (4*coeffXSquare*constTerm);

    if(discriminant == 0){
        cout<< "Single (repeated) root" << endl;
    }else if(discriminant > 0){
        cout<< "Two real roots" << endl;
    }else{
        cout << "Two complex roots" << endl;
    }
}

void quadraticEq::eqRoots(){
    double discriminant = pow(coeffX,2)- (4*coeffXSquare*constTerm);
    double realPart = -coeffX/(2*coeffXSquare), imgPart = sqrt(-discriminant)/(2*coeffXSquare);
    double equPos = (-coeffX + sqrt(discriminant))/(2*coeffXSquare);
    double equNeg =  (-coeffX - sqrt(discriminant))/(2*coeffXSquare);

    if(discriminant > 0){
        cout << "The roots are: " << equPos << ", " << equNeg << endl;
    }else if(discriminant == 0){ 
        cout << "The roots are: " << equPos << ", " << equNeg << endl;
    }else{
        cout << "The roots are: " << realPart << "+" << imgPart << "i" << ", " << realPart << "-" << imgPart << "i" << endl;
    }


}
void quadraticEq:: setEq(double a,double b, double c){
    coeffXSquare = a;
    coeffX = b;
    constTerm = c;
}

bool quadraticEq::operator==(const quadraticEq& right) const{
    return (coeffXSquare == right.coeffXSquare && coeffX == right.coeffX && constTerm == right.constTerm);

}
bool quadraticEq::operator!=(const quadraticEq& right) const{
    return (coeffXSquare != right.coeffXSquare || coeffX != right.coeffX || constTerm != right.constTerm);
}

quadraticEq quadraticEq:: operator+(const quadraticEq& num){
    quadraticEq temp;
    temp.coeffXSquare = coeffXSquare + num.coeffXSquare;

    temp.coeffX = coeffX + num.coeffX;

    temp.constTerm = constTerm + num.constTerm;
    
    return temp;
}


quadraticEq quadraticEq:: operator-(const quadraticEq& num){
    quadraticEq temp;
    temp.coeffXSquare = coeffXSquare - num.coeffXSquare;

    temp.coeffX = coeffX - num.coeffX;

    temp.constTerm = constTerm - num.constTerm;

    return temp;
}

quadraticEq:: quadraticEq(double a , double b, double c){
    coeffXSquare = a;
    coeffX =b;
    constTerm = c;
}

ostream& operator<< (ostream& osObject, const quadraticEq& quad){

    osObject << "A= " << quad.coeffXSquare << ", B= " << quad.coeffX << ", C= " << quad.constTerm;
    return osObject;
}
istream& operator>> (istream& isObject, quadraticEq& quad){
    isObject >> quad.coeffXSquare >> quad.coeffX >> quad.constTerm;

    return isObject;
}
