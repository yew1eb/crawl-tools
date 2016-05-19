#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
    int q,p,v;
};
node a[505];
int dp[5500];
int cmp(node a,node b)
{
    return a.q-a.p<b.q-b.p;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].p,&a[i].q,&a[i].v);
        int j;
        sort(a+1,a+n+1,cmp);
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=a[i].q;j--)
            {
                dp[j]=max(dp[j],dp[j-a[i].p]+a[i].v);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
