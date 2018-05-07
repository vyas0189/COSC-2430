#ifndef STACK_
#define STACK_

template <typename T>
class Stack
{
  private:
    int maxStackSize;
    int stackTop;
    T *list;
    void copyStack(const Stack<T> &otherStack);

  public:
    const Stack<T> &operator=(const Stack<T> &);
    void initilizeStack();
    bool isEmpty() const;
    bool isFull();
    void push(const T &newItem);
    T top() const;
    void pop();
    Stack(int stackSize = 100);
    Stack(const Stack<T> &otherStack);
    ~Stack();
};

template<typename T>
void Stack<T>::initilizeStack(){
    stackTop = 0;
}

template<typename T>
bool Stack<T>::isEmpty() const{
    return(stackTop == 0);
}

template<typename T>
bool Stack<T>::isFull(){
    return (stackTop==maxStackSize);
}


#endif