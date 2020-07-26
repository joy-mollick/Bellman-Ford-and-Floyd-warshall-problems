
/// Here dist[i][j] shows only -1 or 0 which implies that is j is reachable from i or not ??

#include<bits/stdc++.h>

using namespace std;

const int mx=31;

int V,E;

map<string,int>mapping;

#define inf 1e9

double cost[mx][mx];

int main()

{
    int case_=1;
    string str,src,dest;
    while(cin>>V&&V!=0)
    {
        mapping.clear();
        int id=1;
        for(int t=0;t<V;t++)
        {
            cin>>str;
            /// mapping different string into an id number
            mapping[str]=id;
            id++;
        }

        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                cost[i][j]=0.0;
            }
        }
        cin>>E;
        double c;
        while(E--)
        {
            cin>>src>>c>>dest;
            cost[mapping[src]][mapping[dest]]=c;
        }
    /// floyd-warshall modified algorithm
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
               cost[i][j]=max(cost[i][j], cost[i][k]*cost[k][j]);
            }
        }
    }

       bool arbitrage = false;
		for(int p=1;p<=V;p++)
		{
			if(cost[p][p] > 1.0)
			{
				arbitrage= true;
				break;
			}
		}

		if(arbitrage)
		{
			printf("Case %d: Yes\n", case_);
		}
		else
		{
			printf("Case %d: No\n", case_);
		}
		case_++;
    }

    return 0;
}
