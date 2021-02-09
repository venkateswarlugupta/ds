#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;
void addElements(node *h)
{
    int n;
    printf("No of elements : ");
    scanf("%d",&n);
    node *q=NULL;
    q=h;
    if(q->data==-37678)
    {
        for(int i=0;i<n-1;i++)
        {
            node *t=(node *)malloc(sizeof(node));
            scanf("%d",&q->data);
            q->link=t;
            q=t;
        }
        scanf("%d",&q->data);
        q->link=NULL;
    }
    else
    {
        while(q->link!=NULL)
        {
            q=q->link;
        } 
        for(int i=0;i<n;i++)
        {
            node *t=(node *)malloc(sizeof(node));
            q->link=t;
            q=t;
            scanf("%d",&q->data);
        }
        q->link=NULL;
    }
}
node * insert_Atbegin(node *h)
{
    printf("Enter element to be inserted at the beginning : ");
    if(h->data==-37678)
    {
        scanf("%d",&h->data);
        h->link=NULL;
    }
    else
    {
        node *t;
        t=(node *)malloc(sizeof(node *));
        scanf("%d",&t->data);
        t->link=h;
        h=t;
    }
    return h;
}
void insert_InBetween(node *h)
{
    int pos,i=-1;
    node *q=NULL,*t=(node *)malloc(sizeof(node));
    q=h;
    printf("Enter position (aray indexing) : ");
    scanf("%d",&pos);
    printf("Enter element to be inserted : ");
    scanf("%d",&t->data);
    while(i<pos-2)
    {
        q=q->link;
        i++;
    }
    t->link=q->link;
    q->link=t;
}
void insert_AtEnd(node *h)
{
    printf("Enter element to be inserted at the end : ");
    if(h->data=-37678)
    {
        scanf("%d",&h->data);
        h->link=NULL;
    }
    else
    {
        node *q=NULL,*t=(node *)malloc(sizeof(node));
        q=h;
        while(q->link!=NULL)
        {
            q=q->link;
        }
        scanf("%d",&t->data);
        q->link=t;
        t->link=NULL;
    }
}
void display(node *h)
{
    node *q=NULL;
    q=h;
    while(q->link!=NULL)
    {
        printf("%d->",q->data);
        q=q->link;
    }
    printf("%d\n",q->data);
}
void count(node *h)
{
    int i=0;
    node *q=NULL;
    q=h;
    while(q->link!=NULL)
    {
        q=q->link;
        i++;
    }
    printf("No of elements : %d\n",++i);
}
node *delete_AtBegin(node *h)
{
    if(h->data==-37678)
        printf("No elements to delete");
    else
    {
        node *t;
        t=h->link;
        free(h);
        h=t;
    }
    return h;
}
void delete_InBetween(node *h)
{
    int pos,i=0;
    node *q=NULL;
    printf("Enter position to delete (array indexing) : ");
    scanf("%d",&pos);
    q=h;
    while(i<pos-1)
    {
        q=q->link;
        i++;
    }
    node *t=(node *)malloc(sizeof(node));
    t=q->link;
    q->link=q->link->link;
    free(t);
}
void delete_AtTheEnd(node *h)
{
    node *q=NULL;
    q=h;
    while(q->link->link!=NULL)
    {
        q=q->link;
    }
    node *t=q->link;
    q->link=NULL;
    free(t);
}
void main()
{
    int i;
    short int choice,repeat;
    node *h=(node *)malloc(sizeof(node));
    h->link=NULL;
    h->data=-37678;
    printf("sInGlLy lInKeD lIsT oPeRaTiOnS\n");
    printf(" 1 Create Singlly Linked List\n");
    printf(" 2 Insertion At the Beginning\n");
    printf(" 3 Insertion In Between\n");
    printf(" 4 Insertion At the End\n");
    printf(" 5 Deletion At the Beginning\n");
    printf(" 6 Deletion In Between\n");
    printf(" 7 Deletion At the End\n");
    printf(" # Exit\n");
    do
    {
        printf("Enter choice : ");
        scanf("%hi",&choice);
        switch(choice)
        {
            case 1:addElements(h);
                   display(h);
                   count(h);
                   break;
            case 2:h=insert_Atbegin(h);
                   display(h);
                   count(h);
                   break;
            case 3:insert_InBetween(h);
                   display(h);
                   count(h);
                   break;
            case 4:insert_AtEnd(h);
                   display(h);
                   count(h);
                   break;
            case 5:h=delete_AtBegin(h);
                   display(h);
                   count(h);
                   break;
            case 6:delete_InBetween(h);
                   display(h);
                   count(h);
                   break;
            case 7:delete_AtTheEnd(h);
                   display(h);
                   count(h);
                   break;
            default:exit(1);
        }
        printf("shall we repeat!\n");
        printf("# - Yes\t0 - No\n");
        scanf("%hi",&repeat);
    }while(repeat);  
}
