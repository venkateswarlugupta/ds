#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    char ch;
    struct node *link;
}node;
node *h,*h1;
void create(){
    int n;
    node *q,*q1,*j;
    q=h;
    q1=h1;
    j=h1;
    printf("Enter no of letters : ");
    scanf("%d",&n);
    for(int z=0;z<n;z++){
        node *tt,*t=(node *)malloc(sizeof(node));
        tt=(node *)malloc(sizeof(node));
        scanf(" %c",&t->ch);
        t->link=NULL;
        tt->link=NULL;
        if(h==NULL){
            h=t;
            q=t;
            h1=tt;
            q1=tt;
        }else{
            q->link=t;
            q=q->link;
            q1->link=tt;
            q1=q1->link;
        }
    }
    q->link=h;
    q1->link=h1;
}
void arrange(){
    node *q,*q1;
    q=h;
    q1=h1;
    while(q->link!=h){
        if(q->ch=='a'||q->ch=='e'||q->ch=='i'||q->ch=='o'||q->ch=='u'){
            q1->ch=q->ch;
            q1=q1->link;
        }
        q=q->link;
    }
    if(q->ch=='a'||q->ch=='e'||q->ch=='i'||q->ch=='o'||q->ch=='u'){
        q1->ch=q->ch;
        q1=q1->link;
    }
    q=h;
    while(q->link!=h){
        if(q->ch!='a'&&q->ch!='e'&&q->ch!='i'&&q->ch!='o'&&q->ch!='u'){
            q1->ch=q->ch;
            q1=q1->link;
        }
        q=q->link;
    }
    if(q->ch!='a'&&q->ch!='e'&&q->ch!='i'&&q->ch!='o'&&q->ch!='u'){
        q1->ch=q->ch;
        q1=q1->link;
    }
}
void display(node *head){
    node *q;
    q=head;
    int i=0;
    //while(q->link!=h)
    while(i<14)
    {
        printf("%c->",q->ch);
        q=q->link;
        i++;
    }
    printf("%c\n",q->ch);
}
void main(){
    h=NULL;
    h1=NULL;
    create();    
    arrange();
    display(h);
    display(h1);
}