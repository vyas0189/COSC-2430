#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void bubbleSort(int arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[i + 1] = key;
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* function to sort arr using shellSort */
void shellSort(int arr[], int n)
{
    int gap = n/2;
    while(gap > 0){
        int j = 0;
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            for(j = i; j >= gap && arr[j-gap] > temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
        gap = gap/2;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int len = 5;

    cout << "UNSORTED: " << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    bubbleSort(arr, len);
    cout << "Bubble SORT: " << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    insertionSort(arr, len);
    cout << "Insertion SORT: " << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    selectionSort(arr, len);
    cout << "Selection SORT: " << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    quickSort(arr, 0, len - 1);
    cout << "Quick SORT: " << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    shellSort(arr, len);
    cout << "Shell SORT: " << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}