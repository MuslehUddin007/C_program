#include<stdio.h>
#define MAX_SIZE 1001


long static cache_fibo[MAX_SIZE];


int fibonacci(long n)
{

    //if(n<=1) return 1;

    //else return fibonacci(n-1) + fibonacci(n-2);

    if(cache_fibo[n]== -1){

        if(n<=1) return 1;

        else{

             return cache_fibo[n] = fibonacci(n-1)+fibonacci(n-2);

        }

    }

    return cache_fibo[n];

}



void main(int argc, char const *argv[])
{

    int fibo = atoi(argv[1]);

    int i = 0;

    for(i=0;i<MAX_SIZE;i++){

        if(i==0) cache_fibo[i] = 1;

        else if(i==1) cache_fibo[i] = 1;

        else{

            cache_fibo[i] = -1;

        }

    }

    fibo = fibonacci(fibo);

    printf("Fibonacci = %d\n",fibo);
}
