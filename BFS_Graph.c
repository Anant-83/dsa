#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
int queue[size];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if(rear == size-1)
    {
        printf("Queue is full\n");
        return;
    }
    if(front == -1)
    front = 0;
    rear++;
    queue[rear] = x;
}
int dequeue()
{
    if(front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    return queue[front++];
}
int isempty()
{
    if(front > rear)
    {
        return 1;
    }
    return 0;
}
void bfs(int g[][7],int start, int n)
{
    int i = start;
    int visited[7] = {0};
    printf("%d\n",i);
    visited[i] = 1;
    enqueue(i);
    while(!isempty())
    {
        i = dequeue();
        for(int j=1; j<n; j++)
        {
            if(g[i][j] == 1 && visited[j] == 0)
            {
                printf("%d\n",j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
int main(){ 
    int graph[7][7] = {{0,0,0,0,0,0,0},
                       {0,0,1,1,0,0,0},
                       {0,1,0,0,1,0,0},
                       {0,1,0,0,1,0,0},
                       {0,0,1,1,0,1,1},
                       {0,0,0,0,1,0,0},
                       {0,0,0,0,1,0,0}};
    bfs(graph,1,7);
return 0;
}