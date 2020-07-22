
/// Classical Fast Bellman Ford Algorithm ,ignore unnecessary relaxation 
/// Time-0ms

#include<bits/stdc++.h>

using namespace std;
/// total nodes ->V
/// total edges ->E
int V,E;

#define inf INT_MAX

typedef long long ll;

const int mx=201;

vector<ll>dist(mx,inf);

struct Edge
{
    int u,v;
    ll weight;
};

vector<Edge>edge;

void Bellman_ford(int src)
{
    bool update=false;
    E=(int)edge.size();
    dist[src]=0;
    /// V-1 times relaxation of every edge
    for(int i=0;i<V-1;++i)
    {
        update=false;
        for(int j=0;j<E;++j)
        {
            int now=edge[j].u;
            int to =edge[j].v;
            int Weight=edge[j].weight;
           ///if recent node (now) has been relaxed already i.e. dist[now]!=inf,then we will proceed further by its children
            if(dist[now]!=inf && dist[now]+Weight<dist[to])
            {
                dist[to]=dist[now]+Weight;
                update=true;
            }
        }
        if(!update) break;/// there is no need to iterate again
    }


    for(int i=0;i<E;++i)
    {
        int now=edge[i].u;
        int to =edge[i].v;
        int Weight=edge[i].weight;
        /// after V-1 iterations ,one more iteration can lead you also a shortest_path implies that there is a negative cycle .
        if(dist[now]!=inf && dist[now]+Weight<dist[to])
        {
           dist[to]=-inf;/// again this node is being relaxed ,so obviously after some relaxation - it will lead you to a negative cost.mark them as negative
        }
    }
}

int main()
{
    int tc=0;
    while(scanf("%d",&V)==1)
    {
    int busy[V+1];
    for(int i=1; i<=V; ++i) scanf("%d",&busy[i]);

    for(int k=0;k<=V;k++)
    {
        dist[k]=inf;
    }

    edge.clear();
    scanf("%d",&E);
    int u,v,q,nd;
    ll cost;
    while(E--)
        {
                scanf("%d%d",&u,&v);
                cost=busy[v]-busy[u];
                cost=(cost*cost*cost);/// cost^3
                Edge e;
                e.u=u;
                e.v=v;
                e.weight=cost;
                edge.push_back(e);
        }
    Bellman_ford(1);
    printf("Set #%d\n", ++tc);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&nd);
        if(dist[nd]<3||dist[nd]==inf)
        {
            printf("?\n");
        }
        else
        {
            printf("%lld\n",dist[nd]);
        }
    }

    }
    return 0;
}
