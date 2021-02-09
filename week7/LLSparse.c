#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    int row;
    int col;
    struct node *link;
}Sparse;
Sparse *h1,*h2;
int cnt=0,m,n;
Sparse *storeFromFile(Sparse *h,int fileno){
    FILE *fp;
    Sparse *q;
    q=h;
    if(fileno==1){
        fp=fopen("input1.txt","r");
    }else if(fileno==2){
        fp=fopen("input2.txt","r");
    }
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
    return h;
}
Sparse *add(Sparse *h1,Sparse *h2){
    Sparse *r,*q1,*q2,*q;
    q1=h1;
    q2=h2;
    r=NULL;
    q=r;
    while(1){
        Sparse *t=(Sparse *)malloc(sizeof(Sparse));
        if(q1!=NULL&&q2!=NULL){
            if(q1->row==q2->row&&q1->col==q2->col){
                t->row=q1->row;
                t->col=q1->col;
                t->val=q1->val+q2->val;
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
            }else{
                if(q1->row==q2->row){
                    if(q1->col<q2->col){
                        t->row=q1->row;
                        t->col=q1->col;
                        t->val=q1->val;
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
                        t->row=q2->row;
                        t->col=q2->col;
                        t->val=q2->val;
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
                }else if(q1->row<q2->row){
                    t->row=q1->row;
                    t->col=q1->col;
                    t->val=q1->val;
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
                    t->row=q2->row;
                    t->col=q2->col;
                    t->val=q2->val;
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
            }
        }else if(q1==NULL){
            t->row=q2->row;
            t->col=q2->col;
            t->val=q2->val;
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
            t->row=q1->row;
            t->col=q1->col;
            t->val=q1->val;
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
void display(Sparse *h){
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
Sparse *copy(Sparse *h,int rowcol){
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
Sparse *transpose(Sparse *h){
    Sparse *q,*ht=copy(h,1);
    q=ht;
    printf("Transpose of the matrix\n");
    bubbleSort(ht);
    display(ht);
    storeToFile(ht,n,m,"transpose.txt");
}
void main(){
    h1=NULL;
    h1=storeFromFile(h1,1);
    h2=NULL;
    h2=storeFromFile(h2,2);
    printf("First Sparse Matrix\n");
    display(h1);
    Sparse *ht=transpose(h1);
    printf("Second Sparse Matrix\n");
    display(h2);
    Sparse *sum;
    sum=add(h1,h2);
    display(sum);
    storeToFile(sum,m,n,"sum.txt");
}