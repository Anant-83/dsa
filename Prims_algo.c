#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mx INT_MAX
int cost[][8] = {{mx,mx,mx,mx,mx,mx,mx,mx},
                 {mx,mx,25,mx,mx,mx,5,mx},
                 {mx,25,mx,12,mx,mx,mx,40},
                 {mx,mx,12,mx,8,mx,mx,mx},
                 {mx,mx,mx,8,mx,16,mx,14},
                 {mx,mx,mx,mx,16,mx,20,18},
                 {mx,5,mx,mx,mx,20,mx,mx},
                 {mx,mx,10,mx,14,18,mx,mx},};
int near[8] = {mx,mx,mx,mx,mx,mx,mx,mx};
int ans[2][6];
int main(){ 
    int min = mx;
    int n = 7;
    int x,y; // min_weight vada edge na indices
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                x = i;
                y = j;
            }
        }
    }
    ans[0][0] = x;    
    ans[1][0] = y;
    near[x] = 0;
    near[y] = 0;
    for(int i=1; i<=n; i++) // min weight for vertex x,y to fill near array first time
    {
        if(near[i] != 0)
        {
            if(cost[i][x] < cost[i][y])
            {
                near[i] = x;
            }
            else
            {
                near[i] = y;
            }
        }
    }
    // for(int i=1; i<=n; i++)
    // {
    //     printf("%d ",near[i]);
    // }

    for(int i=1; i<n-1; i++) // n-1 edges
    {
        int k;
        min = mx;
        // printf("->%d\n",k);
        for(int j=1; j<=n; j++)
        {
            if(near[j] != 0 && cost[j][near[j]] < min)
            {
                // printf("->%d\n",j);
                k = j;
                min = cost[j][near[j]];
            }
        }
        ans[0][i] = k;
        ans[1][i] = near[k];
        near[k] = 0;
        for(int j=1; j<=n; j++)
        {
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]])
            {
                near[j] = k;
            }
        }
    }
    for(int i=0; i<n-1; i++)
    {
       printf("(%d,%d)\n",ans[0][i],ans[1][i]);
    }
return 0;
}