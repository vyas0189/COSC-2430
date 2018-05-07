#include <iostream>
#include "lineType.h";
using namespace std;

lineType:: lineType(double a = 0, double b = 0, double c = 0){
    xCoeff = a;
    yCoeff = b;
    constTerm = c;
}

void lineType::setLine(double a = 0, double b = 0, double c = 0){
    xCoeff = a;
    yCoeff = b;
    constTerm = c;
}

void lineType:: equation() const{

}

double lineType:: getXCoefficient() const{
    return xCoeff;
}
double lineType::getYCoefficient() const{
    return yCoeff;
}
double lineType::getConstantTerm() const{
    return constTerm;
}
double lineType::setXCoefficient(double coeff){
    xCoeff = coeff;
}
double lineType::setYCoefficient(double coeff){
    yCoeff = coeff;
}
double lineType::setConstantTerm(double c){
    constTerm = c;
}
double lineType::slope() const{
    
}
bool lineType::verticalLine() const{

}
bool lineType::horizontalLine() const{

}
bool lineType::equalLines(lineType otherLine) const{

}
bool lineType::parallel(lineType otherLine) const{

}
bool lineType::perpendicular(lineType otherLine) const{

}
void lineType::pointOfIntersection(lineType otherLine){

}
