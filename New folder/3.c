#include<stdio.h>
#define N 5
int dequeue[N];
int front=-1;
int rear=-1;
int Isempty(){
    if (front==-1&&rear==-1){
        return 1;
    }
    else
       return 0;
}
int Isfull(){
    if(rear+1==front||rear==N-1){
        return 1;
    }
    else{
        return 0;
    }
}
void Insert_beginning(){
    int x;
    printf("Enter the element to u want to insert\n");
    scanf("%d",&x);
    if(Isfull()==1){
        printf("Queue is full\n");
        
    }
    else if(Isempty()==1){
        front=0;
        rear=0;
        dequeue[rear]=x;
    }
    else{
        front=(front-1+N)%N;
        dequeue[front]=x;
    }
}
void Insert_end(){
        int x;
    printf("Enter the element to u want to insert\n");
    scanf("%d",&x);
  if(Isempty()==1){
      front=0;
      rear=0;
      dequeue[rear]=x;
  } 
  else if(Isfull()==1){
    printf("Queue is full\n");
  }
  else{
       rear=(rear+1)%N;
        dequeue[rear]=x;

  }
}
int delete_front(){
    int x;
    if(Isempty()==1){
        printf("Cannot delete as queue is empty\n");
    }
    else{
        x=dequeue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%N;
        }
        return x;
    }
}
int delete_end(){
   int x;
    if(Isempty()==1){
        printf("Cannot delete as queue is empty\n");
    }
    else{x=dequeue[rear];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            rear=(rear-1+N)%N;
        }
        return x;
    }
}
int display(){int i;
    printf("The elements in the queue are:\n");
    if(Isempty()==1){
        printf("Queueis empty\n");
    }
    else{
        for( i=front;i!=rear; i=(i+1)%N){
            printf("%d ",dequeue[i]);
            
        }
        printf("%d",dequeue[rear]);
    }
}
int main(){
   Insert_beginning();
   Insert_end();
   Insert_end();
   delete_front();
   display();
}