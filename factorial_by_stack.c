#include<stdio.h>
#include<stdlib.h>
#define size 10
int stack[size];
int top = -1;
void push(int a)
{
    top++;
    stack[top] = a;
}
void pop()
{
    top--;
}
int main(){
    int n;
    printf("enter a number :\n");
    scanf("%d",&n);
    push(1);
    for(int i=2; i<=n; i++)
    {
        push(stack[top]*i);
    }
    printf("%d",stack[top]);
return 0;
}