#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dig[20];
long long dp[20][2][12];

long long F(int pos,bool have,int last,bool inf)
{
    int i;
    if (pos==-1) return have;
    if (!inf && dp[pos][have][last]!=-1) return dp[pos][have][last];
    int end=inf?dig[pos]:9;
    long long ans=0;
    for (i=0;i<=end;i++)
    {
        if (last==4 && i==9) ans+=F(pos-1,true,i,inf && (i==end));
        else ans+=F(pos-1,have,i,inf && (i==end));
    }
    if (!inf)
    {
        dp[pos][have][last]=ans;
    }
    return ans;
}

long long Cal(long long t)
{
    int i,j,pos=0;
    while(t)
    {
        dig[pos++]=t%10;
        t/=10;
    }
    return F(pos-1,0,0,1);

}

int main()
{
    int i,j,T;
    __int64 n;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%I64d",&n);
        printf("%I64d\n",Cal(n));
    }
    return 0;
}
