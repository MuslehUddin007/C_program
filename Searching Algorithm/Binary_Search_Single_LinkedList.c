#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* newNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct node* middle(struct node* start, struct node* last)
{
    if(start == NULL)
        return NULL;

    struct node* slow = start;
    struct node* fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }
    printf("Slow: %d\n",slow->data);
    return slow;
}

struct node* binarySearch(struct node* head, int value)
{
    struct node* start = head;
    struct node* last = NULL;

    do{
        struct node* mid = middle(start,last);

        if(mid == NULL)
            return NULL;

        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else
            last = mid;
    }while(last == NULL || last != start);

    return NULL;
}

void main()
{
    struct node* head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(7);
    head->next->next->next = newNode(8);
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->next = newNode(10);
    int value = 4;
    if (binarySearch(head, value) == NULL)
        printf("Value not present\n");
    else
        printf("Present");
}
