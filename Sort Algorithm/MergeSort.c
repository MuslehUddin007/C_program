#include<stdio.h>

void merge(int arr[],int left1,int right1,int left2,int right2)
{
	int temp[50];	//array used for merging
	int i,j,k;
	i=left1;	//beginning of the first list
	j=left2;	//beginning of the second list
	k=0;

	while(i<=right1 && j<=right2)	//while elements in both lists
	{
		if(arr[i]<arr[j]){
            printf("IF K: %d I: %d\n",k,i);
            temp[k++]=arr[i++];
		}
		else{
		    printf("ELSE K: %d J: %d\n",k,j);
            temp[k++]=arr[j++];
		}
	}

	while(i<=right1){	//copy remaining elements of the first list
        printf("while1 K: %d I: %d\n",k,i);
		temp[k++]=arr[i++];
    }
	while(j<=right2){	//copy remaining elements of the second list
		printf("while2 K: %d J: %d\n",k,j);
		temp[k++]=arr[j++];
    }
	//Transfer elements from temp[] back to a[]
	for(i=left1,j=0;i<=right2;i++,j++){
		arr[i]=temp[j];
    }
}


void mergesort(int arr[],int left,int right)
{
	int mid;

	if(left<right)
	{
		mid=(left+right)/2;

		printf("left: %d\nRight : %d\n\n",left,mid);
		mergesort(arr,left,mid);		//left recursion

		printf("left1: %d\nRight1 : %d\n\n",mid+1,right);
		mergesort(arr,mid+1,right);	//right recursion

		printf("\nMerge: %d %d %d %d\n",left,mid,mid+1,right);
		merge(arr,left,mid,mid+1,right);	//merging of two sorted sub-arrays
	}
}


void main()
{
	int arr[30],n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter array elements:");

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	mergesort(arr,0,n-1);

	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

}
