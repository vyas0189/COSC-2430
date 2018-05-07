#include <iostream>
#include <string>
using namespace std;

class stack
{
  private:
	int maxStackSize;
	int stackTop;
	char *list;

  public:
	bool isEmpty() const;
	bool isFull() const;
	void push(const char &newItem);
	char top() const;
	void pop();
	stack(int stackSize);
	~stack();
};

stack::stack(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Size of the array must be postive" << endl;
		maxStackSize = 100;
	}
	else
	{
		maxStackSize = stackSize;
	}
	stackTop = 0;
	list = new char[maxStackSize];
}

bool stack::isEmpty() const
{
	return (stackTop == 0);
}

bool stack::isFull() const
{
	return (stackTop == maxStackSize);
}

void stack::push(const char &newItem)
{
	if (!isFull())
	{
		list[stackTop] = newItem;
		stackTop++;
	}
	else
	{
		cout << "The stack is full" << endl;
	}
}

char stack::top() const
{
	if (stackTop != 0)
	{
		return list[stackTop - 1];
	}
}

void stack::pop()
{
	if (!isEmpty())
	{
		stackTop--;
	}
	else
	{
		cout << "The stack is empty" << endl;
	}
}

stack::~stack()
{
	delete[] list;
}

int main()
{
	string name;

	cout << "Enter your name: ";
	getline(cin, name);
	int size = name.length();
	int i = 0;
	stack s(size);
	while (i < size)
	{
		s.push(name[i]);
		i++;
	}

	while (!s.isEmpty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}