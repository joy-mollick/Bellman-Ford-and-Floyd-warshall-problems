/// total nodes ->V
/// total edges ->E
int V,E;

#define inf 1e9

const int mx=1e5;

vector<int>dist(mx,inf);
vector<int>negative_cycles;
int par[mx];

struct Edge
{
    int u,v,weight;
};

vector<Edge>edge;

void Bellman_ford(int src)
{
    E=(int)edge.size();
    dist[src]=0;
    /// V-1 times relaxation of every edge
    for(int i=0;i<V-1;++i)
    {
        for(int j=0;j<E;++j)
        {
            int now=edge[j].u;
            int to =edge[j].v;
            int Weight=edge[j].weight;
           ///if recent node (now) has been relaxed already i.e. dist[now]!=inf,then we will proceed further by its children
            if(dist[now]!=inf && dist[now]+Weight<dist[to])
            {
                dist[to]=dist[now]+Weight;
                par[to]=now;
            }
        }
    }

    bool negative_cycle_flag=false;
    int x;
    for(int i=0;i<E;++i)
    {
        int now=edge[i].u;
        int to =edge[i].v;
        int Weight=edge[i].weight;
        /// after V-1 iterations ,one more iteration can lead you also a shortest_path implies that there is a negative cycle .
        if(dist[now]!=inf && dist[now]+Weight<dist[to])
        {
            negative_cycle_flag=true;
            x=to;
            break;
        }
    }

    if(negative_cycle_flag)
    {
///x is the node which is part of negative cycle or reachable from any node of negative cycle path.
///So,to get node from the part of negative cycle surely we have to iterate more V times parent iteration.
///Now it can be surely said that after V times iteration, we can get the node of part of negative weight cycle.
     int y = x;
        for (int i=0; i<V; ++i){
            y = par[y];}
/// Now,if we do parent iteration and get same node again we will stop our iteration ,because we had found all nodes of negative cycles.

        for (int cur=y; ; cur=par[cur])
        {
            negative_cycles.push_back (cur);
            if (cur == y && negative_cycles.size() > 1)
                break;
        }
        reverse (negative_cycles.begin(), negative_cycles.end());
       /// printing the path
        for (int i=0; i<negative_cycles.size(); ++i)
            cout << negative_cycles[i] << ' ';
    }
    else
    {
        cout<<"No Cycle"<<endl;
    }
}
