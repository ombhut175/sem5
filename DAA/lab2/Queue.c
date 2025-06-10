#include <stdio.h>

#define SIZE 2

struct Queue
{
   int front;
   int rear;
   int arr[SIZE];
} q;

void enqueue(int n){
    if (q.rear >= SIZE)
    {
        printf("Queue is full\n");
        return;
    }
    
    q.arr[q.rear++] = n;
}

int dequeue(){
    if (q.front >= q.rear || q.front >= SIZE)
    {
        return -1;
    }

    q.front++;

    return q.arr[q.front-1];
}

void printQueue(){
    for(int i = q.front ; i < q.rear ; i++){
        printf("%d ",q.arr[i]);
    }
}

void main(){
    for (int i = 0; i < SIZE + 1; i++)
    {
        enqueue(5+i);
    }

    // printQueue();

    for (int i = 0; i < SIZE + 1; i++)
    {
        printf("%d ",dequeue());
    }
    
}