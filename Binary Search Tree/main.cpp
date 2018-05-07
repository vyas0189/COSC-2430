#include <iostream>
#include "BST.cpp"
using namespace std;

int main()
{
    int treeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BST myTree;

    cout << "Printing the tree in order\nBefore adding numbers\n";
    myTree.PrintInOrder();
    for (auto x : treeKeys)
    {
        myTree.AddLeaf(x);
    }
    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree.PrintInOrder();
}