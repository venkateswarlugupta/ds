#include<stdlib.h>
#include<stdio.h> 
void main()
{
    int i,j,n,**a;
    printf("Enter size of the square matrix : ");
    scanf("%d",&n);
    a=(int **)calloc(n,sizeof(int *));
    printf("Enter elements : ");
    for(i=0;i<n;i++)
    {
        a[i]=(int *)calloc(n,sizeof(int));
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    int m=n,k=0,l=0;
    while(k<m&&l<n) 
    { 
        for(i=l;i<n;++i)  
            printf("%d ",a[k][i]); 
        k++; 
        for(j=k;j<m;++j) 
            printf("%d ",a[j][n-1]); 
        n--; 
        if(k<m)
        { 
            for(i=n-1;i>=l;--i)  
                printf("%d ",a[m-1][i]); 
            m--; 
        }
        if(l<n)
        { 
            for(j=m-1;j>=k;--j)  
                printf("%d ",a[j][l]);
            l++; 
        }
    }
}
