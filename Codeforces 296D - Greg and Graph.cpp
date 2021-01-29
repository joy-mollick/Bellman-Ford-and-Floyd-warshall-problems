
/// Codeforces 296D - Greg and Graph 
/// Only Floyd Warshall and edge relaxation facts
/// Nice problem!!


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxx=1000;

int vis[maxx];
ll dist[maxx][maxx];
ll ans[maxx];
int serial[maxx];
/// when we relax our graph through some edges
/// What does it mean ?
/// It means that if we take into account only those edges
/// Then what will be the shortest path distance between pairs (i,j) dist[i][j]


int main()
{

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>dist[i][j];
        }
    }
    
    for(int i=1;i<=n;i++) cin>>serial[i];

    int now;

        /// we will relax our edges from reverse side
        for(int i=n;i>=1;--i)
    {
        now=serial[i];
        vis[now]=1;
         for(int j=1;j<=n;++j)
            {
            for(int k=1;k<=n;++k)
            {
                dist[j][k]=min(dist[j][k],dist[j][now]+dist[now][k]);
            }
            }
        /// summing all pairs' shortest length assuming now and all serial[i].....serial[n] nodes
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(vis[j]&&vis[k]) ans[i]+=dist[j][k];
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";

    return 0;
}
