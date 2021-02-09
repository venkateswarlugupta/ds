#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int limit;
struct Shopping
{
  int id,quantity,cost;
  char name[32];
};
int size(struct Shopping *cart){
    int i=0,count=0;
    while(cart[i].id!=-1)
    {
        count++;
        i++;
    }
    return count;
}
void DisplayItems(struct Shopping *cart){
    int i;
    printf("Elements in the Cart are:\n");
    for(i=0;i<size(cart);i++){
        printf("%d",i);
        printf("Id: %d    Name: %s    quantity: %d    Cost: %d\n",cart[i].id,cart[i].name,cart[i].quantity,cart[i].cost);
    }
}
void DeleteItem(int pos,struct Shopping* cart){
    int i,j;
    for(j=0;j<size(cart);j++)
    {
        if(cart[j].id==pos)
        {
            pos=j+1;
            for(i=pos-1;i<size(cart);i++)
            {
                cart[i].id=cart[i+1].id;
                strcpy(cart[i].name,cart[i+1].name);
                cart[i].quantity=cart[i+1].quantity;
                cart[i].cost=cart[i+1].cost;
            }
         }
     }
     printf("Deleted Successfully\n");
     if(size(cart)==0)
         printf("Cart is Empty");
     else
         DisplayItems(cart);

}
int cost(struct Shopping* cart){
    int i,t=0;
    for(i=0;i<size(cart);i++){
        t=t+cart[i].cost;
    }
    return t;
}
void AddItems(struct Shopping temp,struct Shopping *cart){
    int l,p;
    char command;
    if((cost(cart)+temp.cost)>limit)
    {
        printf("ERROR: Budget Exceeding %d Rupees. Please remove some item(s).\n",limit);
        printf("Do you want to remove now?(Y/N)");
        scanf(" %c",&command);
        if(command=='Y' || command=='y')
        {
            printf("Enter ID of the element to be Deleted: ");
            scanf("%d",&p);
            DeleteItem(p,cart);
        }
    }
    else
    {
        l=size(cart);
        cart[l].id=temp.id;
        strcpy(cart[l].name,temp.name);
        cart[l].quantity=temp.quantity;
        cart[l].cost=temp.cost;
        DisplayItems(cart);
    }
}
void SearchByID(int x,struct Shopping* cart){
    int i=0;
    if(size(cart)==0)
    {
        printf("No items in cart to search");
    }
    else
    {
        while(i<size(cart))
        {
            if(cart[i].id==x)
            {
                printf("Id: %d\tName: %s\tquantity: %d\t\tCost: %d\n",cart[i].id,cart[i].name,cart[i].quantity,cart[i].cost);
            }
            i++;
        }
    }
}
/*
    Good after noon sir.. I am venkateswarlu vasavi clg of engineering.
    roll no 119 cse b. My topic is memory organiztion in modern computers
    structures i am gonna use are classification and compare contrast
    memory is broadly classfied as Read Only Memeory , Random Access Memeory, and cache 
    different types of rom - magnetic disk, optical disks, flash memeory devices
    RAM further divides into Static and dynamic 
    where dyanmic has 2 types - synchronous and asynchronus
    synchronous works based on clock signal, 
    on the other hand asynchronous does not require any clock
    last but not least cache is avalible as primary and secondary cache
    nevertheless all these are present physically inside the system.
    but relative positions of these units varies
    cache is built along with processor
    where as ram and rom are connected by various buses
    ironically speeds varies, when we compare cache with other memory units,
    speed to accese cache is high, but to access rom it consumes more time
    in the same way, cost to build also worth noting.
    physical sizes of cache is small, but rom is larger  
*/
void SortByCost(struct Shopping* cart)
{
    int i,j;
    struct Shopping temp;
    if(size(cart)==0)
    {
        printf("No Items in cart to sort");
    }
    else
    {
        for(i=0;i<size(cart);i++)
        {
            for(j=i+1;j<size(cart);j++)
            {
                if(cart[j].cost<cart[i].cost)
                {

                    temp=cart[j];
                     cart[j]=cart[i];
                    cart[i]=temp;
                    temp.id=cart[j].id;
                    cart[j].id=cart[i].id;
                    cart[i].id=temp.id;

                    strcpy(temp.name,cart[i].name);
                    strcpy(cart[i].name,cart[j].name);
                    strcpy(cart[j].name,temp.name);

                    temp.quantity=cart[j].quantity;
                    cart[j].quantity=cart[i].quantity;
                    cart[i].quantity=temp.quantity;

                    temp.cost=cart[j].cost;
                    cart[j].cost=cart[i].cost;
                    cart[i].cost=temp.cost;
                }
            }
        }
        printf("Sorted Successfully\n");
    }
}
void main()
{
    printf("Enter your budget: ");
    scanf("%d",&limit);
    struct Shopping temp,cart[20];
    int i,item,element,position,opt;
    char command='y';
    for(i=0;i<20;i++)
        cart[i].id=-1;
    while(command=='y')
    {
        printf("Enter an option from below:\n ");
        printf("\t1) Add Items\n");
        printf("\t2) Delete Items\n");
        printf("\t3) Display them in Descending order based on Cost\n");
        printf("\t4) Search Item\n");
        printf("\t5) Display all The Items\n");
        scanf("%d",&opt);
        switch(opt){
            case 1: printf("Enter the Details of the Item : \n\n");
                    printf("Enter name of Item: ");
                    scanf("%s",temp.name);
                    printf("Enter ID of Item: ");
                    scanf("%d",&temp.id);
                    printf("Enter Quantity: ");
                    scanf("%d",&temp.quantity);
                    printf("Enter cost of Item: ");
                    scanf("%d",&temp.cost);
                    AddItems(temp,cart);
                    break;
            case 2: if(size(cart)==0)
                    {
                        printf("ERROR: No Items in Cart\n");
                    }
                    else
                    {
                        printf("Enter ID of element to be Deleted: ");
                        scanf("%d",&position);
                        DeleteItem(position,cart);
                    }
                    break;
            case 3: printf("Enter Item ID to be Searched: ");
                    scanf("%d",&element);
                    SearchByID(element,cart);
                    break;
            case 4: SortByCost(cart);
                    DisplayItems(cart);
                    break;
            case 5: DisplayItems(cart);
                    break;
        }
        printf("\nDo you want to Still Add Items?(Y/N):");
        scanf(" %c",&command);
        if(command=='N' || command=='n'){
            printf("\tEnd");
        }
    }
}
/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Shopping
{
    short id;
    char name[32];
    short quantity;
    float cost;
};
void main()
{
    short i,j,n;
    printf("No of items : ");
    scanf("%hi",&n);
    struct Shopping *cart;
    cart=(struct Shopping *)malloc(n*sizeof(struct Shopping));
    printf("Memory allocated : %hi\n",n*sizeof(*cart));
    printf("Enter id name quantity cost\n");
    for(i=0;i<n;i++)
        scanf("%hi%s%hi%f",
        &cart[i].id,cart[i].name,&cart[i].quantity,&cart[i].cost);
    switch(opt)
    {
        
    }
    for(i=0;i<n;i++)
        printf("%hi %s %hi %f\n",
        cart[i].id,cart[i].name,cart[i].quantity,cart[i].cost);
    printf("\nOK");
} */