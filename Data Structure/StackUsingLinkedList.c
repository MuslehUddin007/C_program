#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct stack* createStack(unsigned capacity)
{
    struct stack* Stack = (struct stack*)malloc(sizeof(struct stack));
    Stack->capacity = capacity;
    Stack->top = -1;
    Stack->array = (int*)malloc(Stack->capacity*sizeof(int));
    return Stack;
}

int isFull(struct stack* Stack)
{
    return Stack->top == Stack->capacity -1;
}

int isEmpty(struct stack* Stack)
{
    return Stack->top == -1;
}

void push(struct stack* Stack, int item)
{
    if(isFull(Stack))
        return;
    Stack->array[++Stack->top] = item;
    printf("%d pushed to stack\n",item);
}

int pop(struct stack* Stack)
{
    if(isEmpty(Stack))
        return;
    return Stack->array[Stack->top--];
}

void printStack(struct stack* Stack)
{
    while(Stack->top != -1){
        printf("%d ",Stack->array[Stack->top]);
        Stack->top--;
    }
}

void main()
{
    struct stack* Stack = createStack(100);

    push(Stack,10);
    push(Stack,20);
    push(Stack,30);
    printf("%d popped from Stack\n",pop(Stack));
    printf("\n\nStack item:\n");
    printStack(Stack);
}
