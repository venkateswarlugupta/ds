#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
    /* char s[10];
    int i;
    printf("Enter a string \n");
    scanf("%s",&s);
    printf("size of string : %d\n",sizeof(s)/sizeof(s[0]));
    for(i=0;i<10;i++)
        printf("%c ",s[i]);
    printf("End\n"); */

    char *s;
    int n,i;
    printf("lenght of the string : ");
    scanf("%d",&n);
    s=(char *)malloc(n*sizeof(char));
    printf("enter string : ");
    scanf("%s",s);
    printf("size of string : %d\n",strlen(s));
    printf("%s",s);
}

/* #include <stdio.h>
int a[20],n,i,j,pos,item,temp,toBeSearched,found;
//Inserting
void Insert(int a[],int n)
{
    printf("Type a Position where you want to insert: ");
    scanf("%d",&pos);
    printf("Enter Element to be inserted: ");
    scanf("%d",&item);
    printf("Original Elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    j = n;
    n = n+1;
    while(j >= pos-1)
    {
        a[j+1] = a[j];
        j--;
    }
    a[pos-1] = item;
    printf("Elements after Insertion are:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("Insertion Successful\n\n");
}
//Deleting
void Delete(int a[],int n)
{
    if(n==0)
        printf("ERROR: Can't Delete Because their are no elements in the array");
    printf("Type the Position to be deleted: ");
    scanf("%d",&pos);
    printf("Original Elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    j = pos;
    while(j < n)
    {
        a[j-1] = a[j];
        j++;
    }
    n = n - 1;
    printf("Elements After Deletion:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("Deletion Successful\n\n");

}
//Sorting
void Sort(int a[],int n)
{
    if(n==0)
        printf("ERROR: Can't Sort Because their are no elements in the array");
    else
    {
        printf("Original Elements are:\n");
        for(i=0;i<n;i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printf("Elements After Sorting\n");
        for(i=0;i<n;i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        printf("Sorted Successfully\n\n");
    }
}
//Searching
void Search(int a[],int n)
{
    if(n==0)
        printf("ERROR: Can't Search Because their are no elements in the array");
    else
    {
        printf("Enter element to be searched: ");
        scanf("%d",&toBeSearched);
        found = 0;
        for(i=0;i<n;i++)
        {
            if(toBeSearched == a[i])
            {
                found = 1;
                printf("%d found at %d\n\n",toBeSearched,i+1);
            }
        }
        if(found == 0)
            printf("%d not found\n\n",toBeSearched);
    }
}
//Update
void Update(int a[],int n)
{
    if(n==0)
        printf("ERROR: Can't Update Because their are no elements in the array");
    else
    {
        printf("Enter postion to be updated: ");
        scanf("%d",&pos);
        printf("Enter Element to be placed: ");
        scanf("%d",&item);
        a[pos-1] = item;
        printf("Original Elements are:\n");
        for(i=0;i<n;i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        printf("Updated Successfully\n");
    }
}

void main()
{
    int opt;
    char choice;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf(" \t\t1) Insertion \t\t\n \t\t2) Deletion \t\t\n \t\t3) Sorting \t\t\n \t\t4) Searching \t\t\n \t\t5) Updating \t\t\n\nEnter an option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: Insert(a,n);
                    break;
            case 2: Delete(a,n);
                    break;
            case 3: Sort(a,n);
                    break;
            case 4: Search(a,n);
                    break;
            case 5: Update(a,n);
                    break;
        }
        printf("Do You Want To do the Operations Again[Y/N]: ");
        scanf("%c",&choice);
    }while(choice=='Y' || choice=='y');
} */