#include <iostream>
using namespace std;

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedQueueType : public queueADT<Type>
{
  public:
    const linkedQueueType<Type> &operator=(const linkedQueueType<Type> &);
    bool isEmptyQueue() const;

    bool isFullQueue() const;
    void initializeQueue();

    Type front() const;

    Type back() const;
    void addQueue(const Type &queueElement);
    void deleteQueue();
    linkedQueueType();
    linkedQueueType(const linkedQueueType<Type> &otherQueue);
    ~linkedQueueType();
  private:
    nodeType<Type> *queueFront; //pointer to the front of the queue
    nodeType<Type> *queueRear;  //pointer to the rear of the queue
};