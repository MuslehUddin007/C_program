#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int countNodes(struct node* n)
{
    int res = 1;
    struct node* temp = n;

    while(temp->next != n){
        res++;
        temp = temp->next;
    }
    return res;
}

int countNodesInLoop(struct node* list)
{
    struct node* slow_p = list, *fast_p = list;

    while(slow_p && fast_p && fast_p->next){
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if(slow_p == fast_p)
            return countNodes(slow_p);
    }
    return 0;
}

struct node* newNode(int key)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = key;
    temp -> next = NULL;

    return temp;
}

void main()
{
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    //create a loop for testing//
    head->next->next->next->next->next = head->next;

    printf("%d\n",countNodesInLoop(head));
}
