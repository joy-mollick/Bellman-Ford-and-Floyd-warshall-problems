
/// Floyd-warshall Algorithm , all pairs shortest path
/// Time Complexity O(V^3) , Space Complexity O(V^2)

/*
 Think about ,(i)-------(k)--------(j) this three nodes
 dist[i][k]+dist[k][j] =dist[i][j],where dist[i][j] holds for shortest distance between i and j node .
 So, by taking every node as middle node we have to find out dist[i][j] for every pair .At the end dist[i][j] holds for shortest path distance of every pair.
*/

#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

int V;

#define inf 1e9

int dist[mx][mx];
int adj[mx][mx];

void floyd()
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dist[i][j]=adj[i][j];
        }
    }

    /// so we have to take every node as middle node
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int main()

{
    scanf("%d",&V);
    /// taking adjacency matrix 
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    floyd();

    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
