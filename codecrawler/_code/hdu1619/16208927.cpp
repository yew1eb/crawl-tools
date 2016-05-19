#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX 102
using namespace std;
int m,n;
int map[MAX][MAX],nxt[MAX][MAX];
long long dp[MAX][MAX];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    memset(map,0,sizeof(map));
    memset(dp,0,sizeof(dp));
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%lld",&map[i][j]);
    for(int i=m;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
        int ita,itb,itc,res;
        if(j==n)
            ita=1,itb=n-1,itc=n;
        else if(j==1)
            ita=1,itb=2,itc=n;
        else
            ita=j-1,itb=j,itc=j+1;
        long long a=dp[ita][i+1],b=dp[itb][i+1],c=dp[itc][i+1];
        if(a<=b&&a<=c)
            res=ita;
        else if(b<=a&&b<=c)
            res=itb;
        else
            res=itc;
        dp[j][i]=dp[res][i+1]+map[j][i];
        nxt[j][i]=res;
        }
    }
    long long ans=1<<30;
    int ansa=0;
    for(int i=1;i<=n;i++)
        if(ans>dp[i][1])
        {
        ansa=i;
        ans=dp[i][1];
        }
    printf("%d",ansa);
    for(int i=1;i<m;i++)
    {
        ansa=nxt[ansa][i];
        printf(" %d",ansa);
    }
    printf("\n%lld\n",ans);
    }
    return 0;
}
