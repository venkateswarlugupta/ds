#include<stdio.h>
#include<stdlib.h>
#include"bns.h"
void main()
{
    short int m,n,i,j,c;
    printf("Enter dimensions of matrix : ");
    scanf("%hi%hi",&m,&n);
    printf("Enter elements of the array \n");
    int **arr=(int **)malloc(m*sizeof(int *)),x;
    for(i=0;i<m;i++)
    {
        arr[i]=(int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("Enter key : ");
    scanf("%d",&x);
    for(i=0;i<m;i++)
    {
        /* c=BinarySearch(arr[i],x,0,m);
        if(c!=-1)
        {
            printf("%d found at position ( %hi , %hi )\n",x,i,c);
        } */
        short int tr[2];
        BNSrange(arr[i],x,tr,n);
        if(tr[0]!=-1&&tr[1]!=-1)
        {
            for(int j=tr[0];j<=tr[1];j++)
                printf("%d found at position ( %hi , %hi )\n",x,i,j);
        }
    } 
}