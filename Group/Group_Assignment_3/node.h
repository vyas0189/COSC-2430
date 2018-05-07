#ifndef NODE_H_
#define NODE_H_
#include <string>
class node{

    public:
        char n;
        node *next=0;

        node(char x){
            n=x;
        }
};
#endif