#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=100005;

#define mod 258280327

int SUM(int x,int y)
{
    int tmp=x+y;
    int ans=tmp%9;
    if(ans==0)
        return 9;
    return ans;
}

int num[maxn];
int dp[maxn][10];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            sum=SUM(sum,num[i]);
        }
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=9;j++)
            {
                dp[i][j]+=dp[i-1][j];
                dp[i][SUM(num[i],j)]+=dp[i-1][j];
                dp[i][j]%=mod;
                dp[i][SUM(num[i],j)]%=mod;
            }
        }
        int ans=0;
        if(SUM(a,b)==sum)
        {
            ans+=dp[n][a];
            if(a==sum)
                ans--;
        }
        if(a==sum)
            ans++;
        if(b==sum)
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}
