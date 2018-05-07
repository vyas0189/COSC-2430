#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class T>
struct node
{
  T data;
  node<T> *left;
  node<T> *right;
};

template <class T>
class BST
{
public:
  //const BST<T> &operator=(const BST<T> &);
  //Overload the assignment operator.
  bool isEmpty();
  //Returns true if the binary tree is empty;
  //otherwise, returns false.
  void inorderTraversal(void (*visit)(T &));
  //Function to do an inorder traversal of the binary tree.
  void preorderTraversal() const;
  //Function to do a preorder traversal of the binary tree.
  void postorderTraversal() const;
  //Function to do a postorder traversal of the binary tree.
  int treeHeight() const;
  //Returns the height of the binary tree.
  int treeNodeCount() const;
  //Returns the number of nodes in the binary tree.
  int treeLeavesCount() const;
  //Returns the number of leaves in the binary tree.
  //void destroyTree();
  //Deallocates the memory space occupied by the binary tree.
  //Postcondition: root = NULL;
  //BST(const BST<T> &otherTree);
  //copy constructor
  void insert(const T &insertItem);
  bool search(const T &searchItem) const;
  BST();
  //default constructor
  //~BST();
  //destructor
protected:
  node<T> *root;

private:
  //void copyTree(node<T> *&copiedTreeRoot, node<T> *otherTreeRoot);
  //Makes a copy of the binary tree to which
  //otherTreeRoot points. The pointer copiedTreeRoot
  //points to the root of the copied binary tree.
  //void destroy(node<T> *&p);
  //Function to destroy the binary tree to which p points.
  //Postcondition: p = NULL
  void inorder(node<T> *p, void (*visit)(T &));
  //Function to do an inorder traversal of the binary
  //tree to which p points.
  void preorder(node<T> *p) const;
  //Function to do a preorder traversal of the binary
  //tree to which p points.
  void postorder(node<T> *p) const;
  //Function to do a postorder traversal of the binary
  //tree to which p points.
  int height(node<T> *p) const;
  //Function to return the height of the binary tree
  //to which p points.
  int max(int x, int y) const;
  //Returns the larger of x and y.
  int nodeCount(node<T> *p) const;
  //Function to return the number of nodes in the binary
  //tree to which p points
  int leavesCount(node<T> *p) const;
  //Function to return the number of leaves in the binary
  //tree to which p points
};

#endif