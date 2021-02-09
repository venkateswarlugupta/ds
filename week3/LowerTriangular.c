#include<stdio.h>
#include<stdlib.h>
void store(short int *a,short int n)
{
    printf("Enter elements of lower trangular matrix : \n");
    for(int i=0;i<(n*(n+1))/2;i++)
            scanf("%hi",&a[i]);
}
void display(short int **arr,short int n)
{
    for(short int i=0,j;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%hi ",arr[i][j]);
        printf("\n");
    }
}
void main()
{
    short int *a,**arr,i,j,n,k=0;
    printf("Enter dimensions of matrix : ");
    scanf("%hi",&n);
    arr=(short int **)calloc(n,sizeof(short int *));
    a=(short int *)calloc((n*(n+1))/2,sizeof(short int));
    store(a,n);
    for(i=0;i<n;i++)
    {
        arr[i]=(short int *)calloc(n,sizeof(short int));
        for(j=0;j<n;j++)
        {
            if(j<=i)
            {
                arr[i][j]=a[k];
                k++;
            }
            else
                arr[i][j]=0;
        }
    }
    display(arr,n);
}