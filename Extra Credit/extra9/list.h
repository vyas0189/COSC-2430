#ifndef LIST_H_
#define LIST_H_

#include "node.h"
#include <iostream>
using namespace std;

class list{

    private:
        node *head;
    public:
        list(){
            head =NULL;
        }
        void addAtEnd(int x){
            node *temp = new node(x);
            node *current = head;
            if(head == NULL){
                head = temp;
            }else{
                while(current->next != NULL){
                    current = current->next;
                }
                current->next = temp;
            }
        }

        void addAtBeg(int num){
            node *temp = new node(num);
            temp->next = head;
            head = temp;
        }

        void addinMiddle(int num){
            node *temp = new node(num);
            node *cu = head;
            node *per = 0;
            while(cu->n < num){
                per = cu;
                cu = cu->next;
            }
            temp->next =cu->next;
            cu =temp;
            per->next= temp;

        }

        void addBasedonPos(int uNum, int pos){
            node *temp = new node(uNum);
            node *cu = head;
            node *per =0;
            int i=0;
            while(i<pos){
               per = cu;
               cu = cu->next;
               temp->next = cu;
               per->next =temp;
               i++;
            }

           
        }

        void print(){
            node *current = head;
            while(current != NULL){
                cout << current->n << endl;
                current = current->next;
            }
        }
};
#endif