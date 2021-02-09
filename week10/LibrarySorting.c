#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int bookID;
    char bookName[32];
    char author[32];
    int price;
    char specialization[32];
    struct node *link;
}books;
books *loadDetails(books *head){
    int n,i;
    FILE *fp=fopen("listOfBooks.txt","r");
    fscanf(fp,"%d",&n);
    books *q,*t;
    for(i=0;i<n;i++){
        t=(books *)malloc(sizeof(books));
        fscanf(fp,"%d %s %s %d %s",&t->bookID,t->bookName,t->author,&t->price,t->specialization);
        t->link=NULL;
        if(head==NULL){
            head=t;
        }else{
            q->link=t;
        }
        q=t;
    }
    return head;
}
void swap(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void bubbleSort(books *head,int sortBy)
{
    books *i,*j,*t;
    i=head;
    while(i!=NULL)
    {
        j=i->link;
        while(j!=NULL)
        {
            int isSwapRequired=0;
            if(sortBy==1){
                if(i->price>j->price)
                {
                    isSwapRequired=1;
                }
            }else if(sortBy==2){
                if(strcmp(i->bookName,j->bookName)>0){
                    isSwapRequired=1;
                }
            }else if(sortBy==3){
                if(strcmp(i->specialization,j->specialization)>0){
                    isSwapRequired=1;
                }
            }
            if(isSwapRequired==1){
                swap(&i->bookID,&j->bookID);
                    swap(&i->price,&j->price);
                    char temp[32];
                    strcpy(temp,i->author);
                    strcpy(i->author,j->author);
                    strcpy(j->author,temp);
                    strcpy(temp,i->bookName);
                    strcpy(i->bookName,j->bookName);
                    strcpy(j->bookName,temp);
                    strcpy(temp,i->specialization);
                    strcpy(i->specialization,j->specialization);
                    strcpy(j->specialization,temp);
            }
            j=j->link;
        }
        i=i->link;
    }
}
void display(books *head){
    books *q;
    q=head;
    while(q!=NULL){
        printf("%d  %s  %s  %d  %s\n",q->bookID,q->bookName,q->author,q->price,q->specialization);
        q=q->link;
    }
}
void main(){
    books *head=NULL;
    head=loadDetails(head);
    printf("\n\n Unsorted\n\n");
    display(head);
    printf("\n\nSorting by price\n\n");
    bubbleSort(head, 1);//price
    display(head);
    printf("\n\nSorting by bookName\n\n");
    bubbleSort(head, 2);//bookName
    display(head);
    printf("\n\nSorting by specialization\n\n");
    bubbleSort(head, 3);//specialization
    display(head);
}