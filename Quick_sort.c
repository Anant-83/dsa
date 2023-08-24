#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// int partition(int a[], int l, int h)
// {
//     int pivot = a[h];
//     int i = l-1;
//     for(int j=l; j<h; j++)
//     {
//         if(a[j] < pivot)
//         {
//             i++;
//             swap(&a[i],&a[j]);
//         }
//     }
//     swap(&a[i+1],&a[h]);
//     return i+1;
// }
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low,j = high;
    do
    {
        do
        {
            i++;
        }while(a[i] <= pivot);
        do
        {
            j--;
        }while(a[j] > pivot);
        if(i < j)
        {
            swap(&a[i],&a[j]);
        }
    }while(i < j);
    swap(&a[low],&a[j]);
    return j;
}
void quick_sort(int a[], int low, int high)
{
    int j;
    if(low < high)
    {
        j = partition(a,low,high);
        quick_sort(a,low,j-1);
        quick_sort(a,j+1,high);
    }
}
int main(){
    int n;
    printf("Enter the size of array :- \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the value of array :- \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    printf("Sorted array :- \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}