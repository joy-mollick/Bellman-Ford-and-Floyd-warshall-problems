
/// Very Classical One 

#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

int V,E;

#define inf 1e9

int dist[mx][mx];
int adj[mx][mx];
map<int,string>mp;

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
                /// obviously i - k route should be reachable
                /// and k - j route should be reachable
                if(dist[i][k]!=inf&&dist[k][j]!=inf)
                {

                if((dist[i][k]+dist[k][j]<dist[i][j])||(dist[i][j]==inf))
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }

                }
            }
        }
    }
    /// for marking negative cycle's node and undefined paths.
      for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if (dist[i][k]<inf && dist[k][k]<0 && dist[k][j]<inf )
                {
                    dist[i][j] = -inf;
                }
            }
        }
    }
}

int main()

{
    int tc=1;
    string str;
    int q,x,y;
    while(scanf("%d",&V)&&V!=0)
    {
    mp.clear();
    ///taking adjacency matrix
    for(int i=1;i<=V;i++)
    {
        cin>>str;
        mp[i]=str;
        for(int j=1;j<=V;j++)
        {
            scanf("%d",&adj[i][j]);
            if(i==j && adj[i][j]>0) adj[i][j]=0;
            else if(i!=j && adj[i][j]==0) adj[i][j]=inf;///there is no path
        }
    }

    floyd();
    scanf("%d",&q);
    printf("Case #%d:\n",tc);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        x++;y++;
        if(dist[x][y]==inf)/// not reachable
            cout<<mp[x]<<"-"<<mp[y]<<" "<<"NOT REACHABLE"<<endl;
        else if(dist[x][y]==-inf)/// x and y fall into a negative trap
        cout<<"NEGATIVE CYCLE"<<endl;
        else/// print distance
        cout<<mp[x]<<"-"<<mp[y]<<" "<<dist[x][y]<<endl;
    }
    tc++;
    }

    return 0;
}
