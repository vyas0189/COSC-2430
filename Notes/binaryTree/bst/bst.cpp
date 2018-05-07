#include <iostream>
#include "bst.h"
#include <assert.h>
using namespace std;

template <typename T>
bool BST<T>::isEmpty()
{
    return (root == NULL);
}
template <typename T>
BST<T>::BST()
{
    root = NULL;
}

// template <typename T>
// void BST<T>::inorderTraversal() const
// {
//     inorder(root);
// }

template <class T>
void BST<T>::inorderTraversal(void (*visit)(T &item))
{
    inorder(root, *visit);
}
template <class T>
void BST<T>::inorder(node<T> *p, void (*visit)(T &item))
{
    if (p != NULL)
    {
        inorder(p->left, *visit);
        (*visit)(p->data);
        inorder(p->right, *visit);
    }
}

template <typename T>
void BST<T>::preorderTraversal() const
{
    preorder(root);
}

template <typename T>
void BST<T>::postorderTraversal() const
{
    postorder(root);
}

template <typename T>
int BST<T>::treeHeight() const
{
    return height(root);
}

template <typename T>
int BST<T>::treeNodeCount() const
{
    return nodeCount(root);
}

template <typename T>
int BST<T>::treeLeavesCount() const
{
    return leavesCount(root);
}

//template <typename T>
// void BST<T>::inorder(node<T> *p) const
// {

//     if (p != NULL)
//     {
//         inorder(p->left);
//         cout << p->data << " ";
//         inorder(p->right);
//     }
// }

template <typename T>
void BST<T>::preorder(node<T> *p) const
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

template <typename T>
void BST<T>::postorder(node<T> *p) const
{
    if (p != NULL)
    {
        postorder(p->left);
        cout << p->data << " ";
        postorder(p->right);
    }
}

template <typename T>
int BST<T>::height(node<T> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}

template <typename T>
int BST<T>::max(int x, int y) const
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

template <typename T>
int BST<T>::leavesCount(node<T> *p) const
{
    if (p == NULL)
        return 0;
    if (p->left == NULL && p->right == NULL)
    {
        return 1;
    }
    else
    {
        return leavesCount(p->left) + leavesCount(p->right);
    }
}

template <typename T>
int BST<T>::nodeCount(node<T> *p) const
{
    if (!p)
        return 0;
    return 1 + nodeCount(p->left) + nodeCount(p->right);
}

template <typename T>
void BST<T>::insert(const T &insertItem)
{
    node<T> *current;      //pointer to traverse the tree
    node<T> *trailCurrent; //pointer behind current
    node<T> *newNode;      //pointer to create the node
    newNode = new node<T>;
    assert(newNode != NULL);
    newNode->data = insertItem;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
        while (current != NULL)
        {
            trailCurrent = current;
            if (current->data == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed."
                     << insertItem << endl;
                return;
            }
            else if (current->data > insertItem)
                current = current->left;
            else
                current = current->right;
        }
        if (trailCurrent->data > insertItem)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}

template <class T>
bool BST<T>::search(const T &searchItem) const
{
    node<T> *current;
    bool found = false;
    if (root == NULL)
        cerr << "Cannot search the empty tree." << endl;
    else
    {
        current = root;
        while (current != NULL && !found)
        {
            if (current->data == searchItem)
                found = true;
            else if (current->data > searchItem)
                current = current->left;
            else
                current = current->right;
        }
    }
    return found;
}