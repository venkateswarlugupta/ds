#include<stdio.h>
#include<stdlib.h>
struct sparse
{
    short int r;
    short int c;
    int v;
};
/* int storeFromFile(struct sparse *lst,short int d[2])
//int storeFromFile(struct sparse lst[],short int d[2])
{
    FILE *fp;
    int value=0;
    fp=fopen("input.txt","r");
    short int m,n,cnt=0,i,j;
    fscanf(fp,"%hi%hi",&m,&n);
    printf("%hi %hi\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d",&value);
            printf(" %d ",value);
            if(value!=0)
            {
                lst=(struct sparse *)realloc(lst,(cnt+1)*sizeof(struct sparse));
                lst[cnt].r=i;
                lst[cnt].c=j;
                lst[cnt].v=value;
                cnt++; 
                cnt++;
                lst=(struct sparse *)realloc(lst,cnt*sizeof(struct sparse));
                (lst+cnt-1)->r=&i;
                (lst+cnt-1)->c=&j;
                (lst+cnt-1)->v=&value;
            }
        }
    }
    return cnt; 
} */
int store(struct sparse *lst,short int m,short int n)
{
    short int i,j,cnt=0;
    int val;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&val);
            if(val!=0)
            {
                cnt++;
                lst=(struct sparse *)realloc(lst,cnt*sizeof(struct sparse));
                lst[cnt-1].r=i;
                lst[cnt-1].c=j;
                lst[cnt-1].v=val;
            }
        }
    }
    return cnt;    
}
void add(struct sparse *lst1,short int cnt1,struct sparse *lst2,short int cnt2,short int size[])
{
    short i=0,j=0,cntA=0;
    struct sparse *A=(struct sparse *)malloc(0*sizeof(struct sparse));
    if(size[0]==size[2]&&size[1]==size[3])
    {
        while(-273)
        {
            A=(struct sparse *)realloc(A,(cntA+1)*sizeof(struct sparse));
            if(cnt1!=0&&cnt2!=0)
            {
                if(lst1[i].r==lst2[j].r&&lst1[i].c==lst2[j].c)
                {
                    A[cntA].r=lst1[i].r;
                    A[cntA].c=lst1[i].c;
                    A[cntA].v=lst1[i].v+lst2[j].v;
                    i++;j++;cntA++;cnt1--;cnt2--;
                }
                else
                {
                    if(lst1[i].r==lst2[j].r)
                    {
                        if(lst1[i].c<lst2[j].c)
                        {
                            A[cntA].r=lst1[i].r;
                            A[cntA].c=lst1[i].c;
                            A[cntA].v=lst1[i].v;
                            i++;cntA++;cnt1--;   
                        }
                        else
                        {
                            A[cntA].r=lst2[j].r;
                            A[cntA].c=lst2[j].c;
                            A[cntA].v=lst2[j].v;
                            j++;cntA++;cnt2--;
                        }

                    }
                    else if(lst1[i].r<lst2[j].r)
                    {
                        A[cntA].r=lst1[i].r;
                        A[cntA].c=lst1[i].c;
                        A[cntA].v=lst1[i].v;
                        i++;cntA++;cnt1--; 
                    }
                    else
                    {
                        A[cntA].r=lst2[j].r;
                        A[cntA].c=lst2[j].c;
                        A[cntA].v=lst2[j].v;
                        j++;cntA++;cnt2--;                        
                    }
                }
            }
            else if(cnt1==0)
            {
                A[cntA].r=lst2[j].r;
                A[cntA].c=lst2[j].c;
                A[cntA].v=lst2[j].v;
                j++;cntA++;cnt2--;
            }
            else
            {
                A[cntA].r=lst1[i].r;
                A[cntA].c=lst1[i].c;
                A[cntA].v=lst1[i].v;
                i++;cntA++;cnt1--;  
            }
            if(cnt1==0&&cnt2==0)    break;
        }
        int tcntA=0;
        for(int j,i=0;i<size[0];i++)
        {
            for(j=0;j<size[1];j++)
            {
                if(A[tcntA].r==i&&A[tcntA].c==j)
                {
                    printf(" %d",A[tcntA].v);
                    tcntA++;
                }
                else
                printf(" 0");
            }
            printf("\n");
        }
    }
    else
    {
        printf("Addition is impossible\n");
    }
}
void print(struct sparse *lst,short int cnt)
//void print(struct sparse lst[],short int cnt)
{
    short int i;
    printf("serialNo. Row \tColumn\t Value\n");
    for(i=0;i<cnt;i++)
    {
        printf("    %hi \t   %hi \t   %hi\t   %d\n",i,(lst+i)->r,(lst+i)->c,(lst+i)->v);
        //printf(" %hi\t   %hi\t   %d\n",lst[i].r,lst[i].c,lst[i].v);
    }        //column
}           /* 0th 1st 2nd 3rd
        0th  0   0   1   9         0 7 0 2
   r    1st  7   0   0   4         0 0 8 0 
   o    2nd  0   8   3   0         9 4 0 0
   w    3rd  2   0   5   0         1 0 3 5
    
    colcnt:  2   1   3   2
  
  startpos:  0   2   3   6
             1       4   7
                     5  */  
void transpose(struct sparse *lst,short int cnt,short int m,short int n)
{
    struct sparse *tlst=(struct sparse *)calloc(cnt,sizeof(struct sparse));
    short int i,*cntcol=(short int *)calloc(n,sizeof(short int));
    short int *startpos=(short int *)calloc(n,sizeof(short int));
    for(i=0;i<cnt;i++)
        cntcol[lst[i].c]++;
    startpos[0]=0;
    for(i=1;i<n;i++)
        startpos[i]=cntcol[i-1]+startpos[i-1];
    for(i=0;i<cnt;i++)
    {
        int z=startpos[lst[i].c]++;
        tlst[z].r=lst[i].c;
        tlst[z].c=lst[i].r;
        tlst[z].v=lst[i].v;  
    }
    print(tlst,cnt);
}
void main()
{
    /* short int cnt,cnt2,d1[2],d2[2]; 
    printf("Enter a matrix ");
    struct sparse *lst=(struct sparse *)malloc(0,sizeof(struct sparse));
    //struct sparse lst[9];
    cnt=storeFromFile(lst,d1);
    print(lst,cnt); */
    short int i,j,m,n,cnt,m2,n2,cnt2,size[4];
    int val;
    printf("Enter dimensions of Sparse Matrix : ");
    scanf("%hi%hi",&m,&n);
    struct sparse *lst=(struct sparse *)malloc(0*sizeof(struct sparse));
    cnt=store(lst,m,n);
    /* printf("Enter dimensions of another Sparse Matrix : ");
    scanf("%hi%hi",&m2,&n2);
    struct sparse *lst2=(struct sparse *)calloc(0,sizeof(struct sparse));
    cnt2=store(lst2,m2,n2); 
    size[0]=m;size[1]=n;size[2]=m2;size[3]=n2;
    add(lst,cnt,lst2,cnt2,size); */
    printf("Matrix\n");
    print(lst,cnt);
    printf("\nTranspose\n");
    transpose(lst,cnt,m,n);
}