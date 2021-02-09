#include<stdlib.h>
#include<stdio.h>
int count=0;
void DFS(int **Graph, int *visited, int *parent, int *pre, int *post, int n, int startVertex){
    visited[startVertex]=1;
    pre[startVertex]=count++;
    printf("%d",startVertex);
    for(int j=0;j<n;j++){
        if(Graph[startVertex][j]==1){
            if(visited[j]==0){
                parent[j]=startVertex;
                DFS(Graph, visited, parent, pre, post, n, j);
                post[startVertex]=count++;
                //when no elements are left to visit(at the last vertex...), this block wont be triggered
            }
            
        }
    }
}
void main(){
    int noOfVertices,i,j;
    FILE *fp;
    fp=fopen("input1.txt", "r");
    fscanf(fp,"%d",&noOfVertices);
    int **Graph=(int **)malloc(sizeof(int *)*noOfVertices);
    int *visited=(int *)malloc(sizeof(int)*noOfVertices);
    int *parent=(int *)malloc(sizeof(int)*noOfVertices);
    int *pre=(int *)malloc(sizeof(int)*noOfVertices);
    int *post=(int *)malloc(sizeof(int)*noOfVertices);
    for(i=0;i<noOfVertices;i++){
        Graph[i]=(int *)malloc(sizeof(int)*noOfVertices);
        visited[i]=0;
        parent[i]=-1;
        pre[i]=-1;
        post[i]=-1;
        for(j=0;j<noOfVertices;j++){
            fscanf(fp,"%d",&Graph[i][j]);
        }
    }
    for(i=0;i<noOfVertices;i++){
        for(j=0;j<noOfVertices;j++){
            printf("%d ",Graph[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    DFS(Graph, visited, parent, pre, post, noOfVertices, 0);
    printf("Before visiting : ");
    for(i=0;i<noOfVertices;i++){
        printf("%d ",pre[i]);
    }
    printf("\n");
    printf(" After visiting : ");
    for(i=0;i<noOfVertices;i++){
        printf("%d ",post[i]);
    }
    /* printf("\n\n");
    for(i=0;i<noOfVertices;i++){
        visited[i]=0;
    }
    DFS(Graph, visited, parent, noOfVertices, 1);
    printf("\n\n");
    for(i=0;i<noOfVertices;i++){
        visited[i]=0;
    }
    DFS(Graph, visited, parent, noOfVertices, 2);
    printf("\n\n");
    for(i=0;i<noOfVertices;i++){
        visited[i]=0;
    }
    DFS(Graph, visited, parent, noOfVertices, 3);
    printf("\n\n");
    for(i=0;i<noOfVertices;i++){
        visited[i]=0;
    }
    DFS(Graph, visited, parent, noOfVertices, 4);
    printf("\n\n"); */
}