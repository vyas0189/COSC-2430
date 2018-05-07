/*
    1. Array of pointers (ALL Head Are Initialized to NULL)
    2. Has a function: apply on data to get address
    3. Every time we read data
        a. Apply has function get the address
        Add to linked list (at the end, at the beginning, insertion sort)

        Extra Program: Replaces a group assignment
            1. Create an array arr of pointers of size 10
            2. Initialize all pointers to zero
            3. Generate 100 numbers (randomly, fill prime numbers,fill fibonacci)
                for every number
                int address = apply h(x) int h(int v){return v%10}
                arr[address] is the head of the linked list where to add the number x
                    a. insert x at the end/ beginning  of the list
                    b. use insertion sort to insert
            4. search .... ask the user for a number (or generate randomly) binary search if(you do a, or b it will be linear search)
            5. Print an explicit location
                Ex: 
                    -Your number can be found at location address in the array arr
                    -The location in the list is not found in the list or its is at the location
            6. Big O analysis -> how long does it take to search for a value
*/

/*
    Buckets -> no comparsion
    One Array, 10 queues
        1. Write a function to find the lotal number of digits
        2. For loop from 1-> maxdigits
            check the 1 digit postion, fill all the ques
            empty all the queues in order and overwrite the array
        3. Make sure all queues are empty before each round
        4 Big O (add clock check the time)
*/

