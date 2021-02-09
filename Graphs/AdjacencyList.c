#define INF 987654
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int to;
    int weight;
    struct node *next;
};
struct graph
{
    int noOfVertices;
    struct node **lists;
};
struct node *createNode(int t,int w)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->to = t;
    new->weight=w;
    new->next = NULL;
    return new;
}
struct graph *createGraph(int vertices)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->noOfVertices = vertices;
    g->lists = (struct node **)malloc(sizeof(struct node *) * vertices);
    while (vertices > 0)
    {
        g->lists[--vertices] = NULL;
    }
    return g;
}
void addEdgeForward(struct graph *g, int from, int to,int w)
{
    struct node *new = createNode(to,w);
    new->next = g->lists[from];
    g->lists[from] = new;
}
void addEdgeBackward(struct graph *g, int from, int to,int w)
{
    struct node *new = createNode(from, w);
    new->next = g->lists[to];
    g->lists[to] = new;
}
void addEdge(struct graph *g, int from, int to, int isUndirected,int w)
{
    addEdgeForward(g, from, to,w);
    if (isUndirected)
    {
        addEdgeBackward(g, from, to,w);
    }
}
void print(struct graph *g)
{
    for (int v = 0; v < g->noOfVertices; v++)
    {
        struct node *t = g->lists[v];
        //struct graph *t = g;
        printf("\n Vertex %d : ", v);
        while (t->next)
        {
            printf("%d,%d -> ", t->to,t->weight);
            t = t->next;
        }
        printf("%d,%d\n", t->to,t->weight);
    }
}
void dijkstrall(struct graph *g,int n, int source){
    int i,j,max=0;
    int *visited=(int *)calloc(n,sizeof(int));
    int *distance=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        distance[i]=INF;
    } 
    distance[source]=0;
    for(i=0;i<n;i++){
        int uu=INF,u=-1;
        /* struct node *t = g->lists[i];
        while(t){
            if(uu>=distance[t->to]&&visited[t->to]==0){
                uu=distance[t->to];
                u=t->to;
            }
            t=t->next;
        } */
        for(j=0;j<n;j++){
            if(uu>=distance[j]&&visited[j]==0){
                uu=distance[j];
                u=j;
            }
        }
        visited[u]=1;
        struct node *t = g->lists[u];
        while(t){
            max+=t->weight;
            if(visited[t->to]==0){
                if(distance[t->to]>distance[u]+t->weight){
                    distance[t->to]=distance[u]+t->weight;
                }
            }
            t=t->next;
        }
    }
    for(i=0;i<n;i++){
        if(distance[i]>max)
            distance[i]=-1;
        printf("%d ",distance[i]);
    }
    printf("\n");
    
}
void dijkstrallsd(struct graph *g,int n, int source, int d){
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
        struct node *t = g->lists[u];
        while(t){
            max+=t->weight;
            if(visited[t->to]==0){
                if(distance[t->to]>distance[u]+t->weight){
                    distance[t->to]=distance[u]+t->weight;
                }
            }
            t=t->next;
        }
    }
    /* for(i=0;i<n;i++){
        if(distance[i]>max)
            distance[i]=-1;
        printf("%d ",distance[i]);
    }
    printf("\n"); */
    if(distance[d]>max){
        printf("-1\n");
    }else{
        printf("%d",distance[d]);
    }
    
}
void main(){
    struct graph* g=createGraph(5);
    //addEdge(struct graph *g, int from, int to, int isUndirected,int weight)
    addEdge(g,0,1,0,3);
    addEdge(g,1,2,0,2);
    addEdge(g,1,3,0,4);
    addEdge(g,2,4,0,5);
    addEdge(g,3,2,0,5);
    addEdge(g,4,3,0,2);
    print(g);
    dijkstrall(g,5,0);
    dijkstrall(g,5,1);
    dijkstrall(g,5,2);
    dijkstrall(g,5,3);
    dijkstrall(g,5,4);
    dijkstrallsd(g,5,3,4);
}