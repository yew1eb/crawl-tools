#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<map>
#include<cmath>
#include<iostream>
#include <queue>
#include <stack>
#include<algorithm>
#include<set>
using namespace std;
#define INF 1e8
#define inf -0x3f3f3f3f
#define eps 1e-8
#define ll __int64
#define maxn 250001
#define mol 100007
int dp[55];
int n,ans;
void dfs(int m,int d)
{
    if(d>n)
    {
        if(m>ans)
            ans=m-1;
        return ;
    }
    int tmp;
    double cnt;
    cnt=sqrt((double)(dp[d]+m));
    tmp=(int)cnt;
    if(cnt-tmp<eps||dp[d]==0)
    {
        dp[d]=m;
        m++;
        d=1;
        dfs(m,d);
        m--;
    }
    else dfs(m,d+1);
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        ans=0;
        dfs(1,1);
        printf("%d\n",ans);
    }
    return 0;
}
