
/// Time-  0.012s
/// LightOj- 1174 - Commandos
/// BFS / Floyd Warshall Algorithm


/// It is for finding the shortest path of a tree where we can reach all nodes and go to the destination node from initial node.

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int mx=101;
const int inf=INT_MAX;

int dist[mx][mx], n;

void initi ()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        /// there is no self edge
        dist[i][i] = 0;
        for (j = i + 1; j < n; j++)
            dist[i][j] = dist[j][i] = inf;
    }
}

void floyd ()
{
    int i, j, k;
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (dist[i][k]!= inf && dist[k][j]!= inf && dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()

{
    int T,w,query;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
    int s,dest,a,b;
    cin>>n>>query;
    initi();
    while(query--)
        {
            cin>>a>>b;
            dist[a][b]=dist[b][a]=1;
        }
        cin>>s>>dest;
        floyd ();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dist[s][i]==inf || dist[i][dest]==inf) continue;
            int dst=dist[s][i]+dist[i][dest];
            if(dst>ans) ans=dst;
        }
       printf("Case %d: %d\n",caso,ans);
    }
    return 0;
}
