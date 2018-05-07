
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;

template <class T>
class Node
{
public:
	T aData;
	Node<T> *next;
	Node<T> *prev;

	Node(T x)
	{
		aData = x;
		next = nullptr;
		prev = nullptr;
	}
	Node(const Node<T> &object)
	{
		this->aData = object.aData;
		this->next = nullptr;
		this->prev = nullptr;
	}
};
class Message
{
	friend ostream &operator<<(ostream &outp, const Message &object);

public:
	string name;
	string type;
	int date;
	int time;

	Message()
	{
		name = "";
		type = "";
		date = 0;
		time = 0;
	}
	void setTo(Message *copyThis)
	{
		name = copyThis->name;
		type = copyThis->type;
		date = copyThis->date;
		time = copyThis->time;
	}
	Message(int day, int hour, int mail)
	{
		string temp = createType();
		name = createName(temp, day, hour, mail);
		type = temp;
		date = day;
		time = hour;
	}

	string createName(string name, int day, int hour, int mail)
	{
		string temp = "";
		temp += name;
		if (day < 10)
		{
			temp += "0";
		}
		temp += to_string(day);
		if (hour < 10)
		{
			temp += "0";
		}
		temp += to_string(hour) + to_string(mail);
		return temp;
	}
	string createType()
	{
		int temp = rand() % 4 + 1;
		if (temp == 1)
		{
			return "I";
		}
		else if (temp == 2)
		{
			return "R";
		}
		else if (temp == 3)
		{
			return "E";
		}
		else
		{
			return "P";
		}
	}
};

template <class T>
class Queue
{
public:
	Node<T> *front;
	Node<T> *last;
	int counter;

	Queue()
	{
		front = nullptr;
		last = nullptr;
		counter = 0;
	}

	~Queue()
	{
		initialize();
	}
	void initialize()
	{
		front = nullptr;
		last = nullptr;
		counter = 0;
	}

	int size() const { return counter; }
	T pop()
	{
		Node<T> *cu;
		T temp;
		if (!isEmpty())
		{
			cu = front;
			temp = cu->aData;
			front = front->next;
			delete cu;
			counter--;
			return temp;
		}
		else
		{
			cout << "Queue is empty." << endl;
		}
	}
	T peekFront() { return front->aData; }
	T peekLast() { return last->aData; }

	bool isEmpty() const { return front == nullptr; }
	void push_back(T value)
	{
		Node<T> *newNode;
		newNode = new Node<T>(value);

		if (isEmpty())
		{
			front = newNode;
			last = newNode;
			counter++;
		}
		else
		{
			last->next = newNode;
			last = newNode;
			counter++;
		}
	}
};

ostream &operator<<(ostream &outp, const Message &object)
{
	outp << object.name;
	return outp;
}

void printServer(Queue<Message> q1, Queue<Message> q2, Queue<Message> q3, Queue<Message> q4)
{
	Node<Message> *p1 = q1.front, *p2 = q2.front, *p3 = q3.front, *p4 = q4.front;
	bool s1 = true, s2 = true, s3 = true, s4 = true;
	int count = 4, num = 1;

	while (count > 0)
	{
		if (num < 10)
		{
			cout << num << ". ";
		}
		else if (num < 100)
		{
			cout << num << ". ";
		}
		else
		{
			cout << num << ". ";
		}

		if (p1 != nullptr)
		{
			cout << p1->aData << "\t";
			p1 = p1->next;
		}
		else if (s1)
		{
			count--;
			s1 = false;
			cout << "           ";
		}
		else
		{
			cout << "           ";
		}

		if (p2 != nullptr)
		{
			cout << p2->aData << "\t";
			p2 = p2->next;
		}
		else if (s2)
		{
			count--;
			s2 = false;
			cout << "\t           ";
		}
		else
		{
			cout << "\t           ";
		}

		if (p3 != nullptr)
		{
			cout << p3->aData << "\t";
			p3 = p3->next;
		}
		else if (s3)
		{
			count--;
			s3 = false;
			cout << "\t        ";
		}
		else
		{
			cout << "\t        ";
		}

		if (p4 != nullptr)
		{
			cout << p4->aData << "\t";
			p4 = p4->next;
		}
		else if (s4)
		{
			count--;
			s4 = false;
			cout << "\t         ";
		}
		else
		{
			cout << "\t         ";
		}

		cout << endl;
		num++;
	}
}

int main()
{
	srand(time(NULL));
	int numDay = 1, hr = 0;
	int numofMail = 0, numMessages = 0;
	int numLInput = 0, numLError = 0;

	Queue<Message> archiveI, archiveR, archiveP, archiveE;
	Queue<Message> procressI, procressE;

	Message m;

	bool day = false;

	while (numMessages < 1000 && hr < 24)
	{

		hr++;

		if (hr == 24)
		{
			hr = 0;
			numDay++;
			day = true;
		}
		numofMail = rand() % 2 + 1;
		numMessages += numofMail;
		for (int i = 0; i < numofMail; i++)
		{

			Message *hourlyMessage = new Message(hr, numDay, i);

			m.setTo(hourlyMessage);

			delete hourlyMessage;

			if (m.type == "I")
			{
				procressI.push_back(m);
			}
			else if (m.type == "R")
			{
				archiveR.push_back(m);
			}
			else if (m.type == "E")
			{
				procressE.push_back(m);
			}
			else
			{
				archiveP.push_back(m);
			}
		}

		if (day)
		{
			for (int i = 0; i < 5; i++)
			{
				if (!procressE.isEmpty())
				{
					archiveE.push_back(procressE.pop());
				}
			}

			while (!procressE.isEmpty())
			{
				numLError++;
				procressE.pop();
			}
			int oldestInput = procressI.peekFront().date;
			while ((day - oldestInput) > 14)
			{
				procressI.pop();
				numLInput++;
				oldestInput = procressI.peekFront().date;
			}
			for (int i = 0; i < 5; i++)
			{
				if (!procressI.isEmpty())
				{
					archiveI.push_back(procressI.pop());
				}
			}
		}
		day = false;
	}

	cout << "Requests: " << archiveI.size() << endl;
	cout << "Replies: " << archiveR.size() << endl;
	cout << "Errors: " << archiveE.size() << endl;
	cout << "Information: " << archiveP.size() << endl;
	cout << "Remaining request in the Queue:  " << procressI.size() << endl;
	cout << "Error Messages in the  Queue: " << procressE.size() << endl;
	cout << "    Requests       Replies   Errors          Plain Text" << endl;
	printServer(archiveI, archiveR, archiveE, archiveP);
}

/*
* Vyas Ramankulangara: 95%
* Sam Parker: 5%
* Louis Dang: 0%
* Sarah helped me with the Message class and the printServer
*/