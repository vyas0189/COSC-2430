#include <iostream>
#include "player.h"
#include "roster.h"
using namespace std;


doublell::doublell() {
    head= nullptr;
    tail= nullptr;
}

doublell::doublell(player a[]){
    int counter=0;
    while(counter<7)
    {
        benchPlayer *newNode = new benchPlayer(a[counter],'b', nullptr ,nullptr);
        counter++;

        if(head == nullptr)
        {
            head=newNode;
            tail=newNode;
        }

        else
        {
            newNode->setPrev(tail);
            tail->setNext(newNode);
            tail=newNode;
        }
    }
}

benchPlayer* doublell::getHead(){return head;}
benchPlayer* doublell::getTail(){return tail;}
void doublell::setHead(benchPlayer* p){head=p;}
void doublell::setTail(benchPlayer* p){tail=p;}

void doublell::insert(benchPlayer* add)
{
    benchPlayer* cu=head;
    if(cu == nullptr)
    {
        head = add;
        tail = add;
    }
    else
    {
        cu->setPrev(add);
        add->setNext(cu);
        head=add;
    }
}

benchPlayer* doublell::remove(int quarter)
{
    if ((quarter/2) ==0){
        return remove2ndFromBeg();
    }
    else{
        return remove2ndFromEnd();
    }
}

benchPlayer* doublell::remove2ndFromBeg() {
    benchPlayer* toRemove;
    benchPlayer* cu;
    //player to remove is the player in the 2nd node
    toRemove = head->getNext();
    //cu is the 3rd node
    cu = toRemove->getNext();
    //the previous pointer in the 3rd node points to the head
    cu->setPrev(head);
    //next of the 1st node points to the address of the 3rd node.
    head->setNext(toRemove->getNext());
    //2nd node is now removed
    return toRemove;
}

benchPlayer* doublell::remove2ndFromEnd() {
    benchPlayer* toRemove;
    benchPlayer* cu;
    //the node to remove is the 2nd to last node (AKA the node previous to the tail)
    toRemove = tail->getPrev();
    //cu is the 3rd to last node (AKA the node previous to the node that is to be removed)
    cu = toRemove->getPrev();
    //set the next pointer in the 3rd to last node to the address of the tail
    cu->setNext(tail);
    //the previous pointer of the tail points to the 3rd node
    tail->setPrev(cu);
    //the 2nd to last node is now removed
    return toRemove;
}


    void doublell::print(){
    cout<<"\tPlayers Currently on the Bench: "<<endl;
    //declare a pointer to the head
    benchPlayer* cu = head;
    //Print the information.
    do{
        if (cu->getJersey()<10){
            cout<<" ";
        }
        cout << "P" << cu->getJersey();
        cout<<" Age: "<<cu->getAge();
        cout<< " Min: "<<cu->getMin();
        if (cu->getMin()<10){
            cout<<"   ";
            if (cu->getMin()==0){
                cout<<"  ";
            }
        }
        cout<< " Status: "<<cu->getStatus()<<endl;
        cu= cu->getNext();
    }
        //Keep printing until you reach the head again.
    while(cu!= nullptr);
}



circularll::circularll()
{
    head= nullptr;
    tail= nullptr;
}

circularll::circularll(player a[])
{
    int counter=0;
    while(counter<5)
    {
        courtPlayer *newNode = new courtPlayer(a[counter],'c' ,nullptr);
        counter++;

        if(head == nullptr)
        {
            head=newNode;
            tail=newNode;
        }

        else
        {
            tail->setNext(newNode);
            tail=newNode;
        }
    }
}

courtPlayer* circularll::getHead(){return head;}
courtPlayer* circularll::getTail(){return tail;}
void circularll::setHead(courtPlayer* p){head=p;}
void circularll::setTail(courtPlayer* p){tail=p;}

void circularll::insert(courtPlayer* add)
{
    courtPlayer* before = search(add);
    if(before == head)
    {
        add->setNext(head);
        head = add;
    }
    else if(before == tail)
    {
        tail->setNext(add);
        tail = add;
    }
    else
    {
        courtPlayer* cu = before->getNext();
        add->setNext(cu);
        before->setNext(add);
    }
}

void circularll::remove(courtPlayer* x)
{
    courtPlayer *discard = head, *before = head;

    if (discard == x)
    {
        head = head->getNext();
    }
    else
    {
        discard=search(x);
        while (before->getNext()!=discard)
        {
            before=before->getNext();
        }

        if(tail == x)
        {
            tail = before;
        }

        before->setNext(discard->getNext());
    }
    delete discard;
}

//Find the node before the player.
courtPlayer* circularll::search(courtPlayer* x)
{
    double checkAge= x->getAge();
    if (checkAge >= tail->getAge())
    {
        return tail;
    }
    else if (checkAge <= head->getAge())
    {
        return head;
    }
    else
    {
        courtPlayer *cu=head, *before = head;

        while((cu->getNext() != nullptr) && (cu->getAge() < checkAge))
        {
            before = cu;
            cu= cu->getNext();
        }
        if(cu->getAge() > checkAge)
        {
            return before;
        }
        else if(cu->getAge() == checkAge)
        {
            while(cu->getAge() == checkAge)
            {
                before=cu;
                cu= cu->getNext();
            }
            return before;
        }
        else
        {
            cout<<"Search CLL Error!"<<endl;
            return nullptr;
        }
    }
}

void circularll::print()
{
    cout<<"\tPlayers Currently on the Court: "<<endl;
    //declare a pointer to the head
    courtPlayer* cu = head;
    //Print the information.
    do
    {
        if (cu->getJersey()<10)
        {
            cout<<" ";
        }
        cout << "P" << cu->getJersey();
        cout<<" Age: "<<cu->getAge();
        cout<< " Min: "<<cu->getMin();
        if (cu->getMin()<10)
        {
            cout<<"   ";
            if (cu->getMin()==0)
            {
                cout<<"  ";
            }
        }
        cout<< " Status: "<<cu->getStatus()<<endl;
        cu= cu->getNext();
    }
    //Keep printing until you reach the head again.
    while(cu!= nullptr);
}

//Creates a new courtPlayer from the bench
courtPlayer* circularll::activate(benchPlayer x)
{
    courtPlayer* joinIn= new courtPlayer(x.getJersey(), x.getAge(), x.getMin(), x.getReport(), 'c', nullptr);
    return joinIn;
}

double circularll::recordTime()
{
    double playTime = (tail->getAge())/10;
    courtPlayer* cu = head;
    while(cu!= nullptr)
    {
        double total= cu->getMin()+playTime;
        cu->setMin(total);
        cu= cu->getNext();
    }
    return playTime;
}

void circularll::destroy()
{
    courtPlayer* cu = head;
    while( cu != nullptr )
    {
        courtPlayer* next= cu->getNext();
        delete cu;
        cu = next;
    }
    head = nullptr;
}