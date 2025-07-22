#include <stdio.h>
#include <limits.h>

#define V 3

void main()
{
    int graph[V][V] = {
        {0, 2, 3},
        {2, 0, 4},
        {3, 4, 0}};

    int visited[V] = {0,0,0};

    visited[0] = 1;

    int edges = 0;

    int x,y;

    int cost = 0;
    while (edges < V - 1)
    {
        int min = INT_MIN;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                continue;

            for (int j = 0; j < V; j++)
            {
                if (visited[j] && !graph[i][j]) continue;

                int currentEdge = graph[i][j];
                if (currentEdge < min)
                {   
                    min = currentEdge;
                    x = i;
                    y = j;
                }   
            }
        }

        visited[y] = 1;
        printf("Minimum edge for %d is %d\n", x, min);
        cost += graph[x][y];
        edges++;
    }

    printf("total cost is %d",cost);
}