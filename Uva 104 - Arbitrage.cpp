
/// This is beautiful classical one 
/// If there is no need to print the path of exchange ,then no need to use an extra outer loop 
/// It is an algorithm by doing slight modification of floyd warshall algorithm 
/// If I use normal foyd warshall then,by normal two dimensional array path[max][max] we can't retrieve our path of converting from particular(i) to (i)
/// as path[i][i] holds for nothing ,but if we add another state called how many exchanges then path[][][] array can help us to find our path based on exchanges  

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 30;
 
int path[MAXN][MAXN][MAXN],n;
double dp[MAXN][MAXN][MAXN];
 
void print(int i,int j,int p){
    if (p == 0)
        printf("%d",i);
    else {
        print(i,path[i][j][p],p-1);
        printf(" %d",j);
    }
}
 
void floyd(){
    for (int p = 1; p < n; p++){
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++){
                        /// i->k has p exchanges and k-j another exchange ,so totally i-j has (p+1) exchanges 
                    if (dp[i][k][p]*dp[k][j][1] > dp[i][j][p+1]+1e-12){
                        dp[i][j][p+1] = dp[i][k][p]*dp[k][j][1];
                        path[i][j][p+1] = k;
                    }
                }
    /// in the case of several answers, we have to choose a shortest exchange one 
    /// So, after every exchange ,check if such conversion exist or not ? 
        for (int i = 1; i <= n; i++)
            if (dp[i][i][p+1]>1.01){
                print(i,i,p+1);
                printf("\n");
                return;
            }
    }
    printf("no arbitrage sequence exists\n");
}
 
int main()
{
    while (scanf("%d",&n) != EOF){
        memset(dp,0,sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j){
                    scanf("%lf",&dp[i][j][1]);
                    ///initially from i to j only hold one exchange operation 
                    path[i][j][1] = i;
                }
        floyd();
    }
    return 0;
}
