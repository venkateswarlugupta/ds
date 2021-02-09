#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node *link;
}node;
node *h=NULL;
void push(int x){
    node *t;
    t=(node *)malloc(sizeof(node *));
    t->data=x;
    t->link=NULL;
    if(h==NULL)
        h=t;
    else{
        t->link=h;
        h=t;
    }    
}
int pop(){
    int x;
    node *t;
    if(h==NULL)
        printf("No elements to pop!\n");
    else if(h->link==NULL){
        x=h->data;
        t=h;
        h=NULL;
    }else{
        x=h->data;
        t=h;
        h=h->link;
    }
    free(t);
    return x;
}
void display(){
    node *q;
    q=h;
    if(q==NULL) return ;
    printf("Displaying\n");
    while(q->link!=NULL){
        printf("%d->",q->data);
        q=q->link;
    }
    printf("%d\n",q->data);
}
void main(){
    h=NULL;
    char exp[128];
    printf("Enter the Postfix Expression : ");
    scanf("%s",exp);
    for(int i=0;i<strlen(exp)||h==NULL;i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int n2,n1;
            n2=pop();
            n1=pop();
            if(exp[i]=='+'){
                push(n1+n2);
            }else if(exp[i]=='-'){
                push(n1-n2);
            }else if(exp[i]=='*'){
                push(n1*n2);
            }else if(exp[i]=='/'){
                push(n1/n2);
            }
        }else{
            int x=exp[i];
            push(x-48);
        }
    }
    printf("Result : %d",pop());
}