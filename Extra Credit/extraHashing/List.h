#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class List
{
  private:
    node *head, *tail;

  public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_back(int key)
    {
        node *temp = new node;
        temp->data = key;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    int getLoc(int key)
    {
        node *temp = head;
        int iterator = 1;
        int loc;
        while (temp->next != NULL)
        {
            if (temp->data == key)
            {
                loc = iterator;
                return loc;
            }
            temp = temp->next;
            iterator++;
        }
        return -1;
    }
    
    void display()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

#endif