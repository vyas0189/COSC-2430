#ifndef LINE_H
#define LINE_H

#include <iostream>
using namespace std;

class lineType
{
private:
    double xCoeff;
    double yCoeff;
    double constTerm;
    bool hasSlope;
public:
     lineType(double a = 0, double b = 0, double c = 0);

    void setLine(double a = 0, double b = 0, double c = 0);
       
    void equation() const;

    double getXCoefficient() const;
    double getYCoefficient() const;
    double getConstantTerm() const;

    void setXCoefficient(double coeff);
    void setYCoefficient(double coeff);
    void setConstantTerm(double c);

    double slope() const;   //Return the slope. This function does not check if the line is vertical. Because the slope of a   
                             //vertical line is undefined, before calling this function check if the line is nonvertical.

    bool verticalLine() const;
    bool horizontalLine() const;

    bool equalLines(lineType otherLine) const;      //Returns true of both lines are the same.

    bool parallel(lineType otherLine) const;         //Function to determine if this line is parallel to otherLine.

    bool perpendicular(lineType otherLine) const;        //Function to determine if this line is perperdicular to otherLine.

    void pointOfIntersection(lineType otherLine);   //If lines intersect, then this function finds the point of intersection.
 
};
#endif