#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "cmath"
using namespace std;

int N;
struct NODE
{
    double x,y;
}p[205];
double dis[205][205],dp[205][205];

void solve()
{
    int i,j,k;
    dp[1][2]=dis[1][2];
    for(j=3;j<=N;j++)
    {
        for(i=1;i<j-1;i++)
        {
            dp[i][j]=dp[i][j-1]+dis[j-1][j];
        }
        dp[j-1][j]=999999999;
        for(i=1;i<j-1;i++)
        {
            dp[j-1][j]=min(dp[j-1][j],dp[i][j-1]+dis[i][j]);
        }
    }
    dp[N][N]=dp[N-1][N]+dis[N-1][N];
}

int main()
{
    while(~scanf("%d",&N))
    {
        int i,j,k;
        for(i=1;i<=N;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        for(i=1;i<=N;i++) for(j=i+1;j<=N;j++) dis[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        solve();
        printf("%.2lf\n",dp[N][N]);
    }
}
