#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *link;
};
struct node *first = NULL,*second = NULL, *third = NULL;
void create(int a[], int n)
{
    struct node *temp, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = a[0];
    first->link = NULL;
    last = first;
    for(int i=1; i<n; i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->link = NULL;
        last->link = temp;
        last = temp;
    }
}
void insert(struct node*p, int pos, int n)
{
    struct node *temp; 
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    if(pos == 0)
    {
        temp->link = third;
        third = temp;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
}
void create2(int a[], int n)
{
    struct node *temp, *last;
    second = (struct node*)malloc(sizeof(struct node));
    second->data = a[0];
    second->link = NULL;
    last = second;
    for(int i=1; i<n; i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->link = NULL;
        last->link = temp;
        last = temp;
    }
}
int count(struct node *p)
{
    int cnt=0;
    while(p != NULL)
    {
        cnt++;
        p = p->link;
    }
    return cnt;
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
struct node* max(struct node *p, struct node *q)
{
    if(count(p) > count(q))
    return p;
    else
    return q;
}
void sum(struct node *p, struct node *q)
{
    int i=0,x=0,s=0;
    int carry = 0,a,b;
    int f1=1,f2=1;
    while(max(p,q) != NULL)
    { 
        if(f1)
        {
            a = p->data;
        }
        if(f2)
        {
            b = q->data;
        }
        else if(f1 == 0)
        {
            a = 0;
        }
        else if(f2 == 0)
        {
            b = 0;
        }
        s = a + b + x;
        //printf("%d ",s);
        x = s/10;
        insert(third,i,s%10);
        i++;
        if(f1)
        {
          p = p->link;
        }
        if(f2)
        {
          q = q->link;
        }
        if(p == NULL)
        {
            f1 = 0;
        } 
        if(q == NULL)
        {
            f2 = 0;
        } 
    }
    if(x != 0)
    {
        insert(third,i,x);
    }
}
int main(){
    int a[] = {9,9,9,9,9,9,9};
    int b[] = {9,9,9,9};
    create(a,7);
    create2(b,4);
    // display(first);
    // display(second);
    sum(first,second);
    display(third);
return 0;
}