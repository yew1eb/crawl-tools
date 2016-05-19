#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
#define MAXN 105
#define MINN -30000
#define ms(a,what) memset(a,what,sizeof(a));
int map[MAXN][MAXN],lx[MAXN],ly[MAXN],vx[MAXN],vy[MAXN],matchy_x[MAXN],slack[MAXN];
int n,m;
int MIN(int a,int b) {return a<b?a:b;}
bool hungary(int u)
{
    int i;
    vx[u]=1;
    for(i=1;i<=n;i++)
    {
        if(vy[i]) continue;
        if(map[u][i]==lx[u]+ly[i])
        {
            vy[i]=1;
            if(matchy_x[i]==-1 || hungary(matchy_x[i]))
            {
                matchy_x[i]=u;
                return 1;
            }
        }
        else  slack[i]=MIN(slack[i],lx[u]+ly[i]-map[u][i]);
    }
    return 0;
}

void KM_match()
{
    int maxx,i,j;
    ms(ly,0);
    for(i=1;i<=n;i++)
    {
        maxx=MINN;
        for(j=1;j<=n;j++) if(map[i][j]>maxx)
            maxx=map[i][j];
        lx[i]=maxx;
    }
    for(int v=1;v<=n;v++)
    {
        ms(slack,127);
        while(1)
        {
            ms(vx,0);  ms(vy,0);
            if(hungary(v))
                break;
            else
            {
                int temp=(1<<30);
                for(i=1;i<=n;i++) if(!vy[i] && temp>slack[i])
                    temp=slack[i];
                for(i=1;i<=n;i++)
                {
                    if(vx[i]) lx[i]-=temp;
                    if(vy[i]) ly[i]+=temp;
                    else slack[i]-=temp;
                }
            }
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,b,x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++) map[i][j]=MINN;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&x);
            if(map[a][b]< -x) map[a][b]=-x;
        }
        ms(matchy_x,-1);
        KM_match();
        int ans=0,f=0;
        for(i=1;i<=n;i++)
        {
            if(map[matchy_x[i]][i]==MINN)
            {
                f=1;
                break;
            }
            ans+=map[matchy_x[i] ][i];
        }
        printf("%d\n",f?-1:-ans);
    }
    return 0;
}