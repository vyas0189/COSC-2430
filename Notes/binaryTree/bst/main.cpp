#include <iostream>
#include "bst.cpp"
using namespace std;

void print(int &x);
void update(int &x);
int main()
{
    BST<int> treeRoot;
    int num;
    cout << "Enter numbers ending with -999" << endl;
    cin >> num;
    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }
    cout << endl
         << "Tree nodes in inorder: ";
    treeRoot.inorderTraversal(print);
    cout << endl
         << "Tree Height: " << treeRoot.treeHeight() << endl
         << endl;
    cout << "******* Update Nodes *******" << endl;
    treeRoot.inorderTraversal(update);
    cout << "Tree nodes in inorder after "
         << "the update: " << endl
         << " ";
    treeRoot.inorderTraversal(print);
    cout << endl
         << "Tree Height: "
         << treeRoot.treeHeight() << endl;
         
         cout << "Leaves: " << treeRoot.treeLeavesCount();
    return 0;
}
void print(int &x)
{
    cout << x << " ";
}
void update(int &x)
{
    x = 2 * x;
}