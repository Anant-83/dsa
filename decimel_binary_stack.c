#include<stdio.h>
#include<stdlib.h>
#define size 20
int stack[size];
int top = -1;
void push(int a)
{
    if(top == size-1)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top] = a;
}
int pop()
{
    printf("%d",stack[top]);
    top--;
}
int main(){
    int n;
    printf("enter a decimal number :\n");
    scanf("%d",&n);
    int cnt=0;
    while(n != 0)
    {
        int x = n%2;
        push(x);
        n /= 2;
        cnt++;
    }
    printf("the binary form :\n");
    for(int i=0; i<cnt ; i++)
    {
        pop();
    }
return 0;
}