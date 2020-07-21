/// Time Complexity O(V*E) ,slower than Dijkstra 

/// total nodes ->V
/// total edges ->E
int V,E;

#define inf 1e9

const int mx=1e5;

vector<int>dist(mx,inf);

struct Edge
{
    int u,v,weight;
};

vector<Edge>edge;

void Bellman_ford(int src)
{
    E=(int)edge.size();
    /// V-1 times relaxation of every edge
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int now=edge[j].u;
            int to =edge[j].v;
            int Weight=edge[j].weight;
           ///if recent node (now) has been relaxed already i.e. dist[now]!=inf,then we will proceed further by its children
            if(dist[now]!=inf && dist[now]+Weight<dist[to])
            {
                dist[to]=dist[now]+Weight;
            }
        }
    }
    bool negative_cycle_flag=false;
    for(int i=0;i<E;i++)
    {
        int now=edge[i].u;
        int to =edge[i].v;
        int Weight=edge[i].weight;
        /// after V-1 iterations ,one more iteration can lead you also a shortest_path implies that there is a negative cycle .
        if(dist[now]!=inf && dist[now]+Weight<dist[to])
        {
            negative_cycle_flag=true;
            break;
        }
    }
}
