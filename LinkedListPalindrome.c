#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    char data;
    struct node* next;
};

bool isPalindromeUtil(struct node **left, struct node *right)
{
    if(right == NULL)
        return true;
    bool isp = isPalindromeUtil(left,right->next);
    if(isp == false)
        return false;

    bool isp1 = (right->data == (*left)->data);

    *left = (*left)->next;

    return isp1;
}

bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head,head);
}

void push(struct node** head_ref, char new_data)
{
    struct node* new_Node = (struct node*)malloc(sizeof(struct node));

    new_Node->data = new_data;
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}

void printList(struct node* head)
{
    while(head != NULL){
        printf("%c->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void main()
{
    struct node* head = NULL;
    char str[] = "abacaba";

    for(int i = 0;str[i] != '\0';i++){
        push(&head,str[i]);
        printList(head);
        isPalindrome(head)? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n");
    }
}
