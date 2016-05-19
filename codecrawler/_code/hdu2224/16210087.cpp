#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn=1005;
struct node { double x,y; }P[maxn];
double dist(node a,node b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
int n;
double dp[maxn][maxn];
void solve()
{
    dp[1][0]=dp[0][1]=dist(P[0],P[1]);
    for(int i=2;i<n;i++)
    {
        dp[i][i-1]=1000000000.0;
        for(int j=0;j<i-1;j++)
        {
            dp[i][i-1]=min(dp[i][i-1],dist(P[i],P[j])+dp[i-1][j]);
            dp[i][j]=dist(P[i],P[i-1])+dp[i-1][j];
        }
    }
    double ans=1000000000.0;
    for(int i=0;i<n-1;i++) ans=min(ans,dp[n-1][i]+dist(P[i],P[n-1]));
    printf("%.2lf\n",ans);
}
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>P[i].x>>P[i].y;
        solve();
    }
    return 0;
}
