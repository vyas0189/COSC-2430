/*
*Binary Tree
Determine whether the binary tree is empty.
• Search the binary tree for a particular item.
• Insert an item in the binary tree.
• Delete an item from the binary tree.
• Find the height of the binary tree.
• Find the number of nodes in the binary tree.
• Find the number of leaves in the binary tree.
• Traverse the binary tree.
• Copy the binary tree.
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct node
{
  node()
  {
    node<T> *right = NULL;
    node<T> *left = NULL;
  }
  T data;
  node<T> *right;
  node<T> *left;
};
template <typename T>
class BinaryTree
{
protected:
  node<T> *root;
  // search, create, insert, delete, traverse
public:
  BinaryTree();
  bool search(const &key);
  void insert(const &key);
  void deleteKey(const &key);
  bool isEmpty();
  void inOrder(node<T> &key);
  void preorder(node<T> &key);
  void postorder(node<T> &key);
  int treeHeight(node<T> &key);
  int numberOfLeaves(node<T> &key);
  int numberOfNodes(node<T> &key);
};

template <typename T>
bool BinaryTree<T>::search(const T &key)
{
  node<T> *temp = root;
  if (temp == NULL)
  {
    return false;
  }
  else if (key == temp->data)
  {
    return true;
    break;
  }
  else if (temp.data > key)
  {
    search(temp->right, key);
    return true;
  }
  else if (temp.data < key)
  {
    search(temp->left, key);
    return true;
  }
  return false;
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
  root = NULL;
}

int main()
{
  node<int> bst;

  return 0;
}
