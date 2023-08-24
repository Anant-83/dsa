#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[20];
int top = -1;
char prefix[20];
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
void push(char c)
{
    top++;
    stack[top] = c;
}
void pop()
{
    top--;
}
void solve(char s[])
{
    int l = strlen(s);
    for(int i=0; i<l; i++)
    {
        if(s[i] == '(')
        {
            s[i] = ')';
        }
        else if(s[i] == ')')
        {
            s[i] = '(';
        }
    }
    int j=0;
    for(int i=0; i<l; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
        {
            prefix[j++] = s[i];
        }
        else if(s[i] == '(')
        {
            push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                prefix[j++] = stack[top];
                pop();
            }
            if(top != -1)
            {
                pop();
            }
        }
        else
        {
            while(top != -1 && priority(stack[top]) >= priority(s[i]))
            {
                prefix[j++] = stack[top];
                pop();
            }
            push(s[i]);
        }
    }
    while(top != -1)
    {
        prefix[j++] = stack[top];
        pop();
    }
    prefix[j] = '\0';
}
int main(){
    char infix[20];
    printf("enter the infix :\n");
    scanf("%s",infix);
    solve(strrev(infix));
    printf("prefix : %s",strrev(prefix));
return 0;
}