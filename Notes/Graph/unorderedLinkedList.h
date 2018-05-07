template <class T>
struct nodeType
{
    T info;
    nodeType<T> *link;
};

template <class T>
class linkedListIterator
{
  public:
    linkedListIterator();
    linkedListIterator(nodeType<T> *ptr);
    T operator*();
    linkedListIterator<T> operator++();
    bool operator==(const linkedListIterator<T> &right) const;
    bool operator!=(const linkedListIterator<T> &right) const;

  private:
    nodeType<T> *current;
};

template <class T>
linkedListIterator<T>::linkedListIterator()
{
    current = NULL;
}
template <class T>
linkedListIterator<T>::
    linkedListIterator(nodeType<T> *ptr)
{
    current = ptr;
}
template <class T>
T linkedListIterator<T>::operator*()
{
    return current->info;
}

template <class T>
linkedListIterator<T> linkedListIterator<T>::operator++()
{
    current = current->link;
    return *this;
}
template <class T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T> &right) const
{
    return (current == right.current);
}
template <class T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T> &right) const
{
    return (current != right.current);
}

template <class T>
class linkedListType
{
  public:
    const linkedListType<T> &operator=(const linkedListType<T> &);

    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    T front() const;
    T back() const;
    virtual bool search(const T &searchItem) const = 0;
    virtual void insertFirst(const T &newItem) = 0;
    virtual void insertLast(const T &newItem) = 0;
    virtual void deleteNode(const T &deleteItem) = 0;
    linkedListIterator<T> begin();
    linkedListIterator<T> end();
    linkedListType();
    linkedListType(const linkedListType<T> &otherList);
    ~linkedListType();

  protected:
    int count;
    nodeType<T> *first;
    nodeType<T> *last;

  private:
    void copyList(const linkedListType<T> &otherList);
};

template <class T>
linkedListType<T>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class T>
void linkedListType<T>::destroyList()
{
    nodeType<T> *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template <class T>
void linkedListType<T>::initializeList()
{
    destroyList();
}

template <class T>
void linkedListType<T>::print() const
{
    nodeType<T> *current;
    current = first;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class T>
T linkedListType<T>::front() const
{
    assert(first != NULL);
    return first->info;
}
template <class T>
int linkedListType<T>::length() const
{
    return count;
}

template <class T>
T linkedListType<T>::back() const
{
    assert(last != NULL);
    return last->info;
}

template <class T>
linkedListIterator<T> linkedListType<T>::begin()
{
    linkedListIterator<T> temp(first);
    return temp;
}
template <class T>
linkedListIterator<T> linkedListType<T>::end()
{
    linkedListIterator<T> temp(NULL);
    return temp;
}

template <class T>
void linkedListType<T>::copyList(const linkedListType<T> &otherList)
{
    nodeType<T> *newNode;
    nodeType<T> *current;
    if (first != NULL)
        destroyList();
    if (otherList.first == NULL)
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first;
        count = otherList.count;
        first = new nodeType<T>;
        first->info = current->info;
        first->link = NULL;
        last = first;
        current = current->link;
        while (current != NULL)
        {
            newNode = new nodeType<T>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;

            current = current->link;
        }
    }
}

template <class T>
linkedListType<T>::linkedListType(const linkedListType<T> &otherList)
{
    first = NULL;
    copyList(otherList);
}

template <class T>
linkedListType<T>::~linkedListType()
{
    destroyList();
}

template <class T>
const linkedListType<T> &linkedListType<T>::operator=(const linkedListType<T> &otherList)
{
    if (this != &otherList)
    {
        copyList(otherList);
    }
    return *this;
}

template <class T>
class unorderedLinkedList : public linkedListType<T>
{
  public:
    bool search(const T &searchItem) const;

    void insertFirst(const T &newItem);

    void insertLast(const T &newItem);

    void deleteNode(const T &deleteItem);
};

template <class T>
bool unorderedLinkedList<T>::
    search(const T &searchItem) const
{
    nodeType<T> *current;
    bool found = false;
    current = first;

    while (current != NULL && !found)

        if (current->info == searchItem)
            found = true;
        else
            current = current->link;

    return found;
}

template <class T>
void unorderedLinkedList<T>::insertFirst(const T &newItem)
{
    nodeType<T> *newNode;
    newNode = new nodeType<T>;
    newNode->info = newItem;
    newNode->link = first;

    first = newNode;
    count++;
    if (last == NULL)

        last = newNode;
}

template <class T>
void unorderedLinkedList<T>::insertLast(const T &newItem)
{
    nodeType<T> *newNode;
    newNode = new nodeType<T>;
    newNode->info = newItem;
    newNode->link = NULL;
    if (first == NULL)

    {
        first = newNode;
        last = newNode;
        count++;
    }
    else

    {
        last->link = newNode;
        last = newNode;

        count++;
    }
}

template <class T>
void unorderedLinkedList<T>::deleteNode(const T &deleteItem)
{
    nodeType<T> *current;
    nodeType<T> *trailCurrent;
    bool found;
    if (first == NULL)

        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem)
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)

                last = NULL;
            delete current;
        }
        else
        {
            found = false;
            trailCurrent = first;

            current = first->link;

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }

            if (found)
            {
                trailCurrent->link = current->link;
                count--;
                if (last == current)

                    last = trailCurrent;
                delete current;
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }
    }
}
