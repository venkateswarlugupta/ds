#include<stdio.h>
void main(){
    const int n=5;
    int i,arr[n][4];
    //arr[i][0] - depth  of  content
    //arr[i][0] - presentation  
    //arr[i][0] - communications  skills.
    //arr[i][0] - total
    for(i=0;i<n;i++){
        scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
        arr[i][3]=arr[i][0]+arr[i][1]+arr[i][2];
    }
}