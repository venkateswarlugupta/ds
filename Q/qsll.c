#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;
node *front=NULL,*rare=NULL;
void enqueue()
{
    node *t=(node *)malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&t->data);
    t->link=NULL;
    if(front==NULL&&rare==NULL)
    {
        front=t;
        rare=t;
    }
    else
    {
        rare->link=t;
        rare=t;
    }
}
void dequeue()
{
    int data;
    struct node *t;
    if(front==NULL)
        printf("Queue is empty\n");
    data=front->data;
    if(front==rare)
    {
        front=NULL;
        rare=NULL;
    }
    t=front;
    front=front->link;
    free(t);
    printf("Removed from Queue : %d\n",data);
}
void display()
{
    node *t;
    t=front;
    if(front==NULL){
        printf("No elements to display\n");
        return;
    }
    while(t->link!=NULL)
    {
        printf("%d->",t->data);
        t=t->link;
    }
    printf("%d\n",t->data);
}
void main()
{
    short repeat;
    do
    {
        short choice;
        printf(" 1 enqueue\t 2 dequeue\t 3 display\t # exit : ");
        scanf("%hi",&choice);
        switch(choice)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            default:exit(1);
        }
        printf("Shall we repeat\t # - Yes   0 - No :");
        scanf("%hi",&repeat);
    }while(repeat);
}