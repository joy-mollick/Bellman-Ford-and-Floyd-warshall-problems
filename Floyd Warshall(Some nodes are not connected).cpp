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
    /// dist[i][j]=-1 holds for i and j are not connected by edge .
    /// so we have to take every node as middle node
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                /// i->k and k->j must should be connected by edge i.e. not equal to -1 ,then we can proceed from i to j.
                if(dist[i][k]!=-1&&dist[k][j]!=-1)
                {
                    /// if i and j are not directly connected i.e. -1 ,then we will use i->k and k->j indirectly to make edge i.e. i->j .
                    /// Or, dist[i][j] is greater than recent
                    if(dist[i][j]==-1|| (dist[i][k]+dist[k][j]<dist[i][j]))
                    {
                       dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
}
