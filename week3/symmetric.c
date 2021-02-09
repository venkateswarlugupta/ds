#include<stdio.h>
#include<stdlib.h>
void store(short int *a,short int n)
{
    printf("Enter elements of upper trangular matrix row wise : \n");
    for(short int i=0;i<n*(n+1)/2;i++)
        scanf("%hi",&a[i]);
}
void display(short int **arr,short int n)
{
    for(int i=0,j;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%hi ",arr[i][j]);
        printf("\n");
    }
}
/* 
void main()
{
    short int *a,**arr,i,j,n,k=0;
    printf("Enter dimensions of martix : ");
    scanf("%hi",&n);
    arr=(short int **)malloc(n*sizeof(short int *));
    a=(short int *)malloc((n*(n+1)/2)*sizeof(short int));
    store(a,n);
    for(i=0;i<n;i++)
    {
        arr[i]=(short int *)malloc(n*sizeof(short int));
        for(j=0;j<n;j++)
        {
            if(j>=i)
            {
                arr[i][j]=a[k];
                k++;
            }
            else
                arr[i][j]=0;
        }
    } 
    printf("Printing upper triangular matrix : \n");
    display(arr,n);
} */
void main()
{
    short int *a,**arr,i,j,n,k=0;
    printf("Enter dimensions of martix : ");
    scanf("%hi",&n);
    arr=(short int **)malloc(n*sizeof(short int *));
    a=(short int *)malloc((n*(n+1)/2)*sizeof(short int));
    store(a,n);
    for(i=0;i<n;i++)
    {
        arr[i]=(short int *)malloc(n*sizeof(short int));
        for(j=0;j<n;j++)
        {
            if(j>=i)
            {
                arr[i][j]=a[k];
                k++;
            }
            else
                arr[i][j]=arr[j][i];
        }
    } 
    printf("Printing symmetric matrix : \n");
    display(arr,n);
}