#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *link;
};
struct node *first = NULL;
void create(int arr[], int n)
{
    struct node *temp, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = arr[0];
    first->link = NULL;
    last = first;
    for(int i=1; i<n-1; i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->link = NULL;// temp->link = NULL pn chale ek j kevay
        last->link = temp;
        last = temp;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = arr[n-1];
    temp->link = first;
    last->link = temp;
    last = temp;
}
int length(struct node*p)
{
    int cnt=0;
    do
    {
        cnt++;
        p = p->link;
    } while (p!=first);
    return cnt;
}
void delete(struct node *p, int pos)
{
    struct node *q,*temp;
    if(pos == 0)
    {
        while (p->link != first)
        {
            p = p->link;
        }
        if(p == first)
        {
            free(first);
            first = NULL;
        }
        else
        {
          p->link = first->link;
          free(first);
          first = p->link;
        }
    }
    else
    {
      for(int i=1; i <= pos-1; i++)
      {
          p = p->link;
      }
      q = p->link;
      p->link = q->link;
      free(q);
    }
}
void display(struct node *p)
{
    do
    {
        printf("%d\n",p->data);
        p = p->link;
    } while (p != first);
}
void insert(struct node*p, int pos, int n)
{
    if(pos < 0 || pos > length(first))
    {
        printf("INVALID POSITION\n");
        return;
    }
    struct node *temp;
    if(pos == 1)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        if(first == NULL)
        {
            first = temp;
            first->link = first;
        }
        else
        {
          while(p->link != first)
          {
              p = p->link;
          }
          p->link = temp;
          temp->link = first;
          first = temp;
        }
    }
    else
    {
      for(int i=0; i< pos-1; i++)
      {
          p = p->link;
      }
      temp = (struct node*)malloc(sizeof(struct node));
      temp->data = n;
      temp->link = p->link;
      p->link = temp;
    }
}
void recursive_display(struct node *p)
{
    static int flag = 0;
    if(p != first || flag == 0)
    {
        flag = 1;
        printf("%d\n",p->data);
        recursive_display(p->link);
    }
}

int main(){
    int a[] = {2,7,3,4,55};
    create(a,5);
    insert(first,0,8);
    display(first);
    printf("\n------\n");
    delete(first,4);
    display(first);
return 0;
}