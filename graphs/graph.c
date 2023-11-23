#include <stdio.h>
#include <stdlib.h>

void input(int **graph, int vertices)
{
    for (int i = 0; i < vertices; i++)
        graph[i] = (int *)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);
}

void enqueue(int *queue, int *rear, int data)
{
    queue[(*rear)++] = data;
}

int dequeue(int *queue, int *front)
{
    return (*front)++;
}

isQueueEmpty(int *queue, int *front, int *rear)
{
    return (*front) == (*rear);
}

void bfs(int **graph, int vertices, int start)
{
    int *visited=(int*)calloc(vertices,sizeof(int));
    int *queue=(int*)calloc(vertices,sizeof(int));
    int front=0, rear=0;
    enqueue(queue,&rear,start);
    visited[start]=1;
    while(!isQueueEmpty(queue,&front,&rear))
    {
        int node=dequeue(queue,&front);
        for(int i=0;i<vertices;i++)
        {
            if(graph[node][i]==1 && visited[i]==0)
            {
                enqueue(queue,&rear,i);
                visited[i]=i+1;
            }
        }
    }
    for(int i=0;i<vertices;i++)
        if(i==vertices-1)
            printf("%d",queue[i]+1);
        else
            printf("%d->",queue[i]+1);
}

void push(int *stack, int *top, int data)
{
    stack[++(*top)]=data;
}

int pop(int *stack, int *top)
{
    return stack[(*top)--];
}

int isEmpty(int *stack, int *top)
{
    return (*top)==-1;
}

int isFull(int *stack, int *top, int vertices)
{
    return (*top)==vertices-1;
}

void dfs(int **graph, int vertices, int start)
{
    int *visited=(int*)calloc(vertices,sizeof(int));
    int *stack=(int*)calloc(vertices,sizeof(int));
    int *temp=(int*)calloc(vertices,sizeof(int));
    int index=0;
    int top=-1;
    push(stack,&top,start);
    visited[start]=1;
    while(!isEmpty(stack,&top))
    {
        int node=pop(stack,&top);
        temp[index++]=node+1;
        for(int i=0;i<vertices;i++)
        {
            if(graph[node][i]==1 && visited[i]==0)
            {
                push(stack,&top,i);
                visited[i]=i+1;
            }
        }
    }
    for(int i=0;i<vertices;i++)
        if(i==vertices-1)
            printf("%d",temp[i]);
        else
            printf("%d->",temp[i]);
}

int main(int argc, char const *argv[])
{
    int vertices;
    scanf("%d", &vertices);
    int **graph = (int **)malloc(vertices * sizeof(int *));
    input(graph, vertices);
    bfs(graph, vertices, 0);
    printf("\n");
    dfs(graph, vertices, 0);
    return 0;
}
