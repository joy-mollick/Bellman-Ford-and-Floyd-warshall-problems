/// Here dist[i][j] shows only -1 or 0 which implies that is j is reachable from i or not ??

const int mx=1001;

int V,E;

#define inf 1e9

int dist[mx][mx];
int adj[mx][mx];

void floyd()
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
    ///we will take only 1 or 0 i.e. edge is available or not?
    /// no need to think about to put inf 
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
    ///if dist[i][j] is already on,then it's okk
    ///otherwise i->k and k->j both should be connected by edge 
    /// much faster than naive code of if condition .
               dist[i][j]=dist[i][j]||(dist[i][k] && dist[k][j]);
            }
        }
    }
}
