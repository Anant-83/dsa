#include<stdio.h>
#include<stdlib.h>
void display(int a[], int n)
{
    printf("array elements are :\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n------------\n");
}
void insert(int a[], int n)
{
    int k,p;
    printf("enter the position to insert :\n");
    scanf("%d",&p);
    if(p<0 || p >= n)
    {
        printf("entered position is not valid\n");
        return;
    }
    printf("enter the element to insert :\n");
    scanf("%d",&k);
    n++;
    for(int i=n-1; i>=p; i--)
    {
        a[i] = a[i-1];
    }
    a[p-1] = k;
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n-----------\n");
}
void delete(int a[], int n)
{
    int k;
    printf("enter the element to delete :\n");
    scanf("%d",&k);
    int id,flag=0;
    for(int i=0 ;i<n; i++)
    {
        if(a[i] == k)
        {
            id = i;
            flag  =1;
            break;
        }
    }
    if(!flag)
    {
        printf("element was not found\n");
        return;
    }
    for(int i=id; i<n; i++)
    {
        a[i] = a[i+1];
    }
    n--;
    display(a,n);
}
void clear(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        a[i] = 0;
    }
    display(a,n);
}
void search(int a[], int n)
{
    printf("-->enter the element to found :\n");
    int k;scanf("%d",&k);
    int flag=0;
    for(int i=0; i<n; i++)
    {
        if(a[i] == k)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    printf("element found\n");
    else
    printf("element not found\n");
}
int sort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    display(arr,n);
}
void modify(int a[],int n)
{
    int k,j;
    printf("enter the value and position to modify :\n");
    scanf("%d%d",&k,&j);
    if(j < 0 || j >= n)
    {
        printf("not valid position\n");
        return;
    }
    a[j-1] = k;
    display(a,n);
}
void replace(int a[], int n)
{
    int k,l;
    printf("enter the two values to replace :\n");
    scanf("%d %d",&k,&l);
    int f1=0,f2=0;
    int id1,id2;
    for(int i=0; i<n; i++)
    {
        if(a[i] == k)
        {
            f1=1;
            id1 = i;
        }
        if(a[i] == l)
        {
            f2 = 1;
            id2 = i;
        }
    }
    if(f1 == 0 || f2 == 0)
    {
        printf("enterd one or two element no found\n");
        return;
    }
    int temp = a[id2];
    a[id2] = a[id1];
    a[id1] = temp;
    display(a,n);
}
void duplicate(int a[],int n)
{
    sort(a,n);
    printf("duplicate elements are :\n");
    int x;
    for(int i=0; i<n-1; i++)
    {
        if(a[i] == a[i+1] && x != a[i])
        {
            printf("%d ",a[i+1]);
            x = a[i+1];
        }
    }
}
int main(){
    int n;
    printf("enter the size of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array :\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    while(1)
    {
        int t;
        printf("enter your choise :\n");
        printf("1) Display Array\n");
        printf("2) Add Element in Array \n");
        printf("3) Remove Element\n");
        printf("4) Clear Array\n");
        printf("5) Search Element in Array\n");
        printf("6) Sort Elements\n");
        printf("7) Find Duplicate Elements\n");
        printf("8) Modify Element at given  Location \n");
        printf("9) Replace Values in Array \n");
        scanf("%d",&t);
        switch (t)
        {
        case 1:
            display(arr,n);
            break;
        case 2:
            insert(arr,n);
            break;
        case 3:
            delete(arr,n);
            break;
        case 4:
            clear(arr,n);
            break;
        case 5:
            search(arr,n);
            break;
        case 6:
            sort(arr,n);
            break;
        case 7:
            duplicate(arr,n);
            break;
        case 8:
            modify(arr,n);
           // display(arr,n);
            break;
        case 9:
            replace(arr,n);
           // display(arr,n);
            break;
        default:
            return 0;
        }
    }
return 0;
}