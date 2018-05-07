#ifndef CLASSES
#define CLASSES

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
class Node
{
  public:
	T info;
	int balance;
	Node<T> *left;
	Node<T> *right;

	Node()
	{
		balance = 0;
		left = nullptr;
		right = nullptr;
	}
	Node(T x)
	{
		info = x;
		balance = 0;
		left = nullptr;
		right = nullptr;
	}
	Node(const Node &object)
	{
		info = object.info;
		balance = object.balance;
		left = object.left;
		right = object.right;
	}
	bool isALeaf()
	{
		return ((left == nullptr) && (right == nullptr));
	}
};

template <class T>
class LinkedList
{
  public:
	Node<T> *head;
	Node<T> *tail;
	int counter;
	int day;

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
		day = -1;
	}
	LinkedList(int x)
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
		day = x;
	}
	~LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
		day = 0;
	}

	bool push_back(T x)
	{
		Node<T> *cu = new Node<T>(x);

		if (isEmpty())
		{
			head = cu;
			tail = cu;
		}
		else
		{
			cu->left = tail;
			tail->right = cu;
			tail = tail->right;
		}
		counter++;
		return true;
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void print()
	{
		if (counter == 0)
		{
			cout << " Day: " << day << " ||  No Meal " << endl;
		}
		else
		{
			Node<T> *cu = head;
			bool theEnd = false;
			int block = 0;
			string indent = "";

			if (day < 10)
			{
				cout << " Day: " << day;
			}
			else
			{
				cout << "Day: " << day;
			}
			while (!theEnd)
			{
				if (cu != nullptr)
				{
					block++;
					cout << " ||";
					cout << " " << cu->info;
				}

				if (cu == tail)
					theEnd = true;
				cu = cu->right;
			}
			cout << endl;
		}
	}
};

template <class T>
class Stack
{
  public:
	Node<T> *top;
	int counter;

	Stack()
	{
		top = nullptr;
		counter = 0;
	}
	void print()
	{
		if (!isEmpty())
		{
			Node<T> *cu = top;
			while (cu != nullptr)
			{
				cout << cu->info << " ";
				cu = cu->left;
			}
			cout << endl;
		}
	}

	~Stack()
	{
		initialize();
	}
	void initialize()
	{
		top = nullptr;
		counter = 0;
	}
	T pop()
	{
		Node<T> *cu;
		T temp;
		if (!isEmpty())
		{
			cu = top;
			temp = cu->info;
			top = top->left;
			delete cu;
			counter--;
			return temp;
		}
		else
		{
			cout << "Pop Error: Can not remove a node from an empty stack!" << endl;
		}
	}

	bool isEmpty() const
	{
		return top == nullptr;
	}
	T peek() const
	{
		if (isEmpty())
		{
			cout << "Top Error: Attempting to read top of an empty stack" << endl;
		}
		else
		{
			return top->info;
		}
	}
	void push(const T &value)
	{
		Node<T> *newNode;
		newNode = new Node<T>(value);
		newNode->left = top;
		top = newNode;
		counter++;
	}
	int size() const
	{
		return counter;
	}
};

template <class T>
class BST
{
  public:
	Node<T> *root;
	int counter;

	BST()
	{
		root = nullptr;
		counter = 0;
	}
	BST(Node<T> *x)
	{
		root = cu;
		counter = 1;
	}

	bool search(T key)
	{
		Node<T> *start = root;
		return searchHelper(start, key);
	}
	bool searchHelper(Node<T> *cu, T key)
	{
		if (cu == nullptr)
		{
			return false;
		}
		else if (cu->info == key)
		{
			return true;
		}
		else if (cu->info > key)
		{
			return searchHelper(cu->right, key);
		}
		else
		{
			return searchHelper(cu->left, key);
		}
	}
	bool isEmpty()
	{
		return root == nullptr;
	}

	void add(T value)
	{
		Node<T> *start = root;
		if (start == nullptr)
		{
			root = new Node<T>(value);
		}
		else
		{
			addHelper(start, value);
		}
	}
	void addHelper(Node<T> *&cu, T value)
	{
		if (cu == nullptr)
		{
			cu = new Node<T>(value);
			counter++;
		}
		else if (value < cu->info)
		{
			addHelper(cu->left, value);
		}
		else if (value > cu->info)
		{
			addHelper(cu->right, value);
		}
	}

