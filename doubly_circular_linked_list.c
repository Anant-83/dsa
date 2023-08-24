#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node *prev;
    int data;
    struct node *link;
};
struct node *first = NULL;
void create(int arr[], int n)
{
    struct node *temp,*last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->prev = NULL;
    first->link = NULL;
    last = first;
    for(int i=1; i<n-1; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->prev = last;
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = arr[n-1];
    temp->link = first->prev;
    temp->prev = last;
    last->link = temp;
    last = temp;
}
void display(struct node *p)
{
    do
    {
        printf("%d ",p->data);
        p = p->link;
    } while (p != first);
    printf("\n");
}
int main(){
    int a[] = {24,2,6,43,8};
    create(a,5);
    display(first);
return 0;
}