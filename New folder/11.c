#include<stdio.h>
#include<stdlib.h>
struct bank{
    int accnum;
    char accname[40];
    float balance;
};
typedef struct node{
    struct bank b;
    struct node *next;
}node;
node *head;
void Createbankacclist();
void displaydetails();
int main(){
    head=NULL;
    Createbankacclist();
    displaydetails();
    return 0;
}
void Createbankacclist(){
    node *temp,*p;
    int i=0;
    //p=head;
    while(i<2){
          temp=(node *)malloc(sizeof(node ));
        printf("Enter the account number: ");
        scanf("%d",&temp->b.accnum);
        printf("Enter the account name: ");
        scanf("%s",temp->b.accname);
        printf("Enter the balance amount: ");
        scanf("%f",&temp->b.balance);
        if(head==NULL){
            head=temp;
            p=temp;
        }
        else{
            p->next=temp;
            p=temp;
        }
        i++;
        if(i==2){
            p->next=NULL;
            break;
        }
        
    }
    
}
void displaydetails(){
 node *temp;
 temp=head;
 while(temp!=NULL){
     printf("\nBank Account no. :  %d\tBank Account name: %s\tBank Balance: %f\n",temp->b.accnum,temp->b.accname,temp->b.balance);
     temp=temp->next;
 }
}