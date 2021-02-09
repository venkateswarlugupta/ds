/* #include<string.h>
#include<stdio.h>
#include<stdlib.h>
char depts[6][6]={"civil","cse","ece","eee","it","mech"};
int deptcnt[6]={0};
typedef struct E
{
    int id;
    char name[32];
    char dept[8];
    float salary;
    struct E *link;
}E;
void addElements(E *h)
{
    int n;
    printf("No of elements : ");
    scanf("%d",&n);
    E *q=NULL;
    q=h;
    if(q->id==-1)
    {
        for(int i=0;i<n-1;i++)
        {
            E *t=(E *)calloc(1,sizeof(E));
            scanf("%d%s%s%f",&q->id,q->name,q->dept,&q->salary);
            q->link=t;
            q=t;
        }
        scanf("%d%s%s%f",&q->id,q->name,q->dept,&q->salary);
        q->link=NULL;
    }
    else
    {
        while(q->link!=NULL)
        {
            q=q->link;
        } 
        for(int i=0;i<n;i++)
        {
            E *t=(E *)calloc(1,sizeof(E));
            q->link=t;
            q=t;
            scanf("%d%s%s%f",&q->id,q->name,q->dept,&q->salary);
        }
        q->link=NULL;
    }
}
void bubbleStrings(E *h)
{
    E *i,*j;
    i=h;
    while(i->link!=NULL)
    {
        j=i->link;
        while(j->link!=NULL)
        {
            if(strcmp(i->name,j->name)>0)
            {
                int tempid;
                float tempsalary;
                char tempname[32],tempdept[6];
                strcpy(tempname,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,tempname);
                strcpy(tempdept,i->dept);
                strcpy(i->dept,j->dept);
                strcpy(j->dept,tempdept);
                tempid=i->id;
                i->id=j->id;
                j->id=tempid;
                tempsalary=i->salary;
                i->salary=j->salary;
                j->salary=tempsalary;
            }
            j=j->link;
        }
        if(strcmp(i->name,j->name)>0)
        {
                int tempid;
                float tempsalary;
                char tempname[32],tempdept[6];
                strcpy(tempname,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,tempname);
                strcpy(tempdept,i->dept);
                strcpy(i->dept,j->dept);
                strcpy(j->dept,tempdept);
                tempid=i->id;
                i->id=j->id;
                j->id=tempid;
                tempsalary=i->salary;
                i->salary=j->salary;
                j->salary=tempsalary;
        }
        i=i->link;
    }
}
void displaydept(E *h)
{
    E *q=NULL;
    int i=0;
    while(i<6)
    {
        q=h;
        while(q->link!=NULL)
        {
            if(!strcmp(depts[i],q->dept))
            {
                printf("%3d   %7s   %4s        %4.2f\n",q->id,q->name,q->dept,q->salary);
                deptcnt[i]++;
            }
            q=q->link;
        }
        if(!strcmp(depts[i],q->dept))
        {
            printf("%3d   %7s   %4s        %4.2f\n",q->id,q->name,q->dept,q->salary);
            deptcnt[i]++;
        }
        i++;
    }
}
void main()
{
    E *h=(E *)calloc(1,sizeof(E));
    h->id=-1;
    addElements(h);
    bubbleStrings(h);
    printf("\n\n Displaying the details of emploees \n");
    printf("Id      Name    Department  Salary\n");
    displaydept(h); 
    printf("No of Employees in each department\n");   
    for(int i=0;i<6;i++)
    {   
        // printf("%S : ",depts[i]);
        printf(" %s : %d \n",depts[i],deptcnt[i]);
    } 
} */
#include<stdio.h>
void main()
{
    int a[50],i,j,n;
    printf("Enter no of terms : ");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        int m=0;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>m)
                m=a[j];
        }
        printf("%d ",m);
    }
    printf("-1");
}