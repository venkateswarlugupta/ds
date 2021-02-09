#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char c;
    struct node *link;
}node;
node *h,*h1,*h2;
void createSLL(node *head){
    int n;
    node *q;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        node *t=(node *)malloc(sizeof(node));
        scanf(" %c",&t->c);
        t->link=NULL;
        if(head=NULL){
            head=t;
            q=t;
        }
        else{
            q->link=t;
            q=t;
        }
    }
}
void display(node *head){
    node *q;
    q=head;
    if(q==NULL) return;
    while(q->link!=NULL){
        printf("%c->",q->c);
        q=q->link;
    }
    printf("%c\n",q->c);
}
void main(){
    h1=NULL;
    createSLL(h1);
    display(h1);
   // h2=NULL;
    //createSLL(h2);    
}