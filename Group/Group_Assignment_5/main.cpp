#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Friend {
public:
	string name;
	double initial;
	double money;
	Friend *next;
	Friend *prev;
	Friend();
	Friend(int, double);
};

Friend::Friend() {
	name = " ";
	initial = 0;
	money = 0;
	next = NULL;
	prev = NULL;
}

Friend::Friend(int id, double y) {
	name = "Friend " + to_string(id);
	initial = y;
	money = y;
	next = NULL;
	prev = NULL;
}
class Group {
public:
	Friend *head;
	Friend *tail;
	int index;
	Group() {
		head = NULL;
		tail = NULL;
		index = 0;
	}
	bool isEmpty() {
		return (head == NULL);
	}
	void push_front(double elem) {
		Friend *curr = new Friend(index, elem);

		if (isEmpty()) {
			curr->next = curr;
			curr->prev = curr;
			head = curr;
			tail = curr;
		}
		else
		{
			curr->prev = tail;
			curr->next = head;
			tail->next = curr;
			head->prev = curr;
			head = curr;
		}
		index++;
	}
	void push_middle(Friend *temp, double amount) {
		Friend *trail = temp->prev;
		Friend *current = new Friend(index, amount);

		if (!isEmpty()) {
			if (head != tail) {
				trail->next = current;
				temp->prev = current;
				current->next = temp;
				current->prev = trail;
				index++;
			}
			else
			{
				if (head->money >= amount) {
					push_front(amount);
				}
				else
				{
					push_back(amount);
				}
			}
		}
	}

	void push_back(double amount) {
		Friend *curr = new Friend(index, amount);

		if (isEmpty()) {
			curr->next = curr;
			tail->prev = curr;
			head = curr;
			tail = curr;
		}
		else
		{
			curr->prev = tail;
			curr->next = curr;
			tail = curr;
			curr->next = head;
			head->prev = curr;
		}
		index++;
	}
	void insert(double money) {
		Friend *curr = new Friend(index, money);

		if (isEmpty()) {
			push_front(money);
		}
		else if (curr == head) {
			push_middle(curr, money);
		}
	}
};
int fib(int a, int b, int c) {
	if (a == 0) {
		return b;
	}
	if (a == 1) {
		return c;
	}
	return fib(a - 1, c, b + c);
}

double createMoney() {
	double mon = rand() % (101 - 1000) + 1000;
	return mon;
}
int main() {
	srand(time(NULL));
	Group g;
	double money;
	for (int i = 0; i < 5; i++) {
		money = createMoney();
		g.insert(money);
	}
	



	
}
/*
* Vyas Ramankulangara: 100%
* Sam Parker: 0%
* Louis Dang: 0%
*/
