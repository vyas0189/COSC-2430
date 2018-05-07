#include <iostream>
using namespace std;

template <typename T>
class node
{
  public:
    T data;
    node *left, *right;
    node(T x)
    {
        data = x;
        left = right = NULL;
    }

    void print()
    {
        cout << data << endl;
    }
};
//the class node is called node<T>
//node<int> *p = new node<int>(7);
//node<char> *q = new node<char>('a');

template <typename T>
class Tree
{
  private:
    node<T> *root;

  public:
    Tree(); //new node
    Tree(node<T> *p) { root = p; }
    ~Tree(); //delete
    void set(node<T> *);
    node<T> *get();
    void insert(T);       //always write //new node
    bool search(T);       //always write
    void deleteNode(T &); //always write
    int countNodes();
    int childern(node<T> *);
    int height(node<T> *);
    void print();
};
template <typename T>
Tree<T>::Tree()
{
    root = 0;
}

template <typename T>
class bst : public Tree<T>
{
  public:
    void insert(T);
    bool search(T);
    void deleteNode(T &);
};

int main()
{
    Tree<int> t1;
    bst<int> t2;
    t1.insert(4);
    t2.insert(7);

    node<int> *A[2];
    A[0] = t1.get();
    A[1] = t2.get();
    for (int i = 0; i < 2; i++)
    {
        A[i]->print(); //pointer to the tree root;
    }
}