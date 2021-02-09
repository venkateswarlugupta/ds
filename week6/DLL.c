#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}dll;
dll *h;
void create(){
    int n,i;
    dll *q;
    q=h;
    printf("No of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        dll *t=(dll *)malloc(sizeof(dll));
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
    q->next=NULL;
}
void insert_Begin(){
    dll *t=(dll *)malloc(sizeof(dll));
    printf("Enter node to insert infront : ");
    scanf("%d",&t->data);
    t->prev=NULL;
    t->next=h;
    h->prev=t;
    h=t;
}
void insert_Inbetween(){
    int pos,i=-1;
    dll *q,*t=(dll *)malloc(sizeof(dll));
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
    dll *q,*t=(dll *)malloc(sizeof(dll));
    printf("Enter node to insert at the end : ");
    scanf("%d",&t->data);
    while(q->next!=NULL){
        q=q->next;
    }
    t->prev=q;
    q->next=t;
    t->next=NULL;
}
void delete_Begin(){
    dll *t;
    t=h;
    if(h==NULL){
        printf("No elements to delete\n");
    }else if(h->next==NULL){//Only one element
        free(t);
        h=NULL;
    }else{
        h=h->next;
        h->prev=NULL;
        free(t);
    }
}
void delete_InBetween(){
    dll *q,*t;
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
    dll *q,*t;
    q=h;
    if(h==NULL){
        printf("No elements to delete\n");
    }else if(h->next==NULL){
        t=h;
        free(t);
        h=NULL;
    }else{
        while(q->next->next!=NULL){
            q=q->next;
        }
        t=q->next;
        q->next=NULL;
        free(t);
    }
}
void linearSearch(){
    int x,i=1;
    dll *q;
    q=h;
    printf("Enter target : ");
    scanf("%d",&x);
    while(q->next!=NULL){
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
    dll *i,*j;
    i=h;
    while(i->next!=NULL)
    {
        j=i->next;
        while(j->next!=NULL)
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
void count(){
    dll *q;
    q=h;
    int i=0;
    while(q->next!=NULL){
        i++;
        q=q->next;
    }
    printf("No of nodes : %d",i+1);
}
void display(){
    if(h==NULL){
        printf("DLL has no elements\n");
        return;
    }
    dll *q;
    q=h;
    printf("Forword\n");
    while(q->next!=NULL){
        printf("%d->",q->data);
        q=q->next;
    }
    printf("%d\n",q->data);
    printf("Backwards\n");
    while(q->prev!=NULL){
        printf("%d->",q->data);
        q=q->prev;
    }
    printf("%d\n",q->data);
}
void main(){
    h=NULL;
    create();
    display();
    printf("Linear Search\n");
    linearSearch();
    printf("Bubble sort\n");
    bubbleSort();
    display();
    printf("Deletion at begining\n");
    delete_Begin();
    display();
    delete_InBetween();
    display();
    insert_Begin();
    display();
    insert_Inbetween();
    display();
    insert_End();
    display();
}