#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* concatenate(struct node* leftList, struct node *rightList)
{
    if(leftList == NULL)
        return rightList;
    if(rightList == NULL)
        return leftList;

    struct node* leftLast = leftList->left;
    struct node* rightLast = rightList->left;

    leftLast->right = rightList;
    rightList->left = leftLast;

    leftList->left = rightLast;
    rightLast->right = leftList;

    return leftList;
}

struct node *bTreeToCList(struct node *root)
{
    if(root == NULL)
        return NULL;

    struct node* left = bTreeToCList(root->left);
    struct node* right = bTreeToCList(root->right);

    root->left = root->right = root;

    return concatenate(concatenate(left,root),right);
}

void display(struct node* head)
{
    printf("Circular Linked List is: \n");
    struct node* itr = head;

    do{
        printf("%d->",itr->data);
        itr=itr->right;
    }while(head!=itr);
    printf("\n");
}

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

void main()
{
    struct node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    struct node *head = bTreeToCList(root);
    display(head);

}
