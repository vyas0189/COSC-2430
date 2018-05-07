#include <iostream>
#include "list.h"
#include <string>

int main(){

    string userInput;
    int i=0;

    cout << "Enter a word: ";
   	getline(cin, userInput);
    list *myList = new list();
    int len = userInput.length();
    
    do{
        myList->addAtEnd(userInput[i]);
        i++;
    }while(i < len);
    myList->rotate();
    myList->print();

}

/* 
* Vyas Ramankulangara: 55%
* Sam Parker: 40%
* Louis Dang: 5%
 */