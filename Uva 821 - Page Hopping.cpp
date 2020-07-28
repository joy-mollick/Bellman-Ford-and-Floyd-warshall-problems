
/// basic problem of floyd warshall
/// May be , bfs also can work here .not sure .

#include<bits/stdc++.h>

#define inf 100000000

using namespace std;

int  dis[101][101];

int main()
{
    int caso=1;
    set<int>nmber_of_nodes;
    int u,v;
    while((cin>>u>>v)&&(u!=0&&v!=0))
    {
        nmber_of_nodes.clear();
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                dis[i][j]=inf;
                if(i==j) dis[i][i]=0;
            }
        }

        dis[u][v]=1;
        nmber_of_nodes.insert(u);
        nmber_of_nodes.insert(v);

        while((cin>>u>>v)&&(u!=0&&v!=0))
        {
             dis[u][v]=1;
             nmber_of_nodes.insert(u);
             nmber_of_nodes.insert(v);
        }

         for(int k = 1; k <= 100; ++k){
            for(int i = 1; i <= 100; ++i){
                for(int j = 1; j <= 100; ++j){
                    if(dis[i][j]>dis[i][k] + dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }

         int total = 0;
        for(int i = 1; i <= 100; ++i){
            for(int j = 1; j <= 100; ++j){
                if(i != j && dis[i][j] != inf)
                {
                    total =total+dis[i][j];
                }
            }
        }
        int nodes=(int)nmber_of_nodes.size();
        /// how to take two of them nodesC2, (nodes*(nodes-1))/2 .where (u,v) and (v,u) are considered to be same
        /// But ,here (u,v) and (v,u) are different . so, total pairs= (nodes*(nodes-1))/2 *2 = (nodes*(nodes-1)).
        double ans= (double) total / (double) (nodes*(nodes-1));
        printf("Case %d: average length between pages = %.03f clicks\n",caso,ans);
        caso++;
    }
}
