#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[105];
struct node
{
    int w,v;
};
node g[105][105];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        int i,j;
        memset(dp,0,sizeof(dp));
        memset(g,0,sizeof(g));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&g[i][j].v);
                g[i][j].w=j;
            }
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=0;j--)
            {
                int k;
                for(k=1;k<=m;k++)
                {
                    if(j>=g[i][k].w)
                        dp[j]=max(dp[j],dp[j-g[i][k].w]+g[i][k].v);
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
