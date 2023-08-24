#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// MAX HEAP :
void insert(int arr[], int n)
{
    int temp,i = n;
    temp = arr[n];
    while(i > 1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i /= 2;
    }
    arr[i] = temp;
}
void delete(int a[], int n)
{
    //printf("%d\n",a[1]);
    int i,j;
    i = 1;
    j = 2*i;
    int x = a[1];
    a[1] = a[n];
    while(j < n-1) // n-1 bcuse pello delete krvano
    {
        if(a[j+1] > a[j])
        {
            j ++;
        }
        if(a[i] < a[j])
        {
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2*j;
        }
        else
        {
            break;
        }
    }
    a[n] = x;
}
int main(){
    int a[] = {0,10,20,30,25,5,40,35};
    // a[0] dhyan ma nai levanu
    //a[1] already in heap
    for(int i=2; i<=7; i++)
    {
        insert(a,i);
    }
    //delete(a,7);
    // HEAP SORTING :
    for(int i=7; i>1; i--)
    {
        delete(a,i);
    }
    printf("Elements in heap :- \n");
    for(int i=1; i<=7; i++)
    {
        printf("%d ",a[i]);
    }
return 0;
}