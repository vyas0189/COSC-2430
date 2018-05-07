#ifndef NODE
#define NODE
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class node
{
public:
	string record;
	node* next;
	node* previous;

	node(string data) {
		record = data;
		next = nullptr;
		previous = nullptr;
	}
};

class linkedList // (linkedList class)
{
public:

	node * head;
	node* tail;
	int counter;  //Increment when a new node is created & Decrement when a node is deleted.
	string filename;  //input file
	string *listToArray; // dynamic array to store nodes of a linked list

	linkedList()
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
		filename = "";
		listToArray = nullptr;
	}


	linkedList(string theFilename)
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
		filename = theFilename;
		listToArray = nullptr;
	}

	void readFromFile()
	{

		string line;
		ifstream input;
		input.open(filename);

		while (!input.eof())
		{

			getline(input, line);
			node* current = new node(line);

			if (head == nullptr) {
				head = current;
				tail = current;
				counter++;
			}
			else {
				tail->next = current;
				current->previous = tail;
				tail = current;
				counter++;
			}

		}
		input.close();
	}

	void readAttributes()
	{

		string line;
		ifstream input;
		input.open(filename);

		while (!input.eof())
		{

			input >> line;
			node* current = new node(line);

			if (head == nullptr) {
				head = current;
				tail = current;
				counter++;
			}
			else {
				tail->next = current;
				current->previous = tail;
				tail = current;
				counter++;
			}

		}
		input.close();
	}


	void fillArray() {
		//Declare a dynamic array to store the records.
		//The size of the array is dependent on the number of nodes in the list.

		if (head != nullptr) {
			listToArray = new string[counter];
			node* current = head;
			for (int i = 0; i<counter; i++) {
				listToArray[i] = current->record;
				current = current->next;
			}
		}
	}

	void destroy()
	{
		if (head != nullptr)
		{
			while (tail != head)
			{
				node *cu = tail;
				tail = tail->previous;
				delete cu;
			}
			node *cu = tail;
			tail = nullptr;
			head = nullptr;
			delete cu;
		}

	}
};
#endif