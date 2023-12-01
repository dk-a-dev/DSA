// Find the minimal spanning of the following graph by applying Prim’s algorithm.
// Note: Read the number of vertices in the graph and the weight matrix of the graph from the user.
/*
weight matrix of the graph(9x9)=
0 4 0 0 0 0 7 0 0
4 0 9 0 0 0 11 20 0
0 9 0 6 2 0 0 0 0
0 0 6 0 10 5 0 0 0
0 0 2 10 0 15 0 1 5
0 0 0 5 15 0 0 0 12
7 11 0 0 0 0 0 1 0
0 20 0 0 1 0 1 0 3
0 0 0 0 5 12 0 3 0
*/
// Give output in following order and format
/*
Ouput:
Edge:Weight
0-1:4
4-2:2
2-3:6
7-4:1
3-5:5
0-6:7
6-7:1
7-8:3
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

int n;             // no of vertices
int adj[MAX][MAX]; // weight matrix
int predecessor[MAX];
int pathLength[MAX];
int status[MAX];

int min_temp()
{
    int i;
    int min = infinity;
    int k = NIL;
    for (i = 0; i < n; i++)
    {
        if (status[i] == TEMP && pathLength[i] < min)
        {
            min = pathLength[i];
            k = i;
        }
    }
    printf("\n", NULL);
    printf("\ncurrent: %d\n", k);
    return k;
}

void prim()
{
    int i, current;
    for (i = 0; i < n; i++)
    {
        predecessor[i] = NIL;
        pathLength[i] = infinity;
        status[i] = TEMP;
    }
    pathLength[0] = 0;
    while (1)
    {
        current = min_temp();
        int flag = 0;
        if (current == NIL)
            return;
        for (i = 0; i < n; i++)
        {
            if (adj[current][i] != 0 && status[i] == TEMP)
            {
                if (adj[current][i] < pathLength[i])
                {
                    predecessor[i] = current;
                    pathLength[i] = adj[current][i];
                }
                flag = 1;
            }
        }
        status[current] = PERM;
        if (flag == 1)
        {
            printf("predecessor[]: ", NULL);
            for (int i = 0; i < n; i++)
                printf("%d ", predecessor[i]);
            printf("\n", NULL);
            printf("pathLength[]: ", NULL);
            for (int i = 0; i < n; i++)
                printf("%d ", pathLength[i]);
            printf("\n", NULL);
            printf("status[]: ", NULL);
            for (int i = 0; i < n; i++)
                printf("%d ", status[i]);
        }
    }
}

int main()
{
    int total_cost = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    prim();
    printf("Edge:Weight\n", NULL);
    for (int i = 1; i < n; i++)
    {
        printf("%d-%d:%d\n", predecessor[i], i, adj[predecessor[i]][i]);
        total_cost += adj[predecessor[i]][i];
    }
    printf("Minimal Spanning Tree cost: %d\n", total_cost);
    return 0;
}