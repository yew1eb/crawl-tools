#include<iostream>
#include<cstring>
#include<cstdio>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
int t,n,m,d;
double dp[10000+10][55];
vector<int>v[55];
void solve(int x)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[0][i]=1.0/n;
    for(int i=0;i<d;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==x)  continue;
            for(int k=0;k<v[j].size();k++)
                dp[i+1][v[j][k]]+=dp[i][j]*1.0/v[j].size();
        }
    }
    double ans=0.0;
    for(int i=1;i<=n;i++)
    {
        if(i!=x)
            ans+=dp[d][i];
    }
    printf("%.5f\n",ans);
}
int main()
{
    int x,y;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<55;i++)
            v[i].clear();
        scanf("%d%d%d",&n,&m,&d);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
            solve(i);
    }
    return 0;
}
