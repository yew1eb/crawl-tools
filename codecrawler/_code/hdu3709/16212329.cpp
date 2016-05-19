#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;

LL dp[20][20][1800];

int digit[20];

LL dfs(int len,int fixloc,int sum,bool fp)
{
    if(!len)
        return sum == 0 ? 1 : 0;
    if(sum < 0)
        return 0;
    if(!fp && dp[len][fixloc][sum] != -1)
        return dp[len][fixloc][sum];
    int fpmax = fp ? digit[len] : 9;
    LL ret = 0;
    for(int i=0;i<=fpmax;i++){
        ret += dfs(len-1,fixloc,sum+i*(len-fixloc),fp && i == fpmax);
    }
    if(!fp)
        dp[len][fixloc][sum] = ret;
    return ret;
}

LL f(LL n)
{
    if(n == -1)
        return 0;
    int len = 0;
    while(n){
        digit[++len] = n % 10;
        n /= 10;
    }
    LL ret = 0;
    for(int i=len;i>=1;i--){
        ret += dfs(len,i,0,true);
    }
    return ret - len + 1;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int T;
    LL a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&a,&b);
        printf("%I64d\n",f(b)-f(a-1));
    }
    return 0;
}
