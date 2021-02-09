#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
node *create(node *head){
    int n;
    node *q;
    printf("enter no of nodes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        node *t=(node *)malloc(sizeof(node));
        scanf("%d",&t->data);
        t->link=NULL;
        if(head==NULL){
            head=t;
            q=t;
        }else{
            q->link=t;
            q=t;
        }
    }
    return head;
}
node *qq;
node *reverse(node *head, node *rhead){
    if(head->link){
        reverse(head, rhead);
    }else if(!(head->link)){
        rhead=head;
        qq=head;
    }else{
        qq->link=head;
        qq=qq->link;
    }
    return rhead;
}
void display(node *head){
    node *q;
    q=head;
    while(q){
        printf("%d->",q->data);
        q=q->link;
    }
}
void main(){
    node *head=NULL,*rhead;
    head=create(head);
    display(head);
    rhead=reverse(head,rhead);
    display(rhead);
}
