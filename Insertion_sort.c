#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    // int n;
    // printf("Enter the size of array :- \n");
    // scanf("%d",&n);
    // int arr[n];
    // printf("Enter the elements of array :- \n");
    // for(int i=0; i<n; i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    int arr[] = {8,5,14,2,10};
    int n = 5;
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        int x = arr[i]; // aa element ena karta je mota hase ene pachad nakhse
        for(j = i-1; j>=0 && x < arr[j]; j--)
        {
            // printf("%d %d\n",arr[j],arr[j+1]);
            arr[j+1] = arr[j];
        }
        // printf("* %d\n",j);
        arr[j+1] = x;
        // for(int i=0; i<n; i++)
        // {
        //     printf("%d ",arr[i]);
        // }
        // printf("\n");
    }
    printf("Sorted array :- \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}