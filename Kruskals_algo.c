#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int ans[2][6];
void gunion(int x, int y)
{   if(set[x] < set[y])
    {
        set[x] = set[x] + set[y];
        set[y] = x;
    }
    else
    {
        set[y] = set[y] + set[x];
        set[x] = y;
    }
}
int find(int u) // return the parent of u
{
    int x = u,temp = 0;
    while(set[x] > 0)
    {
        x = set[x];
    }
    return x;
}
int edge[3][9] = {{1,1,2,2,3,4,4,5,5}, 
                  {2,6,3,7,4,5,7,6,7},
                  {25,5,12,10,8,16,14,20,18}};
int included[9] = {0};
int main(){
    int i = 0,n = 7,e = 9,min;
    int k,u,v;
     while(i < 6)
     {
        min = INT_MAX;
        for(int j=0; j<9; j++)
        {
            if(included[j] == 0 && edge[2][j] < min)
            {
                min = edge[2][j];
                u = edge[0][j];
                v = edge[1][j];
                k = j;
            }
        }
        // printf("%d %d\n",find(u),find(v));
        if(find(u) != find(v))
        {
            ans[0][i] = u;
            ans[1][i] = v;
            gunion(find(u),find(v));
            i++;
        }
        included[k] = 1;
        // for(int i=0; i<8; i++)
        // {
        //     printf("%d ",set[i]);
        // }
     }
    for(int i=0; i<n-1; i++)
    {
        printf("(%d,%d)\n",ans[0][i],ans[1][i]);
    }
return 0;
}