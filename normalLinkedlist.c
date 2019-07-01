#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};

void printList(struct node *n)
{
    while(n != NULL){
        printf("%s ",n->data);
        n = n -> next;
    }
}

void main()
{
    struct node *head = NULL;
    struct node *first = NULL;
    struct node *second = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));

    head -> data = "Md";
    head -> next = first;
    first -> data = "Musleh";
    first -> next = second;
    second -> data = "Uddin";
    second -> next = NULL;

    printList(head);

}
