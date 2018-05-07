#include <iostream>
#include <List>
#include <ctime>
#include<chrono>
#include "List.h"
using namespace std;


class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array containing buckets
    List *table;

  public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // hash function to map values to key
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }

    void displayHash();
    void searchKey(int key);
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new List[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i << ": ";
        table[i].display(); 
        cout << endl;
    }
}

void Hash::searchKey(int key){
    int index = hashFunction(key);
    
    int itemLoc = table[index].getLoc(key);
    if(itemLoc != -1){
        cout<<"The value: '"<<key<<"' is found in List: "
        <<index<<" Location: "<< itemLoc <<endl;
    }
    
    else{
        cout<<"The item can't be found in the list"<<endl;
    }
}

// Driver program
int main()
{
    srand(time(NULL));

    Hash h(10);
    int ran = 0; 
    for (int i = 0; i < 100; i++)
    {
        ran = rand() % 101;
        h.insertItem(ran);
    }
    h.displayHash();

    int n;
    cout << "Enter a number to look for     : ";
    cin >> n;
    h.searchKey(n);
    
    

    return 0;
}