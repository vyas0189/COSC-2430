bool add(node *r, int key)
{
    if (r == NULL)
    {
        r = new node(t); //class node constructor l = r= null;
        if (r = NULL)
        {
            return false;
        }
        return true;
    }
    if (key == r->info)
    {
        return false;
    }
    if (key < r->info)
    {
        return add(r->left, key);
    }
    if (key > r->info)
    {
        return add(r->right, key);
    }
}

// write a function to test if the tree is BST

bool isBST(node *root)
{
    if (root = NULL)
    {
        return true;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
    }
    if (root->left != NULL && root->left->data >= root->data)
    {
        return false;
    }
    if (root->right != NULL && root->right->data <= root->data)
    {
        return false;
    }

    return isBST(root->left) && isBST(root->right);
}

bool isBST(node *root, int l, int h)
{
    if (root = NULL)
    {
        return true;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
    }
    if (root->left != NULL && root->left->data >= root->data)
    {
        return false;
    }
    if (root->right != NULL && root->right->data <= root->data)
    {
        return false;
    }

    return isBST(root->left) && isBST(root->right);
}

//DELETE A NODE FROM BST
/*
    1.Find the min of the right side
    2.Replace the data ... No pointers
    3.If the min has a right side

    //
    1- check if the the node has no childern, then update the parent pointer
    2- If the node has one child, child will replace the parent
    3- If the node has two childern find the max of the right side.
*/


// ==============================
// avl inherit from bst 
//  -left single roration
//  -right single roration
//  -left double rotation
//  -right double rotation
//count number of nodes
//counts the parents
