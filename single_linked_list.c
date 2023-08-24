#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
// jyare pn first = temp ke evu kai kriye etle fisrt ne temp ma move kryu kehvay
struct node* first = NULL; // create global first(head) pointer
struct node* second = NULL;
struct node* third = NULL;
void create(int a[], int n)
{
    struct node *temp,*last;
    first = (struct node*) malloc(sizeof(struct node));
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
struct node* search(struct node*p ,int k)
{
    struct node*temp;
    while(p != NULL)
    {
        if(p->data == k)
        {
            temp->link = p->link;
            p->link = first;
            first = p;
            return p;
        }
        temp = p;
        p = p->link;
    }
    return NULL;
}
void display(struct node*ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
}
int max(struct node*p)
{
    int mx = INT_MIN;
    while(p != NULL)
    {
        if(p->data > mx)
        {
            mx = p->data;
        }
        p = p->link;
    }
    return mx;
}
int sum(struct node*p)
{
    int sum=0;
    while(p != NULL)
    {
        sum += p->data;
        p = p->link;
    }
    return sum;
}
int count(struct node*p)
{
    int cnt= 0;
    while(p != NULL)
    {
        cnt++;
        p = p->link;
    }
    return cnt;
}
// -> by this insert function we can create linked list
// by calling (first,0,1) , ............
void insert2(struct node *ptr, int position, int n)
{
    struct node *temp;
    if(position < 0 || position > count(ptr))
    {
        printf("NOT A VALID POSITION\n");
        return;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    if(position == 0)
    {
        temp->link = second;
        second = temp;
    }
    else
    {
        for(int i=0; i<position-1; i++)
        {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
void insert(struct node *ptr, int position, int n)
{
    struct node *temp;
    if(position < 0 || position > count(ptr))
    {
        printf("NOT A VALID POSITION\n");
        return;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    if(position == 0)
    {
        temp->link = first;
        first = temp;
    }
    else
    {
        for(int i=0; i<position-1; i++)
        {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
void insert_in_sorted_list(int n)
{
    struct node *temp,*p,*q;
    p = first;// q ae p ni pachad bhage che
    q = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->link = NULL; // jrur nthi but jo e last node hoy ena mate
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
      while(p != NULL && p->data < n)
      {
          q = p;
          p = p->link;
      }
      temp->data = n;
      if(p == first)
      {
          temp->link = first;
          first = temp;
      }
      else
      {
        temp->link = q->link;
        q->link = temp;
      }
    }
}
void delete_node(int index)
{
    if(index <= 0 || index > count(first))
    {
        printf("INVALID INDEX\n");
        return;
    }
    struct node *p,*q;
    p = first;
    q = NULL;
    // delete the first node:-
    if(index == 1)
    {
       q = first;
       first = first->link;
    }
    for(int i=1; i<=index-1 && p != NULL; i++)
    {
        q = p;
        p = p->link;
    }
    q->link = p->link;
    free(p);// now we can delete p;
}
void is_sorted(struct node *p)
{
    int x = INT_MIN;
    int f = 1;
    while(p != NULL)
    {
        if(p->data > x)
        {
            x = p->data;
        }
        else
        {
            f = 0;
            break;
        }
         p = p->link;
    }
    if(f)
    {
        printf("List is sorted\n");
    }
    else
    {
        printf("List is not sorted\n");
    }
}
void remove_duplicate(struct node *p)
{
    struct node *q;
    q = p->link;
    while(q != NULL)
    {
        // if(p->data != q->data)
        // {
        //     p = q;
        //     q = q->link;
        // }
        // else
        // {
        //     p->link = q->link;
        //     q = p->link;
        // }
        if(p->data == q->data)
        {
            p->link = q->link;
            q = p->link;
        }
        else
        {
            p = p->link;
            q = q->link;
        }
    }
}
// Reverce linked list two methods :
// 1)using extra array(reverce elements)
// 2)reverce links(1 krta sari method)
void reverce_element(struct node *p)//<-- method-1
{
    int arr[count(first)];
    int i=0;
    while(p != NULL)
    {
        arr[i] = p->data;
        p = p->link;
        i++;
    }
    i--;
    p = first;
    while(p != NULL)
    {
        p->data = arr[i];
        i--;
        p = p->link;
    }
}
void reverce_links(struct node *p)//<-- method-2,called as three sliding pointers
{
    struct node *q,*r;
    q = NULL;
    r = NULL;
    while(p != NULL)
    { 
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;//for last node to make it first 
}
void recursive_reverce(struct node*q, struct node* p)
{
    if(p != NULL)
    {
        recursive_reverce(p,p->link);
        p->link = q;
    }
    else
    {
        first = q;
    }
}
void merge_two_sorted_list(struct node* p, struct node *q)
{
    struct node *last;
    if(p->data < q->data)
    {
        third = p;
        last = p;
        p = p->link;
        third->link = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->link;
        third->link = NULL;
    }
    while(p != NULL && q != NULL)
    {
        if(p->data < q->data)
        {
            last->link = p;
            last = p;
            p = p->link;
            last->link = NULL;
        }
        else
        {
            last->link = q;
            last = q;
            q = q->link;
            last->link = NULL;
        }
    }
    if(p != NULL)
    {
        last->link = p;
    }
    else
    {
        last->link = q;
    }
}
// ->list-loop etle list ma ek node teni agad na node ni jgya e bija koi node ne point kre
int isloop(struct node *ptr)
{
    struct node *p,*q;
    p = ptr; q = ptr;
    while(p != NULL && q != NULL)
    {
        p = p->link;
        q = q->link;
        if(q)
        {
            q = q->link;
        }
        if(p == q)
        return 1;
    }
    return 0;
}
struct node* recursive_search(struct node*p, int k)
{
    if(p == NULL)
    {
        return NULL;
    }
    if(k == p->data)
    return p;

    return recursive_search(p->link,k);
}
int recursive_max(struct node*p)
{
    int mx = INT_MIN;
    if(p == NULL)
    {
        return mx;
    }
    int x = recursive_max(p->link);
    if(x > p->data)
    return x;

    return p->data;
}
int recursive_sum(struct node*p)
{
    if(p == NULL)
    {
        return 0;
    }
    return recursive_sum(p->link)+p->data;
}
int recursive_count(struct node*p)
{
    if(p == NULL)
    return 0;

    return recursive_count(p->link)+1;
}
void recursive_display(struct node*ptr)
{
    if(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        recursive_display(ptr->link);
    }
}
int main(){
    int arr[] = {1,5,9,15,44};
    create(arr,5);
    // struct node *p,*q;
    // p = first->link->link;
    // q = first->link->link->link->link;
    // q->link = p;
    printf("%d",isloop(first));
    // printf("%d %d",p->data,q->data);
return 0;
}