	void updateBalance(Node<T> *cu)
	{
		cu->balance = height(cu->right) - height(cu->left);
	}
	bool isAVL(Node<T> *cu)
	{
		updateBalance(cu);
		return (abs(cu->balance) < 2);
	}
	void rotateToLeft(Node<T> *&cu)
	{
		Node<T> *p;
		if (cu == nullptr)
		{
			cout << "BST::rotateToLeft() Error!" << endl;
		}
		else if (cu->right == nullptr)
		{
			cout << "BST::rotateToLeft() Error: No right tree to rotate!" << endl;
		}
		else
		{
			p = cu->right;
			cu->right = p->left;
			p->left = cu;
			cu = p;
		}
	}
	void rotateToRight(Node<T> *&cu)
	{
		Node<T> *p;
		if (cu == nullptr)
		{
			cout << "Error in the tree" << endl;
		}
		else if (cu->left == nullptr)
		{
			cout << " No left subtree to rotate." << endl;
		}
		else
		{
			p = cu->left;
			cu->left = p->right;
			p->right = cu;
			cu = p;
		}
	}
	void balanceFromLeft(Node<T> *&cu)
	{
		Node<T> *p;
		Node<T> *w;
		p = cu->left;
		switch (p->balance)
		{
		case -1:
			cu->balance = 0;
			p->balance = 0;
			rotateToRight(cu);
			break;
		case 0:
			cout << "Error: Cannot balance from the left." << endl;
			break;
		case 1:
			w = p->right;

			switch (w->balance)
			{
			case -1:
				cu->balance = 1;
				p->balance = 0;
				break;
			case 0:
				cu->balance = 0;
				p->balance = 0;
				break;
			case 1:
				cu->balance = 0;
				p->balance = -1;
			}
			w->balance = 0;
			rotateToLeft(p);
			cu->left = p;
			rotateToRight(cu);
		}
	}
	void balanceFromRight(Node<T> *&cu)
	{
		Node<T> *p;
		Node<T> *w;
		p = cu->right;
		switch (p->balance)
		{
		case -1:
			w = p->left;
			switch (w->balance)
			{
			case -1:
				cu->balance = 0;
				p->balance = 1;
				break;
			case 0:
				cu->balance = 0;
				p->balance = 0;
				break;
			case 1:
				cu->balance = -1;
				p->balance = 0;
			}
			w->balance = 0;
			rotateToRight(p);
			cu->right = p;
			rotateToLeft(cu);
			break;
		case 0:

			break;

		case 1:
			root->balance = 0;
			p->balance = 0;
			rotateToLeft(cu);
		}
	}
	void avlInsert(Node<T> *&cu, Node<T> *newNode, bool &isTaller)
	{
		if (cu == nullptr)
		{
			cu = newNode;
			isTaller = true;
		}
		else if (cu->info == newNode->info)
		{
			cout << "No duplicates are allowed. " << cu->info;
			cout << " matches with " << newNode->info << endl;
		}
		else if (cu->info > newNode->info)
		{
			avlInsert(cu->left, newNode, isTaller);
			if (isTaller)
				switch (cu->balance)
				{
				case -1:
					balanceFromLeft(cu);
					isTaller = false;
					break;
				case 0:
					cu->balance = -1;
					isTaller = true;
					break;

				case 1:
					cu->balance = 0;
					isTaller = false;
				}
		}
		else
		{
			avlInsert(cu->right, newNode, isTaller);
			if (isTaller)
				switch (cu->balance)
				{
				case -1:
					cu->balance = 0;
					isTaller = false;
					break;
				case 0:
					cu->balance = 1;
					isTaller = true;
					break;
				case 1:
					balanceFromRight(cu);
					isTaller = false;
				}
		}
	}
	void insertIntoAVL(const T &newItem)
	{
		counter++;
		bool isTaller = false;
		Node<T> *newNode;
		newNode = new Node<T>;
		newNode->info = newItem;
		avlInsert(root, newNode, isTaller);
	}

	Node<T> *dailyMeal()
	{
		int choice = rand() % counter;

		Stack<Node<Food> *> stack;
		Node<Food> *cu = root;
		while (((cu != nullptr) || (!stack.isEmpty())) && (choice > 0))
		{
			if (cu != nullptr)
			{
				stack.push(cu);
				cu = cu->left;
			}
			else
			{
				cu = stack.pop();
				choice--;
				if (choice <= 0)
				{
					return cu;
				}
				cu = cu->right;
			}
		}
	}
};

class Food
{
	friend ostream &operator<<(ostream &outp, const Food &object);

  public:
	string name;
	int calories;
	int category;
	int favorite;
	bool diet;

	Food()
	{
		name = "";
		calories = 0;
		category = 0;
		favorite = 0;
		diet = false;
	}
	Food(string a, int b, int c)
	{
		name = a;
		calories = b;
		category = c;
		favorite = 0;
		diet = false;
	}
	void setAll(string a, int b, int c)
	{
		name = a;
		calories = b;
		category = c;
	}
	void goOnDiet()
	{
		diet = true;
	}
	void eatThis()
	{
		favorite++;
	}

	void showAll();

	bool operator==(Food &ob1) const;
	bool operator!=(Food &ob1) const;
	bool operator<=(Food &ob1) const;
	bool operator>=(Food &ob1) const;
	bool operator<(Food &ob1) const;
	bool operator>(Food &ob1) const;
};

bool Food::operator==(Food &ob1) const
{
	if (diet)
	{
		if (this->calories == ob1.calories)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->name == ob1.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Food::operator!=(Food &ob1) const
{
	if (diet)
	{
		if (this->calories != ob1.calories)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->name != ob1.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Food::operator<=(Food &ob1) const
{
	if (diet)
	{
		if (this->calories <= ob1.calories)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->name <= ob1.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Food::operator>=(Food &ob1) const
{
	if (diet)
	{
		if (this->calories >= ob1.calories)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->name >= ob1.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Food::operator<(Food &ob1) const
{
	if (diet)
	{
		if (this->calories < ob1.calories)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->name < ob1.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Food::operator>(Food &ob1) const
{
	if (diet)
	{
		if (this->calories > ob1.calories)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->name > ob1.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Food::showAll()
{
	cout << "Name: " << name;
	int size = 20 - name.length();
	string indent = " ";
	for (int i = 0; i < size; i++)
	{
		indent += " ";
	}
	cout << indent << "Calories: " << calories;
	if (calories > 99)
	{
		indent = "  ";
	}
	else if (calories > 9)
	{
		indent = "   ";
	}
	else
	{
		indent = "    ";
	}
	cout << indent << "Type: ";
	if (category == 1)
	{
		cout << "Plants";
	}
	else if (category == 2)
	{
		cout << "Protein";
	}
	else if (category == 3)
	{
		cout << "Carbs";
	}
	else if (category == 4)
	{
		cout << "Dairy";
	}
	else
	{
		cout << "Food.category Error: Invalid integer value!";
	}
	cout << endl;
}

ostream &operator<<(ostream &outp, const Food &object)
{
	outp << object.name;
	return outp;
}

#endif
