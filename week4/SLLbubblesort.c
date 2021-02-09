#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;
typedef struct str
{
    char name[32];
    struct str *link;
}str;
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
void bubbleSort(node *h)
{
    node *i,*j;
    i=h;
    while(i->link!=NULL)
    {
        j=i->link;
        while(j->link!=NULL)
        {
            if(i->data>j->data)
            {
                i->data=i->data+j->data;
                j->data=i->data-j->data;
                i->data=i->data-j->data;
            }
            j=j->link;
        }
        if(i->data>j->data)
        {
            i->data=i->data+j->data;
            j->data=i->data-j->data;
            i->data=i->data-j->data;
        }
        i=i->link;
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
void addStrings(str *h)
{
    int n;
    printf("No of strings : ");
    scanf("%d",&n);
    str *q=NULL;
    q=h;
    if(!strcmp(q->name,"OOO"))
    {
        for(int i=0;i<n-1;i++)
        {
            str *t=(str *)malloc(sizeof(str));
            scanf("%s",&q->name);
            q->link=t;
            q=t;
        }
        scanf("%s",&q->name);
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
            str *t=(str *)malloc(sizeof(str));
            q->link=t;
            q=t;
            scanf("%d",&q->name);
        }
        q->link=NULL;
    }
}
void bubbleStrings(str *h)
{
    str *i,*j;
    i=h;
    while(i->link!=NULL)
    {
        j=i->link;
        while(j->link!=NULL)
        {
            if(strcmp(i->name,j->name)>0)
            {
                char temp[32];
                strcpy(temp,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,temp);
            }
            j=j->link;
        }
        if(strcmp(i->name,j->name)>0)
        {
            char temp[32];
            strcpy(temp,i->name);
            strcpy(i->name,j->name);
            strcpy(j->name,temp);
        }
        i=i->link;
    }
}
void displaystr(str *h)
{
    str *q=NULL;
    q=h;
    while(q->link!=NULL)
    {
        printf("%s->",q->name);
        q=q->link;
    }
    printf("%s\n",q->name);
}
void main()
{
    /* node *h=(node *)malloc(sizeof(node));
    h->data=-37678;
    addElements(h);
    bubbleSort(h);
    display(h); */
    str *h=(str *)malloc(sizeof(str));
    strcpy(h->name,"OOO");
    addStrings(h);
    bubbleStrings(h);
    displaystr(h);
}