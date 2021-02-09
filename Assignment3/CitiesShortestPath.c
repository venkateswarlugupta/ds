#define INF 987654
#include<stdio.h>
#include<stdlib.h>
struct node{
    int to;
    int weight;
    struct node *next;
};
struct graph{
    int noOfVertices;
    struct node **lists;
};
struct node *createNode(int t,int w){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->to = t;
    new->weight=w;
    new->next = NULL;
    return new;
}
struct graph *createGraph(int vertices){
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->noOfVertices = vertices;
    g->lists = (struct node **)malloc(sizeof(struct node *) * vertices);
    while (vertices > 0){
        g->lists[--vertices] = NULL;
    }
    return g;
}
void addEdgeForward(struct graph *g, int from, int to,int w){
    struct node *new = createNode(to,w);
    new->next = g->lists[from];
    g->lists[from] = new;
}
void addEdgeBackward(struct graph *g, int from, int to,int w){
    struct node *new = createNode(from, w);
    new->next = g->lists[to];
    g->lists[to] = new;
}
void addEdge(struct graph *g, int from, int to, int isUndirected,int w){
    addEdgeForward(g, from, to,w);
    if (isUndirected){
        addEdgeBackward(g, from, to,w);
    }
}
void print(struct graph *g)                                 {
    for (int v = 0; v < g->noOfVertices; v++)               {
        struct node *t = g->lists[v]                        ;
        printf("\n Vertex %d : ", v)                        ;
        while (t)                                           {
            printf("%d,%d -> ", t->to,t->weight)            ;
        t = t->next                                         ;
                                                            }
                                                            }
                                                            }
void dijkstrallsd(struct graph *g,int n, int source, int d) {
    //this function is dijkstra using List Source Destination
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
    if(distance[d]>max){
        printf("-1\n");
    }else{
        printf("%d\n",distance[d]);
    }
}
void main(){
    int i,n,m,q,u,v,w,s,d;
    FILE *fp;
    fp=fopen("graphInput.txt","r");
    fscanf(fp,"%d %d %d",&n,&m,&q);
    struct graph* g=createGraph(n);
    //function signature
    //addEdge(struct graph *g, int from, int to, int isUndirected,int weight)
    for(i=0;i<m;i++){
        fscanf(fp,"%d %d %d",&u,&v,&w);
        addEdge(g,u-1,v-1,0,w);
    }
    //print(g);
    while(q){
        fscanf(fp,"%d%d",&s,&d);
        dijkstrallsd(g,n,s-1,d-1);
        q--;
    }
}


/* #define INF 987654
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
void addEdge(struct graph *g, int from, int to, int w)
{
    struct node *new = createNode(to, w);
    new->next = g->lists[from];
    g->lists[from] = new;
}
void print(struct graph *g)
{
    for (int v = 0; v < g->noOfVertices; v++)
    {
        struct node *t = g->lists[v];
        printf("\n Vertex %d : ", v);
        //while (t->next)
        while (t)
        {
            printf("%d -> ", t->to);
            t = t->next;
        }
 //       if(t!=NULL)
   //         printf("%d", t->to);
    }
}
void dijkstrall(struct graph *g,int n, int source,int destination){
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
    for(i=0;i<n;i++){
        if(distance[i]>max)
            distance[i]=-1;
        printf("%d ",distance[i]);
    }
    printf("\n"); 
    if(distance[destination]>max){
        printf("-1\n");
    }else{
    printf("%d\n",distance[destination]);
    }
}
int main(){
    int i,n,m,q,u,v,w,s,d;
    FILE *fp;
    fp=fopen("graphInput.txt","r");
    fscanf(fp,"%d %d %d",&n,&m,&q);
    struct graph* g=createGraph(n);
    for(i=0;i<m;i++){
        fscanf(fp,"%d %d %d",&u,&v,&w);
        printf("%d %d %d\n",u,v,w);
        addEdge(g,u-1,v-1,w);
    }
    print(g);
    while(q){
        fscanf(fp,"%d%d",&s,&d);
        dijkstrall(g,n,s-1,d-1);
        q--;
    }
} */