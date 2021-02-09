#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    short int coeff;
    short int power;
    char opertor;
    struct poly *link;
}poly;
poly *createPolynomial(poly *h, int fileno){
    FILE *fp;
    poly *q,*t;
    char ch,x='\0';
    q=h;
    if(fileno==1){
        fp=fopen("inputPoly.txt","r");
    }else if(fileno==2){
        fp=fopen("input2.txt","r");
    }
    do{
        fscanf(fp," %c",&ch);
        if(ch=='+'||ch=='-'){
            t=(poly *)malloc(sizeof(poly));
            t->opertor=ch;
            if(q==NULL){
                    h=t;
                    q=t;
                }else{
                    q->link=t;
                    q=t;
                }
        }else if(ch=='x'){
            x='x';
        }else if(x=='\0'){
            t->coeff=ch-'0';
        }else if(x=='x'){
            t->power=ch-'0';
            x='\0';
        }
    }while(ch!='\n');
}
void display(poly *h){
    poly *q;
    q=h;
    while(q!=NULL){
        printf("%c\t%d\t%d\n",q->opertor,q->coeff,q->power);
        q=q->link;
    }
}

poly *h1,*h2;
void main(){
    h1=NULL;
    h2=NULL;
    h1=createPolynomial(h1,1);
}