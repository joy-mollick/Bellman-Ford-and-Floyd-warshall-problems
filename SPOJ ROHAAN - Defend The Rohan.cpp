
/// this is classical easy one only for floyd warshall

#include<bits/stdc++.h>

using namespace std;

const int mx=51;

int dist[mx][mx];
int adj[mx][mx];

int V,E;

#define inf 1e9

void floyd()
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dist[i][j]=adj[i][j];
        }
    }
    /// dist[i][j]=-1 holds for i and j are not connected by edge .
    /// so we have to take every node as middle node
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                    if((dist[i][k]+dist[k][j]<dist[i][j]))
                    {
                       dist[i][j]=dist[i][k]+dist[k][j];
                    }
            }
        }
    }
}

int main()

{
    int tc,caso=1,src,dest;
    cin>>tc;
    while(tc--)
    {
        cin>>V;
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                cin>>adj[i][j];
            }
        }
        floyd();
        cin>>E;
        int ans=0;
        while(E--)
        {
            cin>>src>>dest;
            ans+=dist[src][dest];
        }
        printf("Case #%d: %d\n",caso,ans);
        caso++;
    }
    return 0;
}
