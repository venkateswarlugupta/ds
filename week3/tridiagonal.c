#include<stdio.h>
#include<stdlib.h>
void store(unsigned short int  *a,unsigned short int  n)
{
    printf("Enter elements of tridiagonal Matrix : \n");
    for(unsigned short int  i=0;i<n*3-2;i++)
        scanf("%hu",&a[i]);    
}
void display(unsigned short int  **arr,unsigned short int  n)
{
    for(unsigned short int  i=0,j;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%hu ",arr[i][j]);
        printf("\n");
    }
}
void main()
{
    unsigned short int  i,j,n,*a,**arr;
    printf("Enter dimensions of matrix :");
    scanf("%hu",&n);
    a=(unsigned short int  *)calloc(n*3-1,sizeof(unsigned short int ));
    arr=(unsigned short int  **)malloc(n*sizeof(unsigned short int  *));
    store(a,n);
    for(i=0;i<n;i++)
    {
        unsigned short int  jump=0,cur=(i+n-1)%n;
        arr[i]=(unsigned short int  *)calloc(n,sizeof(unsigned short int ));
        for(j=0;j<n;j++)
        {   
            if(j<=i+1&&j>=i-1)
            { 
                arr[i][j]=a[jump+cur];
                jump+=n+cur;
                cur=0;
            }
            else
            {
                arr[i][j]=0;
            }
        }
    }
    display(arr,n);
}
/* 
1 1 1 0 0 0             1 1 1 0
  1 1 1 0 0               1 1 1
  0 1 1 1 0               0 1 1 1
  0 0 1 1 1
  0 0 0 1 1 1

a f k 0 0 0
  b g l 0 0 
  0 c h m 0
  0 0 d i n
  0 0 0 e j o

    INPUT
                b c d e f g h i j k  l m  n 
         pos:   0 1 2 3 4 5 6 7 8 9 10 11 12
     1st row:           4         9
     2nd row:   0         5         10
     3rd row:     1         6          11
     4th row:       2         7           12
     5th row:         3         8 
 */