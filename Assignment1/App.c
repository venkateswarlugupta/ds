#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char c;
    struct node *link;
}node;
node *h1,*h2;
void createSLL(node *h){
    short n,i;
    node *q;
    printf("Enter no of elements : ");
    scanf("%hi",&n);
    for(i=0;i<n;i++)
    {
        node *t=(node *)malloc(sizeof(node));
        scanf(" %c",&t->c);
        //t->link=NULL;
        if(h==NULL){
            q=t;
            h=t;
        }
        else{
            q->link=t;
            q=t;
        }
    }
    q->link=NULL;
}
node * append(){
    node *q=NULL,*h=NULL;
    if(h1==NULL&&h2==NULL)
        return q;
    else if(h2==NULL)
        return h1;
    else if(h1==NULL)
        return h2;
    else{
        h=q;
        q=h1;
        while(q->link!=NULL){
            if(h==NULL)
                h=q;
            q=q->link;
        }
        node *t=(node *)calloc(1,sizeof(node));
        t->c=q->c;
        q=t;
        q->link=h2;
    }
    return h;
}
void display(node *h){
    node *q;
    q=h;
    while(q->link!=NULL){
        printf("%c->",q->c);
        q=q->link;
    }   
    printf("%c\n",q->c);
}
void main(){
    node *h=NULL;
    h1=NULL;
    createSLL(h1);
    display(h1);
    /* h2=NULL;
    createSLL(h2);
    display(h2);
    h=append();
    display(h); */
}
/* #include <stdio.h>
#include <stdlib.h>
struct node
{
    char c;
    struct node *link;
};
void display(struct node *head)
{
    if(head == NULL)
        return;
    else
    {
        if(head->link!=NULL)
            printf("%c->",head->c);
        else
            printf("%c",head->c);
        display(head->link);
    }
}
void append(struct node *a,struct node *b)
{
        if(a==NULL) 
            a=b;
        if(a->link==NULL)
            a->link=b;
        else
            append(a->link,b);
}
int main()
{
    struct node *prev,*a, *b, *p;
    int n,i;
    printf ("number of elements in a:");
    scanf("%d",&n);
    a=NULL;
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node));
        scanf(" %c",&p->c);
        p->link=NULL;
        if(a==NULL)
            a=p;
        else
            prev->link=p;
        prev=p;
    }
    printf ("number of elements in b:");
    scanf("%d",&n);
    b=NULL;
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node));
        scanf(" %c",&p->c);
        p->link=NULL;
        if(b==NULL)
            b=p;
        else
            prev->link=p;
        prev=p;
    }
    append(a,b);
    display(a);
    return 0;
} */