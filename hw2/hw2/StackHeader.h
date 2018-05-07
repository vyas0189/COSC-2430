#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
struct node {
	T info;
	node<T> *link;
};

template<typename T>
class Stack {
private:
	node<T> *stackTop;
public:
	Stack() {
		stackTop = NULL;
	}
	bool isEmpty() const {
		return (stackTop == NULL);
	}
	void initializeStack() {
		node<T> *temp;
		while (stackTop != NULL) {
			temp = stackTop;
			stackTop = stackTop->link;
			delete temp;
		}
	}

	void push(const T newElement) {
		node<T> *newNode = new node<T>;
		newNode->info = newElement;
		newNode->link = stackTop;
		stackTop = newNode;
	}
	T top() const {
		if (stackTop != NULL) {
			return stackTop->info;
		}
	}

	void pop() {
		node<T> *temp;

		if (stackTop != NULL) {
			temp = stackTop;
			stackTop = stackTop->link;
			delete temp;
		}
		else {
			cerr << "The Stack is empty!" << endl;
		}
	}

	~Stack() {
		initializeStack();
	}
};
#endif // !STACK_H