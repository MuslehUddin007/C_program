#include<stdio.h>

int max(int a, int b){
    return (a>b)? a : b;
}

int knapsack(int maxCapacity, int wt[], int val[],int size){
    int i,w;
    int K[size+1][maxCapacity+1];

    for(i=0;i<=size;i++){
        for(w=0;w<=maxCapacity;w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[size][maxCapacity];
}

int main()
{
    int val[] = {60,10,20,100,120};
    int wt[] = {10,20,30,40,50};
    int maxWeight = 50;

    int n = sizeof(val)/sizeof(val[0]);

    printf("%d\n",knapsack(maxWeight,wt,val,n));

    return 0;
}
