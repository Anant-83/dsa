#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(int a[], int low, int mid, int high)
{
    int b[1000];
    int i = low,j = mid+1,k=low;
    // printf("%d %d\n",low,high);
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++]; 
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    for(; i<=mid; i++)
    {
        b[k++] = a[i];
    }
    for(; j<=high; j++)
    {
        b[k++] = a[j];
    }
    for(int x = low; x<=high; x++)
    {
        a[x] = b[x];
    }
}
void merge_sort(int a[], int n)
{
    int i;
    for(i=2; i<=n; i *= 2)
    {
        for(int j=0; (i+j-1)<=n; j += i)
        {
            // printf("%d , %d\n",j,j+i-1);
                    //low   high
            int mid = (j + (j+i-1))/2;
            merge(a,j,mid,i+j-1);
        }
    }
    if(i/2 < n)
    {
        merge(a,0,i/2 - 1,n);
    }
}
int main(){
    int n;
    printf("Enter the size of array :- \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of array :- \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,n);
    printf("Sorted array :- \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}