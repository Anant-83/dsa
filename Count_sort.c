#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    printf("Enter the size of array :- \n");
    scanf("%d",&n);
    int arr[n];
    int mx = INT_MIN;
    printf("Enter the elements of array :- \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        if(mx < arr[i])
        {
            mx = arr[i];
        }
    }
    int f[mx+1];
    for(int i=0; i<mx+1; i++)
    {
        f[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        f[arr[i]]++;
    }
    int i = 0, j = 0;
    while(i < mx+1)
    {
        if(f[i] > 0)
        {
            arr[j++] = i;
            f[i]--;
        }
        else
        {
            i++;
        }
    }
    printf("Sorted array :- \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}