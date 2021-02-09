#include<stdio.h>
#include<stdlib.h>
#define INF 987654
void dijkstras(int **graph, int n, int source){
    int i,j,max=0;
    int *visited=(int *)calloc(n,sizeof(int));
    int *distance=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        distance[i]=INF;
    } 
    distance[source]=0;
    for(i=0;i<n;i++){
        int uu=INF,u=-1;
        for(j=0;j<n;j++){
            if(uu>=distance[j]&&visited[j]==0){
                uu=distance[j];
                u=j;
            }
        }
        visited[u]=1;
        for(j=0;j<n;j++){
            max+=graph[i][j];
            if(visited[j]==0&&graph[u][j]!=0){
                if(distance[j]>distance[u]+graph[u][j]){
                    distance[j]=distance[u]+graph[u][j];
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(distance[i]>max)
            distance[i]=-1;
        printf("%d ",distance[i]);
    }
    printf("\n");
}
void dijkstrasd(int **graph, int n, int source, int destination){
    int i,j,max=0;
    int *visited=(int *)calloc(n,sizeof(int));
    int *distance=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        distance[i]=INF;
    } 
    distance[source]=0;
    for(i=0;i<n;i++){
        int uu=INF,u=-1;
        for(j=0;j<n;j++){
            if(uu>=distance[j]&&visited[j]==0){
                uu=distance[j];
                u=j;
            }
        }
        visited[u]=1;
        for(j=0;j<n;j++){
            max+=graph[i][j];
            if(visited[j]==0&&graph[u][j]!=0){
                if(distance[j]>distance[u]+graph[u][j]){
                    distance[j]=distance[u]+graph[u][j];
                }
            }
        }
    }
    /* for(i=0;i<n;i++){
        if(distance[i]>max)
            distance[i]=-1;
        printf("%d ",distance[i]);
    }
    printf("\n"); */
    printf("%d",distance[destination]);
}
void main(){
    int **graph;
    int i,j,n;
    FILE *fp;
    fp=fopen("inputDijkstras1.txt","r");
    fscanf(fp,"%d",&n);
    graph=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        graph[i]=(int *)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    printf("From A : ");
    dijkstras(graph, n, 0);
    printf("From B : ");
    dijkstras(graph, n, 1);
    printf("From C : ");
    dijkstras(graph, n, 2);
    printf("From D : ");
    dijkstras(graph, n, 3);
    printf("From E : ");
    dijkstras(graph, n, 4);   
    printf("Shortest path between B and D : ");
    dijkstrasd(graph, n, 1, 3);
}