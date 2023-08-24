#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// method-1 find length , find ceil(length/2)s node
//method-2 two point approach --> find_middle function
//method-3 push address of node in stack and pop out till ceil(size/2)times
{
    int data;
    struct node *link;
};
struct node *first;
void create(int a[], int n)
{
    struct node *temp, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->link = NULL;
    last = first;
    for(int i=1; i<=n ;i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}
int find_middle(struct node *p)
{
    struct node *q = first;
    while(q != NULL)
    {
        q = q->link;
        if(q != NULL)
        {
            q = q->link;
        }
        if(q != NULL)
        {
            p = p->link;
        }
    }
    return p->data;
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
    int a[] = {2,1,3,7,8};
    create(a,5);
    // display(first);
    printf("The middle node's element is %d\n",find_middle(first));
    return 0;
}