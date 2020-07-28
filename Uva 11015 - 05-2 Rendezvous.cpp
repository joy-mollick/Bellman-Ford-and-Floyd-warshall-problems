
/// basic problem of floyd warshall

#include<bits/stdc++.h>

#define inf INT_MAX

using namespace std;

int  dis[26][26];

int main()
{
    int caso=1;
    int V,E,u,v,d;
    while(cin>>V>>E && V!=0)
    {
        map<int,string>mapping;
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                dis[i][j]=inf;
                if(i==j) dis[i][i]=0;
            }
        }

        for(int i=1;i<=V;i++) cin>>mapping[i];

        while(E--)
        {
            cin>>u>>v>>d;
            dis[u][v]=dis[v][u]=d;
        }


         for(int k = 1; k <=V; ++k){
            for(int i = 1; i <=V; ++i){
                for(int j = 1; j <=V; ++j){
                    if(dis[i][j]>dis[i][k] + dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }

         int distance=inf,sum;
         int id;/// from which id ,summation of all other distances are minimum

        for(int i=1; i<=V; i++)
        {
            sum=0;
            for(int j=1; j<=V; j++)
            {
                sum=sum+dis[i][j];
            }
            if(distance>sum)
            {
                distance=sum;
                id=i;
            }
        }
        cout<<"Case #"<<caso<<" : "<<mapping[id]<<endl;
        caso++;
    }
}
