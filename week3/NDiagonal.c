#include<stdlib.h>
#include<stdio.h>
int ND;
int Lost(int nd)
{
    nd/=2;
    return nd*(nd+1);
}
int lr(int row,int size)
{
    int l=row-ND/2;
    if(l<=0)
        l=0;
    return l;
}
int ur(int row,int size)
{
    int m=row-ND/2+ND-1;
    if(m>size-1)
        m=size-1;
    return m;
}
void initialize(int **arr,int n)
{
    for(int j,i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            arr[i][j]=0;
    }
}
void store(int a[],int ElementsInNdiagonal)
{
    printf("Enter elements of %d Diagonal matrix row wise ",ND);
    for(int i=0;i<ElementsInNdiagonal;i++)
        scanf("%d",&a[i]);
}
void main()
{
    int **arr,i,j,n,ElementsInNdiagonal;
    printf("Enter dimensions of matrix : ");
    scanf("%d",&n);
    printf("Enter number of diagonals : ");
    scanf("%d",&ND);
    arr=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        arr[i]=(int *)malloc(n*sizeof(int));
    initialize(arr,n);
    ElementsInNdiagonal=ND*n-Lost(ND);
    int a[ElementsInNdiagonal],k=0;
    store(a,ElementsInNdiagonal);
    for(i=0;i<n;i++)
    {
        int l,m;   
        l=lr(i,n);
        m=ur(i,n);
        for(j=0;j<n;j++)
        {
            if(j>=l&&j<=m) {arr[i][j]=a[k];k++;}
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
/* void main()
{
    int n,i,j,I;
    printf("Enter size of matrix : ");
    scanf("%d",&n);
    printf("Enter number of diagonals : ");
    scanf("%d",&ND);
    int **a;
    a=(int **)calloc(n,sizeof(int *));
    for(i=0;i<n;i++)
    {
        I=i-ND/2;
        if((n-i+1)<ND/2)
            I=i-ND/2+ND-n;
        a[i]=(int *)calloc(ND,sizeof(int));
        for(j=0;j<ND;j++)
        {
            if(I<0&&i<n/2)
            {
                a[i][j]=-1;
                I++;
            }
            if(I<0&&i>n/2)
            {
                a[i][j]=-1;
                I++;
            }
            else
            {
                scanf("%d",&a[i][j]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
} */