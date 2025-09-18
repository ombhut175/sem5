#include <stdio.h>

#define N 4

struct Queue
{
    int front;
    int rear;
    int arr[N];
} q;

void enqueue(int n)
{
    if (q.rear >= N)
    {
        printf("Queue is full\n");
        return;
    }

    q.arr[q.rear++] = n;
}

int dequeue()
{
    if (q.front >= q.rear || q.front >= N)
    {
        return -1;
    }

    q.front++;

    return q.arr[q.front - 1];
}

int isQueueEmpty()
{
    if (q.front >= q.rear || q.front >= N)
        return 1;

    return 0;
}

void printQueue()
{
    for (int i = q.front; i < q.rear; i++)
    {
        printf("%d ", q.arr[i]);
    }
}

void bfs(int graph[N][N])
{
    int visited[N] = {0};
    enqueue(0);
    visited[0] = 1;

    while (!isQueueEmpty())
    {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < N; i++)
        {
            if (graph[currentNode][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void main()
{
    // int graph[N][N] = {
    //     {0, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 0},
    // };

    int graph[N][N] = {
        {0,0,1,0},
        {0,0,1,1},
        {1,1,0,1},
        {0,0,1,0},
    };

    bfs(graph);
}