#include<stdio.h>
int cnt=0,sz=6;
char q[6];
int front=-1,rear=-1;
void enqueue(){
    if((rear+1)%sz==front)
        printf("Q is Full\n");
    else{
        if(front==-1)
            ++front;
        rear=(rear+1)%sz;
        printf("Enter element : ");
        scanf(" %c",&q[rear]);
        cnt++;
    }
}
void dequeue(){
    if(front==-1)
        printf("Q is empty\n");
    else if(front==rear){
        printf("dequeued : %c\n",q[front]);
        front=-1;
        rear=-1;
        cnt--;
    }else{
        printf("dequeued : %c\n",q[front]);
        front=(front+1)%sz;
        cnt--;
    }
}
void display(){
    if(front==-1)
        printf("Q is empty\n");
    else{
        int i=front;
        printf("Elements of Q are\n");
        while(1){
            printf("%c ",q[i]);
            if(i==rear) break;
            i=(i+1)%sz;
        }
        printf("\n");       
    }
}
void main(){
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    dequeue();
    display();
    enqueue();
    enqueue();
    display();
    enqueue();
    printf("Count is : %d\n",cnt);
}