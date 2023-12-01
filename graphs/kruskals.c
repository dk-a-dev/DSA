#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n;
int adj[MAX][MAX];
int parent[MAX];
int weight[MAX][MAX];

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

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

void union_ij(int i, int j)
{
    if (i < j)
        parent[i] = j;
    else
        parent[j] = i;
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
            if (ne == 1)
                printf("%d-%d:%d\n", a, b, min);
            else
            printf("%d-%d:%d\n", b, a, min);
            mincost = mincost + min;
            union_ij(u, v);
        }
        weight[a][b] = weight[b][a] = 999;
    }
}

int main()
{
    input_graph();
    printf("Edge:Weight\n");
    kruskal();
    return 0;
}