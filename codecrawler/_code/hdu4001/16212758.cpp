#include <cstdio>
#include <cstring>
#define  max(a,b) (a>b?a:b)

typedef long long ll;
const int maxn=1050;
int n;
ll a[maxn],b[maxn];
int d[maxn];
ll c[maxn];
ll g[maxn][maxn];
ll dis[maxn];
int ring[maxn];

int find (int x)
{
    return ring[x]==x?x:ring[x]=find(ring[x]);
}

void build()
{
    memset (g , 0 , sizeof(g));
    for (int i=0 ; i<n ; ++i)
        ring[i]=i;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            if(i==j)continue;
            if(d[i]==0)//d=0
            {
                if(d[j]==0)if(a[i]==a[j] && b[i]==b[j])
                {
                    int fi=find(i);
                    int fj=find(j);
                    if(fi==fj)continue;
                    //g[fi][fj]+=c[j];
                    c[fi]+=c[j];
                    ring[fj]=fi;
                    continue;
                }
                if(a[i]>=a[j] && b[i]>=b[j])g[i][j]=c[i];
            }
            if(d[i]==1)
            {
                if(a[i]>=a[j] && b[i]>=b[j] && a[i]*b[i]>a[j]*b[j])g[i][j]=c[i];
            }
            if(d[i]==2)
            {
                if(a[i]>a[j] && b[i]>b[j])g[i][j]=c[i];
            }
        }
    }
}

ll dp(int x)
{
    if(dis[x]>0)return dis[x];
    ll ans=c[x];
    for (int i=0 ; i<n ; ++i)
    {
        if(ring[i]==i)
        if(g[x][i])ans=max(ans,dp(i)+c[x]);
        //if(g[i][x])ans=max(ans,dp(i)+g[i][x]);
    }
    //printf("d[%d]=%d\n",x,dis[x]=ans);
    return dis[x]=ans;
}

void debug ()
{
    puts("graph:");
    for (int i=0 ; i<n ;  ++i)
    {
        for (int j=0 ; j<n ; ++j)
        printf("%I64d  ",g[i][j]);
        puts("");
    }
    puts("c:");
    for (int i=0 ; i<n ; ++i)
    printf("%I64d %d~~~ " ,c[i],ring[i]);
    puts("");
}

int main ()
{
    while (scanf("%d",&n),n)
    {
        for (int i=0 ; i<n ; ++i)
        {
            scanf("%I64d%I64d%I64d%d",a+i , b+i , c+i , d+i);
            if(a[i]<b[i])a[i]^=b[i]^=a[i]^=b[i];
        }
        memset (dis , 0 , sizeof(dis));
        build();
        ll ans=0;
        //debug();
        for (int i=0 ; i<n ; ++i)
        {
            if(ring[i]==i)
                dis[i]=dp(i);
            ans=max(ans,dis[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
