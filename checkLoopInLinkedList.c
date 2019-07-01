#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/*bool detechLoop(struct Node* head)
{
    struct Node* temp = head;

    while(head == temp || head == NULL)
        head = head->next;

    if(head == temp)
        return false;
    if(head == NULL)
        return false;
}*/

void printlist(struct Node* head)
{
    struct Node* current = head;

    printf("%d\n",head->next->next->next->data);

    while(current != NULL){
        printf("[%d]->[%d]\n",current->data,current->next);
        current = current->next;
    }
}

void main()
{
    struct Node* head = NULL;
    push(&head,20);
    push(&head,4);
    push(&head,15);
    push(&head,10);

    printlist(head);
}


