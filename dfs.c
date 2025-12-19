#include<stdio.h>
#include<stdlib.h>

#define max 100

int visited[max];
int a[max][max];
int n;

void DFS(int i)
{
    int j;
    printf("%d ", i);
    visited[i]=1;
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==1 && !visited[j])
            DFS(j);
    }
}

int main()
{
    printf("enter the no. of vertices: ");
    scanf("%d", &n);

    printf("enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int s;
    printf("enter the starting vertex: ");
    scanf("%d", &s);

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    printf("DFS traversal: ");
    DFS(s);

    return 0;
}
