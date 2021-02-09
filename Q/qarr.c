#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
#define n 50
int a[n];
void enqueue(){
    int x;
    printf("Enter element : ");
    scanf("%d",&x);
    if(rear==n-1){
        printf("Queue is full\n");
    }else if(front==-1 && rear==-1){
        front++;
    }
    a[++rear]=x;
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
        return x;
    }
}
void display(){
    printf("Elements in the Q\n");
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
        printf(" 1 enqueue\t 2 dequeue\t 3 display\t # exit : ");
        scanf("%hi",&choice);
        switch(choice)
        {
            case 1:enqueue();
                   break;
            case 2:x=dequeue();
                   printf("%d is deleted\n",x);
                   break;
            case 3:display();
                   break;
            default:exit(1);
        }
        printf("Shall we repeat\t # - Yes   0 - No :");
        scanf("%hi",&repeat);
    }while(repeat);
}