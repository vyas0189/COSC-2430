#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head;

Node *getnewNode(int x){
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int x){
    Node *newNode = getnewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void ReversePrint(){
    Node *temp = head;

    if(temp == nullptr){
        return;
    }

    while(temp->next !=nullptr){
        temp = temp->next;
    }

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void Print(){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){

    head = NULL;
    insertAtHead(2);
    Print();
    ReversePrint();
    insertAtHead(4);
    Print();
    ReversePrint();
    insertAtHead(6);
    Print();
    ReversePrint();


}
