#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
/* void main()
{
    struct node *h;
    h=(struct node *)malloc(sizeof(struct node));
    
    h->data=1;
    h->link=m;
    m->data=2;
    m->link=t;
    t->data=3;
    t->link=NULL;
    printf("%d\t%x\n%d\t%x\n%d\t%x\n",h->data,h->link,m->data,m->link,t->data,t->link);
    
} */
void print(struct node *h)
{
    while(h!=NULL)
    {
        printf("%x\t%d\t%x\n",h,h->data,h->link);
        h=h->link;
    }
}
void main()
{
    struct node *h,*m,*t;
    //creating a linked list with 3 elements 
    h=(struct node *)malloc(sizeof(struct node));
    m=(struct node *)calloc(1,sizeof(struct node));
    t=(struct node *)malloc(sizeof(struct node));
    h->data=1;
    h->link=m;
    m->data=2;
    m->link=t;
    t->data=3;
    t->link=NULL;
    //adding a new element at the begining
    //currently 1,2,3
    struct node *add=(struct node *)calloc(1,sizeof(struct node));
    //now 0,1,2,3
    add->data=0;
    add->link=h;
    h=add;
    //adding a new element after 1st element
    struct node *add1=(struct node *)malloc(sizeof(struct node));
    //now 0,10,1,2,3
    add1->link=h->link;
    add1->data=10;
    h->link=add1;
    //iterator ptr q
    struct node *q=(struct node *)calloc(1,sizeof(struct node));
    q=h;
    while(q->data!=2)
    {
        q=q->link;
    }
    //adding new element after 2
    struct node *add2=(struct node *)malloc(sizeof(struct node));
    //0,10,1,2,20,3
    add2->data=20;
    add2->link=q->link;
    q->link=add2;
    //adding new element before 2
    struct node *add3=(struct node *)calloc(1,sizeof(struct node));
    //0,10,1,15,2,20,3
    q=h;
    while(q->link->data!=2)
    {
        q=q->link;
    }
    add3->data=15;
    add3->link=q->link;
    q->link=add3;
    //deleting last node
    //0,10,1,15,2,20
    q=h;
    while(q->link->link!=NULL)
    {
        q=q->link;
    }
    q->link=NULL;
    q=h;
    //deleting last but one element
    //0,10,1,15,20
    while(q->link->link->link!=NULL)
    {
        q=q->link;
    }
    q->link=q->link->link;
    q->link->link=NULL;
    print(h);
}
/* void main()
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->link=NULL;
    struct node *q=(struct node *)calloc(1,sizeof(struct node));
    q->link=NULL;
    int n,i;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        struct node *t=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&t->data);
        if(i==0) p->link=t;
        q->link=t;
        t->link=NULL;
    }
    printf("Displaying elements in linked list\n");
    q=p;
    while(q!=NULL)
    {
        printf("%d\t%x\n",q->data,q->link);
        q=q->link;
    }
} */