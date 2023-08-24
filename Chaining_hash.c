#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *link;
};
struct node *search(struct node *p, int key)
{
    while(p)
    {
        if(p->data == key)
        {
            return p;
        }
        p = p->link;
    }
    return NULL;
}
void sort_insert(struct node **h, int x)
{
    struct node *temp, *q = NULL, *p = *h;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    if(*h == NULL)
    {
        *h = temp;
    }
    else
    {
        while(p && p->data < x)
        {
            q  = p;
            p = p->link;
        }
        if(p == *h) // at first position
        {
            p->link = *h;
            *h = p;
        }
        else
        {
            temp->link = q->link;
            q->link = temp;
        }
    }
}
void insert(struct node *h[], int key)
{
    sort_insert(&h[key%10],key);
}
int main(){
    struct node* ht[10];
    for(int i=0; i<10; i++)
    {
        ht[i] = NULL;
    }
    insert(ht,12);
    insert(ht,22);
    insert(ht,42);
    struct node *temp = search(ht[22%10],22);
    if(temp)
    printf("%d\n",temp->data);
    else
    printf("Key not found\n");
return 0;
}