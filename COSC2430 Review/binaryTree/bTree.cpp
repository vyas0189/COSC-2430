template <class recType, int bTreeOrder>
struct bTreeNode
{
    int recCount;
    recType list[bTreeOrder - 1];
    bTreeNode *children[bTreeOrder];
};

template <class recType, int bTreeOrder>
class bTree
{

  public:
    bool search(const recType &searchItem);
    void insert(const recType &insertItem);
    void inOrder();
    bTree();

  protected:
    bTreeNode<recType, bTreeOrder> *root;
};

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::searchNode(bTreeNode<recType, bTreeOrder> *current, const recType &item, bool &found, int &location)
{
    location = 0;
    while (location < current->recCount && item > current->list[location])
        location++;
    if (location < current->recCount && item == current->list[location])
        found = true;
    else
        found = false;
}

template <class recType, int bTreeOrder>
bool bTree<recType, bTreeOrder>::search(const recType &searchItem)
{
    bool found = false;
    int location;
    bTreeNode<recType, bTreeOrder> *current;
    current = root;
    while (current != NULL && !found)
    {
        searchNode(current, item, found, location);
        if (!found)
            current = current->children[location];
    }
    return found;
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::inOrder()
{
    recInorder(root);
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::recInorder(bTreeNode<recType, bTreeOrder> *current)
{
    if (current != NULL)
    {
        recInorder(current->children[0]);
        for (int i = 0; i < current->recCount; i++)
        {
            cout << current->list[i] << " ";
            recInorder(current->children[i + 1]);
        }
    }
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insert(const recType &insertItem)
{
    bool isTaller = false;
    recType median;
    bTreeNode<recType, bTreeOrder> *rightChild;
    insertBTree(root, insertItem, median, rightChild, isTaller);
    if (isTaller) //the tree is initially empty or the root
    //was split by the function insertBTree
    {
        bTreeNode<recType, bTreeOrder> *tempRoot;
        tempRoot = new bTreeNode<recType, bTreeOrder>;
        tempRoot->recCount = 1;
        tempRoot->list[0] = median;

        tempRoot->children[0] = root;
        tempRoot->children[1] = rightChild;
        root = tempRoot;
    }
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insertNode(bTreeNode<recType, bTreeOrder> *current, const recType &insertItem, bTreeNode<recType, bTreeOrder> *&rightChild, int insertPosition)
{
    int index;
    for (index = current->recCount; index > insertPosition; index--)
    {
        current->list[index] = current->list[index - 1];
        current->children[index + 1] = current->children[index];
    }
    current->list
        [index] = insertItem;
    current->children
        [index + 1] = rightChild;
    current->recCount++;
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::splitNode(bTreeNode<recType, bTreeOrder> *current, const recType &insertItem, bTreeNode<recType, bTreeOrder> *rightChild, int insertPosition, bTreeNode<recType, bTreeOrder> *&rightNode, recType &median)
{
    rightNode = new bTreeNode<recType, bTreeOrder>;
    int mid = (bTreeOrder - 1) / 2;
    if (insertPosition <= mid) //new item goes in the first
    //half of the node
    {
        int index = 0;
        int i = mid;
        while (i < bTreeOrder - 1)
        {
            rightNode->list[index] = current->list[i];
            rightNode->children[index + 1] = current->children[i + 1];
            index++;
            i++;
        }
        current->recCount = mid;
        insertNode(current, insertItem, rightChild, insertPosition);
        (current->recCount)--;
        median = current->list[current->recCount];
        rightNode->recCount = index;
        rightNode->children[0] = current->children[current->recCount + 1];
    }
    else //new item goes in the second half of the node
    {
        int i = mid + 1;
        int index = 0;
        while (i < bTreeOrder - 1)
        {
            rightNode->list[index] = current->list[i];
            rightNode->children[index + 1] = current->children[i + 1];
            index++;
            i++;
        }
        current->recCount = mid;
        rightNode->recCount = index;
        median = current->list[mid];
        insertNode(rightNode, insertItem, rightChild, insertPosition - mid - 1);
        rightNode->children[0] = current->children[current->recCount + 1];
    }
}