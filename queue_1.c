#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front = -1;
int back = -1;
void enqueue()
{
    if(back == size - 1)
    {
        printf("queue is full\n");
        return;
    }
    int x;
    printf("enter the number to insert :\n");
    scanf("%d",&x);
    front = 0;
    back++;
    queue[back] = x;
}
void dequeue()
{
    if(front > back)
    {
        printf("queue is empty\n");
        return ;
    }
    front++;
}
void peek()
{
    if(front > back)
    {
        printf("queue is empty\n");
        return ;
    }
    printf("the peek element is %d\n", queue[front]);
}
void rear()
{
    if(front > back)
    {
        printf("queue is empty\n");
        return ;
    }
    printf("the back element is %d\n",queue[back]);
}
void display()
{
  for(int i=front; i<=back; i++)
  {
    printf("%d ",queue[i]);
  }
  printf("\n");
}
int main(){
    while(1)
    {
      printf("enter your choice :\n");
      printf("(1) Dequeue\n");
      printf("(2) Enqueue\n");
      printf("(3) Peek\n");
      printf("(4) Rear\n");
      printf("(5) Display\n");
      int n;
      scanf("%d",&n);
      switch (n)
      {
      case 1:
        dequeue();
        break;
      case 2:
        enqueue();
        break;
      case 3:
        peek();
        break;
      case 4:
        rear();
        break;
        case 5:
        display();
        break;
      default:
        return 0;
      }
    }
return 0;
}