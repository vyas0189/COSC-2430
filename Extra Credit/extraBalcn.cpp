#include <iostream>
#include <string>
#include <ctime>
using  namespace std;

template<typename T>
struct node{
    T info;
    node<T> *link;
};

template<typename T>
class stack{
    private:
        node<T> *stackTop;
    public:
        stack(){
            stackTop = NULL;
        }
        bool isEmpty() const{
            return (stackTop == NULL);
        }
        void initializeStack(){
            node<T> *temp;
            while(stackTop != NULL){
                temp = stackTop;
                stackTop = stackTop->link;
                delete temp;
            }
        }

        void push(const T newElement){
            node<T> *newNode = new node<T>;
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
            node<T> *temp;

            if(stackTop != NULL){
                temp = stackTop;
                stackTop = stackTop->link;
                delete temp;
            }else{
                cerr << "The stack is empty!" << endl;
            }
        }

        ~stack(){
            initializeStack();
        }
};
bool match(char a, char b){
    if(a == '(' && b == ')') return true;
    if(a== '{' && b == '}') return true;
    if(a == '[' && b == ']') return true;

    return false;
}
int main(){
    stack<char> exp;
    cout << "Enter a expression: ";
    string expression;
    getline(cin,expression);
    int size  = expression.length();
    int i=0;
    while(expression[i] != ')' || expression[i] != '}' || expression[i] != ']'){
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            exp.push(expression[i]);
        }
        i++;
    }
    int j=i;
    while(j < size){
        if(match(exp.top(), expression[j])){
            cout << "The expression is balanced" << endl;
            break;
        }
    }

}