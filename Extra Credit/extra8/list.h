

#ifndef NODE_LIST_H
#define NODE_LIST_H
#include "node.h"
using namespace std;

template <typename T>
class list {
private:
    node<T> *head;
public:
    list(){
         head = NULL;
    }
    void addAtEnd(T x){
    //first create empty node in temp
    node<T> *temp= new node<T>(x);
    node<T> *cu = head;
    if(head == NULL){
        head = temp;
    }
    else{
        while (cu->next !=NULL) { //this is important
            cu = cu->next;
        }
        cu->next = temp;
    }
    }
    void print(){
        node<T> * cu = head;
        while(cu != NULL){
            cout << cu ->n << endl;
            cu =cu->next;
        }
    }
};


#endif //NODE_LIST_H
