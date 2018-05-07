#ifndef LIST_H_
#define LIST_H_
#include "node.h"
using namespace std;
class list{
    private:
        node *head;
        node *tail;
    public:

        list(){
            head = NULL;
            tail = NULL;
        }

         ~list(){
            if(head == NULL){
                return;
            }
            node *temp = head;
            while(temp != NULL){
                node *next = temp ->next;
                delete temp;
                temp = next;
            }
        }

        void addAtEnd(char x){
            node *temp = new node(x);
            node *curr = head;
            if(head == NULL){
                head = temp;
            }else{
                while(curr->next != NULL){
                   curr = curr->next;
                }
                curr ->next = temp;
            }
        }
        bool isVowel(char ch)
        {
            switch (ch)
            {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    return true;
                default:
                    return false;
                }
        }

        void rotate(){
            node *curr = head;
            if(isVowel(curr->n)){
                addAtEnd('-');
                addAtEnd('w');
                addAtEnd('a');
                addAtEnd('y');
            }else if(curr->n == '0' || curr->n == '1' || curr->n == '2' || curr->n == '3' || curr->n == '4'|| curr->n == '5' || curr->n == '6' || curr->n == '7' || curr->n == '8' || curr->n == '9'){
                addAtEnd('-');
                addAtEnd('w');
                addAtEnd('a');
                addAtEnd('y');
            
            }else{
              char tmp;
              addAtEnd('-');
                while (isVowel(curr->n) != true && curr->next != NULL) {
                    tmp = curr->n;
                    head = curr->next;
                    addAtEnd(tmp);
                    curr = curr->next;
                  }
                addAtEnd('a');
                addAtEnd('y');
            }
        }

        void print(){
            node *current = head;
            while(current != NULL){
                cout << current->n;
                current = current->next;
            }
            cout << endl;
        }

};
#endif