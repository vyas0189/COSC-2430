#include <iostream>
#include <string>
#include<algorithm>
#include <fstream>
using namespace std;;

template<typename T>
struct node {

	T info;
	int bfactor;
	node<T> *right;
	node<T> *left;
};


template<typename T>
class avl {
	node<T> *root;
	void postOrder(node<T> *);
	void insertIntoAVL(node<T> *&root, node<T> *newNode, bool &isTaller);
	void rotateToLeft(node<T> *&);
	void rotateToRight(node<T> *&);
	void balanceFromLeft(node<T> *&);
	void balanceFromRight(node<T> *&);
public:
	void insert(T);
	void print();
	avl() {
		root = NULL;
	}
};


template <class T>
void avl<T>::rotateToRight(node<T> *&root)
{
	node<T> *p; //pointer to the root of
				   //the left subtree of root
	if (root == NULL)
		cerr << "Error in the tree" << endl;
	else if (root->left == NULL)
		cerr << "Error in the tree:" << " No left subtree to rotate." << endl;
	else
	{
		p = root->left;
		root->left = p->right; //the right subtree of p becomes
								//the left subtree of root
		p->right = root;
		root = p; //make p the new root node
	}
}
template <class T>
void avl<T>::rotateToLeft(node<T> *&root)
{
	node<T> *p; //pointer to the root of the
				   //right subtree of root
	if (root == NULL)
		cerr << "Error in the tree" << endl;
	else if (root->right == NULL)
		cerr << "Error in the tree:" << " No right subtree to rotate." << endl;
	else
	{
		p = root->right;
		root->right = p->left; //the left subtree of p becomes
								//the right subtree of root
		p->left = root;
		root = p; //make p the new root node
	}
}


template <class T>
void avl<T>::balanceFromLeft(node<T> *&root)
{
	node<T> *p;
	node<T> *w;
	p = root->left; //p points to the left subtree of root
	switch (p->bfactor)
	{
	case -1:
		root->bfactor = 0;
		p->bfactor = 0;
		rotateToRight(root);
		break;
	case 0:
		cerr << "Error: Cannot balance from the left." << endl;
		break;
	case 1:
		w = p->right;
		switch (w->bfactor) //adjust the balance factors
		{
		case -1:
			root->bfactor = 1;
			p->bfactor = 0;
			break;
		case 0:
			root->bfactor = 0;
			p->bfactor = 0;
			break;
		case 1:
			root->bfactor = 0;
			p->bfactor = -1;
		}
		//end switch
		w->bfactor = 0;
		rotateToLeft(p);
		root->left = p;
		rotateToRight(root);
	}
	//end switch;
}

template <class T>
void avl<T>::balanceFromRight(node<T> *&root)
{
	node<T> *p;
	node<T> *w;
	p = root->right; //p points to the left subtree of root
	switch (p->bfactor)
	{
	case -1:
		w = p->left;
		switch (w->bfactor) //adjust the balance factors
		{
		case -1:
			root->bfactor = 0;
			p->bfactor = 1;
			break;
		case 0:
			root->bfactor = 0;
			p->bfactor = 0;
			break;
		case 1:
			root->bfactor = -1;
			p->bfactor = 0;
		}
		//end switch
		w->bfactor = 0;
		rotateToRight(p);
		root->right = p;
		rotateToLeft(root);
		break;
	case 0:
		cerr << "Error: Cannot balance from the left." << endl;
		break;
	case 1:
		root->bfactor = 0;
		p->bfactor = 0;
		rotateToLeft(root);
	}
	//end switch;
}
template<typename T>
void avl<T>::insert(T val) {
	bool isTaller = false;
	node<T> *newNode;

	newNode = new node<T>;
	newNode->info = val;
	newNode->bfactor = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	insertIntoAVL(root, newNode, isTaller);
}

template <class T>
void avl<T>::insertIntoAVL(node<T> *&root, node<T> *newNode, bool &isTaller)
{
	if (root == NULL)
	{
		root = newNode;
		isTaller = true;
	}
	else if (root->info > newNode->info) //newItem goes in the left subtree
	{
		insertIntoAVL(root->left, newNode, isTaller);	
		if (isTaller) //after insertion, the subtree grew in height
			switch (root->bfactor)
			{
			case -1:
				balanceFromLeft(root);
				isTaller = false;
				break;
			case 0:
				root->bfactor = -1;
				isTaller = true;
				break;
			case 1:
				root->bfactor = 0;
				isTaller = false;
			}
		//end switch
	}
	//end if
	else
	{
		insertIntoAVL(root->right, newNode, isTaller);
		if (isTaller) //after insertion, the subtree grew in
					  //height
			switch (root->bfactor)
			{
			case -1:
				root->bfactor = 0;
				isTaller = false;
				break;
			case 0:
				root->bfactor = 1;
				isTaller = true;
				break;
			case 1:
				balanceFromRight(root);
				isTaller = false;
			}
		//end switch
	}
	//end else
}

template<typename T>
void avl<T>::print() {
	postOrder(root);
}


template<typename T>
void avl<T>::postOrder(node<T> *p)
{
	if (p != NULL)
	{
		postOrder(p->left);
		postOrder(p->right);
		cout << p->info << endl;
	}
}
int main() {
	avl<int> avlI;
	avl<string> avlS;
	fstream ifs("people.txt");
	int id;
	string name;
	while (ifs >> id >> name)
	{
		avlI.insert(id);
		avlS.insert(name);
	}
	
	//avl<int> avlI;
	//avl<string> avlS;
	//int i=0;
	//int id;
	//string name;
	//cout << "Enter -1 to exit." << endl;
	//do {
	//	cout << "Enter the ID: ";
	//	cin >> id;
	//	if (id == -1) {
	//		break;
	//	}
	//	cout << "Enter the name: ";
	//	cin >> name;
	//	avlI.insert(id);
	//	avlS.insert(name);
	//} while (id != -1);

	avlI.print();
	avlS.print();

}