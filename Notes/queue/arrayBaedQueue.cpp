#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class queueADT
{
  public:
    virtual bool isEmptyQueue() const = 0;
    virtual bool isFullQueue() const = 0;
    virtual void initializeQueue() = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual void addQueue(const T &queueElement) = 0;
    virtual void deleteQueue() = 0;
};

template <class T>
class queueType : public queueADT<T>
{
  public:
    const queueType<T> &operator=(const queueType<T> &);
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    T front() const;
    T back() const;
    void addQueue(const T &queueElement);
    void deleteQueue();
    queueType(int queueSize = 100);
    queueType(const queueType<T> &otherQueue);
    ~queueType();

  private:
    int maxQueueSize; //variable to store the maximum queue size
    int count;
    int queueFront; //variable to point to the first
    int queueRear;
    T *list;
};

template <class T>
bool queueType<T>::isEmptyQueue() const
{
    return (count == 0);
}
//end isEmptyQueue
template <class T>
bool queueType<T>::isFullQueue() const
{
    return (count == maxQueueSize);
}
//end isFullQueue

template <class T>
void queueType<T>::initializeQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}
//end initializeQueu

template <class T>
T queueType<T>::front() const
{
    assert(!isEmptyQueue());
    return list[queueFront];
}
//end fron

template <class T>
T queueType<T>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
}
//end back

template <class T>
void queueType<T>::addQueue(const T &newElement)
{
    if (!isFullQueue())
    {
        queueRear = (queueRear + 1) % maxQueueSize; //use the
        count++;
        list[queueRear] = newElement;
    }
    else
        cout << "Cannot add to a full queue." << endl;
}
//end addQueue

template <class T>
void queueType<T>::deleteQueue()
{
    if (!isEmptyQueue())
    {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize; //use the
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}
//end deleteQueu

template <class T>
queueType<T>::queueType(int queueSize)
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;
        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize; //set maxQueueSize to
    //queueSize
    queueFront = 0;
    //initialize queueFront
    queueRear = maxQueueSize - 1; //initialize queueRear
    count = 0;
    list = new T[maxQueueSize]; //create the array to
    //hold the queue elements
}
//end constructor

template <class T>
queueType<T>::~queueType()
{
    delete[] list;
}

int main()
{
    queueType<int> queue;
    int x, y;
    queue.initializeQueue();
    x = 4;
    y = 5;
    queue.addQueue(x);
    queue.addQueue(y);
    x = queue.front();
    queue.deleteQueue();
    queue.addQueue(x + 5);
    queue.addQueue(16);
    queue.addQueue(x);
    queue.addQueue(y - 3);
    cout << "Queue Elements: ";
    while (!queue.isEmptyQueue())
    {
        cout << queue.front() << " ";
        queue.deleteQueue();
    }
    cout << endl;
    return 0;
}