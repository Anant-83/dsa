#include<stdio.h>
#include<stdlib.h>
#define size 10
int dequeue[size];
int front = -1;
int rear = -1;





void insert_front_end(int n)
{
    if(rear == front-1 || front == 0 && rear == size-1)
    {
        printf("\nDeque is full\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
    {
        front = size - 1;
    }
    else
    {
        front--;
    }
    dequeue[front] = n;
}
void insert_rear_end(int n)
{
    if(rear == front-1 || front == 0 && rear == size-1)
    {
        printf("\nDeque is full\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == size-1)
    {
        rear = 0;
    } 
    else
    {
        rear++;
    }
    dequeue[rear] = n;
}
void delete_front()
{
    if(front == -1)
    {
        printf("\nDeque is empty\n");
        return;
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
void delete_rear()
{
    if(front == -1)
    {
        printf("\nDeque is empty\n");
        return;
    }
    if(front == rear)
    {
        rear = -1;
        front = -1;
    }
    else if(rear == 0)
    {
        rear = size-1;
    }
    else
    {
        rear--;
    }
}
void display()
{
    printf("\nElements of deque are :- \n");
    if(front <= rear)
    {
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",dequeue[i]);
        }
    }
    else
    {
        for(int i=front ; i<size ; i++)
        {
            printf("%d ",dequeue[i]);
        }
        for(int i=0; i<=rear ; i++)
        {
            printf("%d ",dequeue[i]);
        }
    }
    printf("\n");
}
int main(){
    while(1)
    {
        int ch;
        printf("\nEnter your choice :- \n");
        printf("1) Insert at front end\n");
        printf("2) Insert at rear end\n");
        printf("3) Delete from front end\n");
        printf("4) Delete from rear end\n");
        printf("5) Display elements\n");
        scanf("%d",&ch);
        int f,r;
        switch(ch)
        {
            case 1:
            printf("\nEnter the number for insert at front end :- ");
            scanf("%d",&f);
            insert_front_end(f);
            break;

            case 2:
            printf("\nEnter the number for insert at rear end :- ");
            scanf("%d",&r);
            insert_rear_end(r);
            break;

            case 3:
            delete_front();
            break;

            case 4:
            delete_rear();
            break;

            case 5:
            display();
            break;

            default:
            break;
        }
    }
return 0;
}