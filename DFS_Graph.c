#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dfs(int g[][7], int x, int n)
{
    static int visited[7] = {0};
    if(visited[x] != 1)
    {
        printf("%d\n",x);
        visited[x] = 1;
        for(int i=1; i<n; i++)
        {
            if(g[x][i] == 1 && visited[i] != 1)
            {
                dfs(g,i,n);
            }
        }
    }
}
int main(){
    int graph[7][7] = {{0,0,0,0,0,0,0},
                       {0,0,1,1,0,0,0},
                       {0,1,0,0,1,0,0},
                       {0,1,0,0,1,0,0},
                       {0,0,1,1,0,1,1},
                       {0,0,0,0,1,0,0},
                       {0,0,0,0,1,0,0}};
                       dfs(graph,1,7);
return 0;
}