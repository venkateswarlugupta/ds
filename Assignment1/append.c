#include<stdio.h>
#include<stdlib.h>
struct list
{
    char c;
    struct list *link;
};
void addElements(struct list *h)
{
    int n;
    printf("No of elements : ");
    scanf("%d",&n);
    if(n==0) return;
    struct list *q=NULL;
    q=h;
    if(q->c=='#')
    {
        for(int i=0;i<n-1;i++)
        {
            struct list *t=(struct list *)malloc(sizeof(struct list));
            scanf(" %c",&q->c);
            q->link=t;
            q=t;
        }
        scanf(" %c",&q->c);
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
            struct list *t=(struct list *)malloc(sizeof(struct list));
            q->link=t;
            q=t;
            scanf(" %c",&q->c);
        }
        q->link=NULL;
    }
}
struct list * append(struct list *h1,struct list *h2)
{
    if(h1->c=='#'&&h2->c=='#')
        return NULL;
    else if(h1->c=='#')
        return h2;
    else if(h2->c=='#')
        return h1;
    else
    {
        struct list *q=h1;
        while(q->link!=NULL)
            q=q->link;
        q->link=q;
        return h1;
    }
}
void display(struct list *h)
{
    struct list *q;
    q=h;
    if(q->c=='#') return;
    while(q->link!=NULL)
    {
        printf("%c->",q->c);
        q=q->link;
    }
    printf("%c\n",q->c);
}
void main()
{
    struct list *head,*h=(struct list *)malloc(sizeof(struct list));
    h->c='#';
    h->link=NULL;
    addElements(h);
    display(h);
    struct list *h2=(struct list *)malloc(sizeof(struct list));
    h2->c='#';
    h->link=NULL;
    addElements(h2);
    display(h2);
    head=append(h,h2);
    display(head);
} 