/// assuming graphs are not connected ,that's why I use a different condition inside if condition of floyd warshall loop 


const int mx=1001;

int V,E;

#define inf 1e9

int dist[mx][mx];
int adj[mx][mx];
vector<int>negative_cycle;

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
    /// for marking negative cycle's node .
      for(int k=1;k<=V;k++)
    {
        /// if the path of a node to itself holds negative value ,then it is a part of negative cycle
                if (dist[k][k]<0)
                {
                    negative_cycle.push_back(k);
                }
    }
}
