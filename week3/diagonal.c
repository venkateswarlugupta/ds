#include<stdlib.h>
#include<stdio.h>
void store(int *a,int n)
{
    printf("Enter diagonal elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void display(int **arr,int n)
{
    for(int i=0,j;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}
void main()
{
    int **arr,*a,i,j,n;
    printf("Enter dimensions of matrix : ");
    scanf("%d",&n);
    arr=(int **)calloc(n,sizeof(int *));
    a=(int *)calloc(n,sizeof(int));
    store(a,n);
    for(i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            if(i!=j)
                arr[i][j]=0;
            else
                arr[i][j]=a[i];
        }
    }
    printf("Printing Diagonal matrix : \n");   
    display(arr,n);
}