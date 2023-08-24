#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;
int top = -1;
void stpush(struct node* st[],struct node *p)
{
    top++;
    st[top] = p;
}
struct node *pop(struct node* st[])
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
int search(struct node *p,int key)
{
    while(p)
    {
        if(p->data == key)
        {
            return 1;
        }
        else if(p->data < key)
        {
            p = p->rchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    return 0;
}
void insert(struct node *p,int key)
{
    struct node *temp,*ans;
    temp = NULL;
    while(p != NULL)
    {
        temp = p;
        if(key == p->data)
        {
            printf("Your value not inserted because of duplicay\n");
            return;
        }
        else if(key < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    ans = (struct node *)malloc(sizeof(struct node));
    ans ->data = key;
    ans->lchild = NULL;
    ans->rchild = NULL;
    if(ans->data < temp->data)
    {
        temp->lchild = ans;
    }
    else 
    {
        temp->rchild = ans;
    }
}
struct node* rec_insert(struct node*p, int key)
{
    struct node *temp;
    if(p == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = key;
        temp->lchild = NULL;
        temp->rchild = NULL;
        return temp;
    }
    if(key < p->data)
    {
        p->lchild = rec_insert(p->lchild,key);
    } 
    else if(key > p->data)
    {
        p->rchild = rec_insert(p->rchild, key);
    }
    else
    {
        printf("Duplicate value entered\n");
    }
    //// return p;
}
// // ->iterative delete :-
// struct node* it_delete(struct node *agad, int key)
// {
//     struct node *pachad;
//     pachad = NULL;
//     //agad = root;
//     while(agad != NULL)
//     {
//         if(agad->data == key)//important dhyan rakhvu avama
//         {
//             break;
//         }
//         pachad = agad;
//         if(key < agad->data)
//         {
//             agad = agad->lchild;
//         }
//         else
//         {
//             agad = agad->rchild;
//         }
//     }
//     if(agad == NULL)
//     {
//         printf("Key is not found in this tree\n");
//     }
//     else if(agad->lchild == NULL && agad->rchild == NULL)// no child
//     {
//         if(pachad == NULL)
//         {
//             root = NULL;
//         }
//         else if(agad == pachad->lchild)
//         {
//             pachad->lchild = NULL;
//         }
//         else
//         {
//             pachad->rchild = NULL;
//         }
//         free(agad);
//     }
//     else if(agad->lchild != NULL && agad->rchild == NULL)//only right child
//     {
//         if(pachad == NULL)
//         {
//             root = pachad;
//         }
//         pachad->lchild = agad->lchild;
//         free(agad);
//     }
//     else if(agad->lchild == NULL && agad->rchild != NULL)//only left child
//     {
//         if(pachad == NULL)
//         {
//             root = pachad;
//         }
//         pachad->rchild = agad->rchild;
//         free(agad);
//     }
//     else // both child
//     {
//         struct node *ans;
//         if(height(agad->lchild) > height(agad->rchild))
//         {
//             ans = in_succ(agad->rchild);
//             agad->data = ans->data;
//             // hve aano rigth ka to left child j bachyo hase to ene apde agad na if else ni jem delete kri devanu
//         }
//         else
//         {
//             ans = in_pred(agad->lchild);
//             agad->data = ans->data;
//         }
//     }
// }
int count(struct node *p)
{
    if(p)
    {
        return (count(p->lchild) + count(p->rchild) + 1);
    }
    return 0;
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
struct node* in_succ(struct node *p)
{
    while(p != NULL && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}
struct node* in_pred(struct node *p)
{
    while(p != NULL && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}
int height(struct node *p)
{
    if(p == NULL)
    return 0;
    int x = height(p->lchild);
    int y = height(p->rchild);
    if(x > y)
    return x+1;
    else
    return y+1;
}
// recursive :-
struct node* delete(struct node *p, int key)
{
    struct node *ans;
    if(p == NULL)
    {
        return NULL;
    }
    if(!p->lchild && !p->rchild)
    {
        if(p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(key < p->data)
    {
        p->lchild = delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild = delete(p->rchild,key);
    }
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            ans = in_succ(p->rchild);
            p->data = ans->data;
            p->rchild = delete(p->rchild,ans->data);
        }
        else
        {
            ans = in_pred(p->lchild);
            p->data = ans->data;
            p->lchild = delete(p->lchild,ans->data);
        }
    }
    return p;
}
void generate(int pre[], int n)
{
    struct node* stack[100];
    struct node *temp, *p;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = pre[0];
    root->lchild = NULL;
    root->rchild = NULL;
    p = root;
    int i = 1;
    while(i < n)
    {
        if(pre[i] < p->data)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = pre[i++];
            temp->lchild = NULL;
            temp->rchild = NULL;
            p->lchild = temp;
            stpush(stack,p);
            p = temp;
        }
        else
        {
            if((pre[i] > p->data && pre[i] < stack[top]->data) || top == -1)
            {
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = pre[i++];
                temp->lchild = NULL;
                temp->rchild = NULL;
                p->rchild = temp;
                p = temp;
            }
            else
            {
                p = pop(stack);
            }
        }
    }
}
void inorder(struct node*p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d\n",p->data);
        inorder(p->rchild);
    }
}
int main(){
    // root = rec_insert(root,50);
    // rec_insert(root,30);
    // rec_insert(root,83);
    // rec_insert(root,15);
    // rec_insert(root,40);
    // rec_insert(root,97); 
    //preorder(root);
    int pre[] = {50,20,10,25,60,55,80};
    generate(pre,7);
    inorder(root);
return 0;
}