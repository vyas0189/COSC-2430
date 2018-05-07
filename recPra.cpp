#include <iostream>
using namespace std;

#define MAX 100
int arr[100];

int fib(int n)
{
    if (arr[n] == -1)
    {
        if (n <= 1)
            arr[n] = n;
        else
            arr[n] = fib(n - 1) + fib(n - 2);
    }

    return arr[n];
}

int main()
{

    for (int i = 0; i < MAX; i++)
    {
        arr[i] = -1;
    }

    int fibNumber;
    //cin >> fibNumber;
    cout << fib(12) << endl;
}