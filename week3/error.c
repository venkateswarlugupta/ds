#include<stdio.h>
#include<stdlib.h>
struct sparse
{
    short int r;
    short int c;
    int v;
};
int storeFromFile(struct sparse lst[],short int d[2])
//int storeFromFile(struct sparse *lst,short int d[2])
{
    FILE *fp;
    int value=0;
    fp=fopen("input.txt","r");
    short int m,n,cnt=0,i,j;
    fscanf(fp,"%hi%hi",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d",&value);
            if(value!=0)
            {
                cnt++; 
                lst[cnt-1].r=i;
                lst[cnt-1].c=j;
                lst[cnt-1].v=value;
                /* cnt++; 
                lst=(struct sparse *)realloc(lst,cnt*sizeof(struct sparse));
                (lst+cnt-1)->r=i;
                (lst+cnt-1)->c=j;
                (lst+cnt-1)->v=value; */
            }
        }
    }
    return cnt; 
}
void print(struct sparse lst[],short int cnt)
//void print(struct sparse *lst,short int cnt)
{
    short int i;
    printf("Row \tColumn\t Value\n");
    for(i=0;i<cnt;i++)
    {
        printf(" %hi\t   %hi\t   %d\n",lst[i].r,lst[i].c,lst[i].v);
        //printf(" %hi\t   %hi\t   %d\n",(lst+i)->r,(lst+i)->c,(lst+i)->v);
    }
}
void main()
{
    short int cnt,cnt2,d1[2],d2[2]; 
    printf("Enter a matrix ");
    struct sparse lst[9];
    //struct sparse *lst=(struct sparse *)calloc(0,sizeof(struct sparse));
    cnt=storeFromFile(lst,d1);
    print(lst,cnt);
}