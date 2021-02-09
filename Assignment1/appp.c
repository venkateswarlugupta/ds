#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char c;
    struct Node *link;
}node;
node *h,*h1,*h2;
void createSLL(node *h){
    int n;
    node *q;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        node *t=(node *)malloc(sizeof(node));
        scanf("%c",&t->c);
        t->link=NULL;
        if(h=NULL){
            h=t;
            q=t;
        }
        else{
            q->link=t;
            q=t;
        }
    }
}
node * append(){

}
void display(node *h){
    node *q;
    q=h;
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
    h2=NULL;
    createSLL(h2);    
}