#include<iostream>
#include<algorithm>
using namespace std;
int dp[5005];
struct good
{
    int p,q,v;
}g[505];
bool cmp(good a,good b)
{
    return a.q-a.p<b.q-b.p;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%d %d %d",&g[i].p,&g[i].q,&g[i].v);
        sort(g,g+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=m;j>=0;j--)
            {
                if(j<g[i].q || j-g[i].p<0)
                    continue;
                dp[j]=max(dp[j],dp[j-g[i].p]+g[i].v);
            }
        }
        int ans=0;
        for(int i=0;i<=m;i++)
            if(dp[i]>ans)
                ans=dp[i];
        printf("%d\n",ans);
    }
    return 0;
}