#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
char stack[size];
int top  = -1;
void push(char c)
{
    top++;
    stack[top] = c;
}
void pop()
{
    printf("%c",stack[top]);
    top--;
}
int main(){
    char s[10];
    printf("enter a string :\n");
    scanf("%s",s);
    int l = strlen(s);
    for(int i=0; i<l; i++)
    {
        push(s[i]);
    }
    printf("string in reverce order :\n");
    for(int i=0; i<l; i++)
    {
        pop();
    }
return 0;
}