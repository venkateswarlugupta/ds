#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;
node *h=NULL;
void push()
{
    node *t;
    t=(node *)malloc(sizeof(node *));
    printf("Enter element : ");
    scanf("%d",&t->data);
    t->link=NULL;
    if(h==NULL)
        {h=t;printf("NULL\n");}
    else
    {
        t->link=h;
        h=t;
    }    
}
void pop()
{
    node *t;
    if(h==NULL)
        printf("No elements to pop!\n");
    else if(h->link==NULL)
    {
        printf("poping %d\n",h->data);
        t=h;
        h=NULL;
    }
    else
    {
        printf("poping %d\n",h->data);
        t=h;
        h=h->link;
    }
    free(t);
}
void display()
{
    node *t;
    t=h;
    if(h==NULL)
        printf("Stack is empty\n");
    else
    {
        while(t->link!=NULL)
        {
            printf("%d->",t->data);
            t=t->link;
        }
        printf("%d\n",t->data);
    }
}
void main()
{
    int choice,repeat;
    do
    {
        printf(" 1 push\t 2 pop \t3 display   # exit :: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            default:exit(1);
        }
        printf("Shall we repeat :: ");
        printf(" # - Yes  0 - No : ");
        scanf("%d",&repeat);        
    }while(repeat);
}