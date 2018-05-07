#include <iostream>
#include <string>
#include <ctime>
using  namespace std;

struct node{
    char info;
    node *link;
};

class linkedStack{
    private:
        node *stackTop;
    public:
        linkedStack(){
            stackTop = NULL;
        }
        bool isEmpty() const{
            return (stackTop == NULL);
        }
        void initializeStack(){
            node *temp;
            while(stackTop != NULL){
                temp = stackTop;
                stackTop = stackTop->link;
                delete temp;
            }
        }

        void push(const char newElement){
            node *newNode = new node;
            newNode->info = newElement;
            newNode->link = stackTop;
            stackTop = newNode;
        }
        char top() const{
            if(stackTop != NULL){
                return stackTop->info;
            }
        }

        void pop(){
            node *temp;

            if(stackTop != NULL){
                temp = stackTop;
                stackTop = stackTop->link;
                delete temp;
            }else{
                cerr << "The stack is empty!" << endl;
            }
        }

        ~linkedStack(){
            initializeStack();
        }
};

int main(){
    linkedStack s;
    clock_t t, t2;
    string name;
    cout << "Enter your name: ";
    getline(cin,name);
    t = clock();
    int size = name.length();
    int i=0;

    while(i < size){
        s.push(name[i]);
        i++;
    }

    while(!s.isEmpty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
    t2 = clock();
        float diff =((float)t2-(float)t)/CLOCKS_PER_SEC;
    cout<<diff<<" seconds" << endl;