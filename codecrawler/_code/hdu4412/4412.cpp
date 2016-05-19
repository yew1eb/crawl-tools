#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 1005
#define MAXN 200005
#define INF 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-6
const double pi=acos(-1.0);
typedef long long ll;
using namespace std;

int n,m,cnt;
map<int,double>mp;
map<int,double>::iterator it;
double cost[maxn][maxn];
double dp[55][maxn],p[maxn];
int pos[maxn];

void init()
{
    int i,j,cur;
    cnt=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cnt++;
        pos[cnt]=it->first;
        p[cnt]=it->second;
    }
    double lp,rp,suml,sumr,best;
    for(i=1;i<=cnt;i++)
    {
        cost[i][i]=0;
        suml=sumr=rp=0;
        lp=p[i];
        cur=i;
        for(j=i+1;j<=cnt;j++)
        {
            rp+=p[j];
            sumr+=p[j]*(pos[j]-pos[cur]);
            best=suml+sumr;
            while(cur<cnt&&best>suml+sumr+(pos[cur+1]-pos[cur])*(lp-rp)) // 中心点右移
            {
                suml+=(pos[cur+1]-pos[cur])*lp;
                sumr-=(pos[cur+1]-pos[cur])*rp;
                lp+=p[cur+1];
                rp-=p[cur+1];
                best=suml+sumr;
                cur++;
            }
            cost[i][j]=best;
            //printf("i:%d j:%d cur:%d best:%lf\n",i,j,cur,best);
        }
    }
}
void solve()
{
    int i,j,k;
    double d,sum=p[1];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=cnt;j++)
        {
            dp[i][j]=INF;
        }
    }
    for(j=1;j<=cnt;j++)
    {
        dp[1][j]=cost[1][j];
    }
    double ans=INF;
    for(i=1;i<m;i++)
    {
        for(j=1;j<=cnt;j++)
        {
            for(k=j+1;k<=cnt;k++)
            {
                dp[i+1][k]=min(dp[i+1][k],dp[i][j]+cost[j+1][k]);
            }
        }
        ans=min(ans,dp[i][cnt]);
    }
    ans=min(ans,dp[m][cnt]);
    printf("%.2f\n",ans);
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break ;
        mp.clear();
        int num,x;
        double d;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            for(j=1;j<=num;j++)
            {
                scanf("%d%lf",&x,&d);
                mp[x]+=d;
            }
        }
        init();
        solve();
    }
    return 0;
}
/*
2 1
2 0 0.5 1 0.5
2 1 0.1 3 0.9
0 0
*/