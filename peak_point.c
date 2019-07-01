#include<stdio.h>



void main()

{

    int arr[]={7,9,-2,-1,5,7,18};

    int i,x;

    x=7;//sizeof(arr)/sizeof(arr[0]);

    for(i=0;i<x;i++){

        if(i != x && arr[i] >= arr[i+1] && arr[i] >= arr[i-1]){

            printf("%d is peak\n",arr[i]);

        }

        else if(i == x && i+1>x && arr[i] >= arr[i-1]){

            printf("%d is not peak point\n",arr[i]);

        }

    }



}
