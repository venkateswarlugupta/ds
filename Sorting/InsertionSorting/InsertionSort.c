#include<stdio.h>
void insertionSort(int arr[], int n){
    for(int nextpos,pos=1;pos<n;pos++){
        nextpos=pos;
        while(nextpos>0&&arr[nextpos]<arr[nextpos-1]){
            arr[nextpos]=arr[nextpos]+arr[nextpos-1];
            arr[nextpos-1]=arr[nextpos]-arr[nextpos-1];
            arr[nextpos]=arr[nextpos]-arr[nextpos-1];
            nextpos--;
        }
    }
}
void main(){
    int arr[6]={5,2,8,6,1,4};
    insertionSort(arr,6);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}