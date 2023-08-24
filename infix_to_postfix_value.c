#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char stack[20];
int top = -1;
char ans[20];
int priority(char c)
{
    if(c == '^')
    return 3;
    if(c == '/' || c == '*')
    return 2;
    if(c == '+' || c == '-')
    return 1;

    return -1;
}
void push(char a)
{
    top++;
    stack[top] = a;
}
void pop()
{
    top--;
}
int pop_element()
{
    return stack[top--];
}
void solve(char infix[])
{
    int j=0;
    for(int i=0; i<strlen(infix); i++)
    {
        if(infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= 'a' && infix[i] <= 'z')
        {
            ans[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                ans[j++] = stack[top];
                pop();
            }
            if(top != -1)
            {
                pop();
            }
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(infix[i]))
            {
                ans[j++] = stack[top];
                pop();
            }
            push(infix[i]);
        }
    }
    while(top != -1)
    {
        ans[j++] = stack[top];
        pop();
    }
    ans[j] = '\0';
}
int value()
{
    for(int i=0; i<strlen(ans); i++)
    {
        if(ans[i] >= '0' && ans[i] <= '9')
        {
            push(ans[i]);
        }
        else
        {
            int a = pop_element();
            int b = pop_element();
            
        }
    }
}
int main(){
    char infix[20];
    printf("enter the infix :\n");
    scanf("%s",infix);
    solve(infix);
    printf("the value of postfix is %d",value());
return 0;
}