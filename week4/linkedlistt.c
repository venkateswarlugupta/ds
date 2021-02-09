#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void main(){
    struct node *h=(struct node *)calloc(1,sizeof(struct node));
    h->link=NULL;
    struct node *q=(struct node *)calloc(1,sizeof(struct node));
    q->link=NULL;
    int n,i,a;
    printf("No of elements : ");
    scanf("%d",&n);
    q=h;
    for(i=0;i<n;i++){
        if(q->link!=NULL){
            q=q->link;            
        }
        struct node *t=(struct node *)calloc(1,sizeof(struct node));
        scanf("%d",&t->data);
        q->data=t->data;
        q->link=t;
        q=t;
    }
    q->link=NULL;
    struct node *add=(struct node *)calloc(1,sizeof(struct node));
    add=NULL;
    q=h;
    /* while(q->link!=NULL){
        struct node *temp=(struct node *)calloc(1,sizeof(struct node));
        temp=q->link;
        add=q->link;
        q->link=add;
        q=add;
    }
    h=q; */
    /* while(q->link!=NULL){
        add->link=q->link;
        q->link=add;
        add=q;
        q=add->link;       
    }
    add->link=q->link;
        q->link=add;
        add=q;
        q=add->link; */
    //q=h;
    while(q->link!=NULL){
        printf("%d",q->data);
        q=q->link;
    }
}