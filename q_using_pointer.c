#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *qu; // array mate smjvu
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->qu = (int*)malloc(q->size*sizeof(int));
}
void enqueue(struct queue *q, int x)
{
    if(q->rear = q->size-1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear++;
        q->qu[q->rear] = x;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        q->front++;
        x = q->qu[q->front];
    }
    return x;
}
void display(struct queue q)
{
    for(int i=q.front + 1; i<=q.rear; i++)
    {
        printf("%d ",q.qu[i]);
    }
    printf("\n");
}
int main(){
    struct queue q;
    create(&q, 5);
    enqueue(&q,9);
    display(q);
return 0;
}