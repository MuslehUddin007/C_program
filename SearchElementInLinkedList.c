#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/* Link list node */
struct Node
{
    int key;
    struct Node* next;
};

/* Given a reference (pointer to pointer) to the head
  of a list and an int, push a new node on the front
  of the list. */
void push(struct Node** head_ref, int new_key)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    /* put in the key  */
    new_node->key  = new_key;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

//using iterative//
/*bool search(struct Node* head, int x)
{
    struct Node* current = head;

    while(current != NULL){
        if(current -> key == x)
            return true;
        current = current -> next;
    }

    return false;
}*/

//using recursion//
bool search(struct Node* head,int x)
{
    if(head == NULL)
        return false;
    if(head -> key == x)
        return true;

    return search(head -> next,x);
}


//getNth position value//

int GetNth(struct Node* head, int index)
{
    struct Node* currtent = head;

    int count = 0;
    while(currtent != NULL){
        if(count == index)
            return(currtent->key);
        count++;
        currtent = currtent->next;
    }

    assert(0);
}
void main()
{
    struct Node* head = NULL;
    int x = 21;

    push(&head,10);
    push(&head,30);
    push(&head,11);
    push(&head,21);
    push(&head,14);

    search(head,21)? printf("Yes\n") : printf("No\n");
    printf("Element at index 3 is %d\n",GetNth(head,3));
}
