#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 9999

void input(int **graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        graph[i] = (int *)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

int minDistance(int dist[], int sptSet[], int size)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++)
    {
        if (sptSet[v] == 0 && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    printf("\n\nMin Value From Vertex:%d\n", min);
    printf("Vertex Number:%d\n", min_index+1);
    return min_index;
}

void printSolution(int dist[], int size)
{
    printf("From source vertex 5\n");
    for (int i = 0; i < size; i++)
    {
        printf("Distance of vertex %d:%d\n", i + 1, dist[i]);
    }
}

void dijkstra(int **graph, int src, int size)
{
    int *dist = (int *)malloc(size * sizeof(int));
    int *sptSet = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < size - 1; count++)
    {
        int flag = 0;
        int u = minDistance(dist, sptSet, size);
        for (int v = 0; v < size; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
            flag = 1;
        }
        sptSet[u] = 1;
        if (flag == 1)
        {
            for (int i = 0; i < size; i++)
            {
                printf("%d ", dist[i]);
            }
            printf("\n");
            for (int i = 0; i < size; i++)
            {
                printf("%d ", sptSet[i]);
            }
        }
    }
    printSolution(dist, size);
}

int main()
{
    int size;
    scanf("%d", &size);
    int **graph = (int **)malloc(size * sizeof(int *));
    input(graph, size);
    dijkstra(graph, 4, size);
    return 0;
}