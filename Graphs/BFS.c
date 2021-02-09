#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct graph
{
    int noOfVertices;
    struct node **lists;
    int *visited;
};
struct node *createNode(int v)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct graph *createGraph(int vertices)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->noOfVertices = vertices;

    g->lists = (struct node **)malloc(vertices * sizeof(struct node *));
    g->visited = (int *)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        g->lists[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}
void addEdge(struct graph *g, int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = g->lists[src];
    g->lists[src] = newNode;
    newNode = createNode(src);
    newNode->next = g->lists[dest];
    g->lists[dest] = newNode;
}
struct Q
{
    int elements[1000];
    int front;
    int rear;
};
struct Q *createQ()
{
    struct Q *q = (struct Q *)malloc(sizeof(struct Q));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct Q *q)
{
    return q->rear == -1 ? 1 : 0;
}
void enQ(struct Q *q, int value)
{
    if (q->rear == 1000 - 1)
    {
        printf("\nQ full\n");
    }
    else
    {
        if (q->front == -1)
            ++q->front;
        q->elements[++q->rear] = value;
    }
}
int deQ(struct Q *q)
{
    int removed;
    if (isEmpty(q))
    {
        printf("Q is empty\n");
        removed = -1;
    }
    else
    {
        removed = q->elements[q->front++];
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return removed;
}
void printQ(struct Q *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (int i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->elements[i]);
        }
    }
    printf("\n");
}
void BFS(struct graph *g, int startVertex)
{
    struct Q *q = createQ();
    int visitingOrder[1000], i = 0;
    g->visited[startVertex] = 1;
    enQ(q, startVertex);
    while (!isEmpty(q))
    {
        printQ(q);
        int cur = deQ(q);
        visitingOrder[i++] = cur;
        visitingOrder[i] = -1;
        printf("Visited %d \n", cur);
        struct node *t = g->lists[cur];
        while (t)
        {
            int adjvertex = t->vertex;
            if (g->visited[adjvertex] == 0)
            {
                g->visited[adjvertex] = 1;
                enQ(q, adjvertex);
            }
            t = t->next;
        }
    }
}
void main()
{
    struct graph *graph = createGraph(10);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    BFS(graph, 0);
}