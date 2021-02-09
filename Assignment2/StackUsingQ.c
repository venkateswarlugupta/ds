#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
#define n 50
//performing rotation after every enQ(push) operation into the Q
int a[n],cnt=0;
void rotate(){
    int t=a[cnt-1];
    for(int i=cnt-1;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=t;
}
void enqueue(){
    int x;
    printf("Enter element : ");
    scanf("%d",&x);
    if(rear==n-1){
        printf("Queue is full\n");
        return;
    }else if(front==-1 && rear==-1){
        front++;
    }
    ++cnt;
    a[++rear]=x;
    rotate();
}
int dequeue(){
    int x;
    if(front==-1 && rear==-1){
        printf("No elements to delete\n");
    }else if(front==rear){
        front=-1;
        rear=-1;
    }else{
        x=a[front];
        front++;
        cnt--;
        return x;
    }
}
void display(){
    printf("Elements in the Stack\n");
    if(front==-1){
        printf("Queue is empty\n");
    }else{
        for(int i=front;i<rear;i++){
        printf("%d->",a[i]);
        }
    }
    printf("%d\n",a[rear]);
}
void main()
{
    int x;
    short repeat;
    do
    {
        short choice;
        printf(" 1 push\t 2 pop\t 3 display\t # exit : ");
        scanf("%hi",&choice);
        switch(choice)
        {
            case 1:enqueue();
                   break;
            case 2:x=dequeue();
                   printf("%d is poped\n",x);
                   break;
            case 3:display();
                   break;
            default:exit(1);
        }
        printf("Shall we repeat\t # - Yes   0 - No :");
        scanf("%hi",&repeat);
    }while(repeat);
}