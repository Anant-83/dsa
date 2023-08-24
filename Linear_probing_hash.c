#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
int hash(int key)
{
    return key%size;
}
int probe(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while(h[(index+i)%size] != 0)
    {
        i++;
    }
    return (index+i)%size;
}
void insert(int h[], int key)
{
    int index = hash(key);
    if(h[index] != 0)
    {
        index = probe(h,key);
    }
    h[index] = key;
}
int search(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while(h[(index+i)%size] != key)
    {
        i++;
    }
    return (index+i)%size;
}
int main(){
    int ht[10] = {0};
    insert(ht,12);
    insert(ht,25);
    insert(ht,35);
    insert(ht,26);
    // for(int i=0; i<10; i++)
    // {
    //     printf("%d ",ht[i]);
    // }
    printf("key found at %d",search(ht,35));
return 0;
}