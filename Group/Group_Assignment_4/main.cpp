#include <iostream>
#include <iomanip>
#include "player.h"
#include "roster.h"
using namespace std;


void fillLockerRoom(player a[]);
void printRoster(player a[]);
void pick5(int a[]);
void splitRosters(player a[], player b[], player c[], int d[]);

//Sorting Methods
int* getMin(int array[], int size, int counter);
void selectionSort(int array[]);
player* getMinAge(player a[], int counter);
void ageSort(player a[]);

//Roster Swapping Methods


int main() {
    ///Create the rosters:
    srand(time(0));
    player lockerRoom[12], court[5], bench[7], test[5];
    int selection[5];
    fillLockerRoom(lockerRoom);
    pick5(selection);
    selectionSort(selection);
    splitRosters(lockerRoom, bench, court, selection);
    ageSort(court);

    ///Create a CLL of players on the court:
    circularll game(court);

    ///Create a DLL of players on the bench:
    doublell resting(bench);

    //TODO Delete this when you're done debugging.
    ////Debug Console: Print the contents of the arrays/lists to check your functions
    cout<<"\tBench Roster"<<endl;
    for (int i=0;i<7;i++){
        if (bench[i].getJersey()<10){
            cout<<" ";
        }
        cout << "P" << bench[i].getJersey();
        cout<<" Age: "<<bench[i].getAge();
        cout<< " Min: "<<bench[i].getMin();
        if (bench[i].getMin()<10){
            cout<<"   ";
            if (bench[i].getMin()==0){
                cout<<"  ";
            }
        }
        cout<<endl;
    }

    resting.print();
    game.print();

    circularll game1(court);
    doublell resting1(bench);

    cout << "\n\tBefore the Game Start:"<<endl;
    game1.print();

    cout << "\n\tOne round of Gameplay."<<endl;
    double timeElps = game1.recordTime();
    game1.print();

    cout << "\n\tTwo Rounds of Gameplay."<<endl;
    timeElps+=game1.recordTime();
    game1.print();

    cout << "\n\tTime Elapsed so far: " << timeElps << endl;
    cout <<"\tTime Remainiing so far: " << 48-timeElps << endl;

	system("pause");
    return 0;
}

//Fill the array with 12 players with random ages.
void fillLockerRoom(player a[]){
    for(int i=0;i<12;i++){
        a[i].setJersey(i);
        a[i].setAge(rand()%30+15);
    }
}

//Show the random assignments.
void printRoster(player a[]){
    cout<<"---------- Team Roster ----------"<<endl;
    for(int i=0;i<12;i++){
        if(i<10){
            cout<<" ";
        }
        cout<<a[i]<<endl;
    }
    cout<<"---------------------------------"<<endl;
}

//Get 5 unique random numbers.
void pick5(int a[]){
    int index=0, choice;
    for (int i=0;i<5;i++){
        do{
            choice=rand()%12;
            for (int j=0;j<5;j++){
                if (choice== a[j]){
                    choice=0;
                    break;
                }
            }
        }while(choice==0);
        a[index]=choice;
        index++;
        }
}

//Fill the rosters with their respective players.
void splitRosters(player a[], player b[], player c[], int d[]){
    int benchCount=0, courtCount=0;
    for (int i=0;i<12;i++){
        if (d[courtCount]==a[i].getJersey()){
            c[courtCount].setAll(a[i]);
            courtCount++;
        }
        else{
            b[benchCount].setAll(a[i]);
            benchCount++;
        }
    }
}

int* getMin(int array[], int size, int counter)
{   int min = array[counter], indexMin = counter;
    for (int i = counter+1;i<size;i++)
    {
        if (array[i]<min)
        {
            min = array[i];
            indexMin=i;}
    }
    return &array[indexMin];
}

player* getMinAge(player a[], int counter){
    player min = a[counter];
    int indexMin=counter;
    for(int i=counter+1;i<5;i++){
        if (a[i].getAge() < min.getAge()) {
            min =a[i];
            indexMin=i;
        }
    }
    return &a[indexMin];
}

void ageSort(player a[]){
    for (int i=0;i<4;i++){
        swap(a[i], *getMinAge(a,i));
    }
}

void selectionSort(int array[])
{
    for (int i=0; i<4; i++)
    {
        swap(array[i], *getMin(array,5,i));
    }
}