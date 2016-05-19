#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define maxn 55000
#define mod 10000007
#define LL __int64
int vis[maxn];
int dp[maxn];
int biao[2][301];
int a[maxn];
struct list
{
    int x;
    int id;
    friend bool operator <(const list &a,const list &b)
    {
        return a.x<b.x;
    }
}nn[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            nn[i].x=a[i];
            nn[i].id=i;
        }
        sort(nn+1,nn+n+1);
        for(int i=1; i<=n; i++)
        {
            if(nn[i].x!=nn[i-1].x)
            {
                a[nn[i].id]=i;
            }
            else
            {
                a[nn[i].id]=a[nn[i-1].id];
            }
        }
        memset(vis,-1,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(biao,-1,sizeof(biao));
        int m=sqrt(1.0*n);
        for(int i=1; i<=n; i++)
        {
            int x=a[i];
            int k=i&1;
            int ks=(!k);
            if(x!=a[i-1])biao[k][0]=i-1;
            else biao[k][0]=biao[ks][0];
            dp[i]=dp[biao[k][0]]+1;
            int p;
            p=-1;
            for(int j=1; j<=m; j++)
            {
                if(vis[x]==-1||vis[x]<biao[ks][j-1])biao[k][j]=biao[ks][j-1];
                else
                {
                    biao[k][j]=biao[ks][j];
                }
                if(biao[k][j]==-1)break;
                dp[i]=min(dp[i],dp[biao[k][j]]+(j+1)*(j+1));
            }
            vis[x]=i;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}