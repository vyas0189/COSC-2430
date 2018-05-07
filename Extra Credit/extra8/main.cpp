#include <iostream>
#include "list.h"
// #include "node.h"
using namespace std;
int main() {
    int number;
    //another node class  called "student" with student, id, and gpa
    // AND next: id, string, double, student*
    list <int> *myList = new list<int>();
    cout<<"Give me a number: "<<endl;
    cin>> number;
    myList->addAtEnd(number);

    myList->addAtEnd(45);
    myList->addAtEnd(11);
    myList->print();
    return 0;
}