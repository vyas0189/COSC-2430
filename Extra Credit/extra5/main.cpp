#include <iostream> 
#include <string> 
#include "arrayListType.h" 
using namespace std; 
#define temp template <class elemType>

int main() {
    
    arrayListType<int> intList(100);
    arrayListType<string> stringList;
    int number;
    cout << "List 10: Enter 5 integers: ";
    for (int counter = 0; counter < 5; counter++){
        cin >> number;
        intList.insertAt(counter, number);
    }
    cout << endl;
    cout << "List 19: The list you entered is: ";
    intList.print();
    cout << endl;
    cout << " 20: Enter the item to be deleted: ";
    cin >> number;
    intList.remove(number);
    cout << " 23: After removing " << number << ", the list is:" << endl;
    intList.print();
    cout << endl;
    string str;
    cout << " 27: Enter 5 strings: ";
    for (int counter = 0; counter < 5; counter++){
        cin >> str;
        stringList.insertAt(counter, str);
    }
    cout << endl;
    cout << " 34: The list you entered is: " << endl;
    stringList.print();
    cout << endl;
    cout << " 37: Enter the string to be deleted: ";
    cin >> str;
    stringList.remove(str);
    cout << " 40: After removing " << str << ", the list is:" << endl;

    stringList.print();
    cout << endl;
    return 0;
}

temp
bool arrayListType<elemType>::isEmpty() const{
    return (length == 0);
}
//O(1)
temp
bool arrayListType<elemType>::isFull() const{
    return (length == maxSize);
}
//O(1)
temp
int arrayListType<elemType>::listSize() const{
    return length;
}
//O(1)
temp
int arrayListType<elemType>::maxListSize() const{
    return maxSize;
}
//O(n)
temp
void arrayListType<elemType>::print() const{
    for(int i=0; i < length;i++){
        cout << list[i] << " ";
    }
    cout << endl;
}
//O(1)
temp
bool arrayListType<elemType>::isItemAtEqual(int locationation, const elemType& item) const{
    return (list[locationation] == item);
}
//O(n)
temp
void arrayListType<elemType>::insertAt(int locationation, const elemType& insertItem){
    if(locationation < 0 || locationation >= maxSize){
        cerr << "The postion of the item to be inserted is out of range." << endl; 
    }else{
        if(length >= maxSize){
            cerr << "The list is full." << endl;
        }else{
            for(int i=length; i > locationation; i--){
                list[i] = list[i-1];
            }
            list[locationation] = insertItem;
            length++;
        }
    }
}
//O(1)
temp
void arrayListType<elemType>:: insertEnd(const elemType& insertItem){
    if(length >= maxSize){
        cerr << "The list is full."<< endl;
    }else{
        list[length] = insertItem;
        length++;
    }
}
//O(n)
temp
void arrayListType<elemType>:: removeAt(int location){

    if(location < 0 || location >= length){
        cerr << "The postion of the item to be inserted is out of range." << endl; 
    }else{
        for(int i=location; i < length-1;i++){
            list[i] = list[i+1];
        }
        length--;
    }
}
//O(1)
temp
void arrayListType<elemType>:: retrieveAt(int location, elemType& retItem) const{
     if(location < 0 || location >= maxSize){
        cerr << "The postion of the item to be inserted is out of range." << endl; 
    }else{
        retItem = list[location];
    }
}
//O(1)
temp
void arrayListType<elemType>:: replaceAt(int location, const elemType& repItem){
    if(location < 0 || location >= maxSize){
        cerr << "The postion of the item to be inserted is out of range." << endl; 
    }else{
        list[location] = repItem;
    }
}
//O(1)
temp
void arrayListType<elemType>:: clearList(){
    length =0;
}
//O(1)
temp
arrayListType<elemType>::arrayListType(int size){
    if(size < 0){
        cerr << "The array size must be postive." << endl;
        maxSize =100;
    }else{
        maxSize = size;
    }
    length =0;
    list = new elemType[maxSize];
}
//O(1)
temp
arrayListType<elemType>:: ~arrayListType(){
    delete[] list;
}
//O(n)
temp
arrayListType<elemType>:: arrayListType(const arrayListType<elemType>& otherList){
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);
    for(int i=0; i , length;i++){
        list[i] = otherList.list[i];
    }
}
//O(n)
temp
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList){
    if(this != &otherList){
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];
        assert(list !=NULL);
        for(int i=0; i < length;i++){
            list[i] = otherList.list[i];
        }
    }
    return *this;
}

temp
int arrayListType<elemType>:: seqSearch(const elemType& item) const{
    int location;
    bool found = false;

    for(location = 0; location < length; location++){
        if(list[location] == item){
            found = true;
            break;
        }

        if(found){
            return location;
        }else{
            return -1;
        }
    }
}
//O(n)
temp
void arrayListType<elemType>:: insert(const elemType& insertItem){
    int location;
    if(length == 0){
        list[length++]= insertItem;
    }else if(length == maxSize){
        cerr << "The list is full." << endl;
    }else{
        location = seqSearch(insertItem);
        if(location == -1){
            list[length++] = insertItem;
        }else{
            cerr << "The item is already in the list" << endl;
        }
    }
}

temp
void arrayListType<elemType>:: remove(const elemType& removeItem){
    int location;   
    if(length ==0){
        cerr << "The list is empty." << endl;
    }else{
        location = seqSearch(removeItem);
        if(location !=-1){
            removeAt(location);
        }else{
            cout << "The item is not in the list." << endl;
        }
    }
}