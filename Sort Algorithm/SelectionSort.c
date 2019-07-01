#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[],int n)
{
    int i,j,sorted_idx;

    for(i=0;i<n-1;i++){
        sorted_idx = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[sorted_idx]){
                sorted_idx=j;
            }
        }

        swap(&arr[sorted_idx],&arr[i]);
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
    selectionSort(arr,n);
    printf("Sorted Array: \n");
    printArray(arr,n);
}
