
/// Its mainly same floyd warshall algorithm 
/// We have to find the shortest path taking distance of every edge summation + maximum node's cost of the path from start node to end node 
/// for two parameters , we had to run twice floyd warshall 


#include<bits/stdc++.h>

#define inf 100000000

using namespace std;

int total, x, dis[81][81], cost[81][81];

int main(){
    int cs=1, n, m, r, u, v, w, q, tcost;
    while((cin>>n>>m>>q)&&((n!=0&&m!=0&&q!=0)))
        {
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) dis[i][j]=0;/// the dist from a node to itself is zero
                else dis[i][j]=inf;/// normally all are infinite
                cost[i][j]=inf;/// initially maxcost of node from the shortest path from i to j is inf.
            }
        }
        for(int i=1;i<=n;i++){
            cin>>x;
            /// the node (i) itself is the maximum node cost of from the path i to i .
            cost[i][i]=x;
        }
        for(int i=1;i<=m;i++){
            cin>>u>>v>>w;
    /// bidirectional graph
            dis[u][v]=w;
            dis[v][u]=w;
    /// taking maximum
            cost[u][v]=cost[v][u]=max(cost[u][u], cost[v][v]);
        }
   /// it is mainly for finding the maximum cost of the node of shortest path from i to j

   /// now ,there can be similar paths from i to j, but we have to choose that path where path distance is shortest + maximum cost of that path
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    total=dis[i][k]+dis[k][j];
                    tcost=max(cost[i][k], cost[k][j]);
                    if(dis[i][j]+cost[i][j]>total+tcost){
                        dis[i][j]=total;
                        cost[i][j]=tcost;
                    }
                }
            }
        }
        /// now cost[i][j] is ready perfectly
        /// again we run floyd warshall to make dis perfectly
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    total=dis[i][k]+dis[k][j];
                    tcost=max(cost[i][k], cost[k][j]);
                    if(dis[i][j]+cost[i][j]>total+tcost){
                        dis[i][j]=total;
                        cost[i][j]=tcost;
                    }
                }
            }
        }
        if(cs!=1)cout<<endl;
        cout<<"Case #"<<cs++<<endl;

        while(q--)
        {
            cin>>u>>v;
            if(dis[u][v]>=inf) cout<<-1<<endl;
            else cout<<dis[u][v]+cost[u][v]<<endl;
        }
    }
    return 0;
}
