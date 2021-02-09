#include<stdio.h>
#define size 10
int hashFunction(int value){
    return value%size;
}
int checkIsAvailable(int arr[], int position){
    return arr[position]==-1;
}
int updateArray(int arr[], int value){
    int position=hashFunction(value);
    while(1){
        if(checkIsAvailable(arr, position)){
            arr[position]=value;
            break;
        }else{
            position++;
            if(position>=size)
                position=0;
        }
    }
}
int retrieveMe(int arr[], int value){
    int temp=value%size;
    while(1){
        if(arr[temp]==value){
            return temp;
        }else{
            temp++;
            if(temp==size)
                temp=0;
        }
    }
}
void displayHashTable(int arr[]){
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}
void main(){
    int noOfElements,i,element,arr[size];
    for(i=0;i<size;i++)//initialize
        arr[i]=-1;
    printf("Enter no of elements : ");
    scanf("%d",&noOfElements);
    printf("Enter elements \n");
    if(noOfElements<=size){
        for(i=0;i<noOfElements;i++){
            scanf("%d",&element);
            updateArray(arr,element);
        }
        displayHashTable(arr);
    }else{
        printf("Insufficent size \n");
    }
    printf("\nposition of 15 %d",retrieveMe(arr, 15));
}