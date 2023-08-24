#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
};
struct node *root = NULL;
int nheight(struct node *p)
{
    int x,y;
    if(p)
    {
        x = nheight(p->lchild);
        y = nheight(p->rchild);
        if(x > y)
        return x+1;
        else
        return y+1;
    }
    return 0;
}
int balance_fact(struct node *p)
{
    int x,y;
    if(p)
    {
        x = nheight(p->lchild);
        y = nheight(p->rchild);
        return x-y;
    }
    return 0;
}
struct node* ll_rotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = nheight(p);
    pl->height = nheight(pl);
    if(root == p)
    {
        root = pl;
    }
    return pl;
}
struct node* lr_rotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = nheight(p);
    plr->height = nheight(plr);
    pl->height = nheight(pl);
    if(p == root)
    {
        root = plr;
    }
    return plr;
}
struct node* rr_rotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    pr->height = nheight(pr);
    p->height = nheight(p);
    if(p == root)
    {
        root = pr;
    }  
    return pr;
}
struct node* rl_rotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;
    p->height = nheight(p);
    pr->height = nheight(p);
    prl->height = nheight(p);
    if(root == p)
    {
        root = prl;
    }
    return prl;
}
struct node* rec_insert(struct node*p, int key)
{
    struct node *temp = NULL;
    if(p == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = key;
        temp->height = 1;
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
    // else
    // {
    //     printf("Duplicate value entered\n");
    //     return p;
    // }
    p->height = nheight(p);
    if(balance_fact(p) == 2 && balance_fact(p->lchild) == 1) // ll rotation
    {
        return ll_rotation(p);
    }
    else if(balance_fact(p) == 2 && balance_fact(p->lchild) == -1) // lr rotation
    {
        return lr_rotation(p);
    }
    else if(balance_fact(p) == -2 && balance_fact(p->rchild) == 1) // rl rotation
    {
        return rl_rotation(p);
    }
    else if(balance_fact(p) == -2 && balance_fact(p->rchild) == -1) // rr rotation
    {
        return rr_rotation(p);
    }
    return p;
}
struct node* in_succ(struct node *p)
{
    while(p->lchild && p)
    {
        p = p->lchild;
    }
    return p;
}
struct node* in_pred(struct node *p)
{
    while(p->rchild && p)
    {
        p = p->rchild;
    }
    return p;
}
struct node* delete(struct node *p,int key)
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
    else // key mdi jay tyare
    {
        if(nheight(p->lchild) > nheight(p->rchild))
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
    p->height = nheight(p);
    //printf("---> %d , %d\n",balance_fact(p),balance_fact(p->rchild));
    if(balance_fact(p) == 2 && balance_fact(p->lchild) == 1) // ll rotation
    {
        return ll_rotation(p);
    }
    else if(balance_fact(p) == 2 && balance_fact(p->lchild) == -1) // lr rotation
    {
        return lr_rotation(p);
    }
    else if(balance_fact(p) == -2 && balance_fact(p->rchild) == 1) // rl rotation
    {
        return rl_rotation(p);
    }
    else if(balance_fact(p) == -2 && balance_fact(p->rchild) == -1) // rr rotation
    {
        return rr_rotation(p);
    }
    else if(balance_fact(p) == -2 && balance_fact(p->rchild) == 0)
    {
        return rr_rotation(p);
    }
    else if(balance_fact(p) == 2 && balance_fact(p->rchild) == 0)
    {
        return ll_rotation(p);
    }
    return p;   
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
void inorder(struct node *p)
{
    if(p)
    {
        preorder(p->lchild);
        printf("%d\n",p->data);
        preorder(p->rchild);
    }
}
int main(){
    root = rec_insert(root,-10);
    rec_insert(root,-3);
   //rec_insert(root,15);
    // rec_insert(root,30);
    rec_insert(root,0);
    rec_insert(root,5);
    rec_insert(root,9);
    // rec_insert(root,5);
    preorder(root);
    inorder(root);
    // delete(root,5);
    // printf("\nnew:\n");
    // preorder(root);
return 0;
}