#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;

#define LL __int64
const int maxn=5e3+10;
struct node{
    int l,r;
}e[maxn];
int t;
int dp[maxn][maxn],a[maxn],v[maxn];
LL sum[maxn];
int dfs(int l,int r,int i)
{
    if(dp[l][r]!=-1)return dp[l][r];
    if(l>=r)return dp[l][r]=0;
    dp[l][r]=a[r-l+1];
    for(;i<t;i++)
        dp[l][r]=min(dp[l][r],a[e[i].l-l+1]+a[r-e[i].r+1]+dfs(e[i].l+1,e[i].r-1,i+1));
    return dp[l][r];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int i,j,k,p,q;
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            sum[i]=sum[i-1]+v[i];
        }
        t=0;
        p=1;
        for(q=n;q>=1;q--)
        {
            while(p<q&&sum[p]-sum[0]<sum[n]-sum[q-1])p++;
            if(p==q)break;
            if(sum[p]-sum[0]==sum[n]-sum[q-1])
            {
                e[t].l=p;
                e[t++].r=q;
            }
        }
        //for(i=0;i<t;i++)printf("%d %d %d\n",i,e[i].l,e[i].r);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(1,n,0));
    }
    return 0;
}
