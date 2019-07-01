#include<stdio.h>
#include<math.h>

int min(int step, int n){
    return (step<n) ? step : n;
}

int jumpSearch(int arr[],int key, int size)
{
    //Finding block size to be jumped//
    int step = sqrt(size);

    //Finding the block where element is present(if present)//
    int prev = 0;
    while(arr[min(step,size)-1] < key)
    {
        prev = step;
        step += sqrt(size);
        if(prev >= size)
            return -1;
    }
    //Doing a linear search for key in block beginning with prev//
    while(arr[prev] < key){
        prev++;
        //if we reached next block or end of array, element is not present//
        if(prev == min(step,size))
            return -1;
    }

    //if element is found//
    if(arr[prev] == key)
        return prev;

    return -1;
}

void main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89, 144, 233, 377,610};
    int key = 610;
    int size = sizeof(arr) / sizeof(arr[0]);

    //Find the index of 'key' using Jump search//
    int index  = jumpSearch(arr,key,size);
    //print the index where 'key' is located//
    if(index == -1)
        printf("Not found\n");
    else
        printf("Number %d is at index %d\n",key,index);
}
