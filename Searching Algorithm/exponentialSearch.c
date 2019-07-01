#include<stdio.h>

int min(int i, int size)
{
    return (i<size) ? i : size;
}

int exponentialSearch(int arr[], int size, int key)
{
    if(arr[0] == key) return 0;

    int i = 1;
    while(i < size && arr[i] <= key){
        i *= 2;
    }

    return binarySearch(arr, i/2, min(i,size), key);
}

int binarySearch(int arr[], int left, int right, int key)
{
    if(right >= left){
        int mid = (left + right) / 2;

        if(arr[mid] == key)
            return mid;

        if(arr[mid] > key)
            return binarySearch(arr, left, mid-1,key);

        else
            return binarySearch(arr,mid+1, right,key);
    }
    return -1;
}

void main()
{
    int arr[] = {2,3,4,10,40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = exponentialSearch(arr,size,key);

    if(result == -1)
        printf("Not Found!!");
    else
        printf("Found at position: %d\n",result);
}
