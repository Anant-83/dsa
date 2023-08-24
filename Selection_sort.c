#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    printf("Enter the size of array :- \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array :- \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        int k = i;
        for(int j=i; j<n; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    printf("Sorted array :- \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}