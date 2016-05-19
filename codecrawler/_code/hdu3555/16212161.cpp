#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

__int64 dp[25][3];

void Init()
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    int i;
    for(i = 1;i<=22;i++)
    {
        dp[i][0] = dp[i-1][0]*10-dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][2]*10+dp[i-1][1];
    }
}

__int64 solve(__int64 n)
{
    __int64 i,tem = n,len = 0,a[25],flag = 0,ans = 0;
    while(n)
    {
        a[++len] = n%10;
        n/=10;
    }
    a[len+1] = 0;
    for(i = len;i;i--)
    {
        ans+=dp[i-1][2]*a[i];
        if(flag)
        ans+=dp[i-1][0]*a[i];
        if(!flag && a[i]>4)
        ans+=dp[i-1][1];
        if(a[i+1] == 4 && a[i] == 9)
        flag = 1;
    }
    return ans;
}

int main()
{
    int t;
    __int64 n;
    scanf("%d",&t);
    Init();
    while(t--)
    {
        scanf("%I64d",&n);
        printf("%I64d\n",solve(n+1));
    }

    return 0;
}
