#include<stdio.h>
#include<stdlib.h>
typedef struct bank{
    short no;
    char name[32];
    char bnm[8];
    int bal;
    struct bank *link;
}bank;
bank *h;
void create(){
    short n,i;
    bank *q;
    printf("Enter no of accounts : ");
    scanf("%hi",&n);
    printf("Enter account no, name, bank name,cur. balance of %hi accounts\n",n);    
    for(i=0;i<n;i++){
        bank *t=(bank *)malloc(sizeof(bank));
        t->link=NULL;
        scanf("%hi%s%s%d",&t->no,t->name,t->bnm,&t->bal);
        if(h==NULL){
            h=t;
            q=t;
        }else{
            q->link=t;
            q=t;
        }
    }
}
void withdraw(){
    short ano;
    bank *q;
    q=h;
    printf("Enter account no to with draw : ");
    scanf("%hi",&ano);
    while(1){
        if(ano==q->no){
            printf("Enter amount to withdtaw : ");
            int amo;
            scanf("%d",&amo);
            if(amo<=q->bal){
                printf("Withdraw successfull!\n");
                q->bal-=amo;
            }else{
                printf("Insufficent balance!!\n");
            }
            break;
        }
        if(q->link==NULL){
            printf("Invalid bank account\n");
            break;
        }
        q=q->link;
    }
}
void deposit(){
    short ano;
    bank *q;
    q=h;
    printf("Enter account no to deposite : ");
    scanf("%hi",&ano);
    while(1){
        if(ano==q->no){
            printf("Enter amount to deposit : ");
            int amo;
            scanf("%d",&amo);
            if(amo<=q->bal){
                printf("Deposite successfull!\n");
                q->bal+=amo;
            }
            break;
        }
        if(q->link==NULL){
            printf("Invalid bank account\n");
            break;
        }
        q=q->link;
    }
}
void removal(){
    short ano;
    bank *q;
    printf("Enter account no to remove : ");
    scanf("%hi",&ano);
    if(h==NULL){//zero acc's
        printf("No accounts to remove\n");
        return;
    }
    else if(h->link==NULL){//only one acc's
        if(h->no==ano){
            free(h);
            printf("Removed details of acc no %hi \n",ano);
            h=NULL;
        }else{
            printf("Invalid acc no\n");
        }
        return;
    }
    q=h;
    while(1){
        if(h->no==ano){//checking 1st acc
            q=h->link;
            free(h);
            printf("Removed details of acc no %hi \n",ano);
            h=q;
            return;
        }else if(q->link->no==ano){
            bank *t;
            t=q->link;
            printf("Removed details of acc no %hi \n",ano);
            q->link=q->link->link;
            free(t);
            return;
        }
        if(q->link==NULL){
            printf("Invalid bank account\n");
            break;
        }
        q=q->link;
    }
}
void display(){
    bank *q;
    q=h;
    if(h==NULL){
        printf("No accounts\n");
        return;
    }
    while(q->link!=NULL){
        printf("%hi\t%s\t%s\t%d\n",q->no,q->name,q->bnm,q->bal);
        q=q->link;
    }
    printf("%hi\t%s\t%s\t%d\n",q->no,q->name,q->bnm,q->bal);
}
void main(){
    h=NULL;
    short choice,repeat;
    create();
    do{
        printf("Enter choice to perform 1 withdraw, 2 deposite, 3 remove, 4 display, # exit : ");
        scanf("%hi",&choice);
        switch(choice){
            case 1:withdraw();
                   break;
            case 2:deposit();
                   break;
            case 3:removal();
                   break;
            case 4:display();
                   break;
            default:exit(1);
        }
        printf("repeat - #\t end - 0 :");
        scanf("%hi",&repeat);
    }while(repeat);
}