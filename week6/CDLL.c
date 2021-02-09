#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}cdll;
cdll *h;
void create(){
    int n,i;
    cdll *q;
    q=h;
    printf("No of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cdll *t=(cdll *)malloc(sizeof(cdll));
        scanf("%d",&t->data);
        if(q==NULL){
            t->prev=NULL;
            h=t;
            q=t;
        }else{
            t->prev=q;
            q->next=t;
            q=t;
        }
    }
    q->next=h;
    h->prev=q;
}
void insert_Begin(){
    cdll *q,*t=(cdll *)malloc(sizeof(cdll));
    printf("Enter node to insert infront : ");
    scanf("%d",&t->data);
    q=h;
    while(q->next!=h){
        q=q->next;
    }
    q->next=t;
    t->prev=h->prev;
    t->next=h;
    h->prev=t;
    h=t;
}
void insert_Inbetween(){
    int pos,i=-1;
    cdll *q,*t=(cdll *)malloc(sizeof(cdll));
    q=h;
    printf("Enter position (aray indexing)  to insert: ");
    scanf("%d",&pos);
    printf("Enter element to be inserted : ");
    scanf("%d",&t->data);
    while(i<pos-2){
        q=q->next;
        ++i;
    }
    t->prev=q;
    t->next=q->next;
    q->next=t;
    q=t;
    q->next->prev=t;
}
void insert_End(){
    cdll *q,*t=(cdll *)malloc(sizeof(cdll));
    printf("Enter node to insert at the end : ");
    scanf("%d",&t->data);
    q=h;
    while(q->next!=h){
        q=q->next;
    }
    t->prev=q;
    q->next=t;
    t->next=h;
    h->prev=t;
}
void delete_Begin(){
    cdll *t,*q;
    t=h;
    if(h==NULL){
        printf("No elements to delete\n");
    }else if(h->next==h){//Only one element
        free(t);
        h=NULL;
    }else{
        h->next->prev=h->prev;
        q=h;
        while(q->next!=h){
            q=q->next;
        }
        h=h->next;
        q->next=h;
        free(t);
    }
}
void delete_InBetween(){
    cdll *q,*t;
    q=h;
    int pos,i=0;
    printf("Enter position to delete (array indexing) : ");
    scanf("%d",&pos);
    while(i<pos-1){
        q=q->next;
        ++i;
    }
    t=q->next;
    q->next=t->next;
    q=q->next;
    q->prev=t->prev;
    free(t);
}
void delete_End(){
    cdll *q,*t;
    q=h;
    if(h==NULL){
        printf("No elements to delete\n");
    }else if(h->next==h){
        t=h;
        free(t);
        h=NULL;
    }else{
        while(q->next->next!=h){
            q=q->next;
        }
        t=q->next;
        q->next=h;
        h->prev=q;
        free(t);
    }
}
void linearSearch(){
    int x,i=1;
    cdll *q;
    q=h;
    printf("Enter target : ");
    scanf("%d",&x);
    while(q->next!=h){
        if(x==q->data){
            printf("Found at %d position\n",i);
            return;
        }
        q=q->next;
        ++i;
    }
    if(x==q->data){
        printf("Found at %d position\n",i);
    }else{
        printf("Not Found\n");
    }
}
void bubbleSort()
{
    cdll *i,*j;
    i=h;
    while(i->next!=h)
    {
        j=i->next;
        while(j->next!=h)
        {
            if(i->data>j->data)
            {
                i->data=i->data+j->data;
                j->data=i->data-j->data;
                i->data=i->data-j->data;
            }
            j=j->next;
        }
        if(i->data>j->data)
        {
            i->data=i->data+j->data;
            j->data=i->data-j->data;
            i->data=i->data-j->data;
        }
        i=i->next;
    }
}
void display(){
    if(h==NULL){
        printf("CDLL has no elements\n");
        return;
    }
    cdll *q,*t;
    q=h;
    int i=0,j=0;
    printf("Forword\n");
    //while(q->next!=h){
    while(i<12){
        printf("%d->",q->data);
        q=q->next;
        i++;
    }
    t=q;
    printf("%d\n",q->data);
    printf("Backwards\n");
    //while(q->prev!=t){
    while(j<12){
        printf("%d->",q->data);
        q=q->prev;
        j++;
    }
    printf("%d\n",q->data);
}
void count(){
    cdll *q;
    q=h;
    int i=0;
    if(h==NULL){
        printf("0\n");
        return;
    }
    while(q->next!=h){
        i++;
        q=q->next;
    }
    printf("No of nodes : %d",i+1);
}
void main(){
    h=NULL;
    create();
    display();
    // printf("Linear Search\n");
    // linearSearch();
    // printf("Bubble sort\n");
    // bubbleSort();
    // display();
    // insert_Begin();
    // display();
    // insert_Inbetween();
    // display();
    // insert_End();
    // display();
    // printf("Deletion at begining\n");
    // delete_Begin();
    // display();
    // delete_InBetween();
    // display();
    // printf("Deletion at End\n");
    // delete_End();
    // display();
    // count();
}