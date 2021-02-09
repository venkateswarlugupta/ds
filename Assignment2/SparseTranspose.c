#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    int row;
    int col;
    struct node *link;
}Sparse;
Sparse *h;
int cnt=0,m,n;
void storeFromFile(){
    FILE *fp;
    Sparse *q;
    q=h;
    fp=fopen("input.txt","r");
    int i,j,v;
    fscanf(fp,"%d %d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            fscanf(fp,"%d",&v);
            if(v!=0){
                cnt++;
                Sparse *t=(Sparse *)malloc(sizeof(Sparse));
                t->val=v;
                t->row=i;
                t->col=j;
                t->link=NULL;
                if(q==NULL){
                    h=t;
                    q=t;
                }else{
                    q->link=t;
                    q=t;
                }
            }
        }
    }
}
void display(){
    Sparse *q;
    q=h;
    int i=0;
    if(q==NULL){
        printf("All elements are ZERO's\n");
    }else if(q->link==NULL){
        printf("ROW \t COLUMN \t VALUE\n");
        printf(" %d  \t    %d  \t  \t %d\n",q->row,q->col,q->val);
    }else{
        printf("ROW \t COLUMN \t VALUE\n");
        while(q!=NULL){
            printf(" %d  \t    %d  \t  \t %d\n",q->row,q->col,q->val);
            q=q->link;
            i++;
        }
    }
}
Sparse *copy(int rowcol){//if rowcol is one, then rows and columns will be copied oppositely 
    Sparse *t,*q,*qc,*hc;
    q=h;
    hc=NULL;
    qc=hc;
    while(q!=NULL){
        t=(Sparse *)calloc(1,sizeof(Sparse));
        t->link=q->link;
        if(rowcol==0){
            t->row=q->row;
            t->col=q->col;
        }else if(rowcol==1){
            t->row=q->col;
            t->col=q->row;
        }
        t->val=q->val;
        if(hc==NULL){
            hc=t;
            qc=t;
        }else{
            qc->link=t;
            qc=t;
        }
        q=q->link;
    }
    return hc;
}
void bubbleSort(Sparse *h){
    Sparse *i,*j;
    i=h;
    while(i!=NULL)
    {
        j=i->link;
        while(j!=NULL)
        {
            if(i->row>j->row)
            {
                i->row=i->row+j->row;
                j->row=i->row-j->row;
                i->row=i->row-j->row;
                i->col=i->col+j->col;
                j->col=i->col-j->col;
                i->col=i->col-j->col;
                i->val=i->val+j->val;
                j->val=i->val-j->val;
                i->val=i->val-j->val;
            }
            j=j->link;
        }
        i=i->link;
    }
}
void storeToFile(Sparse *r,int m0,int n0,char *filename){
    FILE *fp;
    Sparse *q;
    q=r;
    fp=fopen(filename,"w");
    fprintf(fp,"%d %d\n",m0,n0);
    for(int j,i=0;i<m0;i++){
        for(j=0;j<n0;j++){
            if(q->row==i&&q->col==j){
                fprintf(fp,"%d ",q->val);
                q=q->link;
            }else{
                fprintf(fp,"0 ");
            }
        }
        fprintf(fp,"\n");
    }
}
Sparse *transpose(){
    Sparse *q,*ht=copy(1);
    q=ht;
    printf("Transpose of the matrix\n");
    bubbleSort(ht);
    display(ht);
    storeToFile(ht,n,m,"transpose.txt");
}
void main(){
    h=NULL;
    storeFromFile();
    printf("First Sparse Matrix\n");
    display(h);
    Sparse *ht=transpose(h);
}