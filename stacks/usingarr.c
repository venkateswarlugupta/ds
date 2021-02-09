#include<stdio.h>
#include<stdlib.h>
int top=-1;
void push(int size,int *stack)
{
    if(top==size-1)
        printf("Stack is full, can't push\n");
    else
    {
        int a;
        ++top;
        printf("Enter element : ");
        scanf("%d",&a);
        stack[top]=a;
    }
}
void pop(int size,int *stack)
{
    if(top==-1)
        printf("Stack is empty, no element to delete\n");
    else
        --top;
}
void display(int size,int *stack)
{
    if(top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Elements in stack\n");
        for(int i=top;i>-1;i--)
            printf("%d ",stack[i]);
        printf("\n");
    }
}
void main()
{
    int *stack,n,repeat;
    printf("Size of stack : ");
    scanf("%d",&n);
    stack=(int *)calloc(n,sizeof(int));
    do
    {
        printf(" 1 push\t 2 pop  # exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push(n,stack);
                   display(n,stack);
                   break;
            case 2:pop(n,stack);
                   display(n,stack);
                   break;
            default:exit(1);
        }
        printf("Shall we repeat\n");
        printf(" 1 - Yes  0 - No\n");
        scanf("%d",&repeat);
    } while(repeat);
}