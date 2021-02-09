#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int coef;
    int exp;
    struct node *link;
}Polynomial;
Polynomial *createPolynomial(Polynomial *h){
    Polynomial *q,*t;
    q=h;
    int n;
    char ch;
    printf("No of terms : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        t=(Polynomial *)malloc(sizeof(Polynomial));
        scanf("%d%c%c%d",&t->coef,&ch,&ch,&t->exp);
        t->link=NULL;
        if(q==NULL){
            q=t;
            h=t;
        }else{
            q->link=t;
            q=t;
        }
    }
    return h;
}
Polynomial *addPolynomials(Polynomial *h1, Polynomial *h2){
    Polynomial *r,*q1,*q2,*q;
    q1=h1;
    q2=h2;
    r=NULL;
    q=r;
    while(1){
        Polynomial *t=(Polynomial *)malloc(sizeof(Polynomial));
        if(q1!=NULL&&q2!=NULL){
            if(q1->exp==q2->exp){
                t->exp=q1->exp;
                t->coef=q1->coef+q2->coef;
                t->link=NULL;
                if(q==NULL){
                    r=t;
                    q=t;
                }else{
                    q->link=t;
                    q=t;
                }
                q1=q1->link;
                q2=q2->link;
            }else if(q1->exp>q2->exp){
                t->exp=q1->exp;
                t->coef=q1->coef;
                t->link=NULL;
                if(q==NULL){
                    r=t;
                    q=t;
                }else{
                    q->link=t;
                    q=t;
                }
                q1=q1->link;
            }else{
                t->exp=q2->exp;
                t->coef=q2->coef;
                t->link=NULL;
                if(q==NULL){
                    r=t;
                    q=t;
                }else{
                    q->link=t;
                    q=t;
                }
                q2=q2->link;
            }
        }else if(q1==NULL){
            t->exp=q2->exp;
            t->coef=q2->coef;
            t->link=NULL;
            if(q==NULL){
                r=t;
                q=t;
            }else{
                q->link=t;
                q=t;
            }
            q2=q2->link;
        }else{
            t->exp=q1->exp;
            t->coef=q1->coef;
            t->link=NULL;
            if(q==NULL){
                r=t;
                q=t;
            }else{
                q->link=t;
                q=t;
            }
            q1=q1->link;
        }
        if(q1==NULL&&q2==NULL) break;
    }
    return r;
}
void display(Polynomial *h){
    Polynomial *q;
    q=h;
    while(q->link!=NULL){
        printf("%dx^%d",q->coef,q->exp);
        if(q->link->coef>0){
            printf("+");
        }
        q=q->link;
    }
    printf("%dx^%d",q->coef,q->exp);

}
void main(){
    //  12x^6+3x^3+14x^2+9x^1
    //  6x^6+5x^5-6x^3
    Polynomial *h1, *h2, *r;    
    h1=NULL;
    h2=NULL;
    h1=createPolynomial(h1);
    h2=createPolynomial(h2);
    r=addPolynomials(h1,h2);
    display(r);
}