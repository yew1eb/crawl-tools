#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int dp[59][50009];
int dfs(int z,int s)
{
    if(dp[z][s]!=-1) return dp[z][s];
    if(z==0) return dp[z][s] = s&1;
    if(z==1) return dp[1][s]=1;
    if(s==1) return dp[z][s] = dfs(z+1,0);
    dp[z][s] = 0;
    if(!dfs(z-1,s)) dp[z][s] = 1;///直接拿走1个的
    if(s>1&&!dfs(z,s-1)) dp[z][s] = 1;
    if(s>1&&!dfs(z-1,s+1)) dp[z][s] = 1;
    if(z>1&&!dfs(z-2,s?s+3:s+2)) dp[z][s] = 1;///合并之后加入s里
    return dp[z][s];
}
int main()
{
    freopen("in.txt","r",stdin);
    int cas,T=1,n;
    scanf("%d",&cas);
    memset(dp,-1,sizeof(dp));
    while(cas--)
    {
        scanf("%d",&n);
        int z=0,s=0,t=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t==1) z++;
            else s+=t+1;
        }if(s>1) s--;
        printf("Case #%d: %s\n",T++,dfs(z,s)?"Alice":"Bob");
    }
    return 0;
}
