#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int binary_search(int a[], int n, int key)
{
    int low = 0, high = n;
    int x;
    while(low <= high)
    {
        int mid = (low+high)/2;
        x = mid;
        if(key == a[mid])
        {
            return mid;
        }
        if(key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return x;
}
int main(){
    int n;
    // printf("Enter size of array :- \n");
    // scanf("%d",&n);
    // int arr[n];
    // printf("Enter elements of array :- \n");
    // for(int i=0; i<n; i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    int arr[] = {1,3,5,6};
    printf("%d",binary_search(arr,4,7));
    // if(binary_search(arr,4,7) > 0)
    // {
    //     printf("Element is found at %d index\n",binary_search(arr,n,8));
    // }
    // else
    // {
    //     printf("Element is not found\n");
    // }
return 0;
}