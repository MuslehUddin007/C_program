#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


//PostOrder(left,right,root)//
void printPostOrder(struct node* node)
{
    if(node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ",node->data);
}

//InOrder(left,root,right)//
void printInOrder(struct node* node)
{
    if(node == NULL)
        return;
    printInOrder(node->left);
    printf("%d ",node->data);
    printInOrder(node->right);
}

//PreOrder(root,left,right)//
void printPreOrder(struct node* node)
{
    if(node == NULL)
        return;
    printf("%d ",node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}
/*
            tree
            ====
             (1)
             / \
          (2)  (3)
          / \     \
        (4) (6)   (5)
*/

void main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(5);

    printf("\nPreOrder traversal of binary tree is: \n");
    printPreOrder(root);

    printf("\nInOrder traversal of binary tree is: \n");
    printInOrder(root);

    printf("\nPostOrder traversal of binary tree is: \n");
    printPostOrder(root);

    getchar();
}
