#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void printArray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[] = {25,64,12,22,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted Array: \n");
    printArray(arr,n);
    bubbleSort(arr,n);
    printf("Sorted Array: \n");
    printArray(arr,n);
}
