#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a[], int n)
{
    int mn;
    for(int i=1; i<n; i++)
    {
        if(a[i] < mn)
        {
            mn = a[i];
        }
    }
    return mn;
}
int main(){
    int a[5] = {42,23,-1,9,0};
    printf("%d",min(a,5));
return 0;
}