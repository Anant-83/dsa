#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node *prev; // stores prev. node's address
    int data;
    struct node *link; // stores next node's address
};
struct node *first;
void create(int arr[], int n)
{
    struct node *temp, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = arr[0];
    first->prev = NULL;
    first->link = NULL;
    last = first;
    for(int i=1; i<n; i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->link = last->link;
        temp->prev = last;
        last->link = temp;
        last = temp;
    }
}
int len(struct node *p)
{
    int cnt=0;
    while(p != NULL)
    {
        cnt++;
        p = p->link;
    }
    return cnt;
}
void insert(struct node *p, int pos, int n)
{
    struct node *q,*temp;
    if(pos < 0 || pos > len(first))
    {
        printf("INVALID POSITION\n");
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    if(pos == 0)
    {
        temp->prev = NULL;
        temp->link = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        for(int i=1 ; i<= pos-1 ; i++)
        {
            p = p->link;
        }
        temp->link = p->link;
        temp->prev = p;
        if(p->link != NULL)
        {
            p->link->prev = temp;
        }
        p->link = temp;
    }
}
void delete(struct node *p, int pos)
{
    if(pos < 1 || pos > len(p))
    {
        printf("INVALID POSITION\n");
        return;
    }
    struct node *temp, *q;
    if(pos ==  1)
    {
        p =  first;
        first = first->link;
        if (first != NULL)
        {
            first->prev = NULL;
        }
        free(p);
    }
    else
    {
        for(int i=1 ; i<= (pos-1); i++)
        {
            p = p->link;
        }
        p->prev->link = p->link;
        if(p->link != NULL)
        {
          p->link->prev = p->prev;
        }
        free(p);
    }
}
void reverce(struct node *p)
{
    struct node *temp;
    while(p != NULL)
    {
        temp = p->link;
        p->link = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->link == NULL) // p != NULL e umervu pde bcause chelle e list ni bahar jtu re etle
        {
            first = p;
        }
    }
}
void display(struct node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->link;
    }
    printf("\n");
}
int main(){
    int a[] = {1,2,3,4};
    create(a,4);
    // delete(first,3);
    reverce(first);
    display(first);
return 0;
}