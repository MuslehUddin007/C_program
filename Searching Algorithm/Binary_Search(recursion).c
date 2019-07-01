#include<stdio.h>

int binarySearch(int arr[],int l, int r, int x)
{
    if(r >= l){
        int mid = l+(l + r)/2;

        if(arr[mid] == x) return mid;

        if(arr[mid] > x) return binarySearch(arr,l,mid-1,x);

        return binarySearch(arr,mid+1,r,x);
    }
    return -1;
}

void main()
{
    int arr[] = {2,3,4,10,40,45,78,99};

    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    int result = binarySearch(arr,0,n-1,x);

    (result == -1) ? printf("Not found!!") : printf("Found!!");
}
