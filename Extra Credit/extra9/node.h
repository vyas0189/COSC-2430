#ifndef NODE_H_
#define NODE_H_

class node{
    public:
        int n;
        node *next;
        node(int x){
            n =x;
            next = 0;
        }
};
#endif
