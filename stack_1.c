#include<stdio.h>
#include<stdlib.h>
#define size 10
int top = -1;
int stack[size];
void push(int a)
{
    if(top == size-1)
    {
        printf("stack overflow\n");
        return ;
    }
    top++;
    stack[top] = a;
}
int pop()
{
    if(top == -1)
    {
        printf("stack underflow\n");
        return 0;
    }
    int k = stack[top];
    top--;
    return k;
}
void display()
{
    printf("stack elements are :\n");
    for(int i=top; i>=0; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void peep()
{
    int i;
    printf("enter the position :\n");
    scanf("%d",&i);
    if(top-i+1 < 0)
    {
        printf("position is invalid\n");
        return;
    }
    printf("%d\n",stack[top-i+1]);
}
void peek()
{
    if(top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("%d\b",stack[top]);
}
void change()
{
    int i;
    printf("enter the position you want to change :\n");
    scanf("%d",&i);
    if(i > top || top-i+1 <= 0)
    {
        printf("not valid position\n");
        return;
    }
    int n;
    printf("enter the number for inserting :\n");
    scanf("%d",&n);
    stack[top-i+1] = n;
}
int count()
{
    int cnt=0;
    while(top != -1)
    {
        cnt++;
        top--;
    }
    return cnt;
}
int main(){
    while(1)
    {
        int ps,l;
        int n;
        printf("choose your choise from here\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - display all elements of stack \n");
        printf("4 - peep\n");
        printf("5 - change\n");
        printf("6 - peek\n");
        printf("7 - count\n");
        printf("enter yout choise :\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
        printf("enter the element you want to push :\n");
        scanf("%d",&ps);
        push(ps);
        break;

        case 2:
        l = pop();
        printf("the popped element is %d\n",l);
        break;

        case 3:
        display();
        break;

        case 4:
        peep();
        break;
        case 5:
        change();
        break;
        case 6:
        peek();
        break;
        case 7:
        printf("the number of element in stack is %d\n",count());
        break;
        default:
        return 0;
        }
    }
return 0;
}