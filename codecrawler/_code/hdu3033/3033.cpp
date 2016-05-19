#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

typedef struct node
{
    int v,w;
} shoe;
vector<shoe>brand[15];
int main()
{
    int dp[15][10005];
    int n,m,k,a;
    shoe s;
    while(cin>>n>>m>>k)
    {
        for(int i=0;i<=k;i++)
        brand[i].clear();
        for(int i=0; i<n; i++)
        {
            cin>>a>>s.v>>s.w;
            brand[a].push_back(s);
        }
        memset(dp,-1,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));

        for(int i=1;i<=k;i++)
        for(int p=0;p<(int)brand[i].size();p++)
        for(int j=m;j>=brand[i][p].v;j--)
        {
            if(dp[i][j-brand[i][p].v]!=-1) dp[i][j]=max2(dp[i][j],dp[i][j-brand[i][p].v]+brand[i][p].w); //同一种类的鞋子能取多个
            if(dp[i-1][j-brand[i][p].v]!=-1) dp[i][j]=max2(dp[i][j],dp[i-1][j-brand[i][p].v]+brand[i][p].w);
        }
        if(dp[k][m]>=0)
        cout<<dp[k][m]<<endl;
        else
        cout<<"Impossible"<<endl;
    }
    return 0;
}