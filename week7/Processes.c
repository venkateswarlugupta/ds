#include<stdio.h>
int noOfRoundsRequired=0,noOfProcesses=0,circularQFront=-1,circularQRear=-1;
int waitingQFront=-1,waitingQRear=-1;
int  waitingQ[100][2],circularQ[4][2];
void saving(int activeProcesses){
    if((circularQRear+1)%activeProcesses==circularQFront){
        if(waitingQFront==-1)   waitingQFront++;
        scanf(" %d %d",&waitingQ[++waitingQRear][0],&waitingQ[waitingQRear][1]);
    }
    else{
        if(circularQFront==-1)
            ++circularQFront;
        circularQRear=(circularQRear+1)%activeProcesses;
        scanf(" %d %d",&circularQ[circularQRear][0],&circularQ[circularQRear][1]);
    }
}
void processing(){
    int timeSlice;
    printf("Enter time slice : ");
    scanf("%d",&timeSlice);
    while(noOfProcesses>0){
        ++noOfRoundsRequired;
        for(int i=circularQFront;i<=circularQRear;i++){
            if(circularQ[i][0]==-1&&circularQ[i][1]==-1){
                continue;
            }
            circularQ[i][0]+=timeSlice;
            if(circularQ[i][0]>=circularQ[i][1]){
                if(waitingQFront!=-1){// waiting q not empty
                    circularQ[i][0]=waitingQ[waitingQFront][0];
                    circularQ[i][1]=waitingQ[waitingQFront][1];  
                    waitingQFront++;              
                }else{
                    circularQ[i][0]=-1;
                    circularQ[i][1]=-1;
                }
                noOfProcesses--;
            }
        }
    }
    printf("No of rounds required to complete all processes : %d",noOfRoundsRequired);
}
void main(){
    printf("Enter no of processes : ");
    scanf("%d",&noOfProcesses);
    for(int i=0;i<noOfProcesses;i++){
        printf("Enter %dth process : ",i);
        saving(4);
    }
    processing();
}
/* #include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int start;
    int end;
    struct node *link;
}processes;
processes *h;
int time_slice,count=0,n;
void createProcessesQ(){
    processes *q;
    int i;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    printf("Enter start time, end time of each process\n");
    for(i=0;i<n;i++){
        processes *t=(processes *)malloc(sizeof(processes));
        printf("%d : ",i);
        scanf("%d%d",&t->start,&t->end);
        t->link=NULL;
        if(h==NULL){
            h=t;
            q=t;
        }else{
            q->link=t;
            q=t;
        }
    }
    q->link=h;
}
void processScheduling(){
    processes *q,*th;
    // th is tempHEAD, because head will change
    // when we delete at the begining
    q=h;
    th=h;
    int j=0;
    while(th!=NULL){
        if(q->start>=q->end){
            //delete the process
            processes *t;
            if(q->link==th){//only one process
                t=q;
                free(t);
                th=NULL;
            }else if(q==th){//deletion at the beginning
                t=q;
                th=q;
                while(q->link!=th){
                    q=q->link;
                }
                q->link=th->link;
                q=q->link;
                th=th->link;
                free(t);
            }else if(q->link==th){//deletion at the end
                while(q->link->link!=th){
                    q=q->link;
                }
                t=q->link;
                q->link=th;
                q=q->link;
                free(t);
            }else{
                t=q;
                while(q->link->link!=t){
                    q=q->link;
                }
                q->link=q->link->link;
                free(t);
                q=q->link;
            }
        }
        q->start+=time_slice;
        if(q->link==th) j++;
    }
    count=j;
}
void displayCurrentState(){
    processes *q;
    q=h;
    while(q->link!=h){
        printf("%d\t%d\n",q->start,q->end);
        q=q->link;
    }
    printf("%d\t%d\n",q->start,q->end);
}
void main(){
    h=NULL;
    createProcessesQ();
    printf("Enter time slice : ");
    //displayCurrentState();
    scanf("%d",&time_slice);
    processScheduling();
    printf("Result : %d",count);
} */