#include <stdio.h>

#define N 4

void dfsUtil(int graph[N][N], int visited[N], int currentNode)
{
    visited[currentNode] = 1;
    printf("%d ", currentNode);
    for (int i = 0; i < N; i++)
    {
        if (graph[currentNode][i] == 1 && visited[i] == 0)
        {
            dfsUtil(graph, visited, i);
        }
    }
}

void dfs(int graph[N][N])
{
    int visited[N] = {0};
    dfsUtil(graph, visited, 0);
}

void main()
{
    int graph[N][N] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0},
    };

    dfs(graph);
}