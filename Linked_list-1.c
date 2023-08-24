#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;// link to next node
};
int main(){
    struct node *head;
    head  = (struct node*)malloc(sizeof(struct node));
    head -> data = 21;
    head -> link = NULL;
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 45;
    current->link = NULL;
    head->link = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link->link = current;
    printf("1) %p\n",head->link);
    // method-1 and also memory westage
    // struct node*y = (struct node*)malloc(sizeof(struct node));
    // y->data = 20;
    // y->ptr = NULL;
    // x->ptr = y;
    // printf("----> %p\n",x->ptr);
    //method-2
    printf("2) %p\n",head->link->link);// address of third node
return 0;
}