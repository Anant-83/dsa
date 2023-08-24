#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
int front = -1;
int rear = -1;
int cir_queue[size];
void insert(int n)
{
    if(front == 0 && rear == size - 1 || rear == front -1)
    {
        printf("\nQueue is full\n");
        return;
    }
    if(front == -1)
    {
      front = 0;
    }
    if(rear == size - 1)
    {
        rear = 0;
    }
    else
    {
      rear++;
    }
    cir_queue[rear] = n;
}
void delete()
{
    if(front == -1)
    {
        printf("\nQueue is empty\n");
    }
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == size-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void peek()
{
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nThe peek element is %d",cir_queue[front]);
}
void display()
{
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nElements of queue are :\n");
    if(front <= rear)
    {
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",cir_queue[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i=front; i<size; i++)
        {
            printf("%d ",cir_queue[i]);
        }
        for(int i=0; i<=rear; i++)
        {
            printf("%d ",cir_queue[i]);
        }
        printf("\n");
    }
}
int main(){
    while(1)
    {
        printf("\n -->enter your choise :\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Peek\n");
        printf("4) Display\n");
        int n;
        scanf("%d",&n);
        int k;
        switch(n)
        {
            case 1:
            printf("enter the element to insert :\n");
            scanf("%d",&k);
            insert(k);
            break;

            case 2:
            delete();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            default:
            return 0;
        }
    }
return 0;
}