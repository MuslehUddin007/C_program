#include<stdio.h>

int ternarySearch(int arr[], int left, int right, int key)
{
    if(right >= left){
        int mid1 = left + (right - left)/3;
        int mid2 = mid1 + (right - left)/3;
        printf("%d %d\n",mid1,mid2);
        if(arr[mid1] == key) return mid1;
        if(arr[mid2] == key) return mid2;
        if(arr[mid1] > key)
            return ternarySearch(arr,left,mid1-1,key);
        if(arr[mid2] < key)
            return ternarySearch(arr, mid2+1, right, key);

        return ternarySearch(arr,mid1+1,mid2-1,key);//if key is inside mid1 and mid2//
    }
    return -1;
}

void main()
{
    int arr[] = {1,2,3,4,5,6,78,95,110};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int result = ternarySearch(arr,0,size,key);

    if(result == -1)
        printf("Not found!!");
    else
        printf("Element found position: %d\n",result);
}
