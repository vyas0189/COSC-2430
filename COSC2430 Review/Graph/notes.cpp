#include <iostream>
#include <string>
using namespace std;

class graph{

    int v;
    node<int> *elt;
};

class node{
    string name;
    bool visited;
    double weigth;
    node* adj;
    // edge *next
};

//for traversal stack to push dfs, ques bfs