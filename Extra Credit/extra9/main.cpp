#include <iostream>
#include "list.h"
using namespace std;

int main(){

    int userChoice;
    bool counter = true;
    list *myList = new list();

    
    while(counter){
        cout << "1.Add at the end.\n2.Add at the beggining.\n3.Add based on content.\n4.Add based on postion.\n5.Print.\n6.Exit.\nEnter your choice: ";
    cin >> userChoice;
        switch(userChoice){
            case 1:
                int num1;
                cout << "Enter a number: ";
                cin >> num1;
                myList->addAtEnd(num1);
                break;
            case 2:
                int num2;
                cout << "Enter a number: ";
                cin >> num2;
                myList->addAtBeg(num2);
                break;
            case 3:
                int num3;
                cout << "Enter a number: ";
                cin >> num3;
                myList->addinMiddle(num3);
                break;
            case 4:
                int num4, pos;
                cout << "Enter a number: ";
                cin >> num4;
                cout << "Enter a postion: ";
                cin >> pos;
                myList->addBasedonPos(num4,pos);
                break;
            case 5:
                myList->print();
                break;
            case 6:
                counter = false;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}