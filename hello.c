#include<stdio.h>
#include<limits.h>

int max(int arr[]){
    int i;
    for(i=0;i<10;i++){
        printf("\n%d\n",arr[i]);
    }
    return INT_MIN;
}
void main()
{
    int arr[] = {11,12,13,14,15,16,17,18,19,20};

    //max(arr);
    printf("\n%d\n",max(arr));

}
