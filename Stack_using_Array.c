#include<stdio.h>

int stack[100],top = -1,size = 0;

void push(){
    system("cls");
    int p = 0;
    if(top >= size -1)
        printf("\nStack is Overflow\n");
    else{
        printf("Enter number :");
        scanf("%d",&p);
        top++;
        stack[top] = p;
    }
}

void pop(){
    system("cls");
    if(top <= -1)
        printf("\nStack is Underflow\n");
    else{
        printf("%d item is poped\n",stack[top]);
        top--;
    }
}

void display(){
    system("cls");
    int i;
    if(top >= 0){
        printf("Stack Elements are: \n");
        for(i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
    else{
        printf("Stack is Empty.....\n");
    }
    _getch();
}

void main()
{
    int choice = 0;
    printf("Enter Stack size[MAX = 100]: ");
    scanf("%d",&size);
    printf("\n");
    do{
        system("cls");
        printf("\n1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter you choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong ans!! Press enter to try again....\n");
            _getch();
        }
    }while(choice != 4);
}
