#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 20
char stack[size];
int top = -1;
int check(char a, char b)
{
    if(a == '(' && b == ')')
    return 1;
    if(a == '[' && b == ']')
    return 1;
    if(a == '{' && b == '}')
    return 1;

    return 0;
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
int main(){
    char s[20];
    printf("enter the bracket sequence here :\n");
    scanf("%s",s);
    int l = strlen(s);
    int flag = 1;
    for(int i=0; i<l; i++)
    {
        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            push(s[i]);
        }
        else
        {
            if(top == -1 || check(stack[top],s[i]) == 0)
            {
                flag = 0;
                break;
            }
            else
            {
                pop();
            }
        }
    }
    if(flag && top == -1)
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not balaced\n");
    }
return 0;
}