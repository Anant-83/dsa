#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct listnode
{
    int data;
    struct listnode *link;
};
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **qu; 
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->qu = (struct node**)malloc(q->size*sizeof(struct node*));
}
void enqueue(struct queue *q, struct node *x)
{
    if((q->rear+1)%q->size == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->qu[q->rear] = x;
    }
}
struct node* dequeue(struct queue *q)
{
    struct node *x = NULL;
    if(q->front == q->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->qu[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    if(q.front == q.rear)
    {
        return 1;
    }
    return 0;
}
struct node *root = NULL;
void tree_create()
{
    struct node *p, *temp;
    int x;
    struct queue q;
    create(&q, 100);
    printf("Enter the root value :\n");
    scanf("%d",&x);
    root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(&q,root);
    while(!isempty(q))
    {
      p = dequeue(&q);
      printf("Enter the left child value of %d:\n",p->data);
      scanf("%d",&x);
      if(x != -1)
      {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->lchild = NULL;
        temp->rchild = NULL;
        p->lchild = temp;
        enqueue(&q,temp);
      }
      printf("Enter the right child value of %d :\n",p->data);
      scanf("%d",&x);
      if(x != -1)
      {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->lchild = NULL;
        temp->rchild = NULL;
        p->rchild = temp;
        enqueue(&q,temp);
      }
    }
}
struct listnode *first = NULL;
struct listnode *second = NULL;
void create1(int a[], int n)
{
    struct listnode *temp, *last;
    first = (struct listnode*)malloc(sizeof(struct listnode));
    first->data = a[0];
    first->link = NULL;
    last = first;
    for(int i=1; i<n; i++)
    {
        temp = (struct listnode*)malloc(sizeof(struct listnode));
        temp->data = a[i];
        temp->link = NULL;
        last->link = temp;
        last = temp;
    }
}
void create2(int a[], int n)
{
    struct listnode *temp, *last;
    second = (struct listnode*)malloc(sizeof(struct listnode));
    second->data = a[0];
    second->link = NULL;
    last = second;
    for(int i=1; i<n; i++)
    {
        temp = (struct listnode*)malloc(sizeof(struct listnode));
        temp->data = a[i];
        temp->link = NULL;
        last->link = temp;
        last = temp;
    }
}
struct node* generate(struct listnode*in, struct listnode*pre, int n)
{
    struct node *ans;
    struct listnode *p;
    if(n == 0)
    {
        return NULL;
    }
    ans = (struct node*)malloc(sizeof(struct node));
    ans->data = pre->data;
    ans->lchild = NULL;
    ans->rchild = NULL;
    p = in;
    if(n == 1)
    {
        return ans; 
    }
    int i;
    for(i=0; p->data != pre->data; i++)
    {
        p = p->link;
    }
    ans->lchild = generate(in,pre->link,i);
    for(int j=1; j <= i+1; j++)
    {
        pre = pre->link;
    }   
    ans->rchild = generate(p->link,pre,n-i-1);
    return ans;
}
void display(struct listnode*p)
{
    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->link;
    }
}
void preorder(struct node *p)
{
    if(p)
    {
        printf("%d\n",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main(){
    int pre[] = {4,7,9,6,3,2,5,8,1};
    int in[] = {7,6,9,3,4,5,8,2,1};
    create1(pre,9);
    create2(in,9);
    // display(first);
    //tree_create();
    preorder(second,first,9); 
    return 0;
}