#include <iostream>
#include <iomanip> 
#include <ctime>
using namespace std;

void fill(int **p, int rowSize, int columnSize);
bool search(int **p, int rowSize, int columnSize, int elem);

int main() { 
    
    int **board;
    int row1 = 100;
    int column1 = 100;
    int elem;
    int **board2;
    int row2 = 50000, col2 =50000;
    clock_t t,t2;
    
    t = clock();
    board = new int* [row1];
    for (int i = 0; i < row1; i++)
        board[i] = new int[column1];

    // cout << "Enter a number between 0-100: ";
    // cin >> elem;
    fill(board, row1, column1);
 
    if(search(board, row1, column1, 87)){
        cout << "Element found"<< endl;
    }else{
        cout << "Element is not found" << endl;
    }
    t = clock()-t;
    //cout << t <<endl;
    cout << (float)t/CLOCKS_PER_SEC << " seconds" << endl;


    t2 = clock(); 
    board2 = new int* [row2];
    for (int i = 0; i < row2; i++)
        board2[i] = new int[col2];

    // cout << "Enter a number between 0-100: ";
    // cin >> elem;

    fill(board2, row2, col2);
    if(search(board2, row2, col2, 65)){
        cout << "Element found"<< endl;
    }else{
        cout << "Element is not found" << endl;
    }
    t2 = clock()-t2;
   // cout << t2 <<endl;
    cout <<(float)t2/CLOCKS_PER_SEC << " seconds" << endl;

   for(int i=0; i <row1;++i)
       delete [] board[i];
   delete [] board;
   for(int j=0; j < row2;++j)
       delete [] board2[j];
    delete [] board2;
   
    return 0;
}

void fill(int **p, int rowSize, int columnSize)
{
    srand(time(NULL));
    for (int row = 0; row < rowSize; row++){
        for (int col = 0; col < columnSize; col++)
            p[row][col] =rand() % 101;
    }
}
bool search(int **p, int rowSize, int columnSize,int elem){

    for (int row = 0; row < rowSize; row++){
        for (int col = 0; col < columnSize; col++){
            if(p[row][col] == elem){
                return true;
            }
        }
    }
    return false;
}