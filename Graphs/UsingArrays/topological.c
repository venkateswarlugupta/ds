#include<stdlib.h>
#include<stdio.h>
void topological(int **graph,int n){
    int *indegree=(int *)calloc(n,sizeof(int));//autoinitialization - calloc
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            indegree[i]=indegree[i]+graph[j][i];
        }
    }
    int nn=n;
    while(nn){
        for(i=0;i<n;i++){
            if(indegree[i]==0){
                printf("\n%d\n",i+1);
                nn--;
                for(int p=0;p<n;p++){
                    printf("%d ",indegree[p]);
                }
                indegree[i]=indegree[i]-1;
                for(j=0;j<n;j++){
                    if(graph[i][j]==1){
                        indegree[j]=indegree[j]-1;
                    }
                }
            }
        }
    }
}
void main(){
    int **graph;
    int i,j,n;
    FILE *fp=fopen("inputTopological.txt","r");
    fscanf(fp,"%d",&n);
    graph=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        graph[i]=(int *)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    topological(graph,n);
}