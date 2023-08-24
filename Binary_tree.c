#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
int top = -1;
void stpush(struct node *st[],struct node *p)
{
    top++;
    st[top] = p;
}
struct node *pop(struct node *st[])
{
    if(top != -1)
    {
      return st[top--];
    }
    else
    printf("stack is empty\n");
}
int stempty()
{
    if(top == -1)
    return 1;

    return 0;
}
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
    root = (struct node *)malloc(sizeof(struct node));
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
void preorder(struct node *p)
{
    //printf("\nPreorder :- \n"); // a recursion kevi rite kam kre e check krvu hoy to
    if(p != NULL)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void it_preorder(struct node *p)
{
    if(p == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    struct node *stack[100];
    while(!stempty() || p != NULL)
    {
        if(p != NULL)
        {
            printf("%d\n",p->data);
            stpush(stack,p);
            p = p->lchild;
        }
        else
        {
            p = pop(stack);
            p = p->rchild;
        }
    }
}
void it_inorder(struct node *p)
{
    struct node *stack[100];
    if(p == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while(!stempty() || p != NULL)
    {
        if(p != NULL)
        {
            stpush(stack,p);
            p = p->lchild;
        }
        else
        {
            p = pop(stack);
            printf("%d\n",p->data);
            p = p->rchild;
        }
    }
}
// using one stack :-
void it_postorder(struct node *p)
{
    //-> trace krvu hoy to nicheni lines ne comment out kri code run krvo
    int o = 0;
    struct node *stack[100];
    struct node *temp;
    if(p == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    temp = root;
    while(1)
    {
        while(p->lchild != NULL)
        {
            stpush(stack,p);
            p = p->lchild;
        }
        while(p->rchild == NULL || p->rchild== temp)
        {
            printf("%d\n",p->data);
            temp = p;
            if(stempty())
            {
                return;
            }
            p = pop(stack);
           printf("--> %d %d\n",o,p->data);
           o++;
        }
       printf("\n=>%d\n",p->data);
        stpush(stack,p);
        p = p->rchild;
       printf("\n----->%d\n",p->data);
    }
}
// using two stack :-
// void it_poatorder2(struct node *p)
// {
//     struct node *stack1[100]; //for nodes
//     struct node *stack2[100]; //for lchild and rchild of nodes
//     stpush(stack1,p);
//     while(!stempty())
//     {
//         struct node *tmp = pop(stack1);
//         stpush(stack2,tmp);
//         if(tmp->lchild)
//         {
//             stpush(stack1,tmp->lchild);
//         }
//         if(tmp->rchild)
//         {
//             stpush(stack1,tmp->rchild);
//         }
//     }
//     while(!isempty())
//     {
//         int x = pop(stack2);
//         printf("%d",x);
//     }
// }
void it_levelorder(struct node *p)
{
    struct queue q;
    create(&q, 100);
    enqueue(&q,p);
    while(!isempty(q))
    {
        p = dequeue(&q);
        if(p->lchild)
        {
            printf("%d\n",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d\n",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}
int count(struct node *p)
{
    if(p)
    {
        return (count(p->lchild) + count(p->rchild) + 1);
    }
    return 0;
}
int height(struct node *p)
{
    if(p != NULL)
    {
        int x = height(p->lchild);
        int y = height(p->rchild);
        if(x > y)
        return x+1;

        return y+1;
    }
    else
    return 0;
}
int main(){
    tree_create();
    //preorder(root);
    //inorder(root);
    //postorder(root);
    //it_inorder(root);
    it_postorder(root);
    // printf("Number of node in this tree is %d\n",count(root));
    // printf("The height of this tree is %d\n",height(root));
   // it_levelorder(root);
return 0;
}
//Leetcode Accepted delete :-
/*
struct TreeNode* succ(struct TreeNode* root)
{
    struct TreeNode *q = root;
    while(q->left && q)
    {
        q = q->left;
    }
    return q;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    struct TreeNode* ans;
    if(root == NULL)
    {
        return NULL;
    }
    if(key < root->val)
    {
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->val)
    {
        root->right = deleteNode(root->right,key);
    }
    else
    {
        if(root->left == NULL)
        {
            ans = root->right;
            free(root);
            return ans;
        }
        else if(root->right == NULL)
        {
            ans = root->left;
            free(root);
            return ans;
        }
        ans = succ(root->right);
        root->val = ans->val;
        root->right = deleteNode(root->right,ans->val);
    }
    return root;
}*/