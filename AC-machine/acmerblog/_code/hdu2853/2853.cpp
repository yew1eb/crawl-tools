#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define ll long long
#define eps 1e-6
using namespace std;

const int maxn=55;
const int INF=1000000000;
int G[maxn][maxn],lx[maxn],match[maxn],ly[maxn],slack[maxn];
bool visx[maxn],visy[maxn];
int n,m;
bool find(int u)
{
    visx[u]=true;
    for(int i=1; i<=m; i++)
    {
        if(visy[i]) continue;
        if(lx[u]+ly[i]==G[u][i])
        {
            visy[i]=true;
            if(match[i]==-1||find(match[i]))
            {
                match[i]=u;
                return true;
            }
        }
        else slack[i]=min(slack[i],lx[u]+ly[i]-G[u][i]);
    }
    return false;
}
void KM()
{
    memset(match,-1,sizeof(match));
    for(int i=1; i<=n; i++) lx[i]=-INF;
    memset(ly,0,sizeof(ly));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            lx[i]=max(lx[i],G[i][j]);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) slack[j]=INF;
        while(1)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(find(i)) break;
            else
            {
                int temp=INF;
                for(int j=1; j<=m; j++)
                    if(!visy[j]&&temp>slack[j]) temp=slack[j];
                for(int j=1; j<=n; j++)
                    if(visx[j]) lx[j]-=temp;
                for(int j=1; j<=m; j++)
                {
                    if(visy[j]) ly[j]+=temp;
                    else slack[j]-=temp;
                }
            }
        }
    }
}
int main()
{
    int a;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&G[i][j]);
            G[i][j]*=100;
        }
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            tot+=G[i][a];
            G[i][a]++;
        }
        KM();
        int sum=0;
        for(int i=1; i<=m; i++)
        if(match[i]!=-1) sum+=G[match[i]][i];
        printf("%d %d\n",n-sum%100,sum/100-tot/100);
    }
    return 0;
}