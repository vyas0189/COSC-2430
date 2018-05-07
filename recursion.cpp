/*
    Arguments - return?
    Condition to stop
    How many ifs? ==>testing
    how forward backwards

    17 22 11 5 3 10
    search 3 ==> recursive rep
    condtion to stop, find the number or end of the array
*/

int searchArray(int a[], int size, int key)
{

    if (size == 0)
    {
        return -1;
    }
    if (a[size - 1] == key)
    {
        return size - 1;
    }
    else
    {
        return searchArray(a, size - 1, key);
    }
}

int searchArray(int a[], int low, int upper, int key)
{

    if (low > upper)
    {
        return -1;
    }
    if (a[low] == key)
    {
        return low;
    }
    else
    {
        return searchArray(a, low + 1, upper, key);
    }
}

int search(int a[], int low, int up, int key)
{
    if (low > up)
        return -1;
    if (a[low] == key)
        return low;
    else
        return search(a, low + 1, up, key);
}

/*
    Binary Search Sorted
    5 22 43 71 89 101
    1. low + up / 2
    2.Compare the key to midddle

*/

int binarySearch(int a[], int low, int high, int key)
{
    if (low < high)
    {

        int mid = (low + high) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            return binarySearch(a, mid + 1, high, key);
        }
        else
            return binarySearch(a, low, mid - 1, key);
    }
    return -1;
}

int binarySearch(int a[], int low, int high, int key)
{
    static int mid =0;
    if (low < high)
    {
        
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            return binarySearch(a, mid + 1, high, key);
        }
        else
            return binarySearch(a, low, mid - 1, key);
    }
    return -1;
}