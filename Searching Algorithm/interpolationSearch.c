#include<stdio.h>

int interpolationSearch(int arr[], int size, int key)
{
    int start = 0, end = (size-1);

    while(start <= end && key >= arr[start] && key <= arr[end]){
        if(start == end){
            if(arr[start] == key)
                return start;
            return -1;
        }

        int pos = start + (((double)(end-start) / (arr[end] - arr[start])) * (key - arr[start]));

        if(arr[pos] == key)
            return pos;

        if(arr[pos] < key)
            start = pos + 1;
        else
            end = pos - 1;
    }
    return -1;
}
void main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 12; // Element to be searched
    int index = interpolationSearch(arr, n, x);
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found.");
    return 0;
}
