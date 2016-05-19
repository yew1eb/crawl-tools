#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 110;

int dp[maxn][maxn],path[maxn][maxn],a[maxn][maxn],n,m;

void initial()
{
    memset(path,-1,sizeof(path));
    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            dp[i][j]=inf;
}

void input()
{
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
}

void print(int num,int index)
{
     if(num<1)  return ;
     if(path[num][index]==-1)
     {
          printf("%d ",index);
          return ;
     }
     else
     {
          print(num-1,path[num][index]);
          printf("%d ",index);
     }
}

void solve(int co)
{
    printf("Case %d\n",co);
    for(int j=1; j<=m; j++)  dp[1][j]=a[1][j];
    for(int i=2; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(j!=1 && dp[i][j]>dp[i-1][j-1]+a[i][j])
            {
                dp[i][j]=dp[i-1][j-1]+a[i][j];
                path[i][j]=j-1;
            }
            if(dp[i][j]>=dp[i-1][j]+a[i][j])
            {
                dp[i][j]=dp[i-1][j]+a[i][j];
                path[i][j]=j;
            }
            if(j!=m && dp[i][j]>=dp[i-1][j+1]+a[i][j])
            {
                dp[i][j]=dp[i-1][j+1]+a[i][j];
                path[i][j]=j+1;
            }
        }
    int Min=inf,index=-1;
    for(int j=m;j>=1;j--)
    {
        if(Min>dp[n][j])
        {
            Min=dp[n][j];
            index=j;
        }
    }
    print(n-1,path[n][index]);
    printf("%d\n",index);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int co=1; co<=T; co++)
    {
        initial();
        input();
        solve(co);
    }
    return 0;
}
