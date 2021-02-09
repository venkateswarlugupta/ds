#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    //char ch;
    int value=0,m,n;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d%d",&m,&n);
    int arr[m][n],i,j;
    printf("%d %d \n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    /* fp=fopen("input.txt","r");
    while(1)
    {
        ch=getc(fp);
        if(ch!=' ')
        {
            value=value*10+(int)ch-48;
        }
        if(ch=='\n'||ch==EOF)
            value=value*10+(int)ch-;            
        if(ch==' '||ch=='\n'|| ch==EOF)
        {
            printf("%d ",value);
            value=0;
        } 
         fscanf(fp,"%d",&value);
        if(fscanf(fp,"%d",&value)!=1) exit(1);
        printf("%d ",value);        
    }*/ 
}