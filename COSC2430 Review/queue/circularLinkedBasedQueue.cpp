#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
class Queue
{

  public:
    Node<T> *head, *tail;
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    void push(T data)
    {
        Node<T> *n = new Node<T>();
        n->data = data;
        if (isEmpty())
        {
            head = n;
            tail = n;
            tail->next = head;
        }
        else
        {
            tail->next = n;
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        Node<T> *t = head;
        head = head->next;
        tail->next = head;
        return t->data;
    }
};

int main()
{
    Queue<string> q;

    q.push("HEllo");
    q.push("World");
    cout << q.pop() << endl;
}