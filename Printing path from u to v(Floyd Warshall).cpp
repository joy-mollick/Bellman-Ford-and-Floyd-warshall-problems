/// assuming graphs are not connected ,that's why I use a different condition inside if condition of floyd warshall loop 
/// Extra two dimensional array path[][] has been added.
/// paths vector stored the all nodes from i to j.

const int mx=1001;

int V,E;

#define inf 1e9

int dist[mx][mx];
int adj[mx][mx];
int path[mx][mx];
vector<int>paths;

void floyd()
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dist[i][j]=adj[i][j];
            if(adj[i][j]==inf) path[i][j]=-1;/// there is no edge 
            else path[i][j]=j;/// if there is path,then we can go beyond the edge (i->j) to the node j
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
                    ///so,we will make intermediate node k i.e. take the route i to k as our intermediate route 
                    ///so, first to go from i to j ,we will take the root of i to k.
                    path[i][j]=path[i][k];
                }

                }
            }
        }
    }
    
}

void path_from_u_to_v(int u,int v)
{
    if(path[u][v]==-1) return;
    paths.push_back(u);
     while (u != v) { 
        u = path[u][v]; 
        paths.push_back(u); 
    } 
}
