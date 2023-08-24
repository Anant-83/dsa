#include<stdio.h>
#include<stdlib.h>
void solve(int n, char s, char h, char d)
{
    if(n == 1)
    {
        printf("move disk %d from rod %c to %c\n",n,s,d);
        return;
    }
    solve(n-1,s,d,h);
    printf("move disk %d from rod %c to %c\n",n,s,d);
    solve(n-1,h,s,d);
}
int main(){
    int n;
    printf("enter the number of disc :\n");
    scanf("%d",&n);
    // ex - rod a,b,c
    solve(n,'a','b','c');
return 0;
}