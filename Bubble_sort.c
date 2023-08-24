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
    for(int i=0; i<n-1; i++)
    {
        int check = 0;
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = 1;
            }
        }
        if(!check)
        {
            break;
        }
    }
    printf("Array in sorted order :- \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}