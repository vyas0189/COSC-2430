#include <iostream>
#include <cassert>
using namespace std;

template <class T>
struct nodeType
{
	T info;
	nodeType<T> *link;
};

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
class linkedQueueType : public queueADT<T>
{
  public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	T front() const;
	T back() const;
	void addQueue(const T &queueElement);
	void deleteQueue();
	linkedQueueType();

  private:
	nodeType<T> *queueFront; //pointer to the front of the queue
	nodeType<T> *queueRear;  //pointer to the rear of the queue
};

template <class T>
bool linkedQueueType<T>::isEmptyQueue() const
{
	return (queueFront == NULL);
}
template <class T>
bool linkedQueueType<T>::isFullQueue() const
{
	return false;
}

template <class T>
void linkedQueueType<T>::initializeQueue()
{
	nodeType<T> *temp;
	while (queueFront != NULL) //while there are elements left
	{
		temp = queueFront;			   //set temp to point to the current node
		queueFront = queueFront->link; //advance first to
									   //the next node
		delete temp;
		//deallocate memory occupied by temp
	}
	queueRear = NULL; //set rear to NULL
}
//end initializeQueue

template <class T>
void linkedQueueType<T>::addQueue(const T &newElement)
{
	nodeType<T> *newNode;
	newNode = new nodeType<T>;  //create the node
	newNode->info = newElement; //store the info
	newNode->link = NULL;		//initialize the link field to NULL
	if (queueFront == NULL)		//if initially the queue is empty
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else
	//add newNode at the end
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}
//end addQueue
template <class T>
T linkedQueueType<T>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}
//end front
template <class T>
T linkedQueueType<T>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}
//end back
template <class T>
void linkedQueueType<T>::deleteQueue()
{
	nodeType<T> *temp;
	if (!isEmptyQueue())
	{
		temp = queueFront;			   //make temp point to the first node
		queueFront = queueFront->link; //advance queueFront
		delete temp;
		//delete the first node
		if (queueFront == NULL) //if after deletion the
								//queue is empty
			queueRear = NULL;   //set queueRear to NULL
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
}
//end deleteQueue
template <class T>
linkedQueueType<T>::linkedQueueType()
{
	queueFront = NULL; //set front to null
	queueRear = NULL;  //set rear to null
}
//end default constructor
int main()
{
	linkedQueueType<int> q;
	int x, y;
	q.initializeQueue();
	x = 4;
	y = 5;
	q.addQueue(x);
	q.addQueue(y);
	x = q.front();
	q.deleteQueue();
	q.addQueue(x + 5);
	q.addQueue(16);
	q.addQueue(x);
	q.addQueue(y - 3);
	cout << "Queue Elements: ";
	while (!q.isEmptyQueue())
	{
		cout << q.front() << " ";
		q.deleteQueue();
	}
	cout << endl;
	return 0;
}