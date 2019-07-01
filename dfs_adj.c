#include<stdio.h>
void dfs(int );
int visited[7];
int matrix[7][7]={
    {0,1,1,1,0,0,0},
    {0,0,0,0,1,0,0},
    {0,0,0,1,0,1,0},
    {0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,1,0,0},
};

int main()
{
    int i=0;
    for(i=0; i<7; i++)
        visited[i]=0;
    dfs(0);
    return (0);
}
void dfs(u)
{
    printf("%d\t",u);
    visited[u]=1;
    int v=0;
    for(v=0; v<7; v++)
    {
        if(matrix[u][v]!=0 && visited[v]!=1)
            dfs(v);
    }
}
