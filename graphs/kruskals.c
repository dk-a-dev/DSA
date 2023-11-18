// Kruskals Algorithm
// Find minimal spanning of the following graph by applying Kruskal’s algorithm

// Weight matrix of the graph(6x6)=
/*
0 2 0 1 4 0
2 0 3 3 0 7
0 3 0 5 0 8
1 3 5 0 9 0
4 0 0 9 0 0
0 7 8 0 0 0
*/

// Give output in following order and format
/*
Edge:Weight
1-4:1
2-1:2
3-2:3
5-1:4
6-2:7
*/

// Kruskals Algorithm
// Write algo properly

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TEMP 0

int n;
int adj[MAX][MAX];
int status[MAX];
int parent[MAX];
int weight[MAX][MAX];

void input_graph();
void kruskal();
void make_tree(int, int);
int find(int);
void union_ij(int, int);

int main()
{
    input_graph();
    printf("Edge:Weight\n");
    kruskal();
    return 0;
}

void input_graph()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void kruskal()
{
    int i, j, a, b, u, v, min;
    int ne = 0, mincost = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (adj[i][j] == 0)
            {
                weight[i][j] = 999;
            }
            else
            {
                weight[i][j] = adj[i][j];
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }
    while (ne < n - 1)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (weight[i][j] < min)
                {
                    min = weight[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (u != v)
        {
            ne = ne + 1;
            printf("%d-%d:%d\n", b, a, min);
            mincost = mincost + min;
            union_ij(u, v);
        }
        weight[a][b] = weight[b][a] = 999;
    }
}

void make_tree(int i, int j)
{
    adj[i][j] = adj[j][i] = 1;
}

int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}

void union_ij(int i, int j)
{
    if (i < j)
    {
        parent[i] = j;
    }
    else
    {
        parent[j] = i;
    }
}
