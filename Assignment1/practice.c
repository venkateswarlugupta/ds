#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char c;
    struct node *link;
}node;
void create(node *h){
    int i,n;
    node *q;
    q=h;
    printf("No of elements : ");
    scanf("%d",&n);
    if(n==0) return;
    for(i=0;i<n-1;i++){
        if(q->c=='#'){
            scanf(" %c",&q->c);
        }
        node *t=(node *)malloc(sizeof(node));
        scanf("%c",&t->c);
        t->link=NULL;
        q->link=t;
        q=t;
    }
}
node *append(node *h1,node *h2){
    if(h1->c=='#'&&h2->c=='#')
        return h1;
    else if(h1->c=='#'){
        return h2;
    }
    else if(h2->c=='#'){
        return h1;
    }
    else{
        node *q;
        q=h1;
        while(q->link!=NULL){
            q=q->link;
        }
        q->link=h2;
        return h1;
    }
} 
void display(node *h){
    node *q;
    q=h;
    if(q->c=='#') return;
    while(q->link!=NULL){
        printf("%c->",q->c);
        q=q->link;
    }
    printf("%c\n",q->c);
}
void main(){
    node *h1,*h2,*h;
    h1=(node *)malloc(sizeof(node));
    h1->c='#';
    h1->link=NULL;
    create(h1);
    h2=(node *)malloc(sizeof(node));
    h2->c='#';
    h2->link=NULL;
    create(h2);
    h=append(h1,h2);
    display(h);
}
/* node *head;
node *create(){
    node *t,*q;
    for(int i=0;i<5;i++){
        t=(node *)malloc(sizeof(node ));
        scanf(" %c",&t->c);
        t->link=NULL;
        if(head==NULL){
            head=t;
            q=t;
        }
        else{
            q->link=t;
            q=t;
        }
    }
    return head;
}
void display(){
    node *q;
    q=head;
    while(q->link!=NULL){
        printf("%c->",q->c);
        q=q->link;
    }
    printf("%c\n",q->c);
}
void main(){
    head=NULL;
    head=create();
    display();   
} */