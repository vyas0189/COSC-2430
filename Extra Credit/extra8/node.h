

#ifndef NODE_NODE_H
#define NODE_NODE_H

template <typename T>
class node {
private:


public:
    T n;
    node* next;
    node(T x){
        n = x;
        next = NULL;

    }
    T getN(){
        return n;
    }

};


#endif //NODE_NODE_H
