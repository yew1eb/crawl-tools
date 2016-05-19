#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 104;
const int INF = 0x3fffff;
const double eps = 1e-4;
struct node
{
    int per,remain,s1,p1,s2,p2;
    double ave1,ave2;
}lcm[N];
int n,m;

int dp[1110000];
int pack(int cur,int sum)
{
    int i;
    int a=min(lcm[cur].s1,lcm[cur].s2);
    int b=max(lcm[cur].s1,lcm[cur].s2);
    if(sum < a)
        return min(lcm[cur].p1,lcm[cur].p2);    sum+=b-1;
    for(i=1;i<=sum;i++)
        dp[i]=INF;
    dp[0]=0;
    for(i=1;i<=sum;i++)
        if(i>=lcm[cur].s1&&((i-lcm[cur].s1==0)||dp[i-lcm[cur].s1]))
            dp[i]=min(dp[i],dp[i-lcm[cur].s1]+lcm[cur].p1);
    for(i=1;i<=sum;i++)
        if(i>=lcm[cur].s2&&((i-lcm[cur].s2==0)||dp[i-lcm[cur].s2]))
            dp[i]=min(dp[i],dp[i-lcm[cur].s2]+lcm[cur].p2);
    int ans=INF;
    for(i=sum-(b-1);i<=sum;i++)
        ans=min(ans,dp[i]);
    return ans;
}

int isok(int x)
{
    int money = m;
    int i;
    for(i = 0;i < n;i ++)
    {
        int need = lcm[i].per * x - lcm[i].remain;
        money -= pack(i,need);
        if(money < 0)
            return 0;
    }
    if(money < 0)
        return 0;
    return 1;
}

int main()
{
    int cnt,i;
    while(scanf("%d%d",&n,&m),(m + n))
    {
        int mx = 100000;
        for(i = 0;i < n;i ++)
        {
            scanf("%d%d%d%d%d%d",&lcm[i].per,&lcm[i].remain,&lcm[i].s1,&lcm[i].p1,&lcm[i].s2,&lcm[i].p2);
            lcm[i].ave1 = (double)lcm[i].s1 / (lcm[i].p1 * 1.0);
            lcm[i].ave2 = (double)lcm[i].s2 / (lcm[i].p2 * 1.0);
            int tmp = m / lcm[i].p2;
            cnt = (m - lcm[i].p2 * tmp) * lcm[i].s1 / lcm[i].p1 + tmp * lcm[i].s2;
            cnt += lcm[i].remain;
            cnt /= lcm[i].per;
            if(mx > cnt)
                mx = cnt;
        }
        int l = 1;
        int r = mx;
        int mid;
        int ans;
        while(l <= r)
        {
            mid = (l + r)>>1;
            if(!isok(mid))
                r = mid - 1;
            else
            {
                ans = mid;
                l = mid + 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